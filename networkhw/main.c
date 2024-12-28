#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define CD 5863276
#define PRINTENV 7572809511666715
#define SETENV 6954013771834
#define HELP 6385292014
#define QUIT 6385632776

typedef struct commandType {
    char command[100];
    char parameter[100];
} command_t;

command_t *parser(char *commandStr) {
    command_t *cmd = (command_t *)calloc(1, sizeof(command_t));
    sscanf(commandStr, "%s %s", cmd->command, cmd->parameter);
    return cmd;
}

void execExternalCommand(command_t *cmd) {
    char *args[64] = {0};
    int i = 0;
    args[i++] = cmd->command;
    char *token = strtok(cmd->parameter, " ");

    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    pid_t pid = fork();
    switch (pid){
    case -1:
        perror("fork failed\n");
        exit(EXIT_FAILURE);
    case 0:
        if (execvp(cmd->command, args) == -1) {
            fprintf(stderr, "Unknown command: [%s].\n", cmd->command);
        }
        exit(EXIT_FAILURE);
    default:
        wait(NULL);
    }
}

void execPipeCommand(char *commandStr) {
    pid_t pid;
    int pipefd[2];
    int fd_in = 0;
    char *cmd = strtok(commandStr, "|");

    while (cmd != NULL) {
        pipe(pipefd);
        pid = fork();
        if (pid == 0) {
            dup2(fd_in, 0);
            if (strtok(NULL, "|") != NULL) 
                dup2(pipefd[1], 1);
            close(pipefd[0]);
            execExternalCommand(parser(cmd));
            exit(EXIT_FAILURE);
        }
        else if (pid < 0) {
            perror("fork failed\n");
            exit(EXIT_FAILURE);
        }
        else {
            wait(NULL);
            close(pipefd[1]);
            fd_in = pipefd[0];
            cmd = strtok(NULL, "|");
        }
    }
}

const unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

void changeDir(char *dir) {
    chdir(dir);
}

void printenv(char *arg) {
    if (arg[0] == '\0') {
        extern char **environ;
        for (char **env = environ; *env != NULL; env++)
            printf("%s\n", *env);
    }
    else {
        char *value = getenv(arg);
        if (value != NULL)
            printf("%s=%s\n", arg, value);
        else
            printf("Environment variable %s not found\n", arg);
    }
}

void mysetenv(char *arg) {
    if (arg[0] != '\0') {
        if (setenv("PATH", arg, 1) == 0)
            printf("PATH environment variable set to: %s\n", arg);
        else
            perror("setenv failed");
    } 
    else
        printf("Invalid argument\n");
}

void help() {
    puts("\n WELCOME TO SHELL HELP"
         "\n commands supported"
         "\n>cd"
         "\n>setenv"
         "\n>printenv"
         "\n>quit"
         "\n>help"
         "\n>all other general commands available in bin"
         "\n>normal pipe handling");
}

void quit() {
    printf("\nGoodbye\n");
    exit(EXIT_SUCCESS);
}

void Buildin(command_t *cmd) {
    switch (hash(cmd->command)) {
    case CD:
        changeDir(cmd->parameter);
        break;
    case PRINTENV:
        printenv(cmd->parameter);
        break;
    case SETENV:
        mysetenv(cmd->parameter);
        break;
    case HELP:
        help();
        break;
    case QUIT:
        quit();
        break;
    default:
        execExternalCommand(cmd);
        break;
    }
}

int main() {
    setenv("PATH", "./bin:.", 1);
    char commandStr[256] = {0};
    command_t *cmd = NULL;
    do {
        printf("MyShell%% ");
        fgets(commandStr, sizeof(commandStr), stdin);
        commandStr[strcspn(commandStr, "\n")] = 0;
        if (strchr(commandStr, '|') != NULL) 
            execPipeCommand(commandStr);
        else {
            cmd = parser(commandStr);
            if (cmd->command[0] == '\0')
                continue;
            Buildin(cmd);
            free(cmd);
        }
    } while (1);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define CD 5863276
#define LS 5863588
#define PRINTENV 7572809511666715
#define SETENV 6954013771834
#define HELP 6385292014
#define QUIT 6385632776


typedef struct commandType {
    char command[100];
    char parameter[100];
} command_t;


command_t *parser(char * commandStr) {
    command_t *cmd = (command_t *)malloc(sizeof(command_t));
    sscanf(commandStr, "%s", cmd->command);
    int x = strlen(cmd->command)+1;
    sscanf(commandStr+x, "%[^\n]", cmd->parameter);
    return cmd;
}

const unsigned long hash(const char *str) {
    unsigned long hash = 5381;  
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

void changeDir(char *dir){
    chdir(dir);
}

void printenv(char *arg){
    printf("printenv %s\n", arg);
}

void mysetenv(char *arg){
    printf("setenv %s\n", arg);
}

void help(){
    puts("\n WELCOME TO SHELL HELP"
        "\n commands supported"
        "\n>cd"
        "\n>setenv"
        "\n>printenv"
        "\n>quit"
        "\n>help");
}

void quit(){
    printf("\nGoodbye\n");
    exit(EXIT_SUCCESS);
}

void Buildin(command_t *cmd){
    switch (hash(cmd->command)){
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
        printf("Unknown command: [%s]\n", cmd->command);
        break;
    }
}


int main() {
    char commandStr[256]={0};
    command_t *cmd=NULL;
    do {
        printf("MyShell%% ");
        commandStr[256] = {0};
        fgets(commandStr, sizeof(commandStr), stdin);
        cmd = parser(commandStr);
        Buildin(cmd);
        //printf("cmd->command = %s\n",cmd->command);
        //printf("cmd->parameter = %s\n", cmd->parameter);
        free(cmd);
    } while (strcmp(commandStr, "quit\n") != 0);
}
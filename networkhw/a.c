#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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


void execExternalCommand(command_t *cmd) {
    char *args[64] = {0};  // 用于存放命令及其参数
    char commandPath[256] = {0};
    int i = 0;

    // 获取外部命令的路径，例如从 bin 目录中查找
    snprintf(commandPath, sizeof(commandPath), "/home/shen/Documents/code/test/bin/%s", cmd->command);
    
    // 构建命令的参数列表
    //args[0] = commandPath;  // 第一个参数是命令本身
    //args[1] = cmd->parameter;
    //args[2] = NULL;          // 用 NULL 结束参数列表

    // 将命令本身作为 args[0]
    args[i++] = cmd->command;

    // 使用 strtok 分割参数
    char *token = strtok(cmd->parameter, " ");
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;  // 最后一个元素设置为 NULL，execvp 需要


    for (int j = 0; args[j] != NULL; j++) {
    printf("arg[%d]: %s\n", j, args[j]);
    }

    pid_t pid = fork();
    if (pid == 0) {
        // 子进程执行外部命令
        if (execvp(commandPath, args) == -1) {
            perror("execvp failed");
        }
        exit(1);  // 执行失败时退出
    } else if (pid < 0) {
        // fork 失败
        perror("fork failed");
    } else {
        // 父进程等待子进程结束
        wait(NULL);
    }
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
        execExternalCommand(cmd);  
        break;
    }
}



int main() {
    char commandStr[256]={0};
    command_t *cmd=NULL;
    do {
        printf("MyShell%% ");
        fgets(commandStr, sizeof(commandStr), stdin);
        cmd = parser(commandStr);
        Buildin(cmd);
        //printf("cmd->command = %s\n",cmd->command);
        //printf("cmd->parameter = %s\n", cmd->parameter);
        //printf("cmd->command = %s\n", cmd->command);
        //printf("cmd->parameter = %s\n", cmd->parameter);
        free(cmd);
        memset(cmd->parameter, 0, sizeof(cmd->parameter));
        //printf("cmd->parameter = %s\n", cmd->parameter);
    } while (strcmp(commandStr, "quit\n") != 0);
}
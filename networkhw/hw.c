#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// 定義內建指令的哈希值，這些值是根據命令的字串計算得來的
#define CD 5863276
#define PRINTENV 7572809511666715
#define SETENV 6954013771834
#define HELP 6385292014
#define QUIT 6385632776

// 定義命令結構，包含命令和參數
typedef struct commandType {
    char command[100];    // 儲存命令（例如：cd, ls, 等）
    char parameter[100];  // 儲存命令參數
} command_t;

// 解析命令字串，並將命令和參數分開
command_t *parser(char *commandStr) {
    command_t *cmd = (command_t *)calloc(1, sizeof(command_t)); // 分配記憶體給命令結構
    sscanf(commandStr, "%s %s", cmd->command, cmd->parameter);   // 解析命令和參數
    return cmd; // 回傳解析後的命令結構
}

// 執行外部命令
void execExternalCommand(command_t *cmd) {
    char *args[64] = {0};  // 儲存命令的參數
    int i = 0;
    args[i++] = cmd->command; // 將命令放入參數陣列

    // 使用 strtok 來分割命令參數
    char *token = strtok(cmd->parameter, " ");
    while (token != NULL) {
        args[i++] = token; // 將每個參數存入 args
        token = strtok(NULL, " "); // 繼續分割
    }
    args[i] = NULL; // 最後一個元素設為 NULL，結束參數列表

    pid_t pid = fork(); // 創建子進程
    switch (pid) {
    case -1:
        perror("fork failed\n"); // 如果 fork 失敗，顯示錯誤訊息
        exit(EXIT_FAILURE);
    case 0:
        // 子進程執行命令
        if (execvp(cmd->command, args) == -1) {
            fprintf(stderr, "Unknown command: [%s].\n", cmd->command); // 如果 execvp 失敗，顯示錯誤訊息
        }
        exit(EXIT_FAILURE); // 結束子進程
    default:
        wait(NULL); // 父進程等待子進程結束
    }
}

// 處理管道命令
void execPipeCommand(char *commandStr) {
    pid_t pid;
    int pipefd[2];    // 用來存放管道的文件描述符
    int fd_in = 0;    // 初始輸入文件描述符
    char *cmd = strtok(commandStr, "|"); // 以管道符號分割命令

    while (cmd != NULL) {
        pipe(pipefd); // 創建管道
        pid = fork(); // 創建子進程

        if (pid == 0) {
            dup2(fd_in, 0); // 將輸入重定向到前一個命令的輸出
            if (strtok(NULL, "|") != NULL) {
                dup2(pipefd[1], 1); // 如果還有後續命令，將輸出重定向到管道
            }
            close(pipefd[0]); // 關閉管道讀取端
            execExternalCommand(parser(cmd)); // 執行命令
            exit(EXIT_FAILURE); // 子進程結束
        }
        else if (pid < 0) {
            perror("fork failed\n"); // 如果 fork 失敗，顯示錯誤訊息
            exit(EXIT_FAILURE);
        }
        else {
            wait(NULL); // 父進程等待子進程結束
            close(pipefd[1]); // 關閉管道寫入端
            fd_in = pipefd[0]; // 設定下一個命令的輸入為當前管道的讀取端
            cmd = strtok(NULL, "|"); // 繼續處理管道中的下一個命令
        }
    }
}

// 哈希函數，將指令轉換為數字，方便查找內建指令
const unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; // 使用 DJB2 算法計算哈希值
    return hash;
}

// 變更當前目錄
void changeDir(char *dir) {
    chdir(dir); // 使用 chdir 變更目錄
}

// 打印環境變數
void printenv(char *arg) {
    if (arg[0] == '\0') { // 如果沒有提供參數，列出所有環境變數
        extern char **environ;
        for (char **env = environ; *env != NULL; env++)
            printf("%s\n", *env); // 打印每個環境變數
    }
    else {
        char *value = getenv(arg); // 查找指定的環境變數
        if (value != NULL)
            printf("%s=%s\n", arg, value); // 打印環境變數的值
        else
            printf("Environment variable %s not found\n", arg); // 如果環境變數不存在，顯示錯誤訊息
    }
}

// 設定環境變數
void mysetenv(char *arg) {
    if (arg[0] != '\0') { // 如果有參數
        if (setenv("PATH", arg, 1) == 0) // 設定 PATH 環境變數
            printf("PATH environment variable set to: %s\n", arg); // 顯示設定成功
        else
            perror("setenv failed"); // 如果設定失敗，顯示錯誤訊息
    } 
    else
        printf("Invalid argument\n"); // 如果參數無效，顯示錯誤訊息
}

// 顯示幫助訊息
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

// 退出程式
void quit() {
    printf("\nGoodbye\n");
    exit(EXIT_SUCCESS); // 結束程式
}

// 根據哈希值執行內建指令
void Buildin(command_t *cmd) {
    switch (hash(cmd->command)) {
    case CD:
        changeDir(cmd->parameter); // 執行 cd 指令
        break;
    case PRINTENV:
        printenv(cmd->parameter); // 執行 printenv 指令
        break;
    case SETENV:
        mysetenv(cmd->parameter); // 執行 setenv 指令
        break;
    case HELP:
        help(); // 執行 help 指令
        break;
    case QUIT:
        quit(); // 執行 quit 指令
        break;
    default:
        execExternalCommand(cmd); // 如果是其他指令，執行外部命令
        break;
    }
}

// 主程式，負責命令輸入和執行
int main() {
    setenv("PATH", "./bin:.", 1); // 設定 PATH 環境變數
    char commandStr[256] = {0}; // 儲存用戶輸入的命令字串
    command_t *cmd = NULL;
    do {
        printf("MyShell%% "); // 顯示提示符
        fgets(commandStr, sizeof(commandStr), stdin); // 讀取命令
        commandStr[strcspn(commandStr, "\n")] = 0; // 去除命令字串中的換行符
        if (strchr(commandStr, '|') != NULL) // 如果命令包含管道符號
            execPipeCommand(commandStr); // 處理管道命令
        else {
            cmd = parser(commandStr); // 解析命令
            if (cmd->command[0] == '\0') // 如果沒有輸入命令，則繼續
                continue;
            Buildin(cmd); // 執行內建指令或外部命令
            free(cmd); // 釋放記憶體
        }
    } while (1); // 持續執行直到用戶退出
    return 0;
}

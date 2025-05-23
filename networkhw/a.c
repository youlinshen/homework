#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

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
  char *args[64] = {0};  // 用于存放命令及其参数
  int i = 0;

  // 将命令本身作为 args[0]
  args[i++] = cmd->command;

  // 使用 strtok 分割参数
  char *token = strtok(cmd->parameter, " ");
  while (token != NULL) {
    args[i++] = token;
    token = strtok(NULL, " ");
  }
  args[i] = NULL;  // 最后一个元素设置为 NULL，execvp 需要

  pid_t pid = fork();
  switch (pid) {
    case -1:
      perror("fork failed\n");
      exit(EXIT_FAILURE);
    case 0:
      if (execvp(cmd->command, args) == -1) {
        // 如果执行失败，打印错误信息
        fprintf(stderr, "Unknown command: [%s].\n", cmd->command);
        // printf("Unknown command: [%s].\n", cmd->command);
      }
      exit(EXIT_FAILURE);  // 执行失败时退出
    default:
      wait(NULL);
  }
}

void execPipeCommand(char *commandStr) {
  pid_t pid;
  int pipefd[2];
  int fd_in = 0;  // 管道的输入端

  char *cmd = strtok(commandStr, "|");
  while (cmd != NULL) {
    pipe(pipefd);
    pid = fork();
    if (pid == 0) {
      // 子进程
      dup2(fd_in, 0);  // 将前一个命令的输出连接到当前命令的输入
      if (strtok(NULL, "|") != NULL) {
        dup2(pipefd[1], 1);  // 如果还有下一个命令，将标准输出连接到管道
      }
      close(pipefd[0]);
      execExternalCommand(parser(cmd));
      exit(EXIT_FAILURE);
    } else if (pid < 0) {
      perror("fork failed\n");
      exit(EXIT_FAILURE);
    } else {
      // 父进程
      wait(NULL);
      close(pipefd[1]);
      fd_in = pipefd[0];  // 下一次的输入端为当前的管道读端
      cmd = strtok(NULL, "|");
    }
  }
}

const unsigned long hash(const char *str) {
  unsigned long hash = 5381;
  int c;
  while ((c = *str++)) hash = ((hash << 5) + hash) + c;
  return hash;
}

void changeDir(char *dir) { chdir(dir); }

void printenv(char *arg) {
  if (arg[0] == '\0') {
    // 如果没有参数，打印所有环境变量
    extern char **environ;
    for (char **env = environ; *env != NULL; env++) {
      printf("%s\n", *env);
    }
  } else {
    // 打印指定环境变量
    char *value = getenv(arg);
    if (value != NULL) {
      printf("%s=%s\n", arg, value);
    } else {
      printf("Environment variable %s not found\n", arg);
    }
  }
}

void mysetenv(char *arg) {
  // 设置 PATH 环境变量为 arg 的值
  if (arg[0] != '\0') {
    if (setenv("PATH", arg, 1) == 0)
      printf("PATH environment variable set to: %s\n", arg);
    else
      perror("setenv failed");
  } else
    printf("Invalid argument\n");
}

void help() {
  puts(
      "\n WELCOME TO SHELL HELP"
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

    // 去掉换行符
    commandStr[strcspn(commandStr, "\n")] = 0;

    // 如果命令中包含管道符（|）
    if (strchr(commandStr, '|') != NULL) {
      execPipeCommand(commandStr);
    } else {
      cmd = parser(commandStr);
      if (cmd->command[0] == '\0') continue;
      Buildin(cmd);
      free(cmd);
    }
  } while (1);
  return 0;
}

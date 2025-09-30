#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 10000

bool isValid(char* s){
    int len = strlen(s);
    if((len & 1) == 1)
        return false;
    char stack[len];
    int sp = -1;
    for(int i = 0;i < len;i++){
        char a = s[i];
        if (a == '(' || a == '[' || a == '{'){
            sp++;
            stack[sp] = a;
        }
        else{
            if (sp == -1)
                return false;
            char top = stack[sp];
            if((top == '(' && a == ')') ||
               (top == '[' && a == ']') ||
               (top == '{' && a == '}'))
               sp--;
            else
                return false;
        }
    }
    return sp == -1;
};

int main(void){

    char s[MAX_STACK_SIZE] = "([)]";
    bool a;
    a = isValid(s);
    printf("%d",a);
    return 0;
}

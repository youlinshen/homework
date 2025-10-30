bool isValid(char* s){
    int len = strlen(s);
    if((len & 1) == 1)
        return false;

    char *stack = (char *)malloc(len * sizeof(char));
    if (stack == NULL)
        return false;
    int sp = -1;
    for(int i = 0;i < len;i++){
        char a = s[i];
        if (a == '(' || a == '[' || a == '{'){
            sp++;
            stack[sp] = a;
        }
        else{
            if (sp == -1){
                free(stack);
                return false;
            }
            char top = stack[sp];
            if((top == '(' && a == ')') ||
               (top == '[' && a == ']') ||
               (top == '{' && a == '}'))
               sp--;
            else{
                free(stack);
                return false;
            }
        }
    }
    free(stack);
    return sp == -1;
};

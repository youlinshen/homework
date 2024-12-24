#include <stdio.h>

const unsigned long hash(const char *str) {
    unsigned long hash = 5381;  
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

int main(int argc, char *argv[]){
    printf("%s => %ld\n", argv[1], hash(argv[1]));
    return 0;
}
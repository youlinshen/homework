#include <stdio.h>
#include <stdint.h>
 
int main(){
    int8_t a;
    int16_t b;
    int32_t c;
    int64_t d;
    uint8_t e;
    printf("%ld\n", sizeof(a));
    printf("%ld\n", sizeof(b));
    printf("%ld\n", sizeof(c));
    printf("%ld\n", sizeof(d));
    printf("%ld\n", sizeof(e));
    return 0;
}
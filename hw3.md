# C library (C 內建程式庫)


# **assert.h**
## assert()
>檢查括號的條件為false(0)則終止，非0則繼續執行

Return Value
>This macro does not return any value.

assert(int expression)

    #include <stdio.h>
    #include <assert.h>
 
    int main(){
        int a ;
        scanf("%d", &a);
        assert(a > 0);
        printf("%d", a);
    }

輸入1

    5 
輸出1

    5
輸入2

    -10
輸出2

    assertion "a > 0" failed: file "hw.c", line 7, function: main
      0 [main] a 1585 cygwin_exception::open_stackdumpfile: Dumping stack trace to a.exe.stackdump

# **ctype.h**

## isspace()

>檢查所傳的字符是否是空白字元

Return Value
>This function returns a non-zero value(true) if c is a white-space character else, zero (false).

int isspace(int c);

範例

    #include <stdio.h>
    #include <ctype.h>

    int main(){
       int a1 = 'A';
       int a2 = ' ';

    if( isspace(a1) )
       printf("a1 = |%c| 是空白字符\n", a1 );
    else
       printf("a1 = |%c| 不是空白字符\n", a1 );
    if( isspace(a2) )
       printf("a2 = |%c| 是空白字符\n", a2 );
    else
       printf("a2 = |%c| 不是空白字符\n", a2 );
    return 0;
    }

輸出

    a1 = |A| 不是空白字符
    a2 = | | 是空白字符

## isalpha()

>檢查傳遞的字元是否為字母

Return Value
>This function returns non-zero value if c is an alphabet, else it returns 0.

int isalpha(int c);

範例

    #include <stdio.h>
    #include <ctype.h>

    int main(){
       int a1 = 'A';
       int a2 = ' ';

    if( isalpha(a1) )
       printf("a1 = |%c| 是字母\n", a1 );
    else
       printf("a1 = |%c| 不是字母\n", a1 );
    if( isalpha(a2) )
       printf("a2 = |%c| 是字母\n", a2 );
    else
       printf("a2 = |%c| 不是字母\n", a2 );
    return 0;
    }


輸出

    a1 = |A| 是字母
    a2 = | | 不是字母

## isupper()

>檢查傳遞的字元是否為大寫字母
 
Return Value
>This function returns a non-zero value(true) if c is an uppercase alphabetic letter else, zero (false).

int isupper(int c);

範例

    #include <stdio.h>
    #include <ctype.h>

    int main(){
        int a1 = 'A';
        int a2 = 'f';
        if( isupper(a1) )
           printf("a1 = |%c| 是大寫字母\n", a1 );
        else
           printf("a1 = |%c| 不是大寫字母\n", a1 );
        if( isupper(a2) )
           printf("a2 = |%c| 是大寫字母\n", a2 );
        else
           printf("a2 = |%c| 不是大寫字母\n", a2 );
        return 0;
    }

輸出

    a1 = |A| 是大寫字母
    a2 = |f| 不是大寫字母

## islower()

>檢查傳遞的字元是否為小寫字母
 
Return Value
>This function returns a non-zero value(true) if c is a lowercase alphabetic letter else, zero (false).

int islower(int c);

範例

    #include <stdio.h>
    #include <ctype.h>

    int main(){
        int a1 = 'A';
        int a2 = 'f';
        if( islower(a1) )
           printf("a1 = |%c| 是小寫字母\n", a1 );
        else
           printf("a1 = |%c| 不是小寫字母\n", a1 );
        if( islower(a2) )
           printf("a2 = |%c| 是小寫字母\n", a2 );
        else
           printf("a2 = |%c| 不是小寫字母\n", a2 );
        return 0;
    }

輸出

    a1 = |A| 不是小寫字母
    a2 = |f| 是小寫字母

## tolower()

>把給定的字母轉換為小寫字母

Return Value
>This function returns lowercase equivalent to c, if such value exists, else c remains unchanged. The value is returned as an int value that can be implicitly casted to char.

int tolower(int c);

範例

    #include <stdio.h>
    #include <ctype.h>

    int main(){
        char a[10] = "CtYpe.H";
        for( int i = 0; i < 8; i++)
            printf("%c", tolower(a[i]));
        return 0;
    }

輸出

    ctype.h
    
## toupper()

>把給定的字母轉換為大寫字母

Return Value
>This function returns uppercase equivalent to c, if such value exists, else c remains unchanged. The value is returned as an int value that can be implicitly casted to char.

int toupper(int c);

範例

    #include <stdio.h>
    #include <ctype.h>

    int main(){
        char a[10] = "CtYpe.H";
        for( int i = 0; i < 8; i++)
            printf("%c", toupper(a[i]));
        return 0;
    }

輸出

    CTYPE.H
    
# **math.h**
> 在linux的環境下使用math.h裡的函數，在編譯時必須加上參數-lm

    gcc hw.c -lm
範例

    #include <stdio.h>
    #include <math.h>
 
    int main(){
        int a = 16;
        printf("%f", sqrt(a));
    }
error

    :~/codes$ gcc -g hw.c
    /usr/bin/ld: /tmp/cclsrtWR.o: in function `main':
    /home/shen/codes/hw7.c:6: undefined reference to `sqrt'
    collect2: error: ld returned 1 exit status
## pow()
>返回x^y的值

double pow(double x, double y)

    #include <stdio.h>
    #include <math.h>
 
    int main(){
        printf("%f", pow(2,5));
    }
輸出

    32.000000
## sqrt()
>返回x的平方根

double sqrt(double x)

    #include <stdio.h>
    #include <math.h>
 
    int main(){
        printf("%f", sqrt(25));
    }
輸出

    5.000000
## fabs()
>返回x的絕對值

double fabs(double x)

    #include <stdio.h>
    #include <math.h>
 
    int main(){
        printf("%f", fabs(-1.5));
    }
輸出

    1.500000

## sin()
>返回弧度角 x 的正弦

double sin(double x)

    #include <stdio.h>
    #include <math.h>
 
    int main(){
        float a ;
        a = sin(1.57);
        printf("%f", a);
    }
輸出

    1.000000
## cos()
>返回弧度角 x 的餘弦

double cos(double x)

    #include <stdio.h>
    #include <math.h>
 
    int main(){
        float a ;
        a = cos(0);
        printf("%f", a);
    }
輸出

    1.000000
# **stdio.h**

## stdbuf()
>The C library function void setbuf(FILE *stream, char *buffer) defines how a stream should be buffered. This function should be called once the file associated with the stream has already been opened, but before any input or output operation has taken place.

Return Value
>This function does not return any value.

void setbuf(FILE *stream, char *buffer)

範例

    #include <stdio.h>

    int main () {
       char buf[BUFSIZ];

       setbuf(stdout, buf);
       puts("Hello World");

       fflush(stdout);
       return(0);
    }

輸出

    Hello World

## printf()
>發送格式化輸出到標準輸出 stdout

int printf(const char *format, ...)

Return Value
>If successful, the total number of characters written is returned. On failure, a negative number is returned.

範例

    #include <stdio.h>

    int main() {
        printf("Hello world");
        return 0;
    }
輸出

    Hello world

## scanf()
>從標準輸入 stdin 讀取格式化輸入

Return Value
>On success, the function returns the number of items of the argument list successfully read. If a reading error happens or the end-of-file is reached while reading, the proper indicator is set (feof or ferror) and, if either happens before any data could be successfully read, EOF is returned.

int scanf(const char *format, ...)

範例

    #include <stdio.h>
    int main() {
        int a;
        scanf("%d", &a);
        printf("%d", a);
    }

輸入

    10

輸出

    10

## fgets()
>從指定的流中讀取一行，並將其存儲到 str 指向的字元串中。當讀取 （n-1） 個字元、讀取換行符或到達檔末尾（以先到者為準）時，它將停止。

Return Value
>On success, the function returns the same str parameter. If the End-of-File is encountered and no characters have been read, the contents of str remain unchanged and a null pointer is returned.
>
>If an error occurs, a null pointer is returned.

char *fgets(char *str, int n, FILE *stream)

範例

    #include <stdio.h>

    int main () {
        char str[12];
        fgets(str, 12, stdin);
        puts(str);
    }

輸入

    Hello World

輸出

    Hello World

## puts()
>將字串寫入 stdout，但不包括空字元。換行符將追加到輸出中

int puts(const char *str)

Return Value
>If successful, non-negative value is returned. On error, the function returns EOF.

範例

    #include <stdio.h>

    int main () {
       puts("Hello World");
    }

輸出

    Hello World

# **stdlib.h**

## abs()

>返回 x 的絕對值

int abs(int x)

範例

    #include <stdio.h>
    #include <stdlib.h>
 
    int main(){
        int a = -10;
        a = abs(a);
        printf("%d", a);
    }
輸出

    10

## labs()

>返回 x 的絕對值

long int labs(long int x)

範例

    #include <stdio.h>
    #include <stdlib.h>
 
    int main(){
        int a = -10;
        a = abs(a);
        printf("%d", a);
    }
輸出

    10

## div()

>把 numer（分子）除以 denom（分母）

Return Value
>This function returns the value in a structure defined in <cstdlib>, which has two members. For div_t:int quot; int rem;

div_t div(int numer, int denom)

範例

    #include <stdio.h>
    #include <stdlib.h>

    int main () {
       div_t a;

       a = div(25, 3);
       printf("Quotient part of (25/ 3) = %d\n", a.quot);
       printf("Remainder part of (25/3) = %d\n", a.rem);

       a = div(20, 7);
       printf("Quotient part of (20/ 7) = %d\n", a.quot);
       printf("Remainder part of (20/7) = %d\n", a.rem);

       return 0;
    }

輸出

    uotient part of (25/ 3) = 8
    Remainder part of (25/3) = 1
    Quotient part of (20/ 7) = 2
    Remainder part of (20/7) = 6

## ldiv()

>把 numer（分子）除以 denom（分母）

Return Value
>This function returns the value in a structure defined in <cstdlib>, which has two members. For ldiv_t:long quot; long rem;

ldiv_t ldiv(long int numer, long int denom)

範例

    #include <stdio.h>
    #include <stdlib.h>

    int main () {
       
       ldiv_t a;

       a = ldiv(25, 3);
       printf("Quotient part of (25/ 3) = %d\n", a.quot);
       printf("Remainder part of (25/3) = %d\n", a.rem);

       a = ldiv(20, 7);
       printf("Quotient part of (20/ 7) = %d\n", a.quot);
       printf("Remainder part of (20/7) = %d\n", a.rem);

       return 0;
    }

輸出

    uotient part of (25/ 3) = 8
    Remainder part of (25/3) = 1
    Quotient part of (20/ 7) = 2
    Remainder part of (20/7) = 6

## rand()

>傳回一個介於 0 到 RAND_MAX 之間的偽隨機數

Return Value
>This function returns an integer value between 0 and RAND_MAX.

int rand(void)

範例

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
 
    int main(){
       int i;
       srand(time(NULL));
       for( i = 0 ; i < 5 ; i++ ) {
          printf("%d\n", rand()%(50)+1);
       }
      return(0);
    }

輸出

    15
    26
    31
    44
    20
    
# stdint.h

>義了具有特定位寬的整型，以及對應的宏；還列出了在其他標準頭文件中定義的整型的極限

## int8_t
## int16_t
## int32_t
## int64_t
## uint8_t

typedef signed integer type int8_t;   
typedef signed integer type int16_t;   
typedef signed integer type int32_t;    
typedef signed integer type int64_t;  
typedef unsigned integer type uint8_t;

範例

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

輸出

    1
    2
    4
    8
    1

# string.h
範例
輸出

## strcpy()

>把 src 所指向的字串複製到 dest

Return Value
>This returns a pointer to the destination string dest.

char *strcpy(char *dest, const char *src)

範例

    #include <stdio.h>
    #include <string.h>

    int main () {
    char a1[15];
    strcpy(a1, "abcdef");
    printf("%s", a1);
    return 0;
    }
    
輸出

    abcdef

## strncpy()

>把 src 所指向的字串複製到 dest，最多複製 n 個字元。當 src 的長度小於 n 時，dest 的剩餘部分將用空字元填充

Return Value
>This function returns the pointer to the copied string.

char *strncpy(char *dest, const char *src, size_t n)

範例

    #include <stdio.h>
    #include <string.h>

    int main () {
    char a1[15] = "abcdef";
    char a2[5];
    strncpy(a2, a1, 3);
    printf("%s", a2);
    return 0;
    }
    
輸出

    abc

## strcmp()

>用於比較兩個字串是否相等

Return Value
>This function return values that are as follows −
>
>if Return value < 0 then it indicates str1 is less than str2.
>
>if Return value > 0 then it indicates str2 is less than str1.
>
>if Return value = 0 then it indicates str1 is equal to str2.

int strcmp(const char *str1, const char *str2)

範例

    #include <stdio.h>
    #include <string.h>

    int main () {
       char a1[15];
       char a2[15];
       int p;

       strcpy(a1, "abcdef");
       strcpy(a2, "ABCDEF");

       p = strcmp(a1, a2);

       if(p < 0)
          printf("a1 is less than a2");
       else if(p > 0)
          printf("a2 is less than a1");
       else
          printf("a1 is equal to a2");
   
       return 0;
    }

輸出

    a2 is less than a1

## strncmp()

>用於比較兩個字串的前 n 個字元是否相等

Return Value
>This function return values that are as follows −
>
>if Return value < 0 then it indicates str1 is less than str2.
>
>if Return value > 0 then it indicates str2 is less than str1.
>
>if Return value = 0 then it indicates str1 is equal to str2.

int strncmp(const char *str1, const char *str2, size_t n)

範例

    #include <stdio.h>
    #include <string.h>

    int main () {
       char a1[15];
       char a2[15];
       int p;

       strcpy(a1, "abcdef");
       strcpy(a2, "ABCDEF");

       p = strncmp(a1, a2, 4);

       if(p < 0)
          printf("a1 is less than a2");
       else if(p > 0)
          printf("a2 is less than a1");
       else
          printf("a1 is equal to a2");
   
       return 0;
    }

輸出

    a2 is less than a1

# References
1. https://www.tutorialspoint.com/c_standard_library/index.htm
2. https://www.runoob.com/cprogramming/c-standard-library.html
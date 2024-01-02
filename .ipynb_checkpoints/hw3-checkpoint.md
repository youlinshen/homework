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
int abs(int x)

    #include <stdio.h>
    #include <stdlib.h>
 
    int main(){
        int a = -10;
        a = abs(a);
        printf("%d", a);
    }
輸出

    10

# stdint.h

# string.h

# time.h 

# stdbool.h

# References
1. https://www.tutorialspoint.com/c_standard_library/index.htm
2. https://www.runoob.com/cprogramming/c-standard-library.html
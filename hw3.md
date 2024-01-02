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
範例


## printf()
>發送格式化輸出到標準輸出 stdout

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

# fgets()

# puts()
    
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
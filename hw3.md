# C library (C 內建程式庫)



# assert.h

# ctype.h

# math.h
在linux的環境下使用math.h裡的函數，在編譯時必須加上參數-lm
#### 範例
    #include <stdio.h>
    #include <math.h>
 
    int main(){
        int a = 16;
        printf("%f", sqrt(a));
    }
#### error
    :~/codes$ gcc -g hw.c
    /usr/bin/ld: /tmp/cclsrtWR.o: in function `main':
    /home/shen/codes/hw7.c:6: undefined reference to `sqrt'
    collect2: error: ld returned 1 exit status
### pow()
#### double pow(double, double)
    #include <stdio.h>
    #include <math.h>
 
    int main(){
        printf("%f", pow(2,5));
    }
### 輸出
    32.000000
### sqrt()
#### double sqrt(double)
    #include <stdio.h>
    #include <math.h>
 
    int main(){
        printf("%f", sqrt(25));
    }
### 輸出
    5.000000
### int abs(int)

# stdio.h

### stdbuf()
#### 範例
    /*if ( 1 != scanf("%d", &mode)) {
            mode = 0;    
            setbuf(stdin, NULL);
        }*/

### printf()

#### 範例

    #include <stdio.h>

    int main(){
        for (int i = 97; i <= 122; i++){
            printf("DEC number = %3d, ASCII character = %c\n", i, i);
        } 
    }
#### 說明
printf 是用來印東西的函數，根據變數的資料型態的不同，在%之後要使用不同的

# stdlib.h

# stdint.h

# string.h

# time.h 

# stdbool.h


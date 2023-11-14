# C library (C 內建程式庫)



# assert.h

# ctype.h

# math.h

# stdio.h

### stdbuf()
#### example

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



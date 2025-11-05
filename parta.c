#include <stdbool.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>

// TODO: Include more header files (read the manpages to find out more!)

int main(int argc, const char* argv[]) {
    if (argc <= 1 ){
        return 1;
    }
    
    for (int i = 1; i < argc; i++){
        for (int j = 0; argv[i][j] != '\0'; j++){
            putchar(toupper((unsigned char)argv[i][j]));
        }
        if (i < argc - 1){
            putchar(','); 
        }
       
    }
    printf("\n");
    return 0;
}

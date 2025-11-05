#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>


// TODO: Include more header files (read the manpages to find out more!)

int main(int argc, const char* argv[]) {
    if (argc <= 1) {
        write(2, "ERROR: no arguments\n", 20);
        return 1;
    }

    char *eargs[argc + 2]; 
    int start, count;

    if ((argc - 1) % 2 == 1) {
        start = (argc - 1) / 2 + 1;
        count = 1;
    } else { 
        start = (argc - 1) / 2;    
        count = 2;
    }

    eargs[0] = "echo";

    for (int i = 0; i < count; i++) {
        eargs[i + 1] = argv[start + i];
    }

    eargs[count + 1] = NULL; 

    if (execv("/bin/echo", eargs) == -1) {
        perror("exec");
        return 1;
    }

    return 0;
}

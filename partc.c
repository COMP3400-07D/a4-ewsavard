#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// TODO: Include more header files (read the manpages to find out more!)

int main(int argc, const char* argv[]) {
    if (argc != 3) {
        write(2, "ERROR: no arguments or incorrect usage\n", 40);
        return 1;
    }

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        char *eargs[] = { "/usr/bin/grep", "-s", "-q", argv[1], argv[2], NULL };
        execv("/usr/bin/grep", eargs);
        perror("exec");
        exit(1);
    } else {
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            int code = WEXITSTATUS(status);
            if (code == 0) {
                printf("FOUND: %s\n", argv[1]);
            } else if (code == 1) {
                printf("NOT FOUND: %s\n", argv[1]);
            } else {
                printf("ERROR: %s doesn't exist\n", argv[2]);
                return 2;
            }
        } else {
            printf("ERROR: child process did not exit normally\n");
            return 2;
        }
    }

    return 0;
}

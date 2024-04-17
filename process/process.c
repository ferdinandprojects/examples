#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>


int main(int argc, char *argv[]) {
    
    char *value;    
    pid_t pid;

    if ((pid = fork()) < 0) {
       fprintf(stderr, "fork failed: %s\n", strerror(errno)); 
    } else if (pid == 0) { // (1) child process
        value = "child";
    } else {               // (2) parent process
        value = "parent";
    }

    printf("pid: %d, ppid: %d, value = %s\n", getpid(), getppid(), value); //(3) both proceesses execute this
    
    return 0;
}

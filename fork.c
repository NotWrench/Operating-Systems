#include <stdio.h>
#include <unistd.h>

int main() {
	
    if(fork() == 0) {
        printf("This is CHILD process\n");
    }

    else {
        printf("This is PARENT process\n");
    }

    printf("PID: %d\n", getpid());

    return 0;
}

#include <stdio.h>
#include <unistd.h>

int main() {
    while (1) {
        printf("PID: %d, Parent PID: %d\n", getpid(), getppid());
        sleep(1);
    }
    return 0;
}
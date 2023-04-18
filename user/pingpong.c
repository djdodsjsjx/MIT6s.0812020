#include"kernel/types.h"
#include"kernel/stat.h"
#include"user/user.h"

int main(int argc, char const *argv[])
{

    int pid;
    char buf[100];
    int p2c[2], c2p[2];

    pipe(p2c);  // 父 -> 子(父写，子读)
    pipe(c2p);  // 子 -> 父

    pid = fork();
    if (!pid) {  // 子进程
        pid = getpid();
        int n = read(p2c[0], buf, sizeof buf);
        printf("%d: received ping\n", pid);

        write(c2p[1], buf, n);
    } else {
        pid = getpid();
        write(p2c[1], "h", 1);
        read(c2p[0], buf, sizeof buf);
        printf("%d: received pong\n", pid);
    }
    exit(0);
}


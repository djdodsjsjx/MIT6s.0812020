#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define INT_SIZE sizeof(int)
#define PRIME_END 35

void sieve(int *);
// void check(int* );
int main(int argc, char *argv[]) {
  int i;
  int pid;
  int pipeline[2];

  pipe(pipeline);

  pid = fork();
  if (pid == 0) {
    sieve(pipeline);
    // check(pipeline);
  } else {
    for (i = 2; i <= PRIME_END; i++) {
      write(pipeline[1], &i, INT_SIZE);
    }
    close(pipeline[1]);
    wait((int *)0);
  }

  exit(0);
}
// void check(int* p2c) {
//     int v;
//     close(p2c[1]); // 关闭写端
//     if (!read(p2c[0], &v, sizeof(int))) {
//         close(p2c[0]);
//         exit(0);
//     }
//     for (int i = 2; i < v; ++i) {
//         if (v % 2 == 0) exit(0);
//     }
//     printf("prime %d\n", v);
//     exit(0);
// }
void sieve(int *from_pipeline) {  // dfs
  int p, n, k;
  int pid;
  int to_pipeline[2];

  close(from_pipeline[1]);

  if ((k = read(from_pipeline[0], &p, INT_SIZE)) == 0) {
    close(from_pipeline[0]);
    exit(0);
  }

  fprintf(1, "prime %d\n", p);

  pipe(to_pipeline);
  pid = fork();
  if (pid == 0) {
    sieve(to_pipeline);
  } else {
    while ((k = read(from_pipeline[0], &n, INT_SIZE)) != 0) {
      if (n % p) {
        write(to_pipeline[1], &n, INT_SIZE);
      }
    }
    close(from_pipeline[0]);
    close(to_pipeline[1]);
    wait((int *)0);
  }
  exit(0);
}

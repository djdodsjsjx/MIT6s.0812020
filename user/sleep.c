#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[]) {

//   for(int i = 1; i < argc; i++){
//     write(1, argv[i], strlen(argv[i]));
//     if(i + 1 < argc){
//       write(1, " ", 1);
//     } else {
//       write(1, "\n", 1);
//     }
//   }
    if (argc != 2) {
        printf("请输入延时时间\n");
        exit(1);
    }
    if (sleep(atoi(argv[1])) < 0) {
        printf("延时时间输入错误\n");
        exit(1);
    }
    exit(0);
}

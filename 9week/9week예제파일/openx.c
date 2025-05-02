#include <stdio.h>      // printf
#include <fcntl.h>      // open
#include <unistd.h>     // close
#include <stdlib.h>     // exit

int main(int argc, char *argv[]) {
    int fd;

    if (argc < 2) {
        printf("사용법: %s 파일이름\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("파일 열기 실패");
        exit(1);
    }

    printf("파일 디스크립터: %d\n", fd);
    close(fd);
    exit(0);
}

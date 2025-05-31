// cd.c - 디렉토리 변경
#include <stdio.h>
#include <unistd.h>

int main() {
    char path[256];
    printf("이동할 디렉토리 경로: ");
    scanf("%s", path);

    if (chdir(path) == 0) {
        printf("디렉토리 변경 성공\n");
    } else {
        perror("디렉토리 변경 실패");
    }

    return 0;
}

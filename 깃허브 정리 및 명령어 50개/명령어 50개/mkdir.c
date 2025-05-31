// mkdir.c - 디렉토리 생성
#include <stdio.h>
#include <sys/stat.h>

int main() {
    char dirname[100];
    printf("생성할 디렉토리 이름: ");
    scanf("%s", dirname);

    if (mkdir(dirname, 0755) == 0) {
        printf("디렉토리 생성 완료\n");
    } else {
        perror("디렉토리 생성 실패");
    }

    return 0;
}

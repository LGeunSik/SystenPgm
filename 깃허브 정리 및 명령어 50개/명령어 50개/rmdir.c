// rmdir.c - 디렉토리 삭제
#include <stdio.h>
#include <unistd.h>

int main() {
    char dirname[100];
    printf("삭제할 디렉토리 이름: ");
    scanf("%s", dirname);

    if (rmdir(dirname) == 0) {
        printf("디렉토리 삭제 완료\n");
    } else {
        perror("디렉토리 삭제 실패");
    }

    return 0;
}

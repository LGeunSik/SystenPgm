// rm.c - 파일 삭제
#include <stdio.h>

int main() {
    char filename[100];

    printf("삭제할 파일 이름: ");
    scanf("%s", filename);

    if (remove(filename) == 0) {
        printf("파일 삭제 완료\n");
    } else {
        perror("파일 삭제 실패");
    }

    return 0;
}

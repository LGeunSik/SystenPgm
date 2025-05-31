// mv.c - 파일 이름 변경 또는 이동
#include <stdio.h>

int main() {
    char src[100], dest[100];

    printf("원본 파일 이름: ");
    scanf("%s", src);
    printf("새 파일 이름: ");
    scanf("%s", dest);

    if (rename(src, dest) == 0) {
        printf("파일 이름 변경 또는 이동 완료\n");
    } else {
        perror("작업 실패");
    }

    return 0;
}

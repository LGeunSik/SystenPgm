// touch.c - 빈 파일 생성
#include <stdio.h>

int main() {
    char filename[100];
    FILE *fp;

    printf("생성할 파일 이름: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("파일 생성 실패");
        return 1;
    }

    fclose(fp);
    printf("파일 생성 완료\n");
    return 0;
}

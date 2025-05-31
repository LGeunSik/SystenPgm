// cat.c - 파일 내용 출력
#include <stdio.h>

int main() {
    char filename[100];
    FILE *fp;
    int ch;

    printf("내용을 출력할 파일 이름: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }

    fclose(fp);
    return 0;
}

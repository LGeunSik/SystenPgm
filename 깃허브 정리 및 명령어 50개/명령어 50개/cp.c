// cp.c - 파일 복사
#include <stdio.h>

int main() {
    char src[100], dest[100];
    FILE *fp1, *fp2;
    int ch;

    printf("복사할 원본 파일 이름: ");
    scanf("%s", src);
    printf("복사될 대상 파일 이름: ");
    scanf("%s", dest);

    fp1 = fopen(src, "r");
    if (!fp1) {
        perror("원본 파일 열기 실패");
        return 1;
    }

    fp2 = fopen(dest, "w");
    if (!fp2) {
        perror("대상 파일 열기 실패");
        fclose(fp1);
        return 1;
    }

    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp2);
    }

    fclose(fp1);
    fclose(fp2);
    printf("'%s' 파일이 '%s'로 복사되었습니다.\n", src, dest);
    return 0;
}

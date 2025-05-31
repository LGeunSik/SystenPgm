// file.c - ELF 시그니처 기반 파일 유형 확인
#include <stdio.h>
#include <string.h>

int main() {
    char filename[256];
    FILE *fp;
    char buf[4];

    printf("파일명을 입력하세요: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("❌ 파일 열기 실패");
        return 1;
    }

    fread(buf, 1, 4, fp);  // 앞 4바이트 읽기

    // ELF 시그니처 확인
    if (memcmp(buf, "\x7f""ELF", 4) == 0) {
        printf("✔ ELF 실행 파일입니다.\n");
    } else {
        printf("✔ 일반 텍스트 파일 또는 기타 형식입니다.\n");
    }

    fclose(fp);
    return 0;
}

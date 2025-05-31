// gzip_simple.c - 연속된 동일 문자를 압축하는 단순 gzip 구현
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "사용법: %s <원본파일> <압축파일>\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    if (!in) {
        perror("원본 파일 열기 실패");
        return 1;
    }

    FILE *out = fopen(argv[2], "w");
    if (!out) {
        perror("압축 파일 생성 실패");
        fclose(in);
        return 1;
    }

    int prev = fgetc(in);
    int count = 1;
    int curr;

    while ((curr = fgetc(in)) != EOF) {
        if (curr == prev) {
            count++;
        } else {
            // 연속된 문자를 압축해서 기록: 문자와 개수
            fprintf(out, "%c%d", prev, count);
            prev = curr;
            count = 1;
        }
    }

    // 마지막 문자 기록
    if (prev != EOF)
        fprintf(out, "%c%d", prev, count);

    fclose(in);
    fclose(out);
    printf("✔ 파일이 압축되었습니다: %s → %s\n", argv[1], argv[2]);
    return 0;
}

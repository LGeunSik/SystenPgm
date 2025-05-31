// gunzip_basic.c - .gz 확장자를 제거하고 원본 이름으로 복원하는 예제
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: %s <압축파일.gz>\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    size_t len = strlen(input_filename);

    // .gz 확장자 확인
    if (len <= 3 || strcmp(input_filename + len - 3, ".gz") != 0) {
        fprintf(stderr, "❌ .gz 확장자를 가진 파일이 필요합니다.\n");
        return 1;
    }

    // 복원될 파일 이름 결정: .gz 제거
    char output_filename[256];
    strncpy(output_filename, input_filename, len - 3);
    output_filename[len - 3] = '\0';

    FILE *in = fopen(input_filename, "rb");
    if (!in) {
        perror("압축 파일 열기 실패");
        return 1;
    }

    FILE *out = fopen(output_filename, "wb");
    if (!out) {
        perror("복원 파일 생성 실패");
        fclose(in);
        return 1;
    }

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        fputc(ch, out);  // 여기서는 실제 압축을 안 풀고 복사만 함
    }

    fclose(in);
    fclose(out);

    // 압축 파일 삭제 흉내
    printf("✔ %s → %s 복원 완료 (실제 압축 해제는 아님)\n", input_filename, output_filename);
    // remove(input_filename);  // 실제 gzip -d처럼 원본 삭제하려면 주석 해제

    return 0;
}

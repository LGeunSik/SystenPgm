// tar_simple.c - 여러 파일을 하나의 파일로 묶기 (단순 아카이빙 구현)
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "사용법: %s <아카이브 파일명> <파일1> <파일2> ...\n", argv[0]);
        return 1;
    }

    FILE *archive = fopen(argv[1], "wb");
    if (!archive) {
        perror("아카이브 파일 열기 실패");
        return 1;
    }

    for (int i = 2; i < argc; ++i) {
        FILE *input = fopen(argv[i], "rb");
        if (!input) {
            perror("입력 파일 열기 실패");
            continue;
        }

        // 파일명 기록
        fprintf(archive, "###FILE:%s\n", argv[i]);

        // 파일 내용 복사
        int ch;
        while ((ch = fgetc(input)) != EOF) {
            fputc(ch, archive);
        }

        fprintf(archive, "\n###END\n");

        fclose(input);
    }

    fclose(archive);
    printf("✔ 파일이 %s로 아카이빙 되었습니다.\n", argv[1]);
    return 0;
}

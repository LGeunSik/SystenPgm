// less.c - 파일을 페이지 단위(20줄)로 출력하는 C 프로그램
#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 20  // 한 화면에 보여줄 줄 수

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "사용법: %s <파일명>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("파일 열기 실패");
        return 1;
    }

    char line[1024];
    int count = 0;

    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
        count++;

        // 20줄 출력한 뒤에 대기
        if (count == PAGE_SIZE) {
            printf("---- 스페이스바를 누르면 다음 페이지 ----");
            while (getchar() != ' ') {}  // 스페이스바 입력 대기
            count = 0;
        }
    }

    fclose(fp);
    return 0;
}

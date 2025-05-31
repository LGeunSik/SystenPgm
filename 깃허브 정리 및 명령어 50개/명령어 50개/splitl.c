// split.c - 입력 파일을 일정 줄 수마다 잘라서 출력 파일로 나눠 저장
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 기본 최대 줄 수 설정
#define MAX_LINE 1024
#define MAX_FILENAME 256

int main() {
    char input_filename[MAX_FILENAME];
    char output_prefix[MAX_FILENAME];
    int lines_per_file;

    // 사용자로부터 입력 받을 정보들
    printf("입력 파일명을 입력하세요: ");
    scanf("%s", input_filename);

    printf("출력 파일의 접두어를 입력하세요: ");
    scanf("%s", output_prefix);

    printf("몇 줄마다 분할할까요? ");
    scanf("%d", &lines_per_file);

    FILE *input = fopen(input_filename, "r");
    if (!input) {
        perror("입력 파일 열기 실패");
        return 1;
    }

    char line[MAX_LINE];
    int file_count = 0;     // 몇 번째 분할 파일인지
    int line_count = 0;     // 현재 파일에 몇 줄 적었는지
    FILE *output = NULL;

    // 입력 파일을 한 줄씩 읽어옴
    while (fgets(line, sizeof(line), input)) {
        // 새 파일 시작 조건
        if (line_count == 0) {
            char output_filename[MAX_FILENAME];
            sprintf(output_filename, "%s_%02d.txt", output_prefix, file_count++); // 파일명 생성 (ex: output_00.txt)
            output = fopen(output_filename, "w");
            if (!output) {
                perror("출력 파일 생성 실패");
                fclose(input);
                return 1;
            }
        }

        fputs(line, output);     // 한 줄씩 출력 파일에 씀
        line_count++;

        // 지정된 줄 수에 도달하면 파일 닫기
        if (line_count == lines_per_file) {
            fclose(output);
            output = NULL;
            line_count = 0;
        }
    }

    // 남은 파일 닫기
    if (output != NULL) {
        fclose(output);
    }

    fclose(input);
    printf("✔ 파일 분할 완료\n");
    return 0;
}

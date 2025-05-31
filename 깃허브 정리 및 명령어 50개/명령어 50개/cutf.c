// cut_file.c - 파일로부터 탭(\t) 구분 필드를 추출
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "사용법: %s <파일명> <필드번호>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int field = atoi(argv[2]);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("파일 열기 실패");
        return 1;
    }

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = '\0'; // 개행 제거

        int current_field = 1;
        char *token = strtok(line, "\t");

        while (token != NULL) {
            if (current_field == field) {
                printf("%s\n", token);
                break;
            }
            token = strtok(NULL, "\t");
            current_field++;
        }
    }

    fclose(fp);
    return 0;
}

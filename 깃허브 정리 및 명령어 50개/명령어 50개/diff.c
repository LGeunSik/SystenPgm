// diff.c - 두 파일을 줄 단위로 비교하여 차이점 출력
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024  // 한 줄의 최대 길이

int main() {
    char file1[256], file2[256];  // 비교할 두 파일의 이름
    FILE *fp1, *fp2;              // 파일 포인터
    char line1[MAX_LINE], line2[MAX_LINE];  // 각각의 파일에서 읽을 줄
    int line_num = 1;             // 현재 줄 번호

    // 사용자에게 첫 번째 파일명 입력받기
    printf("첫 번째 파일명 입력: ");
    scanf("%s", file1);

    // 사용자에게 두 번째 파일명 입력받기
    printf("두 번째 파일명 입력: ");
    scanf("%s", file2);

    // 두 파일을 읽기 모드로 열기
    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    // 파일 열기에 실패한 경우 오류 출력
    if (!fp1 || !fp2) {
        perror("파일 열기 실패");
        return 1;
    }

    // 두 파일 모두 끝날 때까지 한 줄씩 읽어서 비교
    printf("🔍 서로 다른 줄:\n");
    while (fgets(line1, sizeof(line1), fp1) != NULL &&
           fgets(line2, sizeof(line2), fp2) != NULL) {
        // 줄 끝의 개행 문자 제거
        line1[strcspn(line1, "\n")] = 0;
        line2[strcspn(line2, "\n")] = 0;

        // 두 줄이 서로 다르면 출력
        if (strcmp(line1, line2) != 0) {
            printf("📌 %d번째 줄 다름\n", line_num);
            printf("  → %s: %s\n", file1, line1);
            printf("  → %s: %s\n", file2, line2);
        }

        line_num++;  // 줄 번호 증가
    }

    // 첫 번째 파일이 더 길 경우 나머지 줄 출력
    while (fgets(line1, sizeof(line1), fp1) != NULL) {
        line1[strcspn(line1, "\n")] = 0;
        printf("📌 %d번째 줄 - %s에서만 존재: %s\n", line_num, file1, line1);
        line_num++;
    }

    // 두 번째 파일이 더 길 경우 나머지 줄 출력
    while (fgets(line2, sizeof(line2), fp2) != NULL) {
        line2[strcspn(line2, "\n")] = 0;
        printf("📌 %d번째 줄 - %s에서만 존재: %s\n", line_num, file2, line2);
        line_num++;
    }

    // 파일 닫기
    fclose(fp1);
    fclose(fp2);

    return 0;
}

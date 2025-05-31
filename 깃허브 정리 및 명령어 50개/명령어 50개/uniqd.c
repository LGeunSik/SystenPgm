// uniq_d.c - 중복된 줄만 한 번 출력하는 프로그램
#include <stdio.h>      // 표준 입출력 함수
#include <string.h>     // 문자열 함수 사용
#define MAX_LINES 100   // 최대 줄 수
#define MAX_LEN 256     // 각 줄의 최대 길이

int main() {
    char lines[MAX_LINES][MAX_LEN];  // 줄 저장 배열
    int count = 0;                   // 총 줄 개수

    printf("중복된 줄만 출력합니다. (입력 종료: 빈 줄)\n");

    // 사용자로부터 줄 입력 받기
    while (fgets(lines[count], MAX_LEN, stdin)) {
        if (lines[count][0] == '\n') break;  // 빈 줄이면 종료
        lines[count][strcspn(lines[count], "\n")] = '\0';  // 개행 제거
        count++;
    }

    printf("\n🟨 중복된 줄만 출력:\n");

    for (int i = 1; i < count; i++) {
        // 현재 줄과 이전 줄이 같고,
        // 그 전 줄과는 달라야 중복 줄을 한 번만 출력
        if (strcmp(lines[i], lines[i - 1]) == 0 &&
            (i == 1 || strcmp(lines[i], lines[i - 2]) != 0)) {
            printf("%s\n", lines[i]);
        }
    }

    return 0;
}

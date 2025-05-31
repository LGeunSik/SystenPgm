// uniq_count.c - 연속된 중복 줄의 개수를 세어 함께 출력하는 프로그램
#include <stdio.h>      // 표준 입출력
#include <string.h>     // 문자열 비교 및 처리

#define MAX_LINES 100   // 최대 줄 수
#define MAX_LEN 256     // 한 줄의 최대 길이

int main() {
    char lines[MAX_LINES][MAX_LEN];  // 입력된 줄들을 저장할 배열
    int count = 0;                   // 총 줄 수

    printf("중복 줄 개수 출력할 문자열을 한 줄씩 입력하세요 (입력 종료: 빈 줄)\n");

    // 줄 입력 받기
    while (fgets(lines[count], MAX_LEN, stdin)) {
        if (lines[count][0] == '\n') break;  // 빈 줄 입력 시 종료
        lines[count][strcspn(lines[count], "\n")] = 0;  // 개행 문자 제거
        count++;
    }

    printf("\n📊 줄별 중복 개수:\n");

    if (count == 0) return 0;  // 입력이 없을 경우 종료

    int duplicate_count = 1;  // 현재 줄의 중복 개수 초기화

    // 첫 줄부터 차례로 검사
    for (int i = 1; i <= count; i++) {
        // 마지막 줄이거나 다음 줄과 현재 줄이 다르면 출력
        if (i == count || strcmp(lines[i], lines[i - 1]) != 0) {
            // 중복 개수와 해당 줄 출력
            printf("%7d %s\n", duplicate_count, lines[i - 1]);
            duplicate_count = 1;  // 개수 초기화
        } else {
            duplicate_count++;  // 중복 개수 증가
        }
    }

    return 0;
}

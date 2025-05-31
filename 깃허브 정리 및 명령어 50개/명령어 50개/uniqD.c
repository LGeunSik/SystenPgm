// uniq_D.c - 중복된 줄이 있을 경우 모두 출력
#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 256

int main() {
    char lines[MAX_LINES][MAX_LEN];
    int count = 0;

    printf("중복된 줄을 모두 출력합니다. (입력 종료: 빈 줄)\n");

    // 입력 받기
    while (fgets(lines[count], MAX_LEN, stdin)) {
        if (lines[count][0] == '\n') break;  // 빈 줄이면 입력 종료
        lines[count][strcspn(lines[count], "\n")] = '\0';  // 줄바꿈 제거
        count++;
    }

    printf("\n📌 중복된 줄 전체 출력:\n");

    // 중복된 줄을 모두 출력
    for (int i = 1; i < count; i++) {
        if (strcmp(lines[i], lines[i - 1]) == 0) {
            // 바로 전 줄과 같으면 둘 다 출력
            printf("%s\n", lines[i - 1]);

            // 이후 연속된 중복 줄도 출력
            while (i < count && strcmp(lines[i], lines[i - 1]) == 0) {
                printf("%s\n", lines[i]);
                i++;
            }
        }
    }

    return 0;
}

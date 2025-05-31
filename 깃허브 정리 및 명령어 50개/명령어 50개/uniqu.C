// uniq_u.c - 중복 없이 한 번만 등장하는 줄만 출력
#include <stdio.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LEN 256

int main() {
    char lines[MAX_LINES][MAX_LEN];
    int count = 0;

    printf("고유한 줄만 출력합니다. (입력 종료: 빈 줄)\n");

    // 입력 받기
    while (fgets(lines[count], MAX_LEN, stdin)) {
        if (lines[count][0] == '\n') break;  // 빈 줄이면 입력 종료
        lines[count][strcspn(lines[count], "\n")] = '\0';  // 개행 제거
        count++;
    }

    printf("\n📌 고유한 줄 출력 (uniq -u):\n");

    // 줄 비교하며 유일한 것만 출력
    for (int i = 0; i < count;) {
        int j = i + 1;
        // 현재 줄과 다음 줄이 같은지 확인
        while (j < count && strcmp(lines[i], lines[j]) == 0) {
            j++;
        }

        if (j == i + 1) {
            // 다음 줄과 다르면 한 번만 등장한 것이므로 출력
            printf("%s\n", lines[i]);
        }

        // 다음 줄로 이동 (중복이라면 j로, 아니면 i+1로)
        i = j;
    }

    return 0;
}

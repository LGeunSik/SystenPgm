// sleep.c - 사용자 입력 시간 동안 일시 정지하는 명령어 구현
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int seconds;

    printf("대기할 시간(초)을 입력하세요: ");
    if (scanf("%d", &seconds) != 1 || seconds < 0) {
        fprintf(stderr, "❌ 유효하지 않은 숫자입니다.\n");
        return 1;
    }

    printf("⏳ %d초 동안 대기 중...\n", seconds);
    sleep(seconds);
    printf("✅ %d초 대기 완료.\n", seconds);

    return 0;
}

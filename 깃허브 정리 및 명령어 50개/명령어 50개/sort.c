// sort.c - 여러 줄의 문자열을 입력받아 오름차순 정렬 후 출력하는 프로그램
#include <stdio.h>      // 표준 입출력 함수 사용
#include <stdlib.h>     // malloc, free, qsort 등 사용
#include <string.h>     // 문자열 처리 함수 사용

#define MAX_LINES 100   // 입력 받을 최대 줄 수
#define MAX_LEN 256     // 각 줄의 최대 길이

// 문자열 정렬을 위한 비교 함수 (qsort에 사용됨)
int cmpfunc(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);  // 문자열 사전순 비교
}

int main() {
    char *lines[MAX_LINES];  // 문자열 포인터 배열 (각 줄을 저장)
    char buffer[MAX_LEN];    // 한 줄씩 임시로 입력 받을 버퍼
    int count = 0;           // 입력된 줄의 개수

    printf("정렬할 문자열을 한 줄씩 입력하세요 (입력 종료: 빈 줄)\n");

    // 표준 입력으로 여러 줄을 입력 받음
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (buffer[0] == '\n') break;  // 빈 줄 입력 시 종료

        buffer[strcspn(buffer, "\n")] = 0;  // 줄바꿈 문자 제거

        // 입력된 문자열에 맞는 크기만큼 메모리 할당
        lines[count] = malloc(strlen(buffer) + 1);
        if (lines[count] == NULL) {
            perror("메모리 할당 실패");
            return 1;
        }

        strcpy(lines[count], buffer);  // 입력 버퍼를 메모리 공간에 복사
        count++;  // 줄 개수 증가
    }

    // 입력된 문자열들을 오름차순으로 정렬
    qsort(lines, count, sizeof(char *), cmpfunc);

    // 정렬된 결과 출력
    printf("\n📄 정렬 결과:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", lines[i]);  // 각 줄 출력
        free(lines[i]);  // 할당된 메모리 해제
    }

    return 0;  // 정상 종료
}

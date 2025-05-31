#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000

int main() {
    char filename[100];
    int n, count = 0;
    FILE *fp;
    char *lines[MAX_LINES];
    char buffer[1024];

    printf("파일 이름을 입력하세요: ");
    scanf("%s", filename);
    printf("출력할 줄 수(N): ");
    scanf("%d", &n);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    // 줄 저장용 동적 배열
    while (fgets(buffer, sizeof(buffer), fp) != NULL && count < MAX_LINES) {
        lines[count] = strdup(buffer);  // 줄 복사
        count++;
    }

    fclose(fp);

    // 뒤에서 N줄 출력
    int start = count - n;
    if (start < 0) start = 0;

    for (int i = start; i < count; i++) {
        printf("%s", lines[i]);
        free(lines[i]);  // 메모리 해제
    }

    return 0;
}

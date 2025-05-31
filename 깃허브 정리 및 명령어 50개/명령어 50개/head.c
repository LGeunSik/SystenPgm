#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    int n;
    FILE *fp;
    char line[1024];

    printf("파일 이름을 입력하세요: ");
    scanf("%s", filename);
    printf("출력할 줄 수(N): ");
    scanf("%d", &n);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("파일 열기 실패");
        return 1;
    }

    // 최대 N줄까지 읽어서 출력
    for (int i = 0; i < n && fgets(line, sizeof(line), fp) != NULL; i++) {
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}

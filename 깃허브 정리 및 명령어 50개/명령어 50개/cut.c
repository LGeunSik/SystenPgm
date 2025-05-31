// cut.c - 구분자 기준으로 분리 후 특정 필드 출력
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char input[1024];
    char delim;
    int field;

    printf("입력 문자열을 입력하세요: ");
    fgets(input, sizeof(input), stdin);

    // 개행 문자 제거
    input[strcspn(input, "\n")] = 0;

    printf("구분자 입력 (예: , 또는 : 또는 공백): ");
    scanf(" %c", &delim);  // 공백 포함한 단일 문자 입력

    printf("출력할 필드 번호 (1부터 시작): ");
    scanf("%d", &field);

    // 문자열 분리
    char *token;
    int count = 1;
    token = strtok(input, &delim);

    while (token != NULL) {
        if (count == field) {
            printf("선택한 필드: %s\n", token);
            break;
        }
        token = strtok(NULL, &delim);
        count++;
    }

    if (token == NULL) {
        printf("❌ 해당 필드가 존재하지 않습니다.\n");
    }

    return 0;
}

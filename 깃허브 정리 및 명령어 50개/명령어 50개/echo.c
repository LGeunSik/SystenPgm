// echo.c
#include <stdio.h>

int main() {
    char input[256];

    printf("출력할 문자열 입력: ");
    getchar();  // 이전 입력 버퍼 비우기
    fgets(input, sizeof(input), stdin);

    printf("%s", input);
    return 0;
}

// basename.c
#include <stdio.h>
#include <string.h>

int main() {
    char path[256];
    char *base;

    printf("파일 경로 입력: ");
    scanf("%s", path);

    base = strrchr(path, '/');  // 마지막 '/' 찾기
    if (base != NULL)
        printf("파일 이름: %s\n", base + 1);  // '/' 다음 문자열
    else
        printf("파일 이름: %s\n", path);  // '/' 없으면 전체가 파일명

    return 0;
}

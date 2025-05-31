// tr.c - 문자열 내 문자 치환 (a-z → A-Z 같은 기본 치환 기능)
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char from[128], to[128];
    char input[1024];

    printf("변환할 문자 집합을 입력하세요 (예: a-z): ");
    scanf("%s", from);

    printf("대체할 문자 집합을 입력하세요 (예: A-Z): ");
    scanf("%s", to);

    printf("문자열을 입력하세요: ");
    getchar();  // 이전 입력의 개행 제거
    fgets(input, sizeof(input), stdin);

    // 소문자-대문자 매핑만 지원
    for (int i = 0; i < strlen(input); i++) {
        if (from[0] == 'a' && to[0] == 'A') {
            if (islower(input[i])) {
                input[i] = toupper(input[i]);
            }
        } else if (from[0] == 'A' && to[0] == 'a') {
            if (isupper(input[i])) {
                input[i] = tolower(input[i]);
            }
        }
    }

    printf("변환 결과: %s", input);
    return 0;
}

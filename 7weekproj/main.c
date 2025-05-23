#include <stdio.h>
#include <string.h>
#define MAXLINE 100

char line[MAXLINE]; // 입력 줄
char longest[MAXLINE]; // 가장 긴 줄
void copy(char from[], char to[]); // copy 함수 프로토타입

int main() {
    int len, max = 0;
    while (fgets(line, MAXLINE, stdin) != NULL) {
        len = strlen(line);
        if (len > max) {
            max = len;
            copy(line, longest);
        }
    }
    if (max > 0) // 입력 줄이 있었다면
        printf("%s", longest);
    return 0;
}

void copy(char from[], char to[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}

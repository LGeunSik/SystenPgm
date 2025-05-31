// pwd.c - 현재 작업 디렉토리 출력
#include <stdio.h>
#include <unistd.h>

int main() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    } else {
        perror("getcwd() 에러");
        return 1;
    }
    return 0;
}

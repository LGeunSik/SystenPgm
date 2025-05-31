// dirname.c - 입력된 경로에서 디렉토리 부분만 출력
#include <stdio.h>
#include <string.h>
#include <libgen.h>  // dirname 함수가 정의된 헤더

int main(int argc, char *argv[]) {
    // 명령어 인자가 없으면 사용법 출력
    if (argc != 2) {
        fprintf(stderr, "사용법: %s <경로>\n", argv[0]);
        return 1;
    }

    // 인자로 받은 경로 복사 (dirname은 원본을 수정함)
    char path[1024];
    strncpy(path, argv[1], sizeof(path));
    path[sizeof(path) - 1] = '\0'; // 널 종료 보장

    // 디렉토리명 추출
    char *dir = dirname(path);
    printf("%s\n", dir);

    return 0;
}

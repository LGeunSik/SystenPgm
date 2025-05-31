// chmod.c - 8진수 권한 값을 사용해 파일 권한을 변경하는 프로그램
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main() {
    char filename[256];
    int mode;

    // 파일 이름 입력
    printf("파일명을 입력하세요: ");
    scanf("%s", filename);

    // 권한 입력 (예: 755, 644 등 8진수)
    printf("변경할 권한(8진수, 예: 755): ");
    scanf("%o", &mode);  // %o: 8진수 입력 받기

    // chmod 함수로 권한 변경
    if (chmod(filename, mode) == 0) {
        printf("✔ 파일 '%s'의 권한이 %o(8진수)로 변경되었습니다.\n", filename, mode);
    } else {
        perror("❌ 권한 변경 실패");
        return 1;
    }

    return 0;
}

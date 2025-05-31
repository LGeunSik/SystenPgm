// chmod.c - 8진수 권한 입력을 받아 chmod 수행
#include <stdio.h>
#include <sys/stat.h>

int main() {
    char filename[256];     // 파일명 입력 버퍼
    int mode;               // 8진수 권한 저장

    printf("파일명을 입력하세요: ");
    scanf("%s", filename);

    printf("변경할 권한을 8진수로 입력하세요 (예: 755): ");
    scanf("%o", &mode);  // %o는 8진수 입력 받기

    // chmod 호출로 권한 변경
    if (chmod(filename, mode) == 0) {
        printf("✔ 권한이 성공적으로 변경되었습니다: %04o\n", mode);
    } else {
        perror("❌ 권한 변경 실패");
        return 1;
    }

    return 0;
}

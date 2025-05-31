// users.c - 로그인한 사용자 ID만 한 줄로 출력
#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    struct utmp entry;
    FILE *fp = fopen(_PATH_UTMP, "rb");  // utmp 파일 열기

    if (!fp) {
        perror("utmp 파일 열기 실패");
        return 1;
    }

    while (fread(&entry, sizeof(entry), 1, fp) == 1) {
        // USER_PROCESS: 현재 로그인한 사용자만 필터링
        if (entry.ut_type == USER_PROCESS) {
            printf("%s ", entry.ut_user);  // 사용자명 출력 (줄바꿈 없음)
        }
    }

    printf("\n");
    fclose(fp);
    return 0;
}

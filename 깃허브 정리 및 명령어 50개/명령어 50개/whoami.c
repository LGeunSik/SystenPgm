// whoami.c - 리눅스/WSL 환경에서도 작동
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

int main() {
    struct passwd *pw;
    uid_t uid;

    uid = getuid();             // 현재 사용자 UID 가져오기
    pw = getpwuid(uid);         // UID에 해당하는 사용자 정보 가져오기

    if (pw) {
        printf("현재 사용자: %s\n", pw->pw_name);
    } else {
        perror("사용자 정보를 가져오는 데 실패했습니다");
        return 1;
    }

    return 0;
}

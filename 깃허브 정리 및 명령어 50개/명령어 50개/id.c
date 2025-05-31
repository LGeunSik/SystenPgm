// id.c - 현재 사용자의 UID, GID, 그룹 정보 출력
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

int main() {
    uid_t uid = getuid();         // UID 가져오기
    gid_t gid = getgid();         // GID 가져오기
    struct passwd *pw = getpwuid(uid);
    struct group *gr = getgrgid(gid);

    if (!pw || !gr) {
        perror("사용자 또는 그룹 정보 조회 실패");
        return 1;
    }

    printf("uid=%d(%s) gid=%d(%s) groups=%d(%s)\n",
           uid, pw->pw_name,
           gid, gr->gr_name,
           gid, gr->gr_name); // 그룹은 단일 그룹만 출력 (단순 구현)

    return 0;
}

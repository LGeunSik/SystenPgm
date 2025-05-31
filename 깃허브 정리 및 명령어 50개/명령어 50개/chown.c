// chown.c - UID, GID 입력을 받아 소유자 변경
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    char filename[256];
    uid_t uid;
    gid_t gid;

    printf("파일명을 입력하세요: ");
    scanf("%s", filename);

    printf("새 사용자 UID를 입력하세요: ");
    scanf("%d", &uid);

    printf("새 그룹 GID를 입력하세요: ");
    scanf("%d", &gid);

    // chown 호출
    if (chown(filename, uid, gid) == 0) {
        printf("✔ 소유자 변경 성공 (UID: %d, GID: %d)\n", uid, gid);
    } else {
        perror("❌ 소유자 변경 실패 (sudo 필요할 수 있음)");
        return 1;
    }

    return 0;
}

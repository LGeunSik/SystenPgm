// df.c - 디스크 사용량 출력 (리눅스 df 명령어 유사)
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>

int main() {
    struct statvfs fs;

    // 현재 디렉토리 기준 파일시스템 정보
    if (statvfs(".", &fs) != 0) {
        perror("❌ 파일시스템 정보 가져오기 실패");
        return 1;
    }

    unsigned long total = fs.f_blocks * fs.f_frsize;     // 총 용량
    unsigned long free = fs.f_bfree * fs.f_frsize;       // 전체 중 사용 가능한 공간
    unsigned long avail = fs.f_bavail * fs.f_frsize;     // 비루트 사용자에게 사용 가능한 공간
    unsigned long used = total - free;

    double usage = (double)used / total * 100;

    printf("Filesystem    Size     Used    Avail   Use%%  Mounted on\n");
    printf("/            %7.1fG %7.1fG %7.1fG %5.1f%%  /\n",
           total / 1073741824.0,
           used / 1073741824.0,
           avail / 1073741824.0,
           usage);

    return 0;
}

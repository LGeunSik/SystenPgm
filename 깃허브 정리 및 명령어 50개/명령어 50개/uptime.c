// uptime.c - 시스템 부팅 이후 경과 시간을 xx일 hh:mm:ss로 출력
#include <stdio.h>

int main() {
    FILE *fp;
    double uptime_seconds;

    fp = fopen("/proc/uptime", "r");
    if (!fp) {
        perror("❌ /proc/uptime 파일 열기 실패");
        return 1;
    }

    // 첫 번째 값만 읽기 (전체 uptime)
    fscanf(fp, "%lf", &uptime_seconds);
    fclose(fp);

    // 계산
    int total_seconds = (int)uptime_seconds;
    int days = total_seconds / 86400;
    int hours = (total_seconds % 86400) / 3600;
    int minutes = (total_seconds % 3600) / 60;
    int seconds = total_seconds % 60;

    // 출력
    printf("🕒 시스템이 켜진 지 %d일 %02d:%02d:%02d 지났습니다.\n", days, hours, minutes, seconds);

    return 0;
}

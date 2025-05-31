// ps.c - 리눅스 기본 ps 명령어 스타일로 출력: PID TTY TIME CMD
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void format_time(long total_ticks, char *out) {
    long seconds = total_ticks / sysconf(_SC_CLK_TCK);
    int h = seconds / 3600;
    int m = (seconds % 3600) / 60;
    int s = seconds % 60;
    sprintf(out, "%02d:%02d:%02d", h, m, s);
}

void get_tty(const char *pid, char *tty) {
    char path[256];
    struct stat st;
    snprintf(path, sizeof(path), "/proc/%s/fd/0", pid);

    if (stat(path, &st) == -1) {
        strcpy(tty, "?");
        return;
    }

    snprintf(path, sizeof(path), "/proc/%s/stat", pid);
    FILE *fp = fopen(path, "r");
    if (!fp) {
        strcpy(tty, "?");
        return;
    }

    int tty_nr;
    fscanf(fp,
           "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %*u %*u %*d %*d %*d %*d %d",
           &tty_nr);
    fclose(fp);

    if (tty_nr == 0) {
        strcpy(tty, "?");
    } else {
        snprintf(tty, 32, "pts/%d", tty_nr & 0xff);
    }
}

int main() {
    DIR *dir = opendir("/proc");
    struct dirent *entry;

    printf("  PID TTY          TIME CMD\n");

    while ((entry = readdir(dir)) != NULL) {
        if (!isdigit(entry->d_name[0])) continue;

        char stat_path[256], cmdline_path[256];
        FILE *fp;
        int pid;
        char comm[256], state;
        unsigned long utime, stime;
        char tty[32] = "?";
        char timebuf[32] = "";

        // /proc/[pid]/stat
        snprintf(stat_path, sizeof(stat_path), "/proc/%s/stat", entry->d_name);
        fp = fopen(stat_path, "r");
        if (!fp) continue;

        fscanf(fp, "%d %s %c", &pid, comm, &state);
        for (int i = 0; i < 11; i++) fscanf(fp, "%*s");  // skip
        fscanf(fp, "%lu %lu", &utime, &stime);
        fclose(fp);

        // 누적 시간 계산
        format_time(utime + stime, timebuf);

        // TTY 얻기
        get_tty(entry->d_name, tty);

        // CMD
        snprintf(cmdline_path, sizeof(cmdline_path), "/proc/%s/cmdline", entry->d_name);
        fp = fopen(cmdline_path, "r");
        char cmdline[256] = "";
        if (fp) {
            fread(cmdline, 1, sizeof(cmdline) - 1, fp);
            fclose(fp);
        }
        if (strlen(cmdline) == 0) {
            snprintf(cmdline, sizeof(cmdline), "%s", comm);
        }

        printf("%5d %-12s %s %s\n", pid, tty, timebuf, cmdline);
    }

    closedir(dir);
    return 0;
}

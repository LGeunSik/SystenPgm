// free.c - /proc/meminfo를 파싱하여 메모리 사용량 출력
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (!fp) {
        perror("❌ /proc/meminfo 열기 실패");
        return 1;
    }

    long mem_total = 0, mem_free = 0, buffers = 0, cached = 0;
    long swap_total = 0, swap_free = 0;

    char label[64];
    long value;
    char unit[16];

    // 필요한 항목만 읽기
    while (fscanf(fp, "%63s %ld %15s", label, &value, unit) == 3) {
        if (strcmp(label, "MemTotal:") == 0) mem_total = value;
        else if (strcmp(label, "MemFree:") == 0) mem_free = value;
        else if (strcmp(label, "Buffers:") == 0) buffers = value;
        else if (strcmp(label, "Cached:") == 0) cached = value;
        else if (strcmp(label, "SwapTotal:") == 0) swap_total = value;
        else if (strcmp(label, "SwapFree:") == 0) swap_free = value;
    }

    fclose(fp);

    long mem_used = mem_total - mem_free - buffers - cached;
    long swap_used = swap_total - swap_free;

    printf("              total        used        free      shared  buff/cache   available\n");
    printf("Mem:     %10ld %10ld %10ld      -    %10ld %10ld\n",
           mem_total, mem_used, mem_free, buffers + cached, mem_free + buffers + cached);

    printf("Swap:    %10ld %10ld %10ld\n", swap_total, swap_used, swap_free);

    return 0;
}

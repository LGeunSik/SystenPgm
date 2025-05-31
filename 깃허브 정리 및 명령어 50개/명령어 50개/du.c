// du.c - 파일/디렉토리 디스크 사용량 출력
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define BLOCK_SIZE 512  // 전통적인 블록 단위 (du도 기본은 512바이트 기준)

long du(const char *path) {
    struct stat st;
    DIR *dir;
    struct dirent *entry;
    char fullpath[1024];
    long total_blocks = 0;

    if (lstat(path, &st) == -1) {
        perror(path);
        return 0;
    }

    // 파일인 경우: 사용한 블록 수 리턴
    if (!S_ISDIR(st.st_mode)) {
        printf("%5ld\t%s\n", (st.st_blocks * 512) / 1024, path);
        return st.st_blocks;
    }

    // 디렉토리인 경우: 내부 탐색
    dir = opendir(path);
    if (!dir) {
        perror(path);
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) {
        // 현재 디렉토리와 상위 디렉토리는 제외
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        total_blocks += du(fullpath);  // 재귀적으로 하위 경로 탐색
    }

    closedir(dir);

    printf("%5ld\t%s\n", (st.st_blocks * 512) / 1024, path);
    return st.st_blocks;
}

int main(int argc, char *argv[]) {
    const char *target = ".";

    if (argc >= 2) {
        target = argv[1];
    }

    du(target);
    return 0;
}

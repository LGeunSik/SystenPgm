#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
    char dirname[100], target[100];
    struct dirent *entry;
    DIR *dp;

    printf("검색할 디렉토리 경로: ");
    scanf("%s", dirname);
    printf("찾을 파일 이름(일치): ");
    scanf("%s", target);

    dp = opendir(dirname);
    if (dp == NULL) {
        perror("디렉토리 열기 실패");
        return 1;
    }

    printf("'%s'에서 '%s' 검색 결과:\n", dirname, target);
    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, target) == 0) {
            printf("  ▶ %s/%s\n", dirname, entry->d_name);
        }
    }

    closedir(dp);
    return 0;
}

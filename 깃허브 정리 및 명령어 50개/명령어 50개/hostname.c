// hostname.c
#include <stdio.h>
#include <unistd.h>

int main() {
    char hostname[1024];
    gethostname(hostname, sizeof(hostname));
    printf("호스트 이름: %s\n", hostname);
    return 0;
}

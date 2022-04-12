#include <stdio.h>
#include <stdlib.h>
#define STDIN  0
#define STDOUT 1
#define STDERR 2
#ifdef _WIN32
# include <io.h>
# include <fcntl.h>
# define SET_BINARY_MODE(handle) setmode(handle, O_BINARY)
#else
# define SET_BINARY_MODE(handle) ((void)0)
#endif
#define N 75000

int main() {
    SET_BINARY_MODE(STDOUT);
    SET_BINARY_MODE(STDIN);
    unsigned char *buf = (unsigned char *)malloc(N * sizeof(char));
    unsigned char check[4] = {0xd9, 0x45, 0x08, 0xd9};
    size_t n = fread(buf, sizeof(char), N, stdin);
    for(size_t i = 0; i < n - 3; i++){
        if(buf[i] == check[0] && buf[i + 1] == check[1] && buf[i + 2] == check[2] && buf[i + 3] == check[3]) {
            buf[i + 4] = 0xeb;
            buf[i + 5] = 0x90;
            buf[i + 6] = 0xd8;
            buf[i + 7] = 0xc9;
            break;
        }
    }
    fwrite(buf, sizeof(char), n, stdout);
    free(buf);
    return 0;
}

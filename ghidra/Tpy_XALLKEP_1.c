#include <stdio.h>

int main() {
    FILE* fin = fopen("source", "rb");
    FILE* fout = fopen("cracked", "wb");
    char buf;
    int i = 0;
    for(;i < 0x520; i++) {
        fread(&buf, sizeof(char), 1, fin);
        fwrite(&buf, sizeof(char), 1, fout);
    }
    for(i = 0; i < 4; i++) {
        fread(&buf, sizeof(char), 1, fin);
    }
    buf = (char) 0xe0;
    fwrite(&buf, sizeof(char), 1, fout);
    buf = (char) 0xfe;
    fwrite(&buf, sizeof(char), 1, fout);
    buf = (char) 0xff;
    fwrite(&buf, sizeof(char), 1, fout);
    buf = (char) 0x54;
    fwrite(&buf, sizeof(char), 1, fout);
    while(1 == fread(&buf, sizeof(char), 1, fin)) {
        fwrite(&buf, sizeof(char), 1, fout);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}

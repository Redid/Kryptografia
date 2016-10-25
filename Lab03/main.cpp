#include <cstdio>
#include <cstring>
#include <openssl/blowfish.h>

char prompt[]  = "[input] [output] [blowfish_key (at least 64 bits)] -cbc/ecb -encrypt/decrypt";

int main(int argc, char** argv) {
    FILE *input, *output;
    unsigned char *key = (unsigned char*)argv[3];
    bool cbc = false;

    BF_KEY bfKey;

    if(argc < 6) {
        puts(prompt);
        return 1;
    }

    input = fopen(argv[1], "rb");
    output = fopen(argv[2], "wb");

    if((input == 0) || (output == 0)) {
        if(input == 0)
            puts("Error reading input file");
        if(output == 0)
            puts("Error reading output file");
        return 4;
    }

    if(!strcmp(argv[4],"-cbc")) {
        cbc = true;
    } else if(!strcmp(argv[4],"-ecb")) {
        cbc = false;
    } else {
        puts(prompt);
        return 2;
    }

    fprintf(stderr, "Block Size: %d\n", BF_BLOCK);
    fprintf(stderr, "Setting key = %s\n", bfKey);

    BF_set_key(&bfKey, 128, key); //TODO: Change or test
    fprintf(stderr, "DONE: Setting key\n");

    return 0;
}


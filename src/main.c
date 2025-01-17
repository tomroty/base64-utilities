#include "base64.h"
#include <stdlib.h>

#define MAX_INPUT_SIZE 1024

static void print_usage(const char *program) {
    fprintf(stderr, "Usage: %s [-e|-d|-h] <string>\n", program);
    fprintf(stderr, "Try '%s -h' for more information.\n", program);
}

void print_help(const char *program) {
    fprintf(stderr, "Usage: %s [-e|-d|-h] <string>\n", program);
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "  -e    encode input string\n");
    fprintf(stderr, "  -d    decode input string\n");
    fprintf(stderr, "  -h    show this help message\n");
    exit(1);
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        print_usage(argv[0]);
        return 1; 
    }

    if (strcmp(argv[1], "-h") == 0) {
        print_help(argv[0]);
        return 0; 
    }


    if (argc != 3) {
        print_usage(argv[0]);
        return 1;  
    }

    char output[MAX_INPUT_SIZE * 2];
    
    if (strcmp(argv[1], "-e") == 0) {
        encode_base64(argv[2], output);
        printf("%s\n", output);
    } 
    else if (strcmp(argv[1], "-d") == 0) {
        decode_base64(argv[2], output);
        printf("%s\n", output);
    }
    else {
        print_usage(argv[0]);
    }

    return 0;
}

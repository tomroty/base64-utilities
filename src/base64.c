#include "base64.h"

static const char *base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

void encode_base64(const char *input, char *output) {
    int i = 0;
    int j = 0;
    int in_len = strlen(input);
    int out_len = 0;
    char *p = output;

    while (i < in_len) {
        int octet_a = i < in_len ? (unsigned char)input[i++] : 0;
        int octet_b = i < in_len ? (unsigned char)input[i++] : 0;
        int octet_c = i < in_len ? (unsigned char)input[i++] : 0;

        int triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c; 

        p[j++] = base64_chars[(triple >> 3 * 6) & 0x3F];
        p[j++] = base64_chars[(triple >> 2 * 6) & 0x3F];
        p[j++] = base64_chars[(triple >> 1 * 6) & 0x3F];
        p[j++] = base64_chars[(triple >> 0 * 6) & 0x3F];
    }

    out_len = j;

    while (out_len % 4) {
        p[j++] = '=';
        out_len++;
    }

    p[j] = '\0';
}

void decode_base64(const char *input, char *output) {
    int i = 0;
    int j = 0;
    int in_len = strlen(input);
    int out_len = 0;
    char *p = output;

    while (i < in_len) {
        int sextet_a = input[i] == '=' ? 0 & i++ : strchr(base64_chars, input[i++]) - base64_chars;
        int sextet_b = input[i] == '=' ? 0 & i++ : strchr(base64_chars, input[i++]) - base64_chars;
        int sextet_c = input[i] == '=' ? 0 & i++ : strchr(base64_chars, input[i++]) - base64_chars;
        int sextet_d = input[i] == '=' ? 0 & i++ : strchr(base64_chars, input[i++]) - base64_chars;

        int triple = (sextet_a << 3 * 6) + (sextet_b << 2 * 6) + (sextet_c << 1 * 6) + (sextet_d << 0 * 6);

        p[j++] = (triple >> 2 * 8) & 0xFF;
        p[j++] = (triple >> 1 * 8) & 0xFF;
        p[j++] = (triple >> 0 * 8) & 0xFF;
    }

    out_len = j;

    while (out_len % 3) {
        j--;
        out_len--;
    }

    p[j] = '\0';
}
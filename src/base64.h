#ifndef BASE64_H
#define BASE64_H

#include <stdio.h>
#include <string.h>

void encode_base64(const char *input, char *output);
void decode_base64(const char *input, char *output);

#endif // BASE64_H

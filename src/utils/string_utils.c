#include <string.h>
#include <stdlib.h>
#include "string_utils.h"

int length(char **strings) {
    int n = 0;
    char *str;

    while ((str = *strings++)) {
        n += strlen(str);
    }
    return n + 1;
}

char *join(char **strings, int len, char *separator) {
    --len;
    char *buf = calloc(1, length(strings) + len * strlen(separator) + 1);
    char *str;

    while ((str = *strings++)) {
        strcat(buf, str);
        if (*strings) strcat(buf, separator);
    }
    return buf;
}

long string_to_milliseconds(const char *str) {
    return strtol(str, NULL, 10) * 1000;
}

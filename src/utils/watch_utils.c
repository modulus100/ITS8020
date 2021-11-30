#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "argument_parser.h"

const char *get_usage() {
    return (
            "\n"
            "  Usage: watch [options] <cmd>\n"
            "\n"
            "  Options:\n"
            "\n"
            "    -n <n>    interval in seconds, default 1 second\n"
            "    -v, --version         output version number\n"
            "    -h, --help            display this help and exit\n"
            "\n"
    );
}

int contains_argument(const char *short_argument, const char *long_argument, const char *actual_argument) {
    return !strcmp(short_argument, actual_argument) || !strcmp(long_argument, actual_argument);
}

void handle_error(char *message, struct ParseResult *parse_result) {
    if (strcmp(message, "") != 0) {
        perror(message);
    }

    free_parse_result(parse_result);
    exit(1);
}

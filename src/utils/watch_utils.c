#include <string.h>
#include "watch_utils.h"

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

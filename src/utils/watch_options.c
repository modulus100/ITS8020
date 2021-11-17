#include "watch_options.h"

const char *get_usage() {
    return (
            "\n"
            "  Usage: watch [options] <cmd>\n"
            "\n"
            "  Options:\n"
            "\n"
            "    -q, --quiet           only output stderr\n"
            "    -x, --halt            halt on failure\n"
            "    -i, --interval <n>    interval in seconds or ms defaulting to 1\n"
            "    -c, --clear           clear the screen between iterations\n"
            "    -v, --version         output version number\n"
            "    -h, --help            display this help and exit\n"
            "\n"
    );
}

#include <string.h>
#include <time.h>
#include "watch_utils.h"

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

int contains_argument(const char *short_argument, const char *long_argument, const char *actual_argument) {
    return !strcmp(short_argument, actual_argument) || !strcmp(long_argument, actual_argument);
}

int contains_short_argument(const char *short_argument, const char *actual_argument) {
    return !strcmp(short_argument, actual_argument);
}

void thread_sleep(long m_sec) {
    struct timespec time = {0};
    time_t sec = (int) (m_sec / 1000);
    m_sec = m_sec - (sec * 1000);
    time.tv_sec = sec;
    time.tv_nsec = m_sec * 1000000L;
    while (nanosleep(&time, &time) < 0);
}

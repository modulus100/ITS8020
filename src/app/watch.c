#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>
//#include <time.h>
//#include <fcntl.h>
//#include <sys/wait.h>
//#include "ms/ms.h"
#include "../utils/watch_options.h"

#define VERSION "0.0.1"
#define DEFAULT_INTERVAL 2
#define ARGS_MAX 128

static int quiet = 0;
static int halt = 0;
static int clear = 0;

void print_usage() {
    printf("%s", get_usage());
    exit(1);
}

int main(int argc, const char **argv) {
    if (argc == 1 || argc == 0) {
        print_usage();
    }

    int interval = DEFAULT_INTERVAL;
    int len = 0;
    int interpret = 1;
    char *args[ARGS_MAX] = {0};

    for (int i = 1; i < argc; ++i) {
        const char *arg = argv[i];
        if (!interpret) goto arg;

        if (contains_option("-h", "--help", arg)) {
            print_usage();
        }

        if (contains_option("-q", "--quiet", arg)) {
            quiet = 1;
            continue;
        }

        if (contains_option("-c", "--clear", arg)) {
            clear = 1;
            continue;
        }

        if (contains_option("-x", "--halt", arg)) {
            halt = 1;
            continue;
        }

        if (contains_option("-v", "--version", arg)) {
            printf("%s\n", VERSION);
            exit(1);
        }

        if (contains_option("-i", "--interval", arg)) {
            if (argc - 1 == i) {
                fprintf(stderr, "\n  --interval requires an argument\n\n");
                exit(1);
            }

            arg = argv[++i];
            continue;
        }

        arg:
        args[len++] = (char *) arg;
        interpret = 0;
    }

    return 0;
}
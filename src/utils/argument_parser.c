#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "argument_parser.h"

#define ARGS_LIMIT 10
#define DEFAULT_INTERVAL 1000

void add_argument(const char *arg, char **args, int index) {
    args[index] = malloc((strlen(arg) + 1) * sizeof(char));
    strcpy(args[index], arg);
}

void free_parse_result(struct ParseResult *result) {
    for (int i = 0; i < result->args_length; i++) {
        free(result->args[i]);
    }

    free(result->args);
}

int get_interval(int argc, char **args) {
    int opt = getopt(argc, args, "n:");
    return opt == 'n' ? atoi(optarg) * 1000 : DEFAULT_INTERVAL;
}


struct ParseResult get_arguments(int argc, char **args) {
    struct ParseResult parse_result = {
        .interval = get_interval(argc, args),
        .args_length = 0,
        .args = malloc(ARGS_LIMIT * sizeof(char *)),
        .parse_failed = 0,
        .clear = 0
    };

    for (int i = 1; i < argc; i++) {
        const char *arg = args[i];

        if (strcmp(args[i], "-n") == 0 && i == 1) {
            continue;
        }

        if (isdigit(*arg) && strcmp(args[i - 1], "-n") == 0) {
            continue;
        }

        add_argument(arg, parse_result.args, parse_result.args_length++);
    }

    if (!parse_result.args_length) {
        parse_result.parse_failed = 1;
        parse_result.reason = "\n  <cmd> required\n\n";
        return parse_result;
    }

    return parse_result;
}

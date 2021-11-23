#include <stdlib.h>
#include <string.h>
#include "argument_parser.h"
#include "string_utils.h"
#include "watch_utils.h"

#define ARGS_LIMIT 4
#define DEFAULT_INTERVAL 2

void add_argument(const char *arg, char **args, int index) {
    args[index] = malloc((strlen(arg) + 1) * sizeof(char));
    strcpy(args[index], arg);
}

void free_parse_result(struct ParseResult *result) {
    for (int i = 0; i < result->args_length; i++) {
        free(result->args[i]);
    }

    free(result->args);
    free(result->reason);
}

struct ParseResult parse_arguments(int argc, const char **argv) {
    struct ParseResult parse_result = {
        .interval = DEFAULT_INTERVAL,
        .args_length = 0,
        .args = malloc(ARGS_LIMIT * sizeof(char *))
    };

    int interpret_flag = 1;

    for (int i = 1; i < argc; i++) {
        const char *arg = argv[i];

        if (!interpret_flag) {
            goto add_arg;
        }

        if (contains_short_argument("-n", arg)) {
            if (argc - 1 == i) {
                parse_result.parse_failed = 1;
                parse_result.reason = "\n  --interval requires an argument\n\n";
                return parse_result;
            }

            arg = argv[++i];
            parse_result.interval = string_to_milliseconds(arg);
            continue;
        }

        add_arg:
        add_argument(arg, parse_result.args, parse_result.args_length++);
        interpret_flag = 0;
    }

    if (!parse_result.args_length) {
        parse_result.parse_failed = 1;
        parse_result.reason = "\n  <cmd> required\n\n";
        return parse_result;
    }

    parse_result.parse_failed = 0;
    return parse_result;
}

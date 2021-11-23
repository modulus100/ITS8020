#pragma once

struct ParseResult {
    long interval;
    char **args;
    int args_length;
    int parse_failed;
    char *reason;
};

/**
 * Default interval is 2
 * @param argc from main
 * @param argv from main
 * @return parse result with props
 */
struct ParseResult parse_arguments(int argc, const char **argv);

void free_parse_result(struct ParseResult *result);

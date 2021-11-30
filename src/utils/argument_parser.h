#pragma once

struct ParseResult {
    long interval;
    char **args;
    int args_length;
    int parse_failed;
    char *reason;
    int clear;
};

/**
 * Default interval is 2
 * @param argc from main
 * @param argv from main
 * @return parse result with props
 */
struct ParseResult get_arguments(int argc, char **argv);

void free_parse_result(struct ParseResult *result);

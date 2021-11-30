#pragma once

/**
 *
 * @return info about command usage
 */
const char *get_usage();

int contains_argument(const char *, const char *, const char *);

void handle_error(char *, struct ParseResult *);

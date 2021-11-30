#pragma once

/**
 *
 * @return info about command usage
 */
const char *get_usage();

int contains_argument(const char *short_argument, const char *long_argument, const char *actual_argument);

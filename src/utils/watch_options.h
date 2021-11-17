#pragma once

/*
 * Returns info about command usage
 */
const char *get_usage();

int contains_option(const char *short_option, const char *long_option, const char *actual_option);

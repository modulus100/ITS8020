#pragma once

int length(char **strings);

char *join(char **strings, int len, char *separator);

long string_to_milliseconds(const char *str);
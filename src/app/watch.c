#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
//#include <unistd.h>
//#include <time.h>
//#include <fcntl.h>
//#include <sys/wait.h>
//#include "ms/ms.h"
#include "../utils/watch_options.h"

#define VERSION "0.0.1"

int main(int argc, const char **argv) {
    if (argc == 1 || argc == 0) {
        printf("%s", get_usage());
//        printf(" %f", add_numbers(1, 3));
        exit(1);
    }
    return 0;
}
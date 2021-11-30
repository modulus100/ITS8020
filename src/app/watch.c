#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <utils/argument_parser.h>
#include "utils/watch_utils.h"

#define VERSION "0.0.1"
#define ARGS_LIMIT 4

void clear();
void print_usage_and_exit();
void check_simple_args(int, char **);
_Noreturn void execute_watch(struct ParseResult *);

static void signal_handler() {
    fflush(stdout);
    exit(1);
}

int main(int argc, char **args) {
    if (argc == 1) {
        print_usage_and_exit();
    }

    struct sigaction psa;
    psa.sa_handler = signal_handler;
    sigaction(SIGTERM, &psa, NULL);

    check_simple_args(argc, args);
    struct ParseResult parsed_result = get_arguments(argc, args);

    if (parsed_result.parse_failed) {
        fprintf(stderr, "%s", parsed_result.reason);
        free_parse_result(&parsed_result);
        exit(1);
    }

    execute_watch(&parsed_result);
}

_Noreturn void execute_watch(struct ParseResult *parse_result) {
    while (1) {
        int status;
        pid_t pid = fork();

        switch (pid) {
            case -1:
                handle_error("fork failed", parse_result);
            case 0:
                if (execvp(parse_result->args[0], parse_result->args) == -1) {
                    handle_error("execvp failed, bad arguments", parse_result);
                }
            default:
                if (waitpid(pid, &status, 0) == -1) {
                    handle_error("waitpid failed", parse_result);
                }

                if (WEXITSTATUS(status)) {
                    fprintf(stderr, "\033[90mexit: %d\33[0m\n\n", WEXITSTATUS(status));
                    handle_error("", parse_result);
                }

                sleep(parse_result->interval);
                clear();
        }
    }
}

void check_simple_args(int argc, char **argv) {
    if (argc < 2) {
        return;
    }
    if (contains_argument("-h", "--help", argv[1])) {
        print_usage_and_exit();
    }

    if (contains_argument("-v", "--version", argv[1])) {
        printf("%s\n", VERSION);
        exit(1);
    }
}

void print_usage_and_exit() {
    printf("%s", get_usage());
    exit(1);
}

void clear() {
    fprintf(stdout, "\033[2J");
    fprintf(stdout, "\033[1;1H");
    fflush(stdout);
}

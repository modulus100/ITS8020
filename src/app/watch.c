#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <utils/argument_parser.h>
#include "utils/watch_utils.h"
#include "utils/string_utils.h"

#define VERSION "0.0.1"
#define ARGS_LIMIT 4

void print_usage_and_exit();
void check_simple_args(int argc, const char **argv);
void execute_watch(long interval, char *command_args[4]);

static void signal_handler() {
    fflush(stdout);
    exit(1);
}

int main(int argc, const char **args) {
    if (argc == 1) {
        print_usage_and_exit();
    }

    struct sigaction psa;
    psa.sa_handler = signal_handler;
    sigaction(SIGTERM, &psa, NULL);

    check_simple_args(argc, args);
    struct ParseResult parsed_result = parse_arguments(argc, args);

    if (parsed_result.parse_failed) {
        fprintf(stderr, "%s", parsed_result.reason);
        free_parse_result(&parsed_result);
        exit(1);
    }

    char *arguments = join(parsed_result.args, parsed_result.args_length, " ");
    char *cmd[4] = {"sh", "-c", arguments, 0};

    free_parse_result(&parsed_result);
    execute_watch(parsed_result.interval, cmd);

    return 0;
}

void execute_watch(long interval, char *command_args[4]) {
    while (1) {
        int status;
        pid_t pid = fork();

        switch (pid) {
            case -1:
                perror("fork failed");
                exit(1);
            case 0:
                execvp(command_args[0], command_args);
            default:
                if (waitpid(pid, &status, 0) < 0) {
                    perror("waitpid failed");
                    exit(1);
                }

                if (WEXITSTATUS(status)) {
                    fprintf(stderr, "\033[90mexit: %d\33[0m\n\n", WEXITSTATUS(status));
                }

                thread_sleep(interval);
        }
    }
}

void check_simple_args(int argc, const char **argv) {
    for (int i = 1; i < argc; i++) {
        const char *arg = argv[i];

        if (contains_argument("-h", "--help", arg)) {
            print_usage_and_exit();
        }

        if (contains_argument("-v", "--version", arg)) {
            printf("%s\n", VERSION);
            exit(1);
        }
    }
}

void print_usage_and_exit() {
    printf("%s", get_usage());
    exit(1);
}
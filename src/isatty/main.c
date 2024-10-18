#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
* Examples:
*   ./hello-isatty will print "Output is a tty"
*   ./hello-isatty | cat will print "Output is NOT a tty (was probably piped)"
*/
int main() {

    int fd = STDOUT_FILENO;

    int is_a_tty = isatty(fd);
    int errsv = errno;

    if (!is_a_tty) {

        if (errsv == ENOTTY) {
            printf("Output is NOT a tty (was probably piped).\n");
            return 0;
        }

        if (errsv == EBADF) {
            fprintf(stderr, "Error %d: %d not a valid file descriptor\n", errsv, fd);
            exit(EXIT_FAILURE);
        }

        fprintf(stderr, "Something went wrong: errno %d)\n", errsv);
        exit(EXIT_FAILURE);
    }

    printf("Output is a tty.\n");
    return 0;
}
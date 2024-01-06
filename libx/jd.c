// jd.c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "jd.h"

int jd_func(const char *path) {
    if (chdir(path) != 0) {
        perror("Error al cambiar de directorio");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

// libx/ll.c
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

#include "ll.h"
#include "jd.h"

void ll_func() {
    // Lógica de 'll'
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");
    if (dir == NULL) {
        perror("Error al abrir el directorio");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
}

void jd_func_wrapper(const char *path) {
    // Lógica de 'jd'
    if (jd_func(path) != EXIT_SUCCESS) {
        fprintf(stderr, "Error al cambiar de directorio\n");
    }
}

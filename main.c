// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dlfcn.h>
#include "libx/ll.h"
#include "libx/jd.h"
#include "libx/call.h"

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 100

void read_input(char *input) {
    printf("J/β-> ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Elimina el salto de línea final si está presente
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
}

void parse_input(char *input, char **tokens, int *token_count) {
    char *token = strtok(input, " ");
    *token_count = 0;

    while (token != NULL && *token_count < MAX_TOKENS) {
        tokens[(*token_count)++] = token;
        token = strtok(NULL, " ");
    }
}

void execute_command(char **tokens) {
    if (strcmp(tokens[0], "ll") == 0) {
        ll_func();
    } else if (strcmp(tokens[0], "jd") == 0) {
        if (tokens[1] != NULL) {
            jd_func_wrapper(tokens[1]);
        } else {
            fprintf(stderr, "Uso: jd <directorio>\n");
        }
    } else if (strcmp(tokens[0], "call") == 0) {
        call_func(tokens);
    } else if (strcmp(tokens[0], "clean") == 0) {
        system("clear");
    } else if (strcmp(tokens[0], "otro_comando") == 0) {
        // Implementa la lógica para otro comando personalizado
        printf("Ejecutando otro comando (implementa tu lógica aquí)\n");
    } else {
        pid_t pid = fork();

        if (pid == -1) {
            perror("Error al hacer fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Proceso hijo
            if (execvp(tokens[0], tokens) == -1) {
                perror("Error al ejecutar el comando");
                exit(EXIT_FAILURE);
            }
        } else {
            // Proceso padre
            wait(NULL);
        }
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *tokens[MAX_TOKENS];
    int token_count;

    while (1) {
        read_input(input);

        if (strcmp(input, "exit") == 0) {
            break; // Salir del bucle si se ingresa "exit"
        }

        parse_input(input, tokens, &token_count);

        if (token_count > 0) {
            execute_command(tokens);
        }
    }

    return 0;
}

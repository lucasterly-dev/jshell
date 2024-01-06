// libx/call.c
#include <stdio.h>
#include "call.h"

void call_func(char **tokens) {
    int i = 1;
    while (tokens[i] != NULL) {
        printf("%s ", tokens[i]);
        i++;
    }
    printf("\n");
}

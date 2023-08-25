#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[]) {
    char *content = NULL;
    FILE *file;
    size_t size = 0;
    ssize_t read_line = 0;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    bus.file = file;
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read_line = (ssize_t)fgets(content, (int)size, file)) != -1) {
        bus.content = content;
        counter++;
        
        /* Remove the newline character from the end of the line */
        content[strlen(content) - 1] = '\0';

        if (read_line > 0) {
            execute(content, &stack, counter, file);
        }
    }

    free_stack(stack);
    fclose(file);
    return 0;
}


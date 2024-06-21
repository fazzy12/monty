#include "monty.h"

/**
 * main - Entry point for the Monty bytecode interpreter
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = _getline(&line, &len, file)) != -1)
    {
        line_number++;
        execute_opcode(&stack, line, line_number);
    }

    free(line);
    fclose(file);
    free_stack(stack);
    return (EXIT_SUCCESS);
}

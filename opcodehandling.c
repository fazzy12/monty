#include "monty.h"

/**
 * execute_opcode - Executes the opcode
 * @stack: Pointer to the stack
 * @line: The line of input
 * @line_number: The line number
 */
void execute_opcode(stack_t **stack, char *line, unsigned int line_number)
{
    char *opcode;
    char *arg;

    opcode = strtok(line, " \n");
    arg = strtok(NULL, " \n");

    if (opcode == NULL)
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }

    if (strcmp(opcode, "push") == 0)
    {
        if (arg == NULL || !isdigit(arg[0]))
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
        push(stack, line_number, arg);
    }
    else if (strcmp(opcode, "pall") == 0)
    {
        pall(stack, line_number);
    }
    else if (strcmp(opcode, "pint") == 0)
    {
        pint(stack, line_number);
    }
    else if (strcmp(opcode, "pop") == 0)
    {
        pop(stack, line_number);
    }
    else if (strcmp(opcode, "swap") == 0)
    {
        swap(stack, line_number);
    }
    else if (strcmp(opcode, "add") == 0)
    {
        add(stack, line_number);
    }
    else if (strcmp(opcode, "nop") == 0)
    {
        nop(stack, line_number);
    }
    else if (strcmp(opcode, "sub") == 0)
    {
        sub(stack, line_number);
    }
    else if (strcmp(opcode, "div") == 0)
    {
        _div(stack, line_number);
    }
    else if (strcmp(opcode, "mul") == 0)
    {
        mul(stack, line_number);
    }
    else
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}

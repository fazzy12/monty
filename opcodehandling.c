#include "monty.h"

int current_mode = STACK_MODE;

/**
 * execute_opcode - Executes the opcode
 * @stack: Pointer to the stack
 * @line: The line of input
 * @line_number: The line number
 *
 * Description:
 * - Tokenizes the input line to extract opcode and argument.
 * - If the line starts with '#',
 *              treats it as a comment and skips further processing.
 * - Executes the corresponding opcode function based on the tokenized opcode.
 * - If opcode is unknown, prints an error message
 *               "L<line_number>: unknown instruction <opcode>"
 *   and exits with EXIT_FAILURE.
 */
void execute_opcode(stack_t **stack, char *line, unsigned int line_number)
{
    char *opcode;
    char *arg;

    if (line[0] == '#')
        return;

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
    else if (strcmp(opcode, "mod") == 0)
    {
        mod(stack, line_number);
    }
    else if (strcmp(opcode, "nop") == 0)
    {
        nop(stack, line_number);
    }
    else if (strcmp(opcode, "pchar") == 0)
    {
        pchar(stack, line_number);
    }
    else if (strcmp(opcode, "pstr") == 0)
    {
        pstr(stack, line_number);
    }
    else if (strcmp(opcode, "rotl") == 0)
    {
        rotl(stack, line_number);
    }
    else if (strcmp(opcode, "rotr") == 0)
    {
        rotr(stack, line_number);
    }
    else if (strcmp(opcode, "stack") == 0)
    {
        stack_mode(stack, line_number);
    }
    else if (strcmp(opcode, "queue") == 0)
    {
        queue_mode(stack, line_number);
    }
    else
    {
        fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
        exit(EXIT_FAILURE);
    }
}

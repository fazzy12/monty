#include "monty.h"


/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the current operation
 */
void add(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    (*stack)->next->n += (*stack)->n;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    free(temp);
}

/**
 * nop - does nothing
 * @stack: pointer to the stack
 * @line_number: line number of the current operation
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

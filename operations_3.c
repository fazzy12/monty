#include "monty.h"


/**
 * mod - Computes the rest of division of the second top element by the top element
 * @stack: Pointer to the stack
 * @line_number: Line number in the bytecode file
 *
 * Description:
 * - If the stack contains less than two elements, prints an error message
 *   "L<line_number>: can't mod, stack too short" and exits with EXIT_FAILURE.
 * - Computes the rest of division of the second top element by the top element of the stack.
 * - The result is stored in the second top element of the stack.
 * - The top element of the stack is removed.
 * - If the top element of the stack is 0, prints an error message
 *   "L<line_number>: division by zero" and exits with EXIT_FAILURE.
 */
void mod(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    (*stack)->next->n %= (*stack)->n;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    free(temp);
}

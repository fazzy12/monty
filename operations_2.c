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

/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: pointer to the stack
 * @line_number: line number of the current operation
 */
void sub(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    (*stack)->next->n -= (*stack)->n;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    free(temp);
}

/**
 * _div - divides the second top element by the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the current operation
 */
void _div(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    (*stack)->next->n /= (*stack)->n;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    free(temp);
}

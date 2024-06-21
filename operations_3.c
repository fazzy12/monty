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

/**
 * pchar - Prints the character at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the current operation
 *
 * Description:
 * - Checks if the stack is empty. If empty, prints an error message and exits with EXIT_FAILURE.
 * - Retrieves the top element of the stack, treated as an ASCII value.
 * - Checks if the value is within the valid ASCII range (0-127). If not, prints an error message
 *   and exits with EXIT_FAILURE.
 * - Prints the corresponding character followed by a newline.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    int ascii_value;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    ascii_value = (*stack)->n;

    if (ascii_value < 0 || ascii_value > 127)
    {
        fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", ascii_value);
}

/**
 * pstr - prints the string starting from the top of the stack
 * @stack: pointer to the head of the stack
 * @line_number: current line number (unused)
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current != NULL && current->n != 0 &&
            current->n >= 0 && current->n <= 127)
    {
        putchar(current->n);
        current = current->next;
    }
    putchar('\n');
}

/**
 * rotl - Rotates the stack to the top
 * @stack: Double pointer to the stack
 * @line_number: Line number being executed
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *temp, *last;

    (void)line_number;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    temp = *stack;
    last = *stack;

    while (last->next != NULL)
        last = last->next;

    *stack = temp->next;
    (*stack)->prev = NULL;
    last->next = temp;
    temp->prev = last;
    temp->next = NULL;
}

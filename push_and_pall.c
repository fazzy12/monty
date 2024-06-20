#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: Pointer to the stack
 * @line_number: The line number
 * @arg: The argument
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    (void)line_number;
    new_node->n = atoi(arg);
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * pall - Prints all the values on the stack, starting from the top
 * @stack: Pointer to the stack
 * @line_number: The line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

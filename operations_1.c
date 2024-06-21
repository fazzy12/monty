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

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the current operation
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the current operation
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;

    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number of the current operation
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;

    if (stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}

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

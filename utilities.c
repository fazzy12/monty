#include "monty.h"

/**
 * _allocate_buffer - Allocates initial buffer for line storage.
 * @lineptr: Pointer to the line buffer to store input.
 * @n: Pointer to the size of the allocated buffer.
 *
 * Return: Pointer to the allocated buffer, or NULL if allocation fails.
 */
char *_allocate_buffer(char **lineptr, size_t *n)
{
    *n = 128;
    *lineptr = malloc(*n);
    if (*lineptr == NULL)
        return (NULL);
    return (*lineptr);
}

/**
 * _reallocate_buffer - Reallocates buffer for additional memory.
 * @buf: Pointer to the current buffer.
 * @n: Pointer to the size of the allocated buffer.
 *
 * Return: Pointer to the reallocated buffer, or NULL if allocation fails.
 */
char *_reallocate_buffer(char *buf, size_t *n)
{
    size_t new_size = *n * 2;
    char *new_buf = realloc(buf, new_size);
    if (new_buf == NULL)
        return (NULL);
    *n = new_size;
    return (new_buf);
}

/**
 * _getline - Custom implementation of getline with dynamic buffer handling.
 * @lineptr: Pointer to the line buffer to store the input.
 * @n: Pointer to the size of the allocated buffer.
 * @stream: Pointer to the input stream.
 *
 * Return: Number of characters read, including the newline character,
 * or -1 if an error occurred or end of file is reached.
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
    int c;
    size_t len = 0;
    char *buf;

    if (lineptr == NULL || n == NULL || stream == NULL)
        return (-1);

    if (*lineptr == NULL)
    {
        if (_allocate_buffer(lineptr, n) == NULL)
            return (-1);
    }

    buf = *lineptr;

    while ((c = fgetc(stream)) != EOF)
    {
        if (len + 1 >= *n)
        {
            char *new_buf = _reallocate_buffer(buf, n);
            if (new_buf == NULL)
                return (-1);
            buf = new_buf;
            *lineptr = new_buf;
        }
        buf[len++] = c;
        if (c == '\n')
            break;
    }

    if (len == 0)
        return (-1);

    buf[len] = '\0';
    return (len);
}

/**
 * stack_mode - Sets the mode of the data to stack (LIFO)
 * @stack: Pointer to the stack
 * @line_number: Line number being executed
 *
 * Description:
 * - Sets the mode of the data to stack (LIFO).
 */
void stack_mode(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    current_mode = STACK_MODE;
}

/**
 * queue_mode - Sets the mode of the data to queue (FIFO)
 * @stack: Pointer to the stack
 * @line_number: Line number being executed
 *
 * Description:
 * - Sets the mode of the data to queue (FIFO).
 */
void queue_mode(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    current_mode = QUEUE_MODE;
}

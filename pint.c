#include "monty.h"
/**
 * zd_pint - .
 * @stack: .
 * @line_number: .
 * Return: .
 */
void zd_pint(stack_t **stack, unsigned int line_number)
{
if ((*stack) == NULL)
{
free_stack(stack);
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
fclose(y.file);
exit(EXIT_FAILURE);
}
printf("%d\n", (*stack)->n);
}

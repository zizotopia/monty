#include "monty.h"
val_t y;
/**
 * run - rum profram
 * @stack: stack list
 * @filename: file name
 * Return: void
 */

void run(stack_t **stack, char *filename)
{
char line[100];
char *line_copy, *_opcode;
int i, check;
unsigned int count = 0;

instruction_t operators_code[] = {{"push", zd_push},
{"pall", zd_pall},
{"pint", zd_pint},
{"pop", zd_pop},
{"swap", zd_swap},
{"add", zd_add},
{"nop", zd_nop},
{"sub", zd_sub},
{"div", zd_div},
{"mul", zd_mul},
{"mod", zd_mod},
{"pchar", zd_pchar},
{"pstr", zd_pstr},
{"rotl", zd_rotl}};

y.file = fopen(filename, "r");
if (y.file == NULL)
fileError(filename);
while (fgets(line, sizeof(line), y.file) != NULL)
{
count++;
line_copy = strcat(line, "\0");
_opcode = strtok(line_copy, " ,\n");
if (_opcode == NULL || _opcode[0] == '#')
continue;
i = find_opcode(_opcode, operators_code);
if (i >= 0)
operators_code[i].f(stack, count);
else
instructError(count, _opcode);
}
check = fclose(y.file);
if (check == -1)
exit(-1);
}

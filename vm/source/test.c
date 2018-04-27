#include "corewar.h"

int main(void)
{
	char *name;
	char *last_name;

	ft_printf("write name      -> ");
	get_next_line(0, &name);
	ft_printf("write last name -> ");
	get_next_line(0, &last_name);

	ft_putchar('\n');
	ft_printf("name is           :%s\n", name);
	ft_printf("last name is      :%s\n", last_name);
	ft_putchar('\n');

	free(name);
	free(last_name);
	system("leaks -quiet a.out");
	return (0);
}

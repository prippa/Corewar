#include "corewar.h"

int main(void)
{
	srand(time(NULL));

	int i = 0;
	int main = 0;
	int back = 0;

	while (i < 100)
	{
		ft_printf("%[*]{*}s\n", main, back, "Hello world");
		main = (rand() % 2147483647 + 1);
		back = (rand() % 2147483647 + 1);
		i++;
	}
    return (0);
}

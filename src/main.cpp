#include "Command.hpp"

int main(int ac, char **av)
{
	Command terminal(av);
	if (ac < 2)
		return 84;
	terminal.display();
	terminal.select();
	return (0);
}

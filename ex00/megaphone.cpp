#include <iostream>

int main(int ac, char **av)
{
	std::cout << "\x1b[1m";
	if (ac == 1) return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	for (int i = 1; i < ac; i++) for (char *p = av[i]; *p; p++) std::cout << (char)std::toupper(*p);
	return (std::cout << "\x1b[0m" << std::endl, 0);
}
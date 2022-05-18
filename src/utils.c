#include "../include/philo.h"

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	long int	res;
	int			num;

	res = 0;
	num = 1;
	while (('\t' <= *str && *str <= '\r') || (*str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			num *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
		if (res > (long int)INT_MIN * -1 && num == -1)
			return (0);
		if (res > INT_MAX && num == 1)
			return (-1);
	}
	return ((int)res * num);
}

bool	check(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < 0)
		{
			printf(RED"Illegal value\n");
			return (false);
		}
		i++;
	}
	return (true);
}

void	print_help(void)
{
	printf(CYAN"Usage: [number of philosophers] ");
	printf(CYAN"[time to die] [time to eat] [time to sleep] ");
	printf(CYAN"[number of meals a philosopher has to eat]\n");
}

bool	ft_isnum(int size, char **s)
{
	int	i;

	while (size > 0)
	{
		i = 0;
		while (s[size][i] >= '0' && s[size][i] <= '9')
			i++;
		if (s[size][i] != '\0')
			return (false);
		size--;
	}
	return (true);
}
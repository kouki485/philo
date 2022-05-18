#include "../include/philo.h"

static bool	init_philos(t_data *data)
{
	size_t	i;

	data->philos = malloc(sizeof(t_philo *) * data->number_of_philo);//error handling
	if (!data->philos)
		return (false);
	i = 0;
	while (i < data->number_of_philo)
	{
		data->philos[i] = malloc(sizeof(t_philo));//error handling
		if (!data->philos[i])
		{
			printf(RED"malloc error\n");
			return (false);
		}
		data->philos[i]->has_fork_right = false;
		data->philos[i]->has_fork_left = false;
		data->philos[i]->eat_count = 0;
		data->philos[i]->philo_number = i + 1;
		data->philos[i]->data = data;
		i++;
	}
	return (true);
}

static bool	init_monitors(t_data *data)
{
	size_t	i;

	data->monitors = malloc(sizeof(t_monitor *) * data->number_of_philo);//error handling
	if (!data->monitors)
		return (false);
	i = 0;
	while (i < data->number_of_philo)
	{
		data->monitors[i] = malloc(sizeof(t_monitor));
		if (!data->monitors[i])
			return (false);
		data->monitors[i]->monitor_number = i + 1;
		data->monitors[i]->data = data;
		data->monitors[i]->philo = data->philos[i];
		data->monitors[i]->is_reached_min_eat = 0;
		i++;
	}
	return (true);
}

static bool	init_forks(t_data *data)
{
	size_t	i;

	data->forks_mutex = malloc(sizeof(pthread_mutex_t) * data->number_of_philo);//error handling
	if (!data->forks_mutex)
		return (false);
	i = 0;
	while (i < data->number_of_philo)
	{
		pthread_mutex_init(&(data->forks_mutex[i]), NULL);
		i++;
	}
	return (true);
}

bool	init_data(t_data *data, int argc, char **argv)
{
	if (ft_atoi(argv[1]) > 200)
	{
		printf(RED"too many philosophers \n");
		return (false);
	}
	data->number_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->argc = argc;
	data->is_finished = 0;
	if (argc == 6)
		data->number_of_min_eat = ft_atoi(argv[5]);
	else
		data->number_of_min_eat = 0;
	pthread_mutex_init(&(data->shared_mutex), NULL);
	// init_philos(data);
	// init_forks(data);
	// init_monitors(data);
	if(!init_philos(data) || !init_forks(data) || !init_monitors(data))
	{
		printf(RED"malloc error\n");
		return (false);
	}
	return (true);
}
#include "../include/philo.h"

size_t	get_time_philo(t_philo *philo)
{
	struct timeval	tv;
	size_t			time;


	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) - philo->start_time;
	return (time);
}

int	print_action(t_philo *philo, char *message)
{
	char *s[4];
	s[0] ="has taken a fork";
	s[1] ="is sleeping";
	s[2] ="is thinking";
	s[3] ="is die";
	if (philo->data->is_finished == 1)
		return (1);
	pthread_mutex_lock(&(philo->data->shared_mutex));
	if (message == s[0])
		printf("\x1b[33m%8zu: \x1b[37m%zu \x1b[36m%s\n",get_time_philo(philo), philo->philo_number, message);
	if (message == s[1])
		printf("\x1b[33m%8zu: \x1b[37m%zu \x1b[35m%s\n",get_time_philo(philo), philo->philo_number, message);
	if (message == s[2])
		printf("\x1b[33m%8zu: \x1b[37m%zu \x1b[32m%s\n",get_time_philo(philo), philo->philo_number, message);
	if (message == s[3])
		printf("\x1b[33m%8zu: \x1b[37m%zu \x1b[31m%s\n",get_time_philo(philo), philo->philo_number, message);
	pthread_mutex_unlock(&(philo->data->shared_mutex));
	return (0);
}
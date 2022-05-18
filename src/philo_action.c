#include "../include/philo.h"

int 	philo_eat(t_philo *philo)
{
	if (philo->data->is_finished == 1)
		return (1);
	if (philo->has_fork_right == 1 && philo->has_fork_left == 1)
	{
		if (print_action(philo, "is eating") == 1)
			return (1);
		philo->last_eat_time = get_time_philo(philo);
		if (time_keeper_philo(philo, philo->data->time_to_eat) == 1)
			return (1);
		if (philo->philo_number != philo->data->number_of_philo)
		{
			pthread_mutex_unlock(&(philo->data->forks_mutex[philo->philo_number - 1]));
			pthread_mutex_unlock(&(philo->data->forks_mutex[philo->philo_number]));
			philo->has_fork_left = 0;
			philo->has_fork_right = 0;
			philo->eat_count++;
		}
		else
		{
			pthread_mutex_unlock(&(philo->data->forks_mutex[philo->philo_number - 1]));
			pthread_mutex_unlock(&(philo->data->forks_mutex[0]));
			philo->has_fork_left = 0;
			philo->has_fork_right = 0;
			philo->eat_count++;
		}
	}
	return (0);
}

int 	philo_sleep(t_philo *philo)
{
	if (philo->data->is_finished == 1)
		return (1);
	if (print_action(philo, "is sleeping") == 1)
		return (1);
	if (time_keeper_philo(philo, philo->data->time_to_sleep) == 1)
		return (1);
	return (0);
}
int 	philo_think(t_philo *philo)
{
	if (philo->data->is_finished == 1)
		return (1);
	if (print_action(philo,"is thinking") == 1)
		return (1);
	return (0);
}
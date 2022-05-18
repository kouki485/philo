#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "unistd.h"
# include "sys/time.h"
# include "unistd.h"
# include "stdlib.h"
# include "stdbool.h"
# include "pthread.h"
# include "limits.h"
# include "string.h"

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define RESET "\x1b[0m"

typedef struct s_data t_data;

typedef struct s_philo
{
	bool		has_fork_right;
	bool		has_fork_left;
	size_t		eat_count;
	size_t		philo_number;
	size_t		last_eat_time;
	pthread_t	thread_philo;
	t_data		*data;
	size_t		start_time;
}	t_philo;

typedef struct s_monitor
{
	size_t		monitor_number;
	bool		is_reached_min_eat;
	pthread_t	thread_monitor;
	t_data		*data;
	t_philo		*philo;
}	t_monitor;

typedef struct s_data
{
	size_t			number_of_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			number_of_min_eat;
	bool			is_finished;
	t_philo			**philos;
	t_monitor		**monitors;
	pthread_mutex_t	shared_mutex;
	pthread_mutex_t	*forks_mutex;
	int				argc;
}	t_data;

//init.c
bool	init_data(t_data *data, int argc, char **argv);
void	create_thread(t_data *data);
void	join_thread(t_data *data);
size_t	get_time(t_data *data);
//fork.c
int		pickup_fork(t_philo *philo);
void	put_down_fork(t_philo *philo);

int		time_keeper(t_data *data, size_t time);
//philo_action.c
int		philo_sleep(t_philo *philo);
int		philo_think(t_philo *philo);
int		philo_eat(t_philo *philo);
int		time_keeper_philo(t_philo *philo, size_t time);
//monitor.c
void	*monitor_routine(void *ptr);
void	terminate_program(t_data *data);
//print_action.c
size_t	get_time_philo(t_philo *philo);
int		print_action(t_philo *philo, char *message);
//utils.c
int		ft_atoi(const char *str);
bool	check(int argc, char **argv);
void	print_help(void);
bool	ft_isnum(int size, char **s);

#endif
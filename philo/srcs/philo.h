/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:20:22 by memahote          #+#    #+#             */
/*   Updated: 2023/10/27 20:20:22 by memahote         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <limits.h>
# include <sys/time.h>

// # define INT_MAX 2147483647
# define NB_ARGS "ERROR: The number of argments must be 4 or 5"
# define ARG1 "ERROR: There is a mistake in number of philosophers"
# define ARG2 "ERROR: There is a mistake in time to die"
# define ARG3 "ERROR: There is a mistake in time to eat"
# define ARG4 "ERROR: There is a mistake in time to sleep"
# define ARG5 "ERROR: There is a mistake in number of times each \
philosopher must eat"

typedef struct s_mutex
{
    int             dead_status;
    pthread_mutex_t writing;
    pthread_mutex_t dead_m;
    pthread_mutex_t meal_m;
}       t_mutex;

typedef struct s_philo
{
    int id;
    int nb_philo;
    int t_to_die;
    int t_to_eat;
    int t_to_sleep;
    int nb_meal;
    int meal_count;
    int *dead;
    size_t time_start;
    size_t last_meal;
    pthread_t thread;
    pthread_mutex_t *fork_l;
    pthread_mutex_t *fork_r;
    pthread_mutex_t *writing;
    pthread_mutex_t *dead_m;
    pthread_mutex_t *meal_m;
}       t_philo;

//parse
int check_args(int ac, char **av);

//Init
void    init_data(t_philo *philos, pthread_mutex_t *forks, t_mutex *mutex, char **av);
void    init_mutex(char **av, pthread_mutex_t *forks, t_mutex *mutex);

// Utils
int	philo_atoi(char *str);
int get_time(void);
int philo_starving(t_philo *philo);

//action
void    philo_eat(t_philo *philo);
void    philo_sleep(t_philo *philo);
void    philo_think(t_philo *philo);

void	*host(void *pointer);
void	print_message(char *message, t_philo *philos, int id);

int	dead_loop(t_philo *philo);
void    *routine(void *arg);
int parse(int ac, char **av);

#endif
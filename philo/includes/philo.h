/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memahote <memahote@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:30:12 by memahote          #+#    #+#             */
/*   Updated: 2023/10/13 20:30:12 by memahote         ###   ########lyon.fr   */
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

typedef struct s_philo
{
    pthread_t p_id;
    pthread_t dead;
    pthread_t eat;
    int id_philo;
    int nb_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nb_time_to_eat;
    int time_start;
    pthread_mutex_t *fork_l;
    pthread_mutex_t *fork_r;

}t_philo;


int	ft_atoi(const char *str);
void init_data(t_philo *philos, pthread_mutex_t *forks, char **argv);
void    init_forks(char **argv, pthread_mutex_t *forks);
int check_args(char **argv);
int	ft_strlen(char *str);
long get_time(void);
void	ft_putstr_fd(char *s, int fd);
int check_args_are_positive(char **argv);
int check_args_are_numbers(char **argv);

#endif
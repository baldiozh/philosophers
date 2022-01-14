/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:56:26 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/14 16:10:48 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

# define ERR_ARG	"\x1b[0;31mNumber of philosophers, tdeath, teat, tsleep.\n"
# define ERR_MEMORY	"\x1b[0;31mMemory allocation error.\n"
# define SLEEP 		"is sleeping"
# define THINK		"is thinking"
# define TAKE_FORK	"has taken fork"
# define EAT		"is eating"
# define DIED		"died\n"
# define TAKE 9
# define PUT 10

typedef struct s_data
{
	int					philo_num;
	int					tdeath;
	int					teat;
	int					tsleep;
	int					meals_num;
	long long int		prog_start;
	int					stop;
	struct s_philarg	*philo;
}			t_data;

typedef struct s_philarg
{
	int						id;
	int						meals;
	long long int			last_meal;
	int						left_fork;
	int						right_fork;
	t_data					*data;

}			t_philarg;

/* init */
void	init(int argc, char **argv, t_data *data);
void	init_data(int argc, char **argv, t_data *data);
void	init_philarg(t_data *data);

/* libft */
int		ft_atoi(const char *str);
void	ft_putstr(char *str);

/* utils */


/* actions */


/* let's go */


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:10:17 by gmckinle          #+#    #+#             */
/*   Updated: 2021/12/13 20:57:33 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_philo
{
	int	num;
	int	tdeath;
	int	teat;
	int	tsleep;

}			t_philo;

typedef struct s_ptread
{
	ptread t1;
	
}

/* init */
t_philo	*init_philo(char **argv);

/* utils */
int	ft_atoi(const char *str);

#endif


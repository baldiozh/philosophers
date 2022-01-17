/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:14:58 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/17 16:10:07 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	terminate(t_data *data)
{
	sem_close(data->forks);
	sem_unlink(FORKS);
	sem_close(data->speaklock);
	sem_unlink(SPEAKLOCK);
}

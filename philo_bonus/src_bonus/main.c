/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:55:30 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/15 18:49:30 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
		error(ERR_ARG);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		error(ERR_MEMORY);
	init_data(argc, argv, data);
	start_process(data);

}

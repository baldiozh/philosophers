/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:13:51 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/14 20:14:23 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

static int	ft_sign(const char *str, int sign, int i)
{
	if (str[i] == '-')
	{
		sign = (-1);
		i++;
		return (sign);
	}
	else if (str[i] == '+' && sign != (-1))
	{
		sign = 1;
		i++;
		return (sign);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = ft_sign(str, sign, i);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res > INT_MAX && sign == 1)
		return (-1);
	if (res > 2147483648 && sign == -1)
		return (0);
	return (res * sign);
}

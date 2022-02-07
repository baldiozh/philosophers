/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:36:32 by gmckinle          #+#    #+#             */
/*   Updated: 2022/02/07 17:34:06 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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
	long long		res;
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
	// if (str[i])
	// 	return(0);
	if ((res > INT_MAX && sign == 1 ) || str[i] != '\0')
		return (-1);
	if (res > (long long)INT_MAX + 1 && sign == -1)
		return (0);
	return (res * sign);
}

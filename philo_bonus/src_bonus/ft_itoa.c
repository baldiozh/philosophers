/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:13:01 by gmckinle          #+#    #+#             */
/*   Updated: 2022/01/15 20:16:15 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmckinle <gmckinle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:27:16 by gmckinle          #+#    #+#             */
/*   Updated: 2021/11/29 17:27:17 by gmckinle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static int	ft_des(int n)
{
	int	des;

	des = 1;
	while (n / 10)
	{
		n /= 10;
		des *= 10;
	}
	return (des);
}

static int	ft_count(int n)
{
	int	len;

	len = 0;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

static char	ft_big(char *str, int n, int len, int i)
{
	int	des;

	des = ft_des(n);
	while (i != len)
	{
		str[i++] = (n / des) + '0';
		n = n % des;
		des /= 10;
	}
	str[i] = '\0';
	return (*str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_count(n);
	if (n < 0)
		len += 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		str[i++] = '-';
	}
	if (n > 47 && n < 58)
	{
		str[i] = n + '0';
		str[i + 1] = '\0';
	}
	ft_big(str, n, len, i);
	return (str);
}

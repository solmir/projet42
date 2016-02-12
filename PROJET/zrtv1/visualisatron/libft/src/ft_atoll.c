/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alelievr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:13:59 by alelievr          #+#    #+#             */
/*   Updated: 2016/01/09 12:08:06 by alelievr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

long long int	ft_atoll(const char *str)
{
	char	sign;
	int64_t	result;

	result = 0;
	while ((*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
				|| *str == '\v' || *str == '\f') && !((result = 0)))
		str++;
	sign = (*str == '-') ? -1 : 1;
	str = (*str == '+' || *str == '-') ? str + 1 : str;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + *str++ - '0';
	result *= sign;
	return ((long long int)result);
}

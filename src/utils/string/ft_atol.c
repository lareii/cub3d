/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebabaogl <ebabaogl@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 20:48:03 by ahekinci          #+#    #+#             */
/*   Updated: 2025/06/26 11:41:31 by ebabaogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	skip_whitespace(const char *c)
{
	int	i;

	i = 0;
	while (c[i] == ' ' || (c[i] >= 9 && c[i] <= 13))
		i++;
	return (i);
}

static int	determine_sign(const char *c, int *i)
{
	int	sign;

	sign = 1;
	if (c[*i] == '-' || c[*i] == '+')
	{
		if (c[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

long	ft_atol(const char *str, int *err)
{
	long	total;
	int		sign;
	int		i;
	int		digit;

	total = 0;
	i = skip_whitespace(str);
	sign = determine_sign(str, &i);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		digit = str[i] - '0';
		if ((sign == 1 && total > (LONG_MAX - digit) / 10)
			|| (sign == -1 && (unsigned long)total
				> ((unsigned long)LONG_MAX + 1UL - digit) / 10))
		{
			*err = -1;
			return (0);
		}
		total = total * 10 + digit;
		i++;
	}
	i += skip_whitespace(str + i);
	if (str[i] && str[i] != '\0')
		*err = -1;
	return (sign * total);
}

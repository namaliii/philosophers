/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamieta <anamieta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:28:34 by anamieta          #+#    #+#             */
/*   Updated: 2024/06/06 19:24:44 by anamieta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_isdigit(char c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int	negative_check(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (i < 5 && ft_atoi(argv[i]) <= 0)
		{
			printf("Arguments should be bigger than 0\n");
			return (1);
		}
		else if (i == 5 && ft_atoi(argv[i]) < 0)
		{
			printf("Last arg (number of meals) is negative!");
			return (1);
		}
		i++;
	}
	return (0);
}

int	numeric_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
			{
				printf("Args should be numeric, dude\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	args_check(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		printf("Wrong number of arguments\n");
		return (1);
	}
	if (ft_atoi(argv[1]) > MAX_PHILOS)
	{
		printf("Don't go too crazy with the numbers\n");
		return (1);
	}
	if (negative_check(argv) == 1 || numeric_check(argv) == 1)
		return (1);
	return (0);
}

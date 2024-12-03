/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irlozano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:34:57 by irlozano          #+#    #+#             */
/*   Updated: 2024/09/08 19:35:06 by irlozano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	any_duplicates(int *number_array, int val_arg)
{
	int		i;
	int		j;

	i = 0;
	while (i < val_arg)
	{
		j = i + 1;
		while (j < val_arg)
		{
			if (number_array[i] == number_array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_chars(int ac, char **av)
{
	int	i;
	int	val_arg;

	i = 1;
	val_arg = 0;
	while (i < ac)
	{
		if (check_characters(av[i], &val_arg) == -1)
			return (-1);
		i++;
	}
	return (val_arg);
}

int	check_characters(char *arg, int *val_arg)
{
	int	j;
	int	only_spaces;

	j = 0;
	only_spaces = 0;
	if (arg[j] == '\0')
		return (-1);
	while (arg[j])
	{
		if (!ft_isdigit(arg[j]) && arg[j] != ' '
			&& arg[j] != '-' && arg[j] != '+')
			return (-1);
		if (arg[j] != ' ')
			only_spaces = 1;
		if ((arg[j] == '-' || arg[j] == '+') && !ft_isdigit(arg[j + 1]))
			return (-1);
		if (ft_isdigit(arg[j]) && (arg[j + 1] == ' ' || arg[j + 1] == '\0'))
			(*val_arg)++;
		j++;
	}
	if (!only_spaces)
		return (-1);
	return (0);
}

void	valid_ints(char **splitted_ascii, int *number_array)
{
	int	i;

	i = 0;
	while (splitted_ascii[i])
	{
		if (ft_atoll(splitted_ascii[i]) > INT_MAX \
			|| ft_atoll(splitted_ascii[i]) < INT_MIN)
		{
			free_s_array(splitted_ascii);
			free(number_array);
			display_error("Error\n");
		}
		i++;
	}
}

int	*arg_to_ints(int ac, char **av, int val_arg)
{
	char	**splitted_ascii;
	int		*num_array;
	int		counter_ac;
	int		counter_num_arr;
	int		c_element;

	num_array = (int *)malloc(sizeof(int) * val_arg);
	if (!num_array)
		return (NULL);
	counter_ac = 0;
	counter_num_arr = 0;
	while (++counter_ac < ac)
	{
		splitted_ascii = ft_split(av[counter_ac], ' ');
		if (!splitted_ascii)
			exit(0);
		valid_ints(splitted_ascii, num_array);
		c_element = 0;
		while (splitted_ascii[c_element])
			num_array[counter_num_arr++] = ft_atoi(splitted_ascii[c_element++]);
		free_s_array(splitted_ascii);
	}
	return (num_array);
}

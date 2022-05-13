/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 22:09:04 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/22 23:42:03 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	**ft_get_dictionary(char *dict_name, int *nbr_lines)
{
	int		size;
	char	*buffer;
	char	**dict;

	size = ft_get_size_of_file(dict_name);
	buffer = ft_create_buffer(dict_name, size);
	*nbr_lines = ft_count_lines(buffer);
	dict = malloc(sizeof(char *) * (*nbr_lines) + 1);
	if (dict == NULL)
		return (0);
	dict = ft_split(buffer, "\n");
	free(buffer);
	if (ft_check_dictionary(dict) == 0)
	{
		ft_free_dict(dict, *nbr_lines);
		return (0);
	}
	ft_trim(dict);
	return (dict);
}

t_key	*ft_process_key(char **dict, int *nbr_lines)
{
	t_key	*key;

	key = ft_declare_struct(*nbr_lines);
	key = ft_putonstruct(dict, key);
	ft_free_dict(dict, *nbr_lines);
	if (ft_check_keys(key, *nbr_lines) == 0)
	{
		return (0);
	}
	return (key);
}

int	ft_sucess_dictionary(char *dict_name, char *nb)
{
	t_key	*key;
	char	**dict;
	char	*nbr;
	int		nbr_lines;

	nbr_lines = 0;
	nbr = ft_get_nbr(nb);
	if (nbr == NULL)
		return (-1);
	dict = ft_get_dictionary(dict_name, &nbr_lines);
	key = ft_process_key(dict, &nbr_lines);
	if (key == 0)
	{
		ft_free_key(key, nbr_lines);
		puts("hey");
		return (-2);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	statut;

	statut = -1;
	if (ac == 2)
		statut = ft_sucess_dictionary("numbers.dict", av[1]);
	if (ac == 3)
		statut = ft_sucess_dictionary(av[1], av[2]);
	if (statut == -2)
		return (ft_dict_error());
	if (statut == -1)
		return (0);
	return (0);
}

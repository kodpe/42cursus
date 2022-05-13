/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:44:35 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/11 19:20:50 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	compare(char *str, char *to_find)
{
	while (*str != '\0' && *to_find != '\0')
	{
		if (*str != *to_find)
			return (0);
		str++;
		to_find++;
	}
	return (*to_find == '\0');
}

char	*ft_strstr(char *str, char *to_find)
{
	if (to_find[0] == 0)
		return (str);
	while (*str != '\0')
	{
		if ((*str == *to_find) && compare(str, to_find))
			return (str);
		str++;
	}
	return (0);
}

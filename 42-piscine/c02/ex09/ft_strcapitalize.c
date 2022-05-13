/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 16:02:41 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/07 18:29:53 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_upper_num(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strupcase(str);
	while (str[i] != '\0')
	{
		if (is_upper_num(str[i]) == 1)
		{
			i++;
			while (is_upper_num(str[i]) == 1)
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					str[i] += 32;
				i++;
			}
		}
		i++;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 09:06:40 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/18 15:36:00 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_str(char *str)
{
	int	size;
	int	i;
	int	tmp;

	size = 0;
	i = 0;
	while (str[i++] != '\0')
		size++;
	i = 0;
	while (i < size--)
	{
		tmp = str[size];
		str[size] = str[i];
		str[i] = tmp;
		i++;
	}
}

int	ft_len_base(char *base)
{
	int	i;
	int	r;

	i = 0;
	while (base[i] != '\0')
	{
		if ((base[i] == 32) || (base[i] >= 9 && base[i] <= 13))
			return (1);
		if ((base[i] == 43) || (base[i] == 45))
			return (1);
		r = i;
		while (base[r] != '\0')
		{
			if ((base[i] == base[r]) && (i != r))
				return (1);
			r++;
		}
		i++;
	}
	if (i < 2)
		return (1);
	return (i);
}

int	ft_char_index_base(unsigned char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	nb;
	int	i;

	if (ft_len_base(base) == 1)
		return (0);
	sign = 1;
	nb = 0;
	i = 0;
	while ((str[i] == 32) || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	while ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_char_index_base(str[i], base) >= 0)
	{
		nb = (nb * ft_len_base(base) + ft_char_index_base(str[i], base));
		i++;
	}
	return (nb * sign);
}

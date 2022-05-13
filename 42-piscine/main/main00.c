/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maine3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 18:06:17 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/09 19:49:28 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

// ex00
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// ex01
void	ft_poudlard(char s)
{
	write(1, &s, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_poudlard(str[i]);
		i++;
	}
}

// ex02
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr((nb / 10) * -1);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
		}
		nb = nb % 10;
		ft_putchar(nb + 48);
	}
}

int	main(void)
{
	char	*str;
	char	*abc;
	char	*nul;
	char	*blabla;

	str = "Pomme de terre";
	abc = "a";
	nul = "";
	blabla = "123456789";
	printf("----------Ex00----------\n");
	printf("str    : %d\n", ft_strlen(str));
	printf("abc    : %d\n", ft_strlen(abc));
	printf("nul    : %d\n", ft_strlen(nul));
	printf("blabla : %d\n", ft_strlen(blabla));
	printf("\n");
	printf("----------Ex01----------\n");
	write(1, "blabla : ", 9);
	ft_putstr(blabla);
	printf("\n");
	write(1, "str    : ", 9);
	ft_putstr(str);
	printf("\n\n");
	printf("----------Ex02----------\n");
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	ft_putnbr(128);
	write(1, "\n", 1);
	ft_putnbr(-0);
	write(1, "\n", 1);
	ft_putnbr(-128);
	write(1, "\n", 1);
	ft_putnbr(-2147483647);
	write(1, "\n", 1);
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	return (0);
}

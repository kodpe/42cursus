/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:13:36 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/10 13:27:46 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

//main
int	main(void)
{
	char	*str;
	char	*abc;
	char	*nul;
	char	*blabla;
	char	*blu;
	char	*bou;
	char	*nop;
	char	*omg;
	char	*okk;
	char	*aaa;

	str = "\t-+--09234ab567";
	abc = "\t10abca";
	nul = "null";
	blabla = "\t-2147483648";
	blu = "\t+++10q 83647";
	bou = "             -+2147483647";
	nop = "\t\t---+101242533abcabc647";
	omg = "021*47483647";
	okk = "---+-b9";
	aaa = "--2147483648";
	printf("----------Ex05----------\n");
	printf("0123456789 : %s > %d\n\n", str, ft_atoi_base(str, "0123456789"));
	printf("0123456789 : %s > %d\n\n", blabla, ft_atoi_base(blabla, "0123456789"));
	printf("0123456789 : %s > %d\n\n", blu, ft_atoi_base(blu, "0123456789"));

	printf("01 : %s > %d\n\n", nop, ft_atoi_base(nop, "01"));
	printf("abc : %s > %d\n\n", okk, ft_atoi_base(okk, "abc"));
	printf("0123456789abcdef : %s > %d\n\n", blu, ft_atoi_base(blu, "0123456789abcdef"));

	printf("abcla      : %s > %d\n\n", str, ft_atoi_base(str, "abca"));
	printf("nu--l      : %s > %d\n\n", str, ft_atoi_base(str, "nu--l"));
	printf("u          : %s > %d\n\n", str, ft_atoi_base(str, "u"));
	return (0);
}

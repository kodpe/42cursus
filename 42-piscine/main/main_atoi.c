/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_base_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:14:00 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/10 19:23:55 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
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

	str = "---+--+1234ab567";
	abc = "\n--++\f1234ab567";
	nul = "\v\t\r ---+--+1234\vab567";
	blabla = "-2147483648";
	blu = "\t21474 83647";
	bou = "             -+2147483647";
	nop = "$\t21*47483647";
	omg = "021*47483647";
	okk = "--2147483648000";
	aaa = "--2147483648";
	printf("----------Ex03----------\n");
	printf("str     : %d\n", ft_atoi(str));
	printf("str    a: %d\n", atoi(str));
	printf("abc     : %d\n", ft_atoi(abc));
	printf("abc    a: %d\n", atoi(abc));
	printf("nul     : %d\n", ft_atoi(nul));
	printf("nul    a: %d\n", atoi(nul));
	printf("blabla  : %d\n", ft_atoi(blabla));
	printf("blabla a: %d\n", atoi(blabla));
	printf("blu     : %d\n", ft_atoi(blu));
	printf("blu    a: %d\n", atoi(blu));
	printf("bou     : %d\n", ft_atoi(bou));
	printf("bou    a: %d\n", atoi(bou));
	printf("nop     : %d\n", ft_atoi(nop));
	printf("nop    a: %d\n", atoi(nop));
	printf("omg     : %d\n", ft_atoi(omg));
	printf("omg    a: %d\n", atoi(omg));
	printf("okk     : %d\n", ft_atoi(okk));
	printf("okk    a: %d\n", atoi(okk));
	printf("aaa     : %d\n", ft_atoi(aaa));
	printf("aaa    a: %d\n", atoi(aaa));
	printf("\n");
	return (0);
}
/* isspace()
vérifie s’il s’agit d’un blanc.
9 ht tabulation horizontale ('\t')
10 nl changement de ligne (newline, '\n')
11 vt tabulation verticale ('\v').
12 np saut de page (form-feed, '\f')
13 cr retour chariot (carriage return, '\r')
32 espace
*/

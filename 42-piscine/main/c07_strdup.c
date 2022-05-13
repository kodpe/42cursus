/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 10:57:57 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/17 17:24:26 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strdup(char *src);

// malloc + free

int	main(void)
{
	char	*src;
	char	*cpy;

	src = " cow jumped over the moon";

	//src = "";
	cpy = "";

	printf("src : %s\n", src);
	printf("cpy : %s\n", cpy);

	cpy = ft_strdup(src);
	//cpy = strdup(src);
	printf("new cpy : %s\n", cpy);

	return (0);
}

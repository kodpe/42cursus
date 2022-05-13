/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:53:49 by sloquet           #+#    #+#             */
/*   Updated: 2021/08/11 17:17:06 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strstr(char *str, char *to_find);
char			*ft_strncat(char *dest, char *src, unsigned int nb);
char			*ft_strcat(char *dest, char *src);
int				ft_strncmp(char *s1, char *s2, unsigned int);
int				ft_strcmp(char *s1, char *s2);

int main()
{
	printf("\n\n");
	/////////////////////////////
	/* ft_strcat & ft_strncat  */

    char dest[70];
    char src[] = "over the moon";
    strcpy(dest, "The cow jumped ");

	//ft_strncat(dest, src, 13);
	ft_strncat(dest, src, 4);
	//ft_strcat(dest, src);
	//
	printf("ft_strcat : ");
    puts(dest);
	printf("\n\n");

	/////////////////////////////
	/* ft_strcmp & ft_strncmp  */

    char s1[] = "abcdefgh";
    char s2[] = "abcdEefgh";
	int	n;

	n = 2;
	printf("strcmp  : %s & %s > %d\n\n", s1, s2, (ft_strcmp(s1, s2)));
	printf("ok with : %s & %s > %d\n\n", s1, s2, (strcmp(s1, s2)));

	printf("strncmp : %s & %s > %d n=%d\n\n", s1, s2, (ft_strncmp(s1, s2, n)),n);
	printf("ok with : %s & %s > %d n=%d\n\n", s1, s2, (ft_strncmp(s1, s2, n)),n);
	printf("\n\n");

	/////////////////////////////
	/*       ft_strstr         */

    char v1[] = "Hello world";
    char v2[] = "ello or";

	printf("strstr  : %s & %s     > %s\n\n", v1, v2, ft_strstr(v1, v2));
	printf("ok with : %s & %s     > %s\n\n", v1, v2, strstr(v1, v2));
	printf("\n\n");

	/////////////////////////////
	/*       ft_strlcat        */

	char buffer[70];
	char t1[] = "0123456789";
	char t2[] = "abcdef";

	strcpy(buffer, t1);
	ft_strlcat(buffer, t2, 10);
	printf("ft_strlcat : %s\n\n", buffer);
	strcpy(buffer, t1);
	strlcat(buffer, t2, 10);
	printf("ok with    : %s\n\n", buffer);

	strcpy(buffer, t1);
	ft_strlcat(buffer, t2, 18);
	printf("ft_strlcat : %s\n\n", buffer);
	strcpy(buffer, t1);
	strlcat(buffer, t2, 18);
	printf("ok with    : %s\n\n", buffer);

	strcpy(buffer, t1);
	ft_strlcat(buffer, t2, 16);
	printf("ft_strlcat : %s\n\n", buffer);
	strcpy(buffer, t1);
	strlcat(buffer, t2, 16);
	printf("ok with    : %s\n\n", buffer);
	printf("\n\n");

	return (0);
}

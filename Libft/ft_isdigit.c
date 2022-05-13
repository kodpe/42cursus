/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:01:09 by sloquet           #+#    #+#             */
/*   Updated: 2021/11/23 11:45:21 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_isdigit test whether c is a character of class digit
 */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

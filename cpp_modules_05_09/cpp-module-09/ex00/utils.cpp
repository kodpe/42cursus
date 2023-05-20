/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:56:47 by sloquet           #+#    #+#             */
/*   Updated: 2023/04/25 11:23:55 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cstdlib>
#include <cerrno>

int	sc_strtod(const char *str, double *nb, char next)
{
	char	*endptr;

	if (str == NULL)
		return -1;
	*nb = strtod(str, &endptr);
	if ((*nb == 0 && endptr == str) || errno == ERANGE || *endptr != next)
		return -1;
	return 0;
}

/*
	bool	date_isvalid(std::string str)
	eval Format: Year-Month-Day
	yyyy-mm-dd
	....4..7..
	28/29 feb, 30 days month : 04/06/09/11
*/

static bool	valid_format(std::string str)
{
	if (str.size() != 10)
		return false;
	for (std::string::size_type i = 0; i < str.size(); ++i)
	{
		if (!isdigit(str[i]) && i != 4 && i != 7)
			return false;
	}
	if (str[4] != '-' || str[7] != '-')
		return false;
	return true;
}

static bool	valid_values(int y, int m, int d)
{
	if (y < 0 || m < 1 || m > 12 || d < 1 || d > 31)
		return false;
	if (d == 31 && (m == 4 || m == 6 || m == 9 || m == 11))
		return false;
	if (m == 2)
	{
		if (d > 29)
			return false;
		if (d == 29 && y % 4)
			return false;
		if (d == 29 && y % 400 && y % 100 == 0)
			return false;
	}
	return true;
}

bool	date_isvalid(std::string str)
{
	double	y, m, d;

	if (!valid_format(str))
		return false;
	if (sc_strtod(str.c_str(), &y, '-'))
		return false;
	if (sc_strtod(str.c_str() + 5, &m, '-'))
		return false;
	if (sc_strtod(str.c_str() + 8, &d, 0))
		return false;
	if (!valid_values(y, m, d))
		return false;
	return true;
}

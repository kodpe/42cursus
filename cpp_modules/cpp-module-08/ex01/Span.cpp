/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:47:48 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/18 02:03:52 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

char const *	Span::SpanIsFull::what() const throw()
{
	return "Span::SpanIsFull";
}

char const *	Span::SpanTooSmall::what() const throw()
{
	return "Span::SpanTooSmall";
}

Span::Span() : _vec(), _N(0)
{}

Span::Span(unsigned int N) : _vec(), _N(N)
{}

Span::Span(const Span &other) : _vec()
{
	*this = other;
}

Span::~Span()
{}

Span&	Span::operator=(const Span &other)
{
	if (this == &other)
		return *this;
	_N = other._N;
	_vec = other._vec;
	return *this;
}

void	Span::addNumber(int nb)
{
	if (_vec.size() == _N)
		throw SpanIsFull();
	_vec.push_back(nb);
}

void Span::displaySpan(void) const
{
	if (_vec.size() == 0)
		return ;
	std::copy(_vec.begin(), _vec.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
}

size_t	Span::shortestSpan(void) const
{
	if (_vec.size() < 2)
		throw SpanTooSmall();
	displayVector(_vec, "_vec");

	std::vector<int> tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	displayVector(tmp, "tmp ");

	std::vector<int> dist;

	for (size_t i = 0; i < tmp.size() - 1; i++)
		dist.push_back(tmp[i + 1] - tmp[i]);
	displayVector(dist, "dist");

	return static_cast<size_t>(*std::min_element(dist.begin(), dist.end()));
}

size_t	Span::longestSpan(void) const
{
	if (_vec.size() < 2)
		throw SpanTooSmall();

	int	max = *std::max_element(_vec.begin(), _vec.end());
	int	min = *std::min_element(_vec.begin(), _vec.end());

	return static_cast<size_t>(max - min);
}

int		my_rand(void) { return std::rand() % 1000000; }

void	Span::addRange(const std::vector<int>::const_iterator& begin,
						const std::vector<int>::const_iterator& end)
{
	size_t	size = static_cast<size_t>(std::abs(std::distance(begin, end)));

	if (size == 0)
		return ;
	if (_vec.size() + size > _N)
		throw SpanTooSmall();
	_vec.insert(_vec.end(), begin, end);
}

void	Span::fill(void)
{
	if (_N == 0)
		return ;
	_vec.erase(_vec.begin(), _vec.end());
	_vec.insert(_vec.begin(), _N, 0);
	std::generate(_vec.begin(), _vec.end(), &my_rand);
}

void	Span::displayVector(const std::vector<int>& v, const char *name) const
{
	if (!DEBUG || _vec.size() == 0)
		return ;
	std::cout << COLOR << "DEBUG : " << name << " : ";
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << RESET << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:21:10 by sloquet           #+#    #+#             */
/*   Updated: 2023/01/18 02:05:21 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>

#if 1

int main()
{
	std::cout << std::endl << "=== MUTANTSTACK ===" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		// return 0;
	}

	/*
		-- std::stack --	-- std::list --

	    	push()		->		push_back()
			pop()		->		pop_back()
			top()		->		back()
	*/
	std::cout << std::endl << "=== STD::LIST ===" << std::endl;
	{
		std::list<int> lst;

		lst.push_back(5);
		lst.push_back(17);

		std::cout << lst.back() << std::endl;

		lst.pop_back();

		std::cout << lst.size() << std::endl;

		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);

		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(lst);
	}
	return 0;
}

#else

int	main(void)
{
	/*
							MUTANTSTACK
	*/
	MutantStack<int> mstack;

	std::cout << std::endl << "=== MUTANTSTACK ===" << std::endl;
	{
		mstack.push(33);
		mstack.push(22);
		mstack.push(11);
		std::cout << "size : " << mstack.size() << std::endl;
		std::cout << "top  : " << *mstack.begin() << std::endl;

		std::cout << std::endl;
		mstack.pop();
		std::cout << "size : " << mstack.size() << std::endl;
		std::cout << "top  : " << *mstack.begin() << std::endl;
		mstack.pop();
		mstack.pop();

		std::cout << std::endl;
		mstack.push(0);
		mstack.push(1);
		mstack.push(42);
		mstack.push(518);
		std::cout << "size : " << mstack.size() << std::endl;
		std::cout << "top  : " << *mstack.begin() << std::endl;
	}

	std::cout << std::endl << "display stack   : ";
	{
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
	}
	std::cout << std::endl << "test copy stack : ";
	{
		MutantStack<int> mycopy(mstack);
		MutantStack<int>::iterator it2 = mycopy.begin();
		MutantStack<int>::iterator ite2 = mycopy.end();
		while (it2 != ite2)
		{
			std::cout << *it2 << " ";
			++it2;
		}
	}
	std::cout << std::endl << "empty stack     : ";
	{
		MutantStack<int> mstack;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << "iterators tests" << std::endl;
	{
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		std::cout << "begin: " << *it << std::endl;
		++it;
		std::cout << "++it : " << *it << std::endl;
		--it;
		std::cout << "--it : " << *it << std::endl;
		std::cout << std::endl;

		--ite;
		std::cout << "last : " << *ite << std::endl;
		--ite;
		std::cout << "--ite: " << *ite << std::endl;
		++ite;
		std::cout << "++ite: " << *ite << std::endl;
	}

	/*
							STD::LIST
	*/
	std::list<int> lst;

	std::cout << std::endl << "=== STD::LIST ===" << std::endl;
	{
		lst.push_back(33);
		lst.push_back(22);
		lst.push_back(11);
		std::cout << "size : " << lst.size() << std::endl;
		std::cout << "begin: " << *lst.begin() << std::endl;

		std::cout << std::endl;
		lst.pop_back();
		std::cout << "size : " << lst.size() << std::endl;
		std::cout << "begin: " << *lst.begin() << std::endl;
		lst.pop_back();
		lst.pop_back();

		std::cout << std::endl;
		lst.push_back(0);
		lst.push_back(1);
		lst.push_back(42);
		lst.push_back(518);
		std::cout << "size : " << lst.size() << std::endl;
		std::cout << "begin: " << *lst.begin() << std::endl;
	}

	std::cout << std::endl << "display lst   : ";
	{
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
	}
	std::cout << std::endl << "test copy lst : ";
	{
		std::list<int> mycopy(lst);
		std::list<int>::iterator it2 = mycopy.begin();
		std::list<int>::iterator ite2 = mycopy.end();
		while (it2 != ite2)
		{
			std::cout << *it2 << " ";
			++it2;
		}
	}

	std::cout << std::endl << "empty lst     : ";
	{
		std::list<int> lst;
		std::list<int>::iterator	it = lst.begin();
		std::list<int>::iterator	ite = lst.end();
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}

	std::cout << std::endl << "iterators tests:" << std::endl;
	{
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();

		std::cout << "begin: " << *it << std::endl;
		++it;
		std::cout << "++it : " << *it << std::endl;
		--it;
		std::cout << "--it : " << *it << std::endl;
		std::cout << std::endl;

		--ite;
		std::cout << "last : " << *ite << std::endl;
		--ite;
		std::cout << "--ite: " << *ite << std::endl;
		++ite;
		std::cout << "++ite: " << *ite << std::endl;
	}

	return 0;
}

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:40:18 by pcamaren          #+#    #+#             */
/*   Updated: 2022/12/27 17:49:00 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector/vector.hpp"
// #include "map.hpp"
#include <iostream>
#include <vector>


#include <sstream>
#include <iomanip>

#define COLOR_ONE	"\033[35m"
#define COLOR_TWO	"\033[33m"
#define COLOR_NO	"\033[0m"

template < typename T >
void	printf_v(T & v, std::string name)
{
	std::cout << name << " = {";
	for (unsigned int i = 0; i < v.size(); i++)
	{
		std::cout << v[i];
		if (i + 1 != v.size())
			std::cout << ", ";
	}
	std::cout << "}; \n";
}

// template <class Key, class T>
// void	print_m(ft::map<Key, T>& lst)
// {
// 	for (typename ft::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
// 		std::cout << it->first << " => " << it->second << '\n';
// }


int main()
{
		// Create a vector containing integers
	{		
		std::cout << COLOR_TWO << "/--Testing: max_size(), size(), capacity()--/" << COLOR_NO << std::endl;
		ft::vector<int>		e_m;
		std::vector<int>	e_v;
		ft::vector<int>		m(10, 42);
		std::vector<int>	v(10, 42);
		ft::vector<int>		m2(m);

		std::cout << "Testing: empty constructor" << std::endl;
		if (e_v.max_size() != e_m.max_size())
			std::cout << "Max_size: ✘" << std::endl;
		else
			std::cout << "Max_size: ✔" << std::endl;

		if (e_v.size() != e_m.size())
			std::cout << "size: ✘" << std::endl;
		else
			std::cout << "size: ✔" << std::endl;

		if (e_v.capacity() != e_m.capacity())
			std::cout << "capacity: ✘" << std::endl;
		else
			std::cout << "capacity: ✔" << "\n\n";		

		std::cout << "Testing: fill constructor" << std::endl;
		if (v.max_size() != m.max_size())
			std::cout << "Max_size: ✘" << std::endl;
		else
			std::cout << "Max_size: ✔" << std::endl;

		if (v.size() != m.size())
			std::cout << "size: ✘" << std::endl;
		else
			std::cout << "size: ✔" << std::endl;

		if (v.capacity() != m.capacity())
			std::cout << "capacity: ✘" << std::endl;
		else
			std::cout << "capacity: ✔" << "\n\n";

		
		// std::cout << "Testing: copy constructor " << std::endl;
		// if (v.max_size() != m2.max_size())
		// 	std::cout << "Max_size: ✘" << std::endl;
		// else
		// 	std::cout << "Max_size: ✔" << std::endl;

		// if (v.size() != m2.size())
		// 	std::cout << "size: ✘" << std::endl;
		// else
		// 	std::cout << "size: ✔" << std::endl;

		// if (v.capacity() != m2.capacity())
		// 	std::cout << "capacity: ✘" << std::endl;
		// else
		// 	std::cout << "capacity: ✔" << "\n\n";

	}
	{
		std::cout << COLOR_TWO << "/--Testing: iterator--/" << COLOR_NO << std::endl;
		ft::vector<int>		m(10, 42);
		std::vector<int>	v(10, 42);

		printf_v(v, "std vector v");
		printf_v(m, "ft vector v");
		ft::vector<int>::iterator ft_it = m.begin();
		std::vector<int>::iterator std_it = v.begin();
		ft::vector<int>::iterator ft_end = m.end();
		while (ft_it != ft_end)
		{
        	if (*ft_it != *std_it)
  	          std::cout <<"iterator: ✘" << "\n";
			ft_it++;
			std_it++;
		}
  	    std::cout <<"iterator: ✔" << "\n";
	}
		
		
		// // Add two more integers to vector
		// v.push_back(7);
		// v.push_back(5);
		// v.push_back(16);
		// v.push_back(8);
		// v.push_back(13);

		// // Add two more integers to vector
		// m.push_back(7);
		// m.push_back(5);  
		// m.push_back(16);
		// m.push_back(8);
		// m.push_back(13);
		// // Print out the vector
	
		// printf_v(v, "v");
		// printf_v(m, "m");
		// std::cout << "MAX_SIZE: " << v.max_size() << "\n";
		// std::cout << "max_size: " << m.max_size() << "\n";
		// std::cout << "SIZE: " << v.size() << "\n";
		// std::cout << "size: " << m.size() << "\n";
		// std::cout << "CAPACITY: " << v.capacity() << "\n";
		// std::cout << "capacity: " << m.capacity() << "\n";
}
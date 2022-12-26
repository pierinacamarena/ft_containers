/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:40:18 by pcamaren          #+#    #+#             */
/*   Updated: 2022/12/26 18:25:34 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vector/ft_vector.hpp"
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
		std::cout << COLOR_TWO << "/--test MAX_SIZE size capacity--/" << COLOR_NO << std::endl;
		ft::vector<int>		m(10, 42);
		std::vector<int>	v(10, 42);

		std::cout << "MAX_SIZE: " << v.max_size() << "\n";
		std::cout << "max_size: " << m.max_size() << "\n";
		std::cout << "SIZE: " << v.size() << "\n";
		std::cout << "size: " << m.size() << "\n";
		std::cout << "CAPACITY: " << v.capacity() << "\n";
		std::cout << "capacity: " << m.capacity() << "\n";

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
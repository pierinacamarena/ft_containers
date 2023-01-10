/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:59:30 by pcamaren          #+#    #+#             */
/*   Updated: 2023/01/10 23:20:58 by pcamaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tester.hpp"

#define COLOR_ONE	"\033[35m"
#define COLOR_TWO	"\033[33m"
#define COLOR_NO	"\033[0m"

template <class Key, class T>
void	print_m(LIB::map<Key, T>& lst)
{
	for (typename LIB::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int main()
{
	{
		// /*Testing empty constructor*/
		// std::cout << "***************Testing empty constructor***************" << '\n';
		// LIB::map<int, std::string> test;
		// LIB::map<int, std::string> test1;
		// LIB::map<int, std::string> test2;
		// LIB::map<int, std::string> test3;
		// LIB::map<int, std::string> test4;
	}
	{
		/*Testing copy constructor*/
		// std::cout << "***************Testing copy constructor***************" << '\n';
		// LIB::map<int, std::string> test;
		// test.insert(LIB::pair<int, std::string>(5, "5"));
		// test.insert(LIB::pair<int, std::string>(7, "7"));
		// test.insert(LIB::pair<int, std::string>(-9, "-9"));
		// test.insert(LIB::pair<int, std::string>(-2, "-2"));
		// test.insert(LIB::pair<int, std::string>(18, "18"));
		// test.insert(LIB::pair<int, std::string>(20, "20"));
		// test.insert(LIB::pair<int, std::string>(31, "31"));
		// test.insert(LIB::pair<int, std::string>(87, "87"));
		// std::cout << "________________________________________" << '\n';
		// std::cout << "Map: test" << '\n';
		// print_m<int, std::string>(test);
		// std::cout << "________________________________________" << '\n';
		// std::cout << "Map: test2 copy constructed from test" << '\n';
		// LIB::map<int, std::string> test2(test);
		// test.insert(LIB::pair<int, std::string>(99, "99"));
		// test.insert(LIB::pair<int, std::string>(33, "33"));
		// print_m<int, std::string>(test2);
		// std::cout << "________________________________________" << '\n';
		// std::cout << "Map: test2 copy constructed from test2" << '\n';
		// LIB::map<int, std::string> test3(test2);
		// print_m<int, std::string>(test3);
		// std::cout << "________________________________________" << '\n';
		// std::cout << "Map: test after insert two extra elements" << '\n';
		// print_m<int, std::string>(test);
		// LIB::map<int, std::string> test4;
		// test4.insert(LIB::pair<int, std::string>(7, "7"));
		// test4.insert(LIB::pair<int, std::string>(8, "8"));
		// test4.insert(LIB::pair<int, std::string>(-9, "-9"));
		// test4.insert(LIB::pair<int, std::string>(-87, "-87"));
		// std::cout << "________________________________________" << '\n';
		// std::cout << "Map: new map test4 with different elements" << '\n';
		// print_m<int, std::string>(test4);
		// LIB::map<int, std::string> test5(test4);
		// std::cout << "________________________________________" << '\n';
		// std::cout << "Map: new map test5 with different elements" << '\n';
		// print_m<int, std::string>(test5);
	}
	{
		// /*Testing iterator constructor*/
		// std::cout << "***************Testing copy constructor***************" << '\n';
		// LIB::map<int, std::string> test;
		// test.insert(LIB::pair<int, std::string>(5, "5"));
		// test.insert(LIB::pair<int, std::string>(7, "7"));
		// test.insert(LIB::pair<int, std::string>(-9, "-9"));
		// test.insert(LIB::pair<int, std::string>(-2, "-2"));
		// test.insert(LIB::pair<int, std::string>(18, "18"));
		// test.insert(LIB::pair<int, std::string>(20, "20"));
		// test.insert(LIB::pair<int, std::string>(31, "31"));
		// test.insert(LIB::pair<int, std::string>(87, "87"));
		// std::cout << "________________________________________" << '\n';
		// std::cout << "Map: test" << '\n';
		// print_m<int, std::string>(test);
		// //creating iterators used for construction
		// LIB::map<int, std::string>::iterator start = test.begin();
		// LIB::map<int, std::string>::iterator end = test.end();
		// LIB::map<int, std::string> test2(start, end);
		// std::cout << "________________________________________" << '\n';
		// std::cout << "Map: test2 constructed from iterators" << '\n';
		// print_m<int, std::string>(test);
		// //new iterators
		// LIB::map<int, std::string>::iterator start2 = test.begin();
		// LIB::map<int, std::string>::iterator end2 = test.end();
		// start2++;
		// start2++;
		// end2--;
		// end2--;
		// end2--;
		// end2--;
		// end2--;
		// end2--;
		// LIB::map<int, std::string> test3(start2, end2);
		// std::cout << "________________________________________" << '\n';
		// std::cout << "Map: test3 constructed from iterators" << '\n';
		// print_m<int, std::string>(test3);
	}
	{
		/*Testing copy operator*/
		// std::cout << "***************Testing copy constructor***************" << '\n';
		// LIB::map<int, std::string> test;
		// test.insert(LIB::pair<int, std::string>(5, "5"));
		// test.insert(LIB::pair<int, std::string>(7, "7"));
		// test.insert(LIB::pair<int, std::string>(-9, "-9"));
		// test.insert(LIB::pair<int, std::string>(-2, "-2"));
		// test.insert(LIB::pair<int, std::string>(18, "18"));
		// test.insert(LIB::pair<int, std::string>(20, "20"));
		// test.insert(LIB::pair<int, std::string>(31, "31"));
		// test.insert(LIB::pair<int, std::string>(87, "87"));
		// std::cout << "________________________________________" << '\n';
		// std::cout << "Map: test" << '\n';
		// print_m<int, std::string>(test);
		
		// LIB::map<int, std::string> test2;
		// test2 = test;
		// std::cout << "________________________________________" << '\n';
		// std::cout << "Map: test2 copied with copy operator" << '\n';
		// print_m<int, std::string>(test);
		
		// LIB::map<int, std::string> test3;
		// test3.insert(LIB::pair<int, std::string>(7, "7"));
		// test3.insert(LIB::pair<int, std::string>(8, "8"));
		// test3.insert(LIB::pair<int, std::string>(-9, "-9"));
		// test3.insert(LIB::pair<int, std::string>(-87, "-87"));
		// std::cout << "________________________________________" << '\n';
		// std::cout << "Map: test3" << '\n';
		// print_m<int, std::string>(test3);
		
		// std::cout << "________________________________________" << '\n';
		// std::cout << "Map: test3 after being set = test2" << '\n';
		// test3 = test2;
		// print_m<int, std::string>(test3);
	}
	{
		// /*testing begin*/
		// std::cout << "***************Testing begin()***************" << '\n';
		// LIB::map<int, std::string> test;
		// test.insert(LIB::pair<int, std::string>(5, "5"));
		// test.insert(LIB::pair<int, std::string>(7, "7"));
		// test.insert(LIB::pair<int, std::string>(-9, "-9"));
		// test.insert(LIB::pair<int, std::string>(-2, "-2"));
		// test.insert(LIB::pair<int, std::string>(18, "18"));
		// test.insert(LIB::pair<int, std::string>(20, "20"));
		// test.insert(LIB::pair<int, std::string>(31, "31"));
		// test.insert(LIB::pair<int, std::string>(87, "87"));
		// LIB::map<int, std::string>::iterator iter = test.begin();
		// test.insert(LIB::pair<int, std::string>(87, "87"));
		// iter = test.begin();
		// std::cout << "iter " << iter->first << " => " << iter->second << '\n';
		// test.insert(LIB::pair<int, std::string>(-10, "-10"));
		// iter = test.begin();
		// std::cout << "iter " << iter->first << " => " << iter->second << '\n';
		// test.insert(LIB::pair<int, std::string>(-15, "-15"));
		// iter = test.begin();
		// std::cout << "iter " << iter->first << " => " << iter->second << '\n';
		// test.insert(LIB::pair<int, std::string>(8, "8"));
		// iter = test.begin();
		// std::cout << "iter " << iter->first << " => " << iter->second << '\n';
		// test.insert(LIB::pair<int, std::string>(-90, "-90"));
		// iter = test.begin();
		// std::cout << "iter " << iter->first << " => " << iter->second << '\n';

		// std::cout << "Testing begin() const" << '\n';
		// LIB::map<int, std::string> test2;
		// test2.insert(LIB::pair<int, std::string>(5, "5"));
		// test2.insert(LIB::pair<int, std::string>(7, "7"));
		// test2.insert(LIB::pair<int, std::string>(-9, "-9"));
		// test2.insert(LIB::pair<int, std::string>(-2, "-2"));
		// test2.insert(LIB::pair<int, std::string>(18, "18"));
		// test2.insert(LIB::pair<int, std::string>(20, "20"));
		// test2.insert(LIB::pair<int, std::string>(31, "31"));
		// test2.insert(LIB::pair<int, std::string>(87, "87"));
		// LIB::map<int, std::string>::const_iterator iter_const = test2.begin();
		// test2.insert(LIB::pair<int, std::string>(87, "87"));
		// iter_const = test2.begin();
		// std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
		// test2.insert(LIB::pair<int, std::string>(-10, "-10"));
		// iter_const = test2.begin();
		// std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
		// test2.insert(LIB::pair<int, std::string>(-15, "-15"));
		// iter_const = test2.begin();
		// std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
		// test2.insert(LIB::pair<int, std::string>(8, "8"));
		// iter_const = test2.begin();
		// std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
		// test2.insert(LIB::pair<int, std::string>(-90, "-90"));
		// iter_const = test2.begin();
		// std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
	}
	{
	// 	/*testing end*/
	// 	std::cout << "***************Testing end()***************" << '\n';
	// 	LIB::map<int, std::string> test;
	// 	test.insert(LIB::pair<int, std::string>(5, "5"));
	// 	test.insert(LIB::pair<int, std::string>(7, "7"));
	// 	test.insert(LIB::pair<int, std::string>(-9, "-9"));
	// 	test.insert(LIB::pair<int, std::string>(-2, "-2"));
	// 	test.insert(LIB::pair<int, std::string>(18, "18"));
	// 	test.insert(LIB::pair<int, std::string>(20, "20"));
	// 	test.insert(LIB::pair<int, std::string>(31, "31"));
	// 	test.insert(LIB::pair<int, std::string>(87, "87"));
	// 	LIB::map<int, std::string>::iterator iter = test.end();
	// 	test.insert(LIB::pair<int, std::string>(87, "87"));
	// 	iter = test.end();
	// 	iter--;
	// 	std::cout << "iter " << iter->first << " => " << iter->second << '\n';
	// 	test.insert(LIB::pair<int, std::string>(150, "150"));
	// 	iter = test.end();
	// 	iter--;
	// 	std::cout << "iter " << iter->first << " => " << iter->second << '\n';
	// 	test.insert(LIB::pair<int, std::string>(159, "159"));
	// 	iter = test.end();
	// 	iter--;
	// 	std::cout << "iter " << iter->first << " => " << iter->second << '\n';
	// 	test.insert(LIB::pair<int, std::string>(147, "147"));
	// 	iter = test.end();
	// 	iter--;
	// 	std::cout << "iter " << iter->first << " => " << iter->second << '\n';
	// 	test.insert(LIB::pair<int, std::string>(190, "190"));
	// 	iter = test.end();
	// 	iter--;
	// 	std::cout << "iter " << iter->first << " => " << iter->second << '\n';

	// 	std::cout << "Testing end() const" << '\n';
	// 	LIB::map<int, std::string> test2;
	// 	test2.insert(LIB::pair<int, std::string>(5, "5"));
	// 	test2.insert(LIB::pair<int, std::string>(7, "7"));
	// 	test2.insert(LIB::pair<int, std::string>(-9, "-9"));
	// 	test2.insert(LIB::pair<int, std::string>(-2, "-2"));
	// 	test2.insert(LIB::pair<int, std::string>(18, "18"));
	// 	test2.insert(LIB::pair<int, std::string>(20, "20"));
	// 	test2.insert(LIB::pair<int, std::string>(31, "31"));
	// 	test2.insert(LIB::pair<int, std::string>(87, "87"));
	// 	LIB::map<int, std::string>::const_iterator iter_const = test2.end();
	// 	test2.insert(LIB::pair<int, std::string>(87, "87"));
	// 	iter_const = test2.end();
	// 	iter_const--;
	// 	std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
	// 	test2.insert(LIB::pair<int, std::string>(150, "150"));
	// 	iter_const = test2.end();
	// 	iter_const--;
	// 	std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
	// 	test2.insert(LIB::pair<int, std::string>(159, "159"));
	// 	iter_const = test2.end();
	// 	iter_const--;
	// 	std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
	// 	test2.insert(LIB::pair<int, std::string>(147, "147"));
	// 	iter_const = test2.end();
	// 	iter_const--;
	// 	std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
	// 	test2.insert(LIB::pair<int, std::string>(190, "190"));
	// 	iter_const = test2.end();
	// 	iter_const--;
	// 	std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
	}
	{
	// /*testing begin*/
	// std::cout << "***************Testing rbegin()***************" << '\n';
	// LIB::map<int, std::string> test;
	// test.insert(LIB::pair<int, std::string>(5, "5"));
	// test.insert(LIB::pair<int, std::string>(7, "7"));
	// test.insert(LIB::pair<int, std::string>(-9, "-9"));
	// test.insert(LIB::pair<int, std::string>(-2, "-2"));
	// test.insert(LIB::pair<int, std::string>(18, "18"));
	// test.insert(LIB::pair<int, std::string>(20, "20"));
	// test.insert(LIB::pair<int, std::string>(31, "31"));
	// test.insert(LIB::pair<int, std::string>(87, "87"));
	// LIB::map<int, std::string>::reverse_iterator iter = test.rbegin();
	// test.insert(LIB::pair<int, std::string>(87, "87"));
	// iter = test.rbegin();
	// iter--;
	// std::cout << "iter " << iter->first << " => " << iter->second << '\n';
	// test.insert(LIB::pair<int, std::string>(150, "150"));
	// iter = test.rbegin();
	// iter--;
	// std::cout << "iter " << iter->first << " => " << iter->second << '\n';
	// test.insert(LIB::pair<int, std::string>(159, "159"));
	// iter = test.rbegin();
	// iter--;
	// std::cout << "iter " << iter->first << " => " << iter->second << '\n';
	// test.insert(LIB::pair<int, std::string>(147, "147"));
	// iter = test.rbegin();
	// iter--;
	// std::cout << "iter " << iter->first << " => " << iter->second << '\n';
	// test.insert(LIB::pair<int, std::string>(190, "190"));
	// iter = test.rbegin();
	// iter--;
	// std::cout << "iter " << iter->first << " => " << iter->second << '\n';

	// std::cout << "Testing rbegin() const" << '\n';
	// LIB::map<int, std::string> test2;
	// test2.insert(LIB::pair<int, std::string>(5, "5"));
	// test2.insert(LIB::pair<int, std::string>(7, "7"));
	// test2.insert(LIB::pair<int, std::string>(-9, "-9"));
	// test2.insert(LIB::pair<int, std::string>(-2, "-2"));
	// test2.insert(LIB::pair<int, std::string>(18, "18"));
	// test2.insert(LIB::pair<int, std::string>(20, "20"));
	// test2.insert(LIB::pair<int, std::string>(31, "31"));
	// test2.insert(LIB::pair<int, std::string>(87, "87"));
	// LIB::map<int, std::string>::const_reverse_iterator iter_const = test2.rbegin();
	// test2.insert(LIB::pair<int, std::string>(87, "87"));
	// iter_const = test2.rbegin();
	// iter_const--;
	// std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
	// test2.insert(LIB::pair<int, std::string>(150, "150"));
	// iter_const = test2.rbegin();
	// iter_const--;
	// std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
	// test2.insert(LIB::pair<int, std::string>(159, "159"));
	// iter_const = test2.rbegin();
	// iter_const--;
	// std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
	// test2.insert(LIB::pair<int, std::string>(147, "147"));
	// iter_const = test2.rbegin();
	// iter_const--;
	// std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
	// test2.insert(LIB::pair<int, std::string>(190, "190"));
	// iter_const = test2.rbegin();
	// iter_const--;
	// std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
	}
	{
	// 	/*testing rend*/
	// 	std::cout << "***************Testing rend()***************" << '\n';
	// 	LIB::map<int, std::string> test;
	// 	test.insert(LIB::pair<int, std::string>(5, "5"));
	// 	test.insert(LIB::pair<int, std::string>(7, "7"));
	// 	test.insert(LIB::pair<int, std::string>(-9, "-9"));
	// 	test.insert(LIB::pair<int, std::string>(-2, "-2"));
	// 	test.insert(LIB::pair<int, std::string>(18, "18"));
	// 	test.insert(LIB::pair<int, std::string>(20, "20"));
	// 	test.insert(LIB::pair<int, std::string>(31, "31"));
	// 	test.insert(LIB::pair<int, std::string>(87, "87"));
	// 	LIB::map<int, std::string>::reverse_iterator iter = test.rend();
	// 	test.insert(LIB::pair<int, std::string>(87, "87"));
	// 	iter = test.rend();
	// 	std::cout << "iter " << iter->first << " => " << iter->second << '\n';
	// 	test.insert(LIB::pair<int, std::string>(-10, "-10"));
	// 	iter = test.rend();
	// 	std::cout << "iter " << iter->first << " => " << iter->second << '\n';
	// 	test.insert(LIB::pair<int, std::string>(-15, "-15"));
	// 	iter = test.rend();
	// 	std::cout << "iter " << iter->first << " => " << iter->second << '\n';
	// 	test.insert(LIB::pair<int, std::string>(8, "8"));
	// 	iter = test.rend();
	// 	std::cout << "iter " << iter->first << " => " << iter->second << '\n';
	// 	test.insert(LIB::pair<int, std::string>(-90, "-90"));
	// 	iter = test.rend();
	// 	std::cout << "iter " << iter->first << " => " << iter->second << '\n';

	// 	std::cout << "Testing rend() const" << '\n';
	// 	LIB::map<int, std::string> test2;
	// 	test2.insert(LIB::pair<int, std::string>(5, "5"));
	// 	test2.insert(LIB::pair<int, std::string>(7, "7"));
	// 	test2.insert(LIB::pair<int, std::string>(-9, "-9"));
	// 	test2.insert(LIB::pair<int, std::string>(-2, "-2"));
	// 	test2.insert(LIB::pair<int, std::string>(18, "18"));
	// 	test2.insert(LIB::pair<int, std::string>(20, "20"));
	// 	test2.insert(LIB::pair<int, std::string>(31, "31"));
	// 	test2.insert(LIB::pair<int, std::string>(87, "87"));
	// 	LIB::map<int, std::string>::const_reverse_iterator iter_const = test2.rend();
	// 	test2.insert(LIB::pair<int, std::string>(87, "87"));
	// 	iter_const = test2.rend();
	// 	std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
	// 	test2.insert(LIB::pair<int, std::string>(-10, "-10"));
	// 	iter_const = test2.rend();
	// 	std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
	// 	test2.insert(LIB::pair<int, std::string>(-15, "-15"));
	// 	iter_const = test2.rend();
	// 	std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
	// 	test2.insert(LIB::pair<int, std::string>(8, "8"));
	// 	iter_const = test2.rend();
	// 	std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
	// 	test2.insert(LIB::pair<int, std::string>(-90, "-90"));
	// 	iter_const = test2.rend();
	// 	std::cout << "iter_const " << iter_const->first << " => " << iter_const->second << '\n';
	}
	{
		/*Testing empty*/
		// std::cout << "***************Testing empty***************" << '\n';
		// LIB::map<int, std::string> test;
		// bool is_empty = test.empty();
		// std::cout << "Testing map constructed with empty constructor" << '\n';
		// if (is_empty)
		// 	std::cout << "The map is empty" << '\n' << '\n';
		// else
		// 	std::cout << "The map is not empty" << '\n' << '\n';

		// test.insert(LIB::pair<int, std::string>(5, "5"));
		// test.insert(LIB::pair<int, std::string>(7, "7"));
		// test.insert(LIB::pair<int, std::string>(-9, "-9"));
		// test.insert(LIB::pair<int, std::string>(-2, "-2"));
		// test.insert(LIB::pair<int, std::string>(18, "18"));
		// test.insert(LIB::pair<int, std::string>(20, "20"));
		// test.insert(LIB::pair<int, std::string>(31, "31"));
		// test.insert(LIB::pair<int, std::string>(87, "87"));
		// LIB::map<int, std::string> test2(test);
		// LIB::map<int, std::string> test3;
		
		// std::cout << "Testing map after inserting elements" << '\n';
		// is_empty = test.empty();
		// if (is_empty)
		// 	std::cout << "The map is empty" << '\n' << '\n';
		// else
		// 	std::cout << "The map is not empty" << '\n' << '\n';

		// test.clear();
		// std::cout << "Testing map after clearing it" << '\n';
		// is_empty = test.empty();
		// if (is_empty)
		// 	std::cout << "The map is empty" << '\n' << '\n';
		// else
		// 	std::cout << "The map is not empty" << '\n' << '\n';
		
		// std::cout << "Testing map copy constructed" << '\n';
		// is_empty = test2.empty();
		// if (is_empty)
		// 	std::cout << "The map is empty" << '\n' << '\n';
		// else
		// 	std::cout << "The map is not empty" << '\n' << '\n';

		// test3 = test2;
		// std::cout << "Testing map from copy operator" << '\n';
		// is_empty = test3.empty();
		// if (is_empty)
		// 	std::cout << "The map is empty" << '\n' << '\n';
		// else
		// 	std::cout << "The map is not empty" << '\n' << '\n';
	}
	{
		// //size
		// std::cout << "***************Testing size***************" << '\n';
		// LIB::map<int, std::string> test;
		
		// std::cout << "Size of empty map" << '\n';
		// std::cout << test.size() << '\n' << '\n';
		
		// test.insert(LIB::pair<int, std::string>(5, "5"));
		// test.insert(LIB::pair<int, std::string>(7, "7"));
		// test.insert(LIB::pair<int, std::string>(-9, "-9"));
		// test.insert(LIB::pair<int, std::string>(-2, "-2"));
		// test.insert(LIB::pair<int, std::string>(18, "18"));
		// test.insert(LIB::pair<int, std::string>(20, "20"));
		// test.insert(LIB::pair<int, std::string>(31, "31"));
		// test.insert(LIB::pair<int, std::string>(87, "87"));


		// std::cout << "Size of map after inserting 8 elements" << '\n';
		// std::cout << test.size() << '\n' << '\n';
		
		// LIB::map<int, std::string> test2(test);
		// std::cout << "Size of map copy constructed from a map of 8 elements" << '\n';
		// std::cout << test2.size() << '\n' << '\n';
		

		// test.clear();
		// std::cout << "Size of map after clearing it" << '\n';
		// std::cout << test.size() << '\n' << '\n';

		// test.insert(LIB::pair<int, std::string>(-2, "-2"));
		// test.insert(LIB::pair<int, std::string>(18, "18"));
		// test.insert(LIB::pair<int, std::string>(20, "20"));
		// test.insert(LIB::pair<int, std::string>(31, "31"));
		// test.insert(LIB::pair<int, std::string>(87, "87"));

		// std::cout << "Size of map after inserting 5 elements" << '\n';
		// std::cout << test.size() << '\n' << '\n';
	}
	{
		// std::cout << "***************Testing max_size***************" << '\n';
		// std::cout << "All output should be the same" << '\n';
	
		// LIB::map<int, std::string> test;
		// std::cout << "Max_size of empty map" << '\n';
		// std::cout << test.max_size() << '\n' << '\n';
		
		// test.insert(LIB::pair<int, std::string>(-2, "-2"));
		// test.insert(LIB::pair<int, std::string>(18, "18"));
		// test.insert(LIB::pair<int, std::string>(20, "20"));
		// test.insert(LIB::pair<int, std::string>(31, "31"));
		// test.insert(LIB::pair<int, std::string>(87, "87"));
		// std::cout << "Max_size of map with elements" << '\n';
		// std::cout << test.max_size() << '\n' << '\n';

		// test.clear();
		// std::cout << "Max_size map after being cleared" << '\n';
		// std::cout << test.max_size() << '\n' << '\n';
	}
	{
		// std::cout << "***************Testing operator[]***************" << '\n';
		// LIB::map<int, std::string> test;
		// std::cout << "printing empty map" << '\n';
		// print_m<int, std::string>(test);
		
		// test[9] = "9";
		// test[14] = "14";
		// test[2] = "2";
		// test[21] = "21";
		// test[-7] = "-7";
		// test[-1] = "-1";
		// test[1] = "1";
		// test[61] = "61";

		// std::cout << "printing map after inserting elements with []operator" << '\n';
		// print_m<int, std::string>(test);
		// std::cout << '\n';

		// std::cout << "Printing elements accessed with operator[]" << '\n';
		// std::cout << "test[9] is: " << test[9] << '\n';
		// std::cout << "test[1] is: " << test[1] << '\n';
		// std::cout << "test[21] is: " << test[21] << '\n';
		// std::cout << "test[61] is: " << test[61] << '\n';
		// std::cout << "test[2] is: " << test[2] << '\n';
		// std::cout << "test[14] is: " << test[14] << '\n';
		// std::cout << "test[-7] is: " << test[-7] << '\n';

		// std::cout << '\n' << "Printing map test2 made from copy constructor of map test" << '\n';
		// LIB::map<int, std::string> test2(test);
		// print_m<int, std::string>(test);
		// std::cout << '\n';
		
		// std::cout << "Printing elements accessed with operator[]" << '\n';
		// std::cout << "test2[9] is: " << test2[9] << '\n';
		// std::cout << "test2[1] is: " << test2[1] << '\n';
		// std::cout << "test2[21] is: " << test2[21] << '\n';
		// std::cout << "test2[61] is: " << test2[61] << '\n';
		// std::cout << "test2[2] is: " << test2[2] << '\n';
		// std::cout << "test2[14] is: " << test2[14] << '\n';
		// std::cout << "test2[-7] is: " << test2[-7] << '\n';
	}
	{
		// std::cout << "***************Testing insert: version single parameter***************" << '\n';
		// LIB::map<int, std::string> test;

		// std::cout << "printing empty map" << '\n';
		// print_m<int, std::string>(test);
		// std::cout << '\n';
		
		// test.insert(LIB::pair<int, std::string>(5, "5"));
		// test.insert(LIB::pair<int, std::string>(7, "7"));
		// test.insert(LIB::pair<int, std::string>(-9, "-9"));
		// test.insert(LIB::pair<int, std::string>(-2, "-2"));
		// test.insert(LIB::pair<int, std::string>(18, "18"));
		// test.insert(LIB::pair<int, std::string>(20, "20"));
		// test.insert(LIB::pair<int, std::string>(31, "31"));
		// test.insert(LIB::pair<int, std::string>(87, "87"));

		// std::cout << "printing map after inserting 8 elements" << '\n';
		// print_m<int, std::string>(test);
		// std::cout << '\n';

		// std::cout << "printing map after inserting 4 extra elements" << '\n';
		// test.insert(LIB::pair<int, std::string>(1, "1"));
		// test.insert(LIB::pair<int, std::string>(0, "0"));
		// test.insert(LIB::pair<int, std::string>(3, "3"));
		// test.insert(LIB::pair<int, std::string>(-87, "-87"));
		// print_m<int, std::string>(test);
		// std::cout << '\n';
	}
	{
		// std::cout << "***************Testing insert: version hint position***************" << '\n';
		// LIB::map<int, std::string> test;
		// LIB::map<int, std::string>::iterator iter;
		// iter = test.begin();

		// std::cout << "printing empty map" << '\n';
		// print_m<int, std::string>(test);
		// std::cout << '\n';
		
		// test.insert(iter, LIB::pair<int, std::string>(5, "5"));
		// test.insert(iter, LIB::pair<int, std::string>(7, "7"));
		// test.insert(iter, LIB::pair<int, std::string>(-9, "-9"));
		// test.insert(iter, LIB::pair<int, std::string>(-2, "-2"));
		// test.insert(iter, LIB::pair<int, std::string>(18, "18"));
		// test.insert(iter, LIB::pair<int, std::string>(20, "20"));
		// test.insert(iter, LIB::pair<int, std::string>(31, "31"));
		// test.insert(iter, LIB::pair<int, std::string>(87, "87"));

		// std::cout << "printing map after inserting 8 elements" << '\n';
		// print_m<int, std::string>(test);
		// std::cout << '\n';

		// std::cout << "printing map after inserting 4 extra elements" << '\n';
		// test.insert(iter, LIB::pair<int, std::string>(1, "1"));
		// test.insert(iter, LIB::pair<int, std::string>(0, "0"));
		// test.insert(iter, LIB::pair<int, std::string>(3, "3"));
		// test.insert(iter, LIB::pair<int, std::string>(-87, "-87"));
		// print_m<int, std::string>(test);
		// std::cout << '\n';
	}
	{
		// std::cout << "***************Testing insert: version iterator***************" << '\n';
		// LIB::map<int, std::string> test;		
		// LIB::map<int, std::string> test2;
		// test.insert(LIB::pair<int, std::string>(5, "5"));
		// test.insert(LIB::pair<int, std::string>(7, "7"));
		// test.insert(LIB::pair<int, std::string>(-9, "-9"));
		// test.insert(LIB::pair<int, std::string>(-2, "-2"));
		// test.insert(LIB::pair<int, std::string>(18, "18"));
		// test.insert(LIB::pair<int, std::string>(20, "20"));
		// test.insert(LIB::pair<int, std::string>(31, "31"));
		// test.insert(LIB::pair<int, std::string>(87, "87"));

		// LIB::map<int, std::string>::iterator first = test.begin();
		// LIB::map<int, std::string>::iterator last = test.end();
		
		// std::cout << "printing empty map test2" << '\n';
		// print_m<int, std::string>(test2);
		// std::cout << '\n';
		
		// test2.insert(first, last);
		// std::cout << "printing map after inserting all the elements of test" << '\n';
		// print_m<int, std::string>(test2);
		// std::cout << '\n';

		// LIB::map<int, std::string> test3;
		// first = test2.find(-2);
		// last = test2.find(31);

		
		// test3.insert(first, last);
		// std::cout << "printing map after inserting all the elements between two keys" << '\n';
		// print_m<int, std::string>(test3);
		// std::cout << '\n';

		// first++;
		// last--;
		// LIB::map<int, std::string> test4;
		// test4.insert(first, last);
		// std::cout << "printing map after inserting all the elements between two keys" << '\n';
		// print_m<int, std::string>(test4);
		// std::cout << '\n';
	}
	{
		//erase position
		std::cout << "***************Testing erase: version position***************" << '\n';
		LIB::map<int, std::string> test;
		
		test.insert(LIB::pair<int, std::string>(5, "5"));
		test.insert(LIB::pair<int, std::string>(7, "7"));
		test.insert(LIB::pair<int, std::string>(-9, "-9"));
		test.insert(LIB::pair<int, std::string>(-2, "-2"));
		test.insert(LIB::pair<int, std::string>(18, "18"));
		test.insert(LIB::pair<int, std::string>(20, "20"));
		test.insert(LIB::pair<int, std::string>(31, "31"));
		test.insert(LIB::pair<int, std::string>(87, "87"));
		
		std::cout << "printing map after inserting 8 elements" << '\n';
		print_m<int, std::string>(test);
		std::cout << '\n';
		
		LIB::map<int, std::string>::iterator found;
		found = test.find(-2);
		test.erase(found);
		std::cout << "printing map after deleting the element at the position of key -2" << '\n';
		print_m<int, std::string>(test);
		std::cout << '\n';

		found = test.find(31);
		test.erase(found);
		std::cout << "printing map after deleting the element at the position of key 31" << '\n';
		print_m<int, std::string>(test);
		std::cout << '\n';

		found = test.find(5);
		test.erase(found);
		std::cout << "printing map after deleting the element at the position of key 5" << '\n';
		print_m<int, std::string>(test);
		std::cout << '\n';

		// found = test.find(18);
		// test.erase(found);
		// std::cout << "printing map after deleting the element at the position of key 31" << '\n';
		// print_m<int, std::string>(test);
		// std::cout << '\n';

		// found = test.find(-9);
		// test.erase(found);
		// std::cout << "printing map after deleting the element at the position of key 31" << '\n';
		// print_m<int, std::string>(test);
		// std::cout << '\n';
	}
	{
		//erase key	
	}
	{
		//erase iterator
	}
	{
		//swap
	}
	{
		// std::cout << "***************Testing clear***************" << '\n';
		// LIB::map<int, std::string> test;
		// std::cout << "printing empty map" << '\n';
		// print_m<int, std::string>(test);
		// std::cout << '\n';
		// test.insert(LIB::pair<int, std::string>(5, "5"));
		// test.insert(LIB::pair<int, std::string>(7, "7"));
		// test.insert(LIB::pair<int, std::string>(-9, "-9"));
		// test.insert(LIB::pair<int, std::string>(-2, "-2"));
		// test.insert(LIB::pair<int, std::string>(18, "18"));
		// test.insert(LIB::pair<int, std::string>(20, "20"));
		// test.insert(LIB::pair<int, std::string>(31, "31"));
		// test.insert(LIB::pair<int, std::string>(87, "87"));
		// std::cout << "printing map after inserting 8 elementes" << '\n';
		// print_m<int, std::string>(test);
		// std::cout << '\n';
		// test.clear();
		// std::cout << "printing map after clearing it" << '\n';
		// print_m<int, std::string>(test);
	}
	return (0);
}
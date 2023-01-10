/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcamaren <pcamaren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:59:30 by pcamaren          #+#    #+#             */
/*   Updated: 2023/01/10 03:11:16 by pcamaren         ###   ########.fr       */
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
		// std::cout << "Testing empty constructor" << '\n';
		// LIB::map<int, std::string> test;
		// LIB::map<int, std::string> test1;
		// LIB::map<int, std::string> test2;
		// LIB::map<int, std::string> test3;
		// LIB::map<int, std::string> test4;
	}
	{
		/*Testing copy constructor*/
		// std::cout << "Testing copy constructor" << '\n';
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
		// std::cout << "Testing copy constructor" << '\n';
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
		// std::cout << "Testing copy constructor" << '\n';
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
		// std::cout << "Testing begin()" << '\n';
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
	// 	std::cout << "Testing end()" << '\n';
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
	// std::cout << "Testing rbegin()" << '\n';
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
	// 	std::cout << "Testing rend()" << '\n';
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
		// /*Testing empty*/
		// std::cout << "Testing empty" << '\n';
		// LIB::map<int, std::string> test;
		
		// test.insert(LIB::pair<int, std::string>(5, "5"));
		// test.insert(LIB::pair<int, std::string>(7, "7"));
		// test.insert(LIB::pair<int, std::string>(-9, "-9"));
		// test.insert(LIB::pair<int, std::string>(-2, "-2"));
		// test.insert(LIB::pair<int, std::string>(18, "18"));
		// test.insert(LIB::pair<int, std::string>(20, "20"));
		// test.insert(LIB::pair<int, std::string>(31, "31"));
		// test.insert(LIB::pair<int, std::string>(87, "87"));
	}
	{
		//size
	}
	{
		//max_size
	}
	{
		// operator[]
	}
	{
		//insert val
	}
	{
		//insert position
	}
	{
		//insert iterator
	}
	{
		//erase position
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
		// clear
		std::cout << "Testing clear" << '\n';
		LIB::map<int, std::string> test;
		std::cout << "printing empty map" << '\n';
		print_m<int, std::string>(test);
		test.insert(LIB::pair<int, std::string>(5, "5"));
		test.insert(LIB::pair<int, std::string>(7, "7"));
		test.insert(LIB::pair<int, std::string>(-9, "-9"));
		test.insert(LIB::pair<int, std::string>(-2, "-2"));
		test.insert(LIB::pair<int, std::string>(18, "18"));
		test.insert(LIB::pair<int, std::string>(20, "20"));
		test.insert(LIB::pair<int, std::string>(31, "31"));
		test.insert(LIB::pair<int, std::string>(87, "87"));
		std::cout << "printing map" << '\n';
		print_m<int, std::string>(test);
		test.clear();
		std::cout << "printing map after clear" << '\n';
		print_m<int, std::string>(test);
	}
	{
	// 	ft::map<int, std::string> test;
	// 	test.insert(ft::pair<int, std::string>(5, "5"));
	// 	test.insert(ft::pair<int, std::string>(7, "7"));
	// 	test.insert(ft::pair<int, std::string>(-9, "-9"));
	// 	test.insert(ft::pair<int, std::string>(-2, "-2"));
	// 	test.insert(ft::pair<int, std::string>(18, "18"));
	// 	test.insert(ft::pair<int, std::string>(20, "20"));
	// 	test.insert(ft::pair<int, std::string>(31, "31"));
	// 	test.insert(ft::pair<int, std::string>(87, "87"));
	// 	test.insert(ft::pair<int, std::string>(1, "-1"));
	// 	test.insert(ft::pair<int, std::string>(23, "23"));
	// 	test.insert(ft::pair<int, std::string>(4, "4"));
	// 	test.insert(ft::pair<int, std::string>(12, "12"));
	// 	test.insert(ft::pair<int, std::string>(41, "41"));
	// 	test.insert(ft::pair<int, std::string>(37, "37"));
	// 	test.insert(ft::pair<int, std::string>(89, "89"));
	// 	test.insert(ft::pair<int, std::string>(14, "14"));
	// 	test.insert(ft::pair<int, std::string>(13, "13"));
	// 	test.insert(ft::pair<int, std::string>(2, "2"));
	// 	test.insert(ft::pair<int, std::string>(100, "100"));
	// 	test.insert(ft::pair<int, std::string>(8, "8"));
	// 	test.insert(ft::pair<int, std::string>(49, "49"));
	// 	// print_m<int, std::string>(test);
	// 	ft::map<int, std::string> test2;
	// 	std::cout << "___________________________________________" << '\n';
	// 	test2 = test;
	// 	test.insert(ft::pair<int, std::string>(20, "20"));
	// 	ft::map<int, std::string>::iterator iter;
	// 	iter = test2.find(100);
	// // 	// std::cout << "it:find: " << it_find->first << " => " << it_find->second << '\n';
	// 	print_m<int, std::string>(test2);
	}
	{
	// 	{
	// 	ft::pair<int, std::string>	my_pair(8, "salut");
	// 	ft::map<int, std::string>	test;
	// 	ft::map<int, std::string>::iterator	it;
	// 	ft::pair<int, std::string>	my_pair2(9, "meow");
	// 	// test.insert(my_pair);
	// 	// test.insert(my_pair2);
		
	// 	// print_m<int, std::string>(test);
	// 	test.insert(ft::pair<int, std::string>(19, "machin"));
	// 	test.insert(ft::pair<int, std::string>(-4, "bar"));
	// 	test.insert(ft::pair<int, std::string>(9, "meow"));
	// 	// ft::map<int, std::string>::iterator	it_find;
	// 	// it_find = test.find(2);
	// 	// std::cout << "it:find: " << it_find->first << " => " << it_find->second << '\n';
	// 	// it_find = test.find(9);
	// 	// std::cout << "it:find: " << it_find->first << " => " << it_find->second << '\n';
	// 	// it = test.begin();
	// 	// std::cout << "it:find: " << it->first << " => " << it->second << '\n';
	// 	// it++;
	// 	// std::cout << "it: " << it->first << " => " << it->second << '\n';
	// 	// it = test.begin();
	// 	// std::cout << it->first << " => " << it->second << '\n';
	// 	// it++;
	// 	// std::cout << it->first << " => " << it->second << '\n';
	// 	// it++;
	// 	// std::cout << it->first << " => " << it->second << '\n';
	// 	// it++;
	// 	// std::cout << it->first << " => " << it->second << '\n';
	// 	// it++;
	// 	// std::cout << it->first << " => " << it->second << '\n';
	// 	// it++;
	// 	// std::cout << it->first << " => " << it->second << '\n';
		
	// 	print_m<int, std::string>(test);
	// 	// test.insert(ft::pair<int, std::string>(-4, "bar"));
	// 	// test.insert(ft::pair<int, std::string>(2, "machin"));
	// 	// test.insert(ft::pair<int, std::string>(3, "foo"));
	// 	// test.insert(ft::pair<int, std::string>(746, "Marcel"));
	// 	// test.insert(ft::pair<int, std::string>(1, "truc"));
	// 	// print_m<int, std::string>(test);
	// 	// std::cout << '\n';
	// }
	}
	return (0);
}
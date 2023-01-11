#include "../includes/tester.hpp"

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

void vector_test(void)
{
	{
		std::cout << "***************Testing Constructors and copy operator***************" << '\n';
		
		std::cout << "Empty constructor" << '\n';
		LIB::vector<int> test;
		LIB::vector<int> test2;
		LIB::vector<int> test3;
		printf_v(test, "test");
		std::cout << '\n';
		printf_v(test2, "test2");
		std::cout << '\n';
		printf_v(test3, "test3");
		std::cout << '\n';
		std::cout << '\n';
		
		std::cout << "Fill constructor" << '\n';
		LIB::vector<int> test4(8, 10);
		LIB::vector<int> test5(5, 8);
		LIB::vector<int> test6(9, 9);
		printf_v(test4, "test4");
		std::cout << '\n';
		printf_v(test5, "test5");
		std::cout << '\n';
		printf_v(test6, "test6");
		std::cout << '\n';
		std::cout << '\n';
		
		std::cout << "Range constructor" << '\n';
		LIB::vector<int>::iterator first = test4.begin();
		LIB::vector<int>::iterator last = test4.end();
		LIB::vector<int> test7(first, last);
		printf_v(test7, "test7");
		std::cout << '\n';
		first++;
		last--;
		LIB::vector<int> test8(first, last);
		printf_v(test8, "test8");
		std::cout << '\n';
		std::cout << '\n';

		std::cout << "Copy constructor" << '\n';
		LIB::vector<int> test9(test5);
		LIB::vector<int> test10(test6);
		printf_v(test9, "test9");
		std::cout << '\n';
		printf_v(test10, "test10");
		std::cout << '\n';
		std::cout << '\n';

		std::cout << "Copy operator" << '\n';
		LIB::vector<int> test11;
		test11 = test7;
		printf_v(test11, "test11");
		test11 = test3;
		printf_v(test11, "test11");
		
	}
	{
		std::cout << "***************Testing iterators***************" << '\n';
		LIB::vector<int> test(8, 10);
		LIB::vector<int>::iterator start = test.begin();
		LIB::vector<int>::iterator last = test.end();
		last--;
		std::cout << "start is: " << *start << '\n';
		std::cout << "last-- is: " << *last << '\n' << '\n';

		LIB::vector<int>::const_iterator start_const = test.begin();
		std::cout << "start_const is: " << *start_const << '\n';
		
		LIB::vector<int> test2(5);

		int i=0;
		LIB::vector<int>::reverse_iterator rit = test2.rbegin();
		for (; rit!= test2.rend(); ++rit)
			*rit = ++i;
		for (LIB::vector<int>::iterator it = test2.begin(); it != test2.end(); ++it)
    		std::cout << ' ' << *it;
  		std::cout << '\n';

		LIB::vector<int> test3(5);

		i=0;
		LIB::vector<int>::reverse_iterator rit2 = test3.rbegin();
		for (; rit2!= test3.rend(); ++rit2)
			*rit2 = ++i;
		for (LIB::vector<int>::iterator it = test3.begin(); it != test3.end(); ++it)
    		std::cout << ' ' << *it;
  		std::cout << '\n';
	}
	{
		std::cout << "***************Testing Capacity***************" << '\n';
		LIB::vector<int> test(41, 10);
		std::cout << "size is: " << test.size() << '\n';
		std::cout << "max_size is: " << test.max_size() << '\n';
		std::cout << "capacity is: " << test.capacity() << '\n';
		if (test.empty())
			std::cout << "vector is empty" << '\n';
		else
			std::cout << "vector is not empty" << '\n';
		test.resize(60);
		std::cout << "new size is: " << test.size() << '\n';
		std::cout << "new capacity is: " << test.capacity() << '\n';
		test.reserve(70);
		std::cout << "new size is: " << test.size() << '\n';
		std::cout << "new capacity is: " << test.capacity() << '\n';
	}
	{
		std::cout << "***************Testing Element access***************" << '\n';
		LIB::vector<int> test(41, 10);
		test.insert(test.begin(), 7, 9);
		std::cout << "operator[]: " << test[4] << '\n';
		std::cout << "operator[]: " << test[6] << '\n';
		std::cout << "operator[]: " << test[7] << '\n';
		std::cout << "operator[]: " << test[2] << '\n';
		std::cout << "operator[]: " << test[12] << '\n';

		std::cout << "at: " << test.at(5) << '\n';
		std::cout << "at: " << test.at(15) << '\n';
		std::cout << "at: " << test.at(20) << '\n';
		std::cout << "at: " << test.at(30) << '\n';
		std::cout << "at: " << test.at(1) << '\n';

		std::cout << "front: " << test.front() << '\n';
		std::cout << "back: " << test.back() << '\n';
	}
	{
		std::cout << "***************Testing Modifiers***************" << '\n';
		LIB::vector<int> first;
		LIB::vector<int> second;
		LIB::vector<int> third;

		first.assign (7,100);             // 7 ints with a value of 100

		LIB::vector<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
		std::cout << "Size of third: " << int (third.size()) << '\n';

		first.push_back(8);
		first.push_back(9);
		first.push_back(10);
		first.push_back(62);
		first.push_back(33);
		first.push_back(1);
		first.push_back(14);
		first.push_back(87);
		first.push_back(91);
		first.push_back(22);
		first.push_back(30);
		printf_v(first, "first");
		std::cout << '\n';

		first.pop_back();
		first.pop_back();
		first.pop_back();
		first.pop_back();
		printf_v(first, "first");
		std::cout << '\n';

		first.insert(first.begin(), 13);
		printf_v(first, "first");
		std::cout << '\n';

		first.insert(first.begin(), 7, 4);
		printf_v(first, "first");
		std::cout << '\n';
		
		first.insert(first.end(), second.begin(), second.end());
		printf_v(first, "first");
		std::cout << '\n';

		LIB::vector<int>::iterator iter = first.begin();
		iter = iter + 2;
		first.erase(iter);
		printf_v(first, "first");
		std::cout << '\n';
		
		iter = first.begin();
		LIB::vector<int>::iterator iter2;
		iter2 = iter + 3;
		first.erase(iter, iter2);
		printf_v(first, "first");
		std::cout << '\n';

		first.clear();
		printf_v(first, "first");
		std::cout << '\n';
	}
	{
		std::cout << "***************Testing allocator***************" << '\n';
		LIB::vector<int> myvector;
		int * p;
		unsigned int i;

		// allocate an array with space for 5 elements using vector's allocator:
		p = myvector.get_allocator().allocate(5);

		// construct values in-place on the array:
		for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

		std::cout << "The allocated array contains:";
		for (i=0; i<5; i++) std::cout << ' ' << p[i];
		std::cout << '\n';

		// destroy and deallocate:
		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
		myvector.get_allocator().deallocate(p,5);
	}
	{
		std::cout << "***************Testing relational operators***************" << '\n';
		LIB::vector<int> foo (3,100);
		LIB::vector<int> bar (2,200);

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
	{
		std::cout << "***************Testing swap***************" << '\n';
		LIB::vector<int> foo (3,100);   // three ints with a value of 100
		LIB::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		std::cout << "foo contains:";
		for (LIB::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';

		std::cout << "bar contains:";
		for (LIB::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
}
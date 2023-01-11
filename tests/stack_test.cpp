#include "../includes/tester.hpp"

void stack_test(void)
{
	LIB::stack<float> other_stack;
	LIB::vector<std::string> lst;

	lst.push_back("meow");
	lst.push_back("woof");
	lst.push_back("quack");
	lst.push_back("oink oink");

	LIB::stack<std::string, LIB::vector<std::string> >	my_stack(lst);
	LIB::stack<std::string, LIB::vector<std::string> >	my_stack2(lst);
	

	std::cout << std::boolalpha << other_stack.empty() << std::endl;
	other_stack.push(8.5); 
	other_stack.push(42.4242);
	std::cout << other_stack.size() << '\n';
	other_stack.pop();
	std::cout << other_stack.size() << '\n';
	other_stack.push(78541.987);
	std::cout << other_stack.size() << '\n';
	std::cout << other_stack.top() << '\n';
	std::cout << std::boolalpha << other_stack.empty() << std::endl;

	const std::string const_top = my_stack.top();

	std::cout << "const top: " << const_top << '\n';

	while (!my_stack.empty())
	{
		std::cout << my_stack.top() << '\n';
		my_stack.pop();
	}
}
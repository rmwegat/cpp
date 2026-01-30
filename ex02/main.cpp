#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	std::string input;
	PmergeMe merge;
	for (int i = 1; i < argc; i++)
	{
		input.append(argv[i]);
		input.append(" ");
	}
	int range = 0;
	for (int i = 0; i < (int)input.size(); i++)
		if (input[i] == ' ')
			range++;
	std::cout << "Before:	" << input << std::endl;
	try
	{
		merge.sortlist(input);
		merge.sortDeque(input);
		merge.compare_sorts();
		std::cout << "After:	";
		merge.print_deque();
		std::cout << "Time to process a range of	" << range << "	with std::list :	" << merge.getListTime() << " µs" << std::endl;
		std::cout << "Time to process a range of	" << range << "	with std::deque :	" << merge.getDequeTime() << " µs" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	int debug = 1;
	if (debug == 1)
	{
		std::list<int>& list = merge.getList();
		if (std::is_sorted(list.begin(), list.end()) == true)
			std::cout << "PASS" << std::endl;
		else
			std::cout << "FAIL" << std::endl;
	}
	return (0);
}
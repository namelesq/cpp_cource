#include <iostream>
std::string changeSpaces(std::string str)
{
	size_t size= str.size();
	for (size_t i = 0; i < size; i++)
	{
		if (str[i] == ' ')
		{
			str[i] = '\t';
		}
	}
	return str;
}
int main()
{
	std::string expo;
	std::cout << "Enter string: ";
	std::cin >> expo;
	std::string new_s = changeSpaces(expo);
	std::cout << "New string: "<<new_s;
	return 0;
}
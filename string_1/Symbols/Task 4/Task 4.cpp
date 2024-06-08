#include <iostream>
bool palindrome(std::string str)
{
	size_t size = str.size();
	std::string oth_str;
	int k = 0;
	for (int i = size; i > 0; i--)
	{
		oth_str[k] == str[i];
		k++;
	}
	if (oth_str == str)
	{
		std::cout << "You string is a palindrome";
		return true;
	}
	else
	{
		std::cout << "You string is not a palindrome";
		return false;
	}
}
int main()
{
	std::string str;
	std::cout << "enter string: ";
	std::cin >> str;
	bool flag = palindrome(str);
	std::cout << flag;
	return 0;
}
#include <iostream>
int QuantityWords(std::string str)
{
	size_t size = str.size();
	int words = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (str[i] == ' ')
		{
			words++;
		}
	}
	std::cout << "Quantity words: " << words;
	return words;
}
int main()
{
	std::string str;
	std::cout << "Enter string: ";
	std::cin >> str;
	int func = QuantityWords(str);
	std::cout << func;
	return 0;
}
#include <iostream>
#include <string>
std::string serachDigitsAlph(std::string str)
{
	size_t size = str.size();
	int dig, alph, other;
	for (size_t i = 0; i < size; i++)
	{
		if (isdigit(str[i]))
		{
			dig++;
		}
		else if (isalpha(str[i]))
		{
			alph++;
		}
		else
		{
			other++;
		}
	}
	std::cout << "Digits: " << dig << "\nAlphas: " << alph << "\nOther: " << other;
	return str;
}
int main()
{
	std::string str;
	std::cout << "Enter string: ";
	std::cin >> str;
	std::string new_r = serachDigitsAlph(str);
	std::cout << new_r;
	return 0;
}
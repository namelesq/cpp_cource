#include <iostream>
#include <string>
void delete_symb(std::string expo) {
	int index;
	std::cout << "Enter index element for delete: ";
	std::cin >> index;
	for (int i = 0; i < size(expo); i++) {
		if (i == index) {
			expo.erase(index, 1);
			break;
		}
	}
	std::cout << "New string: " << expo;
}
void func_2(std::string& expo, char symb) {
	int quantity = 0;
	for (int i = 0; i < size(expo); i++) {
		if (expo[i] == symb) {
			quantity += 1;
		}
	}
	for (int i = 0; i < size(expo); i++) {
		if (expo[i] == symb) {
			expo.erase(symb, quantity);
		}
	}
	std::cout << "New string: " << expo;
}
void input_symb(char str[50], char symbol, int position) {
	for (size_t i = 0; i < strlen(str); i++) {
		if (position == i) {
			str[i] = symbol;
		}
	}
	std::cout << "You string: " << str;
}
int main() {
	std::cout << "Task 1\n";
	std::string str;
	std::cout << "Enter string: ";
	std::cin >> str;
	delete_symb(str);

	std::cout << "\nTask 2\n";
	std::string str_1;
	char symbol;
	std::cout << "Enter string: ";
	std::cin >> str_1;
	std::cout << "Enter symbol to remove it from the string: ";
	std::cin >> symbol;
	func_2(str_1, symbol);

	std::cout << "\nTask 3\n";
	char str_c[50];
	char symbol_a;
	int pos_on;
	std::cout << "Enter string: ";
	std::cin >> str_c;
	std::cout << "Enter symbol: ";
	std::cin >> symbol_a;
	std::cout << "Enter position: ";
	std::cin >> pos_on;
	input_symb(str_c, symbol_a, pos_on);
	std::cout << "\nTask 4\n";
	char str_2[50];
	std::cout << "Enter string: ";
	std::cin >> str_2;
	for (size_t i = 0; i < strlen(str_2); i++) {
		if (str_2[i] == '.') {
			str_2[i] = '!';
		}
	}
	std::cout << "New string: " << str_2;
	std::cout << "\nTask 5\n";
	char str_d[50];
	std::cout << "Enter string: ";
	std::cin >> str_d;
	char symb_d;
	std::cout << "Enter symbol: ";
	std::cin >> symb_d;
	int summ = 0;
	for (int i = 0; i < strlen(str_d); i++)
	{
		if (str_d[i] == symb_d)
		{
			summ++;
		}
	}
	std::cout << "Quantity your symbol in string: " << summ;
	std::cout << "\nTask 6\n";
	short numbers = 0, letters = 0, other = 0;
	char str_f[50];
	std::cout << "Enter string: ";
	std::cin >> str_f;
	for (int i = 0; i < strlen(str_f); i++) {
		if (isalpha(str_f[i])) {
			letters++;
		}
		else if (isdigit(str_f[i])) {
			numbers++;
		}
		else {
			other++;
		}
	}
	std::cout << "Quantity numbers: " << numbers << "\nQuantity letters: " << letters << "\nQuantity others: " << other;
	return 0;

}
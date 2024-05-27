#include <iostream>
#include <string>
#include<cctype>
#include <map>
std::string ReplaceWordByText(std::string text, std::string const& word, std::string const& word_ch) {
	size_t size = text.find(word_ch);
	if (size != std::string::npos) {
		text.replace(size, word_ch.length(), word);
	}
	return text;
}
std::string Upper(std::string text) {
	bool capitalize = true;
	for (size_t i = 0; i < text.length(); ++i) {
		if (capitalize && isalpha(text[i])) {
			text[i] = toupper(text[i]);
			capitalize = false;
		}
		else if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
			capitalize = true;
		}
	}
	return text;
}

int main() {
	std::string text = "Martha also needs 2 bags of flour and 2 bags of sugar. flour costs 3 dollars per 5-pound bag. sugar costs 4 dollars per 5-pound bag. it costs 6 dollars for the flour and 8 dollars for the sugar. together, they cost 14 dollars.";
	std::string word, word_ch;
	std::cout << "Enter word: ";
	std::cin >> word;
	std::cout << "Enter word for change: ";
	std::cin >> word_ch;
	std::cout << "New text: " << ReplaceWordByText(text, word, word_ch);
	std::cout << "\n\n";
	std::cout << "New text: " << Upper(text);
	std::map<char, int> letterCount;
	for (char c : text) {
		if (isalpha(c)) {
			letterCount[tolower(c)]++;
		}
	}
	int digitCount = 0;
	for (char c : text) {
		if (isdigit(c)) {
			digitCount++;
		}
	}
	std::cout << "\n\nLetter count:\n";
	for (const auto& pair : letterCount) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	}
	std::cout << "\nQuantity digit: " << digitCount;
	return 0;
}

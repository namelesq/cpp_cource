
#include <iostream>
#include <vector>
#include <string>
using namespace std;
union Number {
	int numeric;
	char word[8];
};
struct Car {
	std::string color;
	std::string model;
	Number number;
};
void fillCar(Car& car) {
	std::cout << "Enter color: ";
	std::cin >> car.color;
	std::cout << "Enter model: ";
	std::cin >> car.model;
	std::cout << "Enter number (numeric or word): ";
	std::cin >> car.number.numeric;
}
void printCar(Car car) {
	std::cout << "Color: " << car.color;
	std::cout << "Model: " << car.model;
	if (isdigit(car.number.word[0])) {
		std::cout << "Number: " << car.number.numeric;
	}
	else {
		std::cout << "Number: " << car.number.word;
	}
}
void editCar(vector<Car>& cars, int index) {
	fillCar(cars[index]);
}
void printAllCars(vector<Car> cars) {
	for (Car car : cars) {
		printCar(car);
		cout << endl;
	}
}
void searchCar(vector<Car> cars, int searchNumber) {
	for (Car car : cars) {
		if (isdigit(car.number.word[0])) {
			if (car.number.numeric == searchNumber) {
				printCar(car);
			}
		}
		else {
			string word(car.number.word);
			if (word == to_string(searchNumber)) {
				printCar(car);
			}
		}
	}
}
int main() {
	vector<Car> cars(10);
	fillCar(cars[0]);
	fillCar(cars[1]);
	fillCar(cars[2]);
	editCar(cars, 1);
	printAllCars(cars);
	searchCar(cars, 12345);
	return 0;
}
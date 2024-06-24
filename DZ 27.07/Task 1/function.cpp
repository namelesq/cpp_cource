#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include "function.h"
void InputdataInVectorInt(std::vector<int>& data)
{
	srand(time(NULL));
	for (size_t i = 0; i < 20; i++)
	{
		data.push_back(rand()%30);
	}
}
void printVectorInt(std::vector<int>& data)
{
	std::cout << "{";
	for (size_t i = 0; i < 20; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << "}\n";
}	
void SearchMinMeaningInt(std::vector<int>& data)
{
	int min = data[0];
	for (size_t i = 0; i < 20; i++)
	{
		if (data[i] < min)
		{
			min = data[i];
		}
	}
	std::cout << "Minimal meaning: " << min<<"\n";
}
void SearchMaxMeaningInt(std::vector<int>& data)
{
	int max = data[0];
	for (size_t i = 0; i < 20; i++)
	{
		if (data[i] > max)
		{
			max = data[i];
		}
	}
	std::cout << "\nMaximal meaning: " << max << "\n";
}
void VectorSortInt(std::vector<int>& data)
{
	size_t length = 20;
	while (length--)
	{
		bool swapped = false;
		for (size_t i = 0; i < length; i++)
		{
			if (data[i] > data[i + 1])
			{
				std::swap(data[i], data[i + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
	std::cout << "Array with sorted data: \n";
	printVectorInt(data);
}
void editVectorInt(std::vector<int>& data)
{
	size_t index;
	std::cout << "Enter index element for edit meaning: ";
	std::cin >> index;
	for(size_t i = 0; i < 20; i++)
	{
		int new_mean;
		if (i == index-1)
		{
			std::cout << "Enter new meaning: ";
			std::cin >> new_mean;
			data[i] = new_mean;
		}
	}
	std::cout << "Array with edit data: \n";
	printVectorInt(data);
}
void InputdataInVectorDouble(std::vector<double>& data)
{
	srand(time(NULL));
	for (size_t i = 0; i < 20; i++)
	{
		data.push_back((double)(1+rand() % 30)/30);
	}
}
void printVectorDouble(std::vector<double>& data)
{
	std::cout << "{";
	for (size_t i = 0; i < 20; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << "}\n";
}
void SearchMinMeaningDouble(std::vector<double>& data)
{
	double min = data[0];
	for (size_t i = 0; i < 20; i++)
	{
		if (data[i] < min)
		{
			min = data[i];
		}
	}
	std::cout << "Minimal meaning: " << min << "\n";
}
void SearchMaxMeaningDouble(std::vector<double>& data)
{
	double max = data[0];
	for (size_t i = 0; i < 20; i++)
	{
		if (data[i] > max)
		{
			max = data[i];
		}
	}
	std::cout << "\nMaximal meaning: " << max << "\n";
}
void VectorSortDouble(std::vector<double>& data)
{
	size_t length = 20;
	while (length--)
	{
		bool swapped = false;

		for (size_t i = 0; i < length; i++)
		{
			if (data[i] > data[i + 1])
			{
				std::swap(data[i], data[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
	std::cout << "Array with sorted data: \n";
	printVectorDouble(data);
}
void editVectorDouble(std::vector<double>& data)
{
	size_t index;
	std::cout << "Enter index element for edit meaning: ";
	std::cin >> index;
	for (size_t i = 0; i < 20; i++)
	{
		double new_mean;
		if (i == index-1)
		{
			std::cout << "Enter new meaning: ";
			std::cin >> new_mean;
			data[i] = new_mean;
		}
	}
	std::cout << "Array with edit data: \n";
	printVectorDouble(data);
}
void InputDataInVectorChar(std::vector<char>& data)
{
	srand(time(NULL));
	for (size_t i = 0; i < 20; i++)
	{
		data.push_back(rand() % 255);
	}
}
void printVectorChar(std::vector<char>& data)
{
	std::cout << "{";
	for (size_t i = 0; i < 20; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << "}\n";
}
void SearchMinMeaningChar(std::vector<char>& data)
{
	char min = data[0];
	for (size_t i = 0; i < 20; i++)
	{
		if (data[i] < min)
		{
			min = data[i];
		}
	}
	std::cout << "Minimal meaning: " << min << "\n";
}
void SearchMaxMeaningChar(std::vector<char>& data)
{
	char max = data[0];
	for (size_t i = 0; i < 20; i++)
	{
		if (data[i] > max)
		{
			max = data[i];
		}
	}
	std::cout << "\nMaximal meaning: " << max << "\n";
}
void VectorSortChar(std::vector<char>& data)
{
	size_t length = 20;
	while (length--)
	{
		bool swapped = false;

		for (size_t i = 0; i < length; i++)
		{
			if (data[i] > data[i + 1])
			{
				std::swap(data[i], data[i + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
	std::cout << "Array with sorted data: \n";
	printVectorChar(data);
}
void editVectorChar(std::vector<char>& data)
{
	size_t index;
	char new_mean;
	std::cout << "Enter index for edit meaning: ";
	std::cin >> index;;
	for (size_t i = 0; i < 20; i++)
	{
		if (i == index-1)
		{
			std::cout << "Enter new meaning: ";
			std::cin >> new_mean;
			data[i] = new_mean;
		}
	}
	std::cout << "Array with edit data: \n";
	printVectorChar(data);
}
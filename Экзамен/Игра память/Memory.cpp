

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment(lib,"winmm.lib")


void PrintGameField(std::vector<char> field, int size)
{
	std::cout << "You game field: \n";
	for (int i = 0; i < field.size(); i++)
	{
		std::cout << field[i] << " ";
		if (i == 0)
		{
		}
		else if ((i+1) % size == 0)
		{
			std::cout << "\n";
		}
	}
	std::cout << "\n\n";
}

void TheGameProcess(std::vector<char> field,std::vector<char> FieldPlayers, int rows)
{
	short int pointPlayer1=0, pointPlayer2=0;

	while (true)
	{
		int position1, position2, index1,index2;
		char meaning1, meaning2;

		if (std::count(field.begin(), field.end(), '*') == field.size())
		{
			std::cout << "Quantity points at Player 1: " << pointPlayer1 << "\n";
			std::cout << "Quantity point at Player 2: " << pointPlayer2;
			if (pointPlayer1 > pointPlayer2)
			{
				std::cout << "\n\nPlayer 1 is winner!\n";
			}
			else if (pointPlayer1 == pointPlayer2)
			{
				std::cout << "\n\nDraw!";
			}
			else
			{
				std::cout << "\n\nPlayer 2 is winner!\n";
			}
			break;
		}

		std::cout << "\nPlayer 1, enter the card position\nfirst card: ";
		std::cin >> position1;
		std::cout << "Second card: ";
		std::cin >> position2;
		for (int i = 0; i < field.size(); i++)
		{
			if (i == position1)
			{
				meaning1 = field[i];
				index1 = i;
			}
			if (i == position2)
			{
				meaning2 = field[i];
				index2 = i;
			}
		}

		if (meaning1 == meaning2)
		{
			PlaySound(TEXT("completed.wav"), NULL, SND_FILENAME | SND_SYNC);
			std::cout << "You guessed a couple of numbers!\n";
			pointPlayer1++;
			field[index1]= '*';
			field[index2]= '*';
			FieldPlayers[index1] = ' ';
			FieldPlayers[index2] = ' ';
			PrintGameField(FieldPlayers,rows);

			while (std::count(field.begin(), field.end(), '*') != field.size())
			{
				std::cout << "Enter first card position: ";
				std::cin >> position1;
				std::cout << "Enter second card position: ";
				std::cin >> position2;
				for (int i = 0; i < field.size(); i++)
				{
					if (i == position1)
					{
						meaning1 = field[i];
						index1 = i;
					}

					if (i == position2)
					{
						meaning2 = field[i];
						index2 = i;
					}
				}

				if (meaning1 == meaning2)
				{
					PlaySound(TEXT("completed.wav"), NULL, SND_FILENAME | SND_SYNC);
					std::cout << "You guessed a couple of numbers!\n";
					pointPlayer1++;
					field[index1]= '*';
					field[index2]= '*';
					FieldPlayers[index1] = ' ';
					FieldPlayers[index2] = ' ';
					PrintGameField(FieldPlayers, rows);
					continue;
				}
				else
				{
					PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_SYNC);
					std::cout << "You have different cards, passing the move to another player";
					break;
				}
			}
			
		}
		else
		{
			PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_SYNC);
			std::cout << "You have different cards, passing the move to another player\n";
		}

		if (std::count(field.begin(), field.end(), '*') == field.size())
		{
			std::cout << "Quantity points at Player 1: " << pointPlayer1 << "\n";
			std::cout << "Quantity point at Player 2: " << pointPlayer2;
			break;
		}

		std::cout << "\nPlayer 2, enter the card position\nfirst card: ";
		std::cin >> position1;
		std::cout << "Second card: ";
		std::cin >> position2;

		for (int i = 0; i < field.size(); i++)
		{
			if (i == position1)
			{
				meaning1 = field[i];
				index1 = i;
			}

			if (i == position2)
			{
				meaning2 = field[i];
				index2 = i;
			}
		}

		if (meaning1 == meaning2)
		{
			PlaySound(TEXT("completed.wav"), NULL, SND_FILENAME | SND_SYNC);
			std::cout << "You guessed a couple of numbers!\n";
			pointPlayer2++;
			field[index1] = '*';
			field[index2]= '*';
			FieldPlayers[index1] = ' ';
			FieldPlayers[index2] = ' ';
			PrintGameField(FieldPlayers, rows);

			while (std::count(field.begin(), field.end(), '*')!=field.size())
			{
				std::cout << "Enter first card position: ";
				std::cin >> position1;
				std::cout << "Enter second card position: ";
				std::cin >> position2;
				for (int i = 0; i < field.size(); i++)
				{
					if (i == position1)
					{
						meaning1 = field[i];
						index1 = i;
					}

					if (i == position2)
					{
						meaning2 = field[i];
						index2 = i;
					}
					
				}

				if (meaning1 == meaning2)
				{
					PlaySound(TEXT("completed.wav"), NULL, SND_FILENAME | SND_SYNC);
					std::cout << "You guessed a couple of numbers!\n";
					pointPlayer2++;
					field[index1] = '*';
					field[index2]= '*';
					FieldPlayers[index1] = ' ';
					FieldPlayers[index2] = ' ';
					PrintGameField(FieldPlayers, rows);
					continue;
				}
				else
				{
					PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_SYNC);
					std::cout << "You have different cards, passing the move to another player\n";
					break;
				}
			}
		}
		else
		{
			PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_SYNC);
			std::cout << "You have different cards, passing the move to another player\n";
		}
	}
}

int main() 
{
	
	std::cout << "------------------------Game Memory-----------------------\n\n";
	int size;
	std::cout << "Enter the dimension of the field (2,4,6): ";
	std::cin >> size;
	std::vector<char> GameField;
	std::vector<char> FieldForPlayers;
	char symbol_pl = '&';
	for (int i = 0; i < size * 2; i++)
	{
		FieldForPlayers.push_back(symbol_pl);
		FieldForPlayers.push_back(symbol_pl);
	}
	clock_t start, end;
	for (int i = 0; i < size * 2; i++)
	{
		char symbol = rand() % 256;
		GameField.push_back(symbol);
		GameField.push_back(symbol);
	}
	std::random_shuffle(GameField.begin(), GameField.end());
	PrintGameField(FieldForPlayers, size); 
	start = clock();
	TheGameProcess(GameField,FieldForPlayers, size);
	end = clock();
	double seconds = (double)(end - start) / 1000;
	std::cout << "\nGame time: " << seconds << " seconds";
	return 0;
}


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
		else if ((i + 1) % size == 0)
		{
			std::cout << "\n";
		}
	}
	std::cout << "\n";
}

void PlayErrorMusic()
{
	PlaySound(TEXT("error.wav"), NULL, SND_FILENAME | SND_SYNC);
	std::cout << "You have different cards, passing the move to another player\n";
}

void PlayCompletedMusic()
{
	PlaySound(TEXT("completed.wav"), NULL, SND_FILENAME | SND_SYNC);
	std::cout << "You guessed a couple of numbers!\n";
}

char SearchElementsFirstPosition(std::vector<char> field, int pos1)
{
	char mean1;
	for (int i = 0; i < field.size(); i++)
	{
		if (i == pos1)
		{
			mean1 = field[i];
		}
	}
	return mean1;
}

char SearchElememntsSecondPosition(std::vector<char> field, int pos2)
{
	char mean2;
	for (int i = 0; i < field.size(); i++)
	{
		if (i == pos2)
		{
			mean2 = field[i];
		}
	}
	return mean2;
}

int isEndGame(std::vector<char> field)
{
	return std::count(field.begin(), field.end(), '*') == field.size();
}

int PrintPlayerNumber(bool isFirstPlayer)
{
	return isFirstPlayer ? 1 : 2;
}

void TheGameProcess(std::vector<char> field, std::vector<char> fieldPlayers, int size)
{
	int pointPlayer1 = 0, pointPlayer2 = 0;
	bool isFirstPlayer = true;

	while (true)
	{
		if (isEndGame(fieldPlayers))
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

		int position1, position2;
		std::cout << "\nPlayer " << PrintPlayerNumber(isFirstPlayer) << ", enter the card position\nfirst card : ";
		std::cin >> position1;
		std::cout << "Second card: ";
		std::cin >> position2;
		char meaning1 = SearchElementsFirstPosition(field, position1);
		char meaning2 = SearchElememntsSecondPosition(field, position2);
		if (meaning1 == meaning2)
		{
			PlayCompletedMusic();
			isFirstPlayer ? pointPlayer1++ : pointPlayer2++;
			fieldPlayers[position1] = '*';
			fieldPlayers[position2] = '*';
			PrintGameField(fieldPlayers, size);
			continue;
		}
		else
		{
			PlayErrorMusic();
			isFirstPlayer = !isFirstPlayer;
		}
	}
}

int main()
{
	std::cout << "------------------------Game Memory-----------------------\n\n";
	int size;
	const int SizeMultiplier = 2;
	const int Allsymbols = 256;
	const int TimeDivider = 1000;
	std::cout << "Enter the dimension of the field (2,4,6): ";
	std::cin >> size;
	std::vector<char> GameField;
	std::vector<char> FieldForPlayers;
	char symbol_pl = '&';
	for (int i = 0; i < size * SizeMultiplier; i++)
	{
		FieldForPlayers.push_back(symbol_pl);
		FieldForPlayers.push_back(symbol_pl);
	}
	clock_t start, end;
	for (int i = 0; i < size * SizeMultiplier; i++)
	{
		char symbol = rand() % Allsymbols;
		GameField.push_back(symbol);
		GameField.push_back(symbol);
	}
	std::random_shuffle(GameField.begin(), GameField.end());
	PrintGameField(FieldForPlayers, size);
	start = clock();
	TheGameProcess(GameField, FieldForPlayers, size);
	end = clock();
	double seconds = (double)(end - start) / TimeDivider;
	std::cout << "\nGame time: " << seconds << " seconds";
	return 0;
}
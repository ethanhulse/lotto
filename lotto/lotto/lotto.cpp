// lotto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
//Main driver file for 'lotto' project
#include <iostream> //For cout and cin
#include <string> //for string
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //For randint
#include <vector> //For vector
#include <iomanip> //For setw
#include <cstdlib>
using std::rand;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int randint(int a, int b)
{
	return rand() % b + (a + 1);
}
class LottoGame
{
public:
	LottoGame() {} //Default Constructor
	~LottoGame() {} //Destruct
	LottoGame(int n) //Parameterized Constructor
	{
		this->n = n;
	}

private:
	int n; //User choice for number of tips
	vector <vector<int>> userTips;
	int winningTip[6];

public:
	//GenerateTips, creates an integer array and fills it with 6 random numbers in specified range. [1,49] inclusive
	//Adds the array to the vector of tickets userTips, only if the size of the vector is not greater than the user's choice.
	void GenerateTips()
	{
		for (int j = 0; j < n + 1; j++)
		{
			vector<int> ticket;
			for (int i = 0; i < 6; i++)
			{
				ticket.push_back(randint(1, 49));
				if (j == n) this->winningTip[i] = ticket[i];
			}
			if (j < n) this->userTips.push_back(ticket);
		}
		return;
	}

	//Outputs contents of all tips
	void PrintTips()
	{
		for (int i = 0; i < this->n + 1; i++)
		{
			if (i < this->n)
			{
				cout << "Tip " << i + 1 << ": [";
				for (int j = 0; j < 6; j++)
				{
					cout << this->userTips[i][j];
					if (j < 5)
					{
						cout << ",";
					}
					else {
						cout << "]" << endl;
					}
				}
			}
			else if (i == this->n)
			{
				cout << "Winning Numbers: [";
				for (int k = 0; k < 6; k++)
				{
					cout << this->winningTip[k];
					if (k < 5)
					{
						cout << ",";
					}
					else {
						cout << "]" << endl;
					}
				}
			}
		}
		return;
	}

	//Prints matches for each ticket
	void FindMatches()
	{
		for (int i = 0; i < this->n; i++)
		{
			int ticketNum = i + 1;
			int matches = 0;
			vector<int> positions;
			for (int j = 0; j < 6; j++)
			{
				if (this->userTips[i][j] == this->winningTip[j])
				{
					matches++;
					positions.push_back(j);
				}
			}
			if (matches > 0)
			{
				cout << "Tip " << ticketNum << " had " << matches << " matches. " << endl;
			}
		}
	}

};

int main() {
	bool cont;
	do {
		//Initial Output and user input
		system("CLEAR"); //Clears console

		cout << "Lottery Simulator" << endl;
		cout << "How many tips would you like to buy? : ";
		int choice;
		cin >> choice;
		cout << endl << "You have bought " << choice << " tickets" << endl << "Generating tickets.." << endl;

		cin.ignore();
		do {
			cout << "Press Enter to display the results" << endl;
		} while (cin.get() != '\n');

		//LottoGame
		LottoGame game(choice);
		game.GenerateTips();
		game.PrintTips();
		cout << endl;
		game.FindMatches();

		cout << endl << "Try again? y/n" << endl;
		char repeat;
		cin >> repeat;
		if (repeat == 'y') cont = true;
		if (repeat == 'n') cont = false;
		if (!(repeat == 'y' || repeat == 'n')) cont = false;
	} while (cont);
	cin.ignore();
	//End of program
	do {
		cout << "Press Enter to continue.." << endl;
	} while (cin.get() != '\n');

	return 0;
}

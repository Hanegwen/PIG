// PIG.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <random>
#include <string>



class Player
{
public: 
	
	int totalNumber = 0;
	int turnTotal = 0;


	enum Decision
	{
		Hold, Roll
	};


	void TurnDecision(std::string localDecision)
	{
		if (localDecision == "Hold")
		{
			
		}
		else
		{
			std::cout << "Die is Rolling" << std::endl;
			RollDie();
		}
	}
private:
	
	
	void RollDie()
	{
		std::mt19937 rng;
		rng.seed(std::random_device()());
		std::uniform_int_distribution<int> dist6(1, 6);
		int random_integer = dist6(rng);

		if (random_integer == 1)
		{
			std::cout << "You Rolled a 1, Lame" << std::endl;
			turnTotal = -1;
			totalNumber = 0;
			
			
		}
		else
		{
			std::cout << "You Rolled a " << random_integer << std::endl;
			totalNumber += random_integer;
		}
	}

};


int main()
{

	bool playerTurn = false;
	
	Player player1;
	Player player2;

	playerTurn = true;
	do
	{
		if (playerTurn)
		{
			std::cout << "Player Turn" << std::endl;
			int decisionTime = 0;

			std::cout << "Your Total is " + player1.totalNumber << std::endl;
			std::cout << "Your Turn Total is " << player1.turnTotal << std::endl;

			std::cout << "Press 1 to Hold, Press 2 to Roll" << std::endl;
			std::cin >> decisionTime;
			if (decisionTime == 1)
			{
				player1.TurnDecision("Hold");
				playerTurn = false;
			}
			else if (decisionTime == 2)
			{
				player1.TurnDecision("Roll");
				if (player1.turnTotal == -1)
				{
					playerTurn = false;
				}
			}
		}
		else 
		{
			std::cout << "AI Turn" << std::endl;
			if (player2.turnTotal < 20)
			{
				player2.TurnDecision("Roll");
				if (player2.turnTotal == -1)
				{
					playerTurn = true;
				}
			}
			else
			{
				player2.TurnDecision("Hold");
				playerTurn = false;
			}
		}
	} while (player1.totalNumber < 100 & player2.totalNumber < 100);
	std::cin >> player1.totalNumber;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#include <iostream>
#include <conio.h>
#include<stdio.h> 
#include<string.h>
#include <cstdlib>

using namespace std;


int checkWin();
void gameUI();
void gamePlay();
void resetArray();
void resetGame();

char draw = 'X';

char matrix[3][3] = { ' ', ' ', ' ',
					' ', ' ', ' ',
					' ', ' ', ' ' };
int countDraw = 0;
int row, col;

char strName1[50];
char strName2[50];

int main()
{

	
	char mode;

	/////////////////		Introduce
	cout << "Welcom to tic-tac-toe game! Play with your way! \n";
	cout << "If you find any problem, please contract Tuan.NguyenQuoc@gameloft.com\n";

	cout << "Select your mode (1 -- play game, orther -- exit game)";

	cin >> mode;
	/////////////////		Check mode
	switch (mode)
	{
	case '1':
		cout << "You choose play game, but first, please enter player 1 name : ";
		cin.ignore();
		cin.getline(strName1, 50);
		cout << "and player 2 name : ";
		cin.ignore();
		cin.getline(strName2, 50);
		cout << "So " << strName1 << " will be X and " << strName2 << " will be O\n";
		cout << "Ok! lets start the game, ";
		system("pause");

		gamePlay();

		break;

	default:
		break;
	}
	cout << "dsadsa";
	system("pause");
}

void gameUI()
{
	system("CLS");

	cout << "\t _______________" << " _______________" << " _______________" << "\n";
	cout << "\t|\t " << " \t|\t " << " \t|\t " << " \t| \n";
	cout << "\t|\t " << matrix[0][0] << " \t|\t " << matrix[0][1] << " \t|\t " << matrix[0][2] << " \t| \n";
	cout << "\t|\t " << " \t|\t " << " \t|\t " << " \t| \n";
	cout << "\t _______________" << " _______________" << " _______________" << "\n";
	cout << "\t|\t " << " \t|\t " << " \t|\t " << " \t|\t \n";
	cout << "\t|\t " << matrix[1][0] << " \t|\t " << matrix[1][1] << " \t|\t " << matrix[1][2] << " \t| \n";
	cout << "\t|\t " << " \t|\t " << " \t|\t " << " \t| \n";
	cout << "\t|\t " << " \t|\t " << " \t|\t " << " \t|\t \n";
	cout << "\t _______________" << " _______________" << " _______________" << "\n";
	cout << "\t|\t " << matrix[2][0] << " \t|\t " << matrix[2][1] << " \t|\t " << matrix[2][2] << " \t| \n";
	cout << "\t|\t " << " \t|\t " << " \t|\t " << " \t| \n";
	cout << "\t|\t " << " \t|\t " << " \t|\t " << " \t|\t \n";
	cout << "\t _______________" << " _______________" << " _______________" << "\n";
}

void gamePlay()
{
	int whoWon;
	int player = 2, choice;
	int i;
	do
	{
		i = checkWin();
		if (i == 1) // Win
		{

			gameUI();

			if (whoWon == 1) //////// Get name of the winner
			{
				cout << "\n ===== " << strName1 << " win ===== \n";

			}
			else
			{
				cout << "\n ===== " << strName2 << " win ===== \n";
			}

			resetGame();

		}
		////////////		Draw game!
		if (countDraw == 9)
		{
			gameUI();
			cout << "\m Draw game, ";

			resetGame();
		}

		gameUI();
		//////// Check player Turn
		if (player % 2 == 0)
		{
			draw = 'X';
			whoWon = 1; ///////		Get name turn
		}
		else
		{
			draw = 'O';
			whoWon = 2;
		}

		if (whoWon == 1)
		{
			cout << "\n\t" << strName1 << " turn (input row(1 ---> 3) and column(1 ---> 3) you want, ex: 12) " << draw << ":";
		}
		else
		{
			cout << "\n\t" << strName2 << " turn (input row(1 ---> 3) and column(1 ---> 3) you want, ex: 12) " << draw << ":";
		}

		cin >> choice;
		row = choice / 10 - 1;
		col = choice % 10 - 1;

		if (matrix[row][col] != 'X' && matrix[row][col] != 'O')
		{
			matrix[row][col] = draw;
			countDraw++;
		}
		else
		{
			player--;
		}

		row = 0;
		col = 0;
		player++;

	} while (i == -1);
}

int checkWin()
{

	///////////	'X'
	for (int i = 0; i < 3; i++) // row and column
	{
		if (matrix[0][i] == 'X' && matrix[1][i] == 'X' && matrix[2][i] == 'X') {
			return 1;
		}
		else if (matrix[i][0] == 'X' && matrix[i][1] == 'X' && matrix[i][2] == 'X')
		{
			return 1;
		}
	}
	if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
	{
		return 1;
	}
	else if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X')
	{
		return 1;
	}


	//////////// 'O'
	for (int i = 0; i < 3; i++) // row and column
	{
		if (matrix[0][i] == 'O' && matrix[1][i] == 'O' && matrix[2][i] == 'O') {
			return 1;
		}
		else if (matrix[i][0] == 'O' && matrix[i][1] == 'O' && matrix[i][2] == 'O')
		{
			return 1;
		}
	}
	if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
	{
		return 1;
	}
	else if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O')
	{
		return 1;
	}

	return -1;
}

void resetArray()
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			matrix[i][j] = ' ';
		}
	}
}

void resetGame()
{
	cout << "\ndo you want reset the game (y -- reset/orther --- exit)?? ";
	char op;
	cin >> op;

	switch (op)
	{
	case 'y':
		cout << "\nReset the game, ";
		resetArray();
		countDraw = 0;
		row = 0;
		col = 0;
		system("pause");
		gamePlay();
		break;
	default:
		exit(0);
		break;
	}
}
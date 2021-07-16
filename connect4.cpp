/*
Task : Connect for game
Author : M Usama
Date : 10-16-2020
*/
#include <iostream>
#include <iomanip>
using namespace std;

enum p_turn { player1 = 1 , player2 = 2 };
int ibf = 0;
class game {
private :
	static const int size = 7;
	int board[size][size];
	p_turn turn;
public:

	// Default constructer 
	game()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j< size; j++)
			{
				board[i][j] = 0;
			}
		}
		turn = player2;

	}
	void show_board()
	{
		cout << "\n \t\t\t   Connect 4 Game \n\n" << endl;
		cout << " \t\t  1    2    3    4    5    6    7 \n\n";
		
		for (int i = 0; i < size; i++)
		{
			cout << "\t\t| ";
			for (int j = 0; j<size; j++)
			{
				if (board[i][j] != 0) {
					cout << setw(3) << left << board[i][j];
				}
				else {
					cout << setw(3) << left << " - ";
				}
				cout << "| ";
			
			}
			cout << endl;
		}
		cout << " \t\t------------------------------------\n";
	}
	void switch_turn()
	{
		if (turn == player1)
		turn = player2;
		else 
		turn = player1;
		
	}
	bool is_won()
	{
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (j < 3) {			//Horizontal Check 
					if (board[i][j] == turn) {
						if (board[i][j] == turn && board[i][j + 1] == turn &&
							board[i][j + 2] == turn && board[i][j + 3] == turn)
							return true;
					}
				}
				else {				 
					if (board[i][j] == turn) {
						if (board[i][j] == turn && board[i][j - 1] == turn &&
							board[i][j - 2] == turn && board[i][j - 3] == turn)
							return true;
					}
				}
				if (i < 3) {			//Verticle Check 
					if (board[i][j] == turn) {
						if (board[i][j] == turn && board[i + 1][j] == turn &&
							board[i + 2][j] == turn && board[i + 3][j] == turn)
							return true;
					}
				}
				else {					 
					if (board[i][j] == turn) {
						if (board[i][j] == turn && board[i - 1][j] == turn &&
							board[i - 2][j] == turn && board[i - 3][j] == turn)
							return true;
					}
				}
				if (i < 3 && j <=3) {			//Diagnol Check 
					if (board[i][j] == turn) {
						if (board[i][j] == turn && board[i + 1][j + 1] == turn &&
							board[i + 2][j + 2] == turn && board[i + 3][j + 3] == turn)
							return true;
					}
				}
				else {					 
					if (board[i][j] == turn) {
						if (board[i][j] == turn && board[i - 1][j - 1] == turn &&
							board[i - 2][j - 2] == turn && board[i - 3][j - 3] == turn)
							return true;
					}
				}
				if (i < 3 && j > 3) {		
					if (board[i][j] == turn) {
						if (board[i][j] == turn && board[i + 1][j - 1] == turn &&
							board[i + 2][j - 2] == turn && board[i + 3][j - 3] == turn)
							return true;
					}
				}
				else {					
					if (board[i][j] == turn) {
						if (board[i][j] == turn && board[i - 1][j + 1] == turn &&
							board[i - 2][j + 2] == turn && board[i - 3][j + 3] == turn)
							return true;
					}
				}

			}


		}
		return false;
	}
	bool is_board_full()
	{
	
		if (ibf >= 49)
		{
			 cout <<"The match has been drawn.";
			 	return false;
		}
		else
			return true;
	}
	void start()
	{
		show_board();
		while (is_board_full())
		{
			if (is_board_full())
			{


				int index;
				switch_turn();
				cout << "Player " << turn << " turn  \nEnter value in range(1-7) : ";
			loop:
				cin >> index;
				if (index < 0 || index>7) {
					cout << "Invalid Input ! Column Does not exist.Enter again : ";
					goto loop;
				}
				loop1:
				if (board[0][index - 1] != 0) {
					cout << "No space here. Enter Again  : ";
					cin >> index;
					goto loop1;
				}
				if (turn == player1) {
					ibf++;
					for (int i = 6; i >= 0; i--) {
						if (board[i][index - 1] == 0) {
							board[i][index - 1] = 1;
							system("cls");
							show_board();

							if (is_won())
							{
								cout << "\nPlayer 1 has won the match.\n";

								return;
							}

							system("cls");
							show_board();



							break;
						}
					}
				}
				else if (turn == player2) {
					ibf++;
					for (int i = 6; i >= 0; i--) {
						if (board[i][index - 1] == 0) {
							board[i][index - 1] = 2;
							system("cls");
							show_board();
							if (is_won())
							{
								cout << "\nPlayer 2 has won the match.\n";

								return;
							}
							system("cls");
							show_board();


							break;
						}
					}
				}
			}
		
			
		}
	}
};
int main()
{
	
	game play;
	play.start();

	cout << "\n\n\t\t\t   ------------\n";
	cout << "\t\t\t    GAME ENDED";
}


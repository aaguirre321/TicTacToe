/*
PIC 10B
Discussion 2B
HW 1: Tic-Tac-Toe Game
Arely Aguirre
10/10/2021
*/

#include "game.h"
#include "person.h"

Game::Game(int rounds, Person* p1, Person* p2) 
{
	for (int i = 0; i < rounds; i++)
	// keeps game running for however many rounds the user inputs
	{
		std::cout << std::endl;
		std::cout << "       Round Number:" << (i + 1) << std::endl;
		end_round = false;
		while (end_round == false)
		{
			if (turn % 2 == 0)
			{
				//set player 1's turn whenever turn is even
				current_player = &p1;
				marker = 'X';
			}
			else
			{
				//set player 2's turn whenever turn is odd
				current_player = &p2;
				marker = 'O';
			}

			print_board();
			std::cout << std::endl;
			take_input(current_player);
			check_rows();
		}
		add_win(current_player, p1, p2);
		clear_board();
	}
	check_winner(p1, p2);
}
	

	
void Game::print_board()
// prints board in addition to any modifications
{
	std::cout <<std::endl;
	std::cout << "      1       2       3  " <<std::endl;

	for (x = 0; x < 3; x++)
	{
		std::cout << "          |       |      " << std::endl;
		for (y = 0; y < 3; y++)
		{
			if(y==0)
			{
				if (x == 0)
				{
					std::cout << " 1 ";
				}
				else if (x == 1)
				{
					std::cout << " 2 ";
				}
				else
				{
					std::cout << " 3 ";
				}
			}
			if (y < 2)
			{
				std::cout << "   " << board[x][y] << "   |";
				
			}
			else
			{
				std::cout << "    " << board[x][y] << "   " << std::endl;
			}
		}
		if (x < 2)
		{
			std::cout << "   _______|_______|________" << std::endl;
		}
		else
		{
			std::cout << "          |       |       " << std::endl;
		}
	}
	
}	

void Game::take_input(Person** pointer)
// takes input and checks if it is valid
{
	valid_inp = false;

	while (valid_inp == false)
	{
		std::cout << " " <<(*pointer)->get_name() << " " << "(" << marker << ")" << " Mark Location row# column#: ";
		//prompts current player to chose a spot
		std::cin >> row >> column;
		row = row - 1;
		column = column - 1;
		//subtracts one from row and column to account for zero based indexing

		if (std::cin.fail())
		//prints error message if non-integers are entered
		//prompts for new input
		{
			std::cout << " Invalid Input: Please Only Enter Integers" << std::endl;
			std::cin.clear();
			std::cin.ignore(100000, '\n');
		}
		else if ((row < 0 || row > 2) || (column < 0 || column > 2))
		// prints error message if integers out of range are entered
		//prompts for new input
		{
			std::cout << " Invalid Input: Please Enter Integers Between 1 and 3" << std::endl;
		}
		else if (board[row][column] == 'X' || board[row][column]=='O')
		//prints error message if spot is already taken
		//prompts for new input
		{
			std::cout << " Invalid Input: Please Select a Spot That is Not Taken Already" << std::endl;
		}
		else
		// marks spot if input is valid
		{
			valid_inp = true;
			board[row][column] = marker;
		}
	}
}

bool Game::check_rows()
{
	tie = false;
	if (board[0][0] == marker && board[0][1] == marker && board[0][2] == marker)
	{
		end_round = true;
	}
	else if (board[1][0] == marker && board[1][1] == marker && board[1][2] == marker)
	{
		end_round = true;
	}
	else if(board[2][0] == marker && board[2][1] == marker && board[2][2] == marker)
	{
		end_round = true;
	}
	else if (board[0][0] == marker && board[1][0] == marker && board[2][0] == marker)
	{
		end_round = true;
	}
	else if (board[0][1] == marker && board[1][1] == marker && board[2][1] == marker)
	{
		end_round = true;
	}
	else if (board[0][2] == marker && board[1][2] == marker && board[2][2] == marker)
	{
		end_round = true;
	}
	else if (board[0][0] == marker && board[1][1] == marker && board[2][2] == marker)
	{
		end_round = true;
	}
	else if (board[2][0] == marker && board[1][1] == marker && board[0][2] == marker)
	{
		end_round = true;
	}
	else
	// continues the round if no row has been made
	{
		end_round = false;
		turn++;
		//sets next player's turn
		variables = 0;
		for (x = 0; x < 3; x++)
		{
			for (y = 0; y < 3; y++)
			{
				if (board[x][y] == 'X' || board[x][y] == 'O')
				{
					variables++;
				}
			}
		}
		if (variables == 9)
		//checks if board has filled without any rows made
		{
			end_round = true;
			tie = true;
		}
	}
	return end_round;
}
void Game::add_win(Person** pointer, Person* ptr1, Person* ptr2)
{
	if (tie == false)
	//if a row was made, adds a point to the current players score
	// outputs round winner and current scores
	{
		(*pointer)->add_wins(1);
		print_board();
		std::cout << std::endl;
		std::cout << " " << (*pointer)->get_name() << " wins this round" << std::endl;
		std::cout << " " << ptr1->get_name() << " : " << ptr1->get_score() << std::endl;
		std::cout << " " << ptr2->get_name() << " : " << ptr2->get_score() << std::endl;
	}
	else
	// if board fills without a winner, outputs a no winner message
	//outputs current scores
	{
		print_board();
		std::cout << std::endl;
		std::cout << " No winners this round" << std::endl;
		std::cout << " " << ptr1->get_name() << " : " << ptr1->get_score() << std::endl;
		std::cout << " " << ptr2->get_name() << " : " << ptr2->get_score() << std::endl;
	}
	turn = 0;
	//sets turn to 0 so player 1 will always start off the rounds
}
void Game::clear_board()
//clears board
{
	for ( x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y++)
		{
			board[x][y] = ' ';
		}
	}
}
void Game::check_winner(Person* ptr1, Person* ptr2) const
// outputs a winner or tie message
{
	if (ptr1->get_score() > ptr2->get_score())
	{
		std::cout << " Congratulations " << ptr1->get_name() << ". You won!" << std::endl;
	}
	else if (ptr2->get_score() > ptr1->get_score())
	{
		std::cout << " Congratulations " << ptr2->get_name() << ". You won!" << std::endl;
	}
	else
	{
		std::cout << " It's a tie!" << std::endl;
	}
}


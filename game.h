/*
PIC 10B
Discussion 2B
HW 1: Tic-Tac-Toe Game
Arely Aguirre
10/10/2021
*/

#ifndef game_h
#define game_h
#include<iostream>
#include <string>

class Person;
class Game
{
public:
	Game(int rounds, Person* p1, Person* p2);
	void print_board();
	void take_input(Person** pointer);
	bool check_rows();
	void clear_board();
	void add_win(Person** pointer, Person* ptr1, Person* ptr2);
	void check_winner(Person* ptr1, Person* ptr2) const;


private:
	
	Person** current_player = nullptr;

	char marker = ' ';
	char board[3][3] = {};

	int x=0;
	int y=0;
	int variables = 0;
	int turn = 0;
	int row = 0;
	int column = 0;

	bool valid_inp=false;
	bool end_round = false;
	bool tie = false;
	
};

#endif
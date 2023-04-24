/*
PIC 10B 
Discussion 2B
HW 1: Tic-Tac-Toe Game
Arely Aguirre
10/10/2021
*/

#include <iostream>
#include <string>
#include "game.h"
#include "person.h"
using namespace std;


int main()
{
	cout << " Number of Games: ";
	int games;
	cin >> games;
	cout << " Player 1 Name = ";
	string p1name;
	cin >> p1name;
	cout << " Player 2 Name = ";
	string p2name;
	cin >> p2name;
	cout << "     Tic Tac Toe" << endl;
	cout <<" " << p1name << " (X) - " << p2name << " (O)" << endl;

	Person player1(p1name);
	Person* ptr_p1 = &player1;
	//creates a Person object for player 1 and a pointer
	Person player2(p2name);
	Person* ptr_p2 = &player2;
	//creates a Person object for player 2 and a pointer

	Game Playthru(games, ptr_p1, ptr_p2);

	return 0;
}
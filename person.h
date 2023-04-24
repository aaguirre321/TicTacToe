/*
PIC 10B
Discussion 2B
HW 1: Tic-Tac-Toe Game
Arely Aguirre
10/10/2021
*/

#ifndef person_h
#define person_h
#include <string>
#include <iostream>


class Person
{
public:
	Person(std::string name);
	std::string get_name() const;
	int get_score() const;
	void add_wins(int new_wins);
private:
	int wins=0;
	int new_wins=0;
	std::string name;

};

#endif


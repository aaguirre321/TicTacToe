/*
PIC 10B
Discussion 2B
HW 1: Tic-Tac-Toe Game
Arely Aguirre
10/10/2021
*/

#include "person.h"

Person::Person(std::string name) : name(name) {}
// holds player info

std::string Person::get_name() const
{        
    return name;
}

void Person::add_wins(int new_wins)
{
    wins = wins + new_wins;
   
}

int Person::get_score() const
{
    return wins;
}
  

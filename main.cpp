//
//  main.cpp
//  Tic Tac Game
//
//  Created by Aviv hagag on 24/09/2022.
//
#include <iostream>
using namespace std;
#include <unistd.h>
#include "Game.h"

int main() {
    Game TicTac;
    TicTac.welcome();
    TicTac.printMenu();
    return 0;
}

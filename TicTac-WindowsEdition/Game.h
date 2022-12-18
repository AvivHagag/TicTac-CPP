//
//  Game.h
//  Tic Tac Game
//
//  Created by Aviv hagag on 24/09/2022.
//

#pragma once
#include <iostream>
using namespace std;

class Game {
protected:
    bool end,play,f1,f2,f3,f4,f5,f6,f7,f8,f9;
    char num1,num2,num3,num4,num5,num6,num7,num8,num9;
    int winner;
public:
    Game();
    ~Game(){};
    void printMenu();
    void printBoard();
    void printRes(string A);
    void Start1();
    void Start2();
    void Start3();
    bool endgame();
    void Function1(int numCell,char CellC);
    void Reset();
    void welcome();
};



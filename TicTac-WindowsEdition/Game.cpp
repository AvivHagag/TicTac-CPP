//
//  Game.cpp
//  Tic Tac Game
//
//  Created by Aviv hagag on 24/09/2022.
//
#include<unistd.h>
unsigned int microsecond = 1000000;
#include "Game.h"
#include "time.h"


void Game::Function1(int numCell,char CellC) {
    switch(numCell) {
    case 1: {
        num1=CellC;
        f1=true;
        break;
        };
    case 2: {
        num2=CellC;
        f2=true;
        break;
        };
    case 3: {
        num3=CellC;
        f3=true;
        break;
        };
    case 4: {
        num4=CellC;
        f4=true;
        break;
        };
    case 5: {
        num5=CellC;
        f5=true;
        break;
        };
    case 6: {
        num6=CellC;
        f6=true;
        break;
        };
    case 7: {
        num7=CellC;
        f7=true;
        break;
        };
    case 8: {
        num8=CellC;
        f8=true;
        break;
        };
    case 9: {
        num9=CellC;
        f9=true;
        break;
        };
    }
};

Game::Game() {
    end=false, play=false,f1=false, f2=false, f3=false, f4=false, f5=false, f6=false, f7=false, f8=false, f9=false;
    num1='1', num2='2', num3='3', num4='4', num5='5', num6='6', num7='7', num8='8', num9='9';
    winner=0;
}

void Game::Reset() {
    end=false, play=false, f1=false, f2=false, f3=false, f4=false, f5=false, f6=false, f7=false, f8=false, f9=false;
    num1='1', num2='2', num3='3', num4='4', num5='5', num6='6', num7='7', num8='8', num9='9';
    winner=0;
}

void Game::printMenu() {
    int number=0;
    while (number != 3) {
        Reset();
        cout << "=====================================================" << endl;
        cout << " \t\t MENU \t  " << endl;
        cout << "=====================================================" << endl;
        cout << " 1.Start Play, Player1-Vs-Player2" << endl;
        cout << " 2.Start play, Player1-Vs-Computer" << endl;
        cout << " 3.Exit " << endl;
        cin >> number;
        switch(number) {
            case 1: {
                Start1();
                break;
            };
                // **************************************************
            case 2: {
                cout << "Choose level: 0-Easy / 1-Hard" << endl;
                bool level;
                cin >> level;
                if(level==0)
                    Start2();
                else
                    Start3();
                break;
            };
                // **************************************************
            case 3: {
                cout << endl;
                cout << "Good Bye" << endl;
                cout << endl;
                break;
            };
        }
    }
};

void Game::Start1() {
        cout << endl;
        cout << "Welcome To Tic Tac Game !    " << endl;
        cout << "Player 1 - X , Player 2 - O ,lets playyyyy :-)" << endl;
        int player=2;
        while(end==false) {
            play=false;
            printBoard();
            while(play==false) {
                int choose=0;
                char temp;
                if(player%2==0) {
                    cout << "Player 1 , choose number: " ;
                    temp='X';
                    cin >> choose;
                }
                else {
                    cout << "Player 2 , choose number: " ;
                    temp='O';
                    cin >> choose;
                }
                switch (choose) {
                    case 1: {
                        if(f1==false) {
                            Function1(1,temp);
                            player++;
                            break;
                        }
                        else{
                            cout << endl <<"***** Error! This cell is already selected *****" << endl;
                        }
                        break;
                    }
                    case 2: {
                        if(f2==false) {
                            Function1(2,temp);
                            player++;
                            break;
                        }
                        else{
                            cout << endl <<"***** Error! This cell is already selected *****" << endl;
                        }
                        break;
                    }
                    case 3: {
                        if(f3==false) {
                            Function1(3,temp);
                            player++;
                            break;
                        }
                        else{
                            cout << endl <<"***** Error! This cell is already selected *****" << endl;
                        }
                        break;
                    }
                    case 4: {
                        if(f4==false) {
                            Function1(4,temp);
                            player++;
                            break;
                        }
                        else{
                            cout << endl <<"***** Error! This cell is already selected *****" << endl;
                        }
                        break;
                    }
                    case 5: {
                        if(f5==false) {
                            Function1(5,temp);
                            player++;
                            break;
                        }
                        else{
                            cout << endl <<"***** Error! This cell is already selected *****" << endl;
                        }
                        break;
                    }
                    case 6: {
                        if(f6==false) {
                            Function1(6,temp);
                            player++;
                            break;
                        }
                        else{
                            cout << endl <<"***** Error! This cell is already selected *****" << endl;
                        }
                        break;
                    }
                    case 7: {
                        if(f7==false) {
                            Function1(7,temp);
                            player++;
                            break;
                        }
                        else{
                            cout << endl <<"***** Error! This cell is already selected *****" << endl;
                        }
                        break;
                    }
                    case 8: {
                        if(f8==false) {
                            Function1(8,temp);
                            player++;
                            break;
                        }
                        else{
                            cout << endl <<"***** Error! This cell is already selected *****" << endl;
                        }
                        break;
                    }
                    case 9: {
                        if(f9==false) {
                            Function1(9,temp);
                            player++;
                            break;
                        }
                        else{
                            cout << endl <<"***** Error! This cell is already selected *****" << endl;
                        }
                        break;
                    }
                }
                play=true;
                if(endgame()==true) {
                    end=true;
                }
                if(end==true) {
                    string Res;
                    if(winner==1)
                        Res="player 1 is the winner !";
                    else if(winner==2)
                        Res="player 2 is the winner !" ;
                    else
                        Res="Draw !" ;
                    printRes(Res);
                }
            }
    }
};

void Game::Start2() {
cout << endl;
cout << "Welcome To Tic Tac Game !    " << endl;
    int player=2;
    srand(time(0));
    int numR;
    numR=rand() %2 +1;
    if(numR==1) {
        cout << "Player 1 - X , Computer - O ,lets playyyyy :-)" << endl;
    }
    if(numR==2) {
        cout << "Computer - X , Player 1 - O ,lets playyyyy :-)" << endl;
        usleep(0.5 * microsecond);//sleeps for 0.5 second
        player++;
    }
    while(end==false) {
        play=false;
        printBoard();
        while(play==false) {
            int choose=0;
            char temp;
            if(player%2==0) {
                cout << "Player 1 , choose number: " ;
                temp='X';
                cin >> choose;
            }
            else {
                cout << "Computer choosen number: " ;
                temp='O';
                choose = (rand() % 9);
            }
            switch (choose) {
                case 1: {
                    if(f1==false) {
                        Function1(1,temp);
                        player++;
                        break;
                    }
                    else{
                        cout << endl <<"***** Error! This cell is already selected *****" << endl;
                    }
                    break;
                }
                case 2: {
                    if(f2==false) {
                        Function1(2,temp);
                        player++;
                        break;
                    }
                    else{
                        cout << endl <<"***** Error! This cell is already selected *****" << endl;
                    }
                    break;
                }
                case 3: {
                    if(f3==false) {
                        Function1(3,temp);
                        player++;
                        break;
                    }
                    else{
                        cout << endl <<"***** Error! This cell is already selected *****" << endl;
                    }
                    break;
                }
                case 4: {
                    if(f4==false) {
                        Function1(4,temp);
                        player++;
                        break;
                    }
                    else{
                        cout << endl <<"***** Error! This cell is already selected *****" << endl;
                    }
                    break;
                }
                case 5: {
                    if(f5==false) {
                        Function1(5,temp);
                        player++;
                        break;
                    }
                    else{
                        cout << endl <<"***** Error! This cell is already selected *****" << endl;
                    }
                    break;
                }
                case 6: {
                    if(f6==false) {
                        Function1(6,temp);
                        player++;
                        break;
                    }
                    else{
                        cout << endl <<"***** Error! This cell is already selected *****" << endl;
                    }
                    break;
                }
                case 7: {
                    if(f7==false) {
                        Function1(7,temp);
                        player++;
                        break;
                    }
                    else{
                        cout << endl <<"***** Error! This cell is already selected *****" << endl;
                    }
                    break;
                }
                case 8: {
                    if(f8==false) {
                        Function1(8,temp);
                        player++;
                        break;
                    }
                    else{
                        cout << endl <<"***** Error! This cell is already selected *****" << endl;
                    }
                    break;
                }
                case 9: {
                    if(f9==false) {
                        Function1(9,temp);
                        player++;
                        break;
                    }
                    else{
                        cout << endl <<"***** Error! This cell is already selected *****" << endl;
                    }
                    break;
                }
            }
            play=true;
            if(endgame()==true) {
                end=true;
            }
            if(end==true) {
                string Res;
                if(winner==1)
                    Res="player 1 is the winner !";
                else if(winner==2)
                    Res="Computer is the winner !" ;
                else
                    Res="Draw !" ;
                printRes(Res);
            }
        }
    }
}

void Game::Start3() {
    bool* flags = new bool(24);
    bool* flagA = new bool(24);
    for(int i=0;i<24;i++){
        flags[i]=false;
        flagA[i]=false;
    }
cout << endl;
cout << "Welcome To Tic Tac Game !    " << endl;
    int player=2,step=0;
    srand(time(0));
    int numR;
    numR=rand() %2 +1;
    if(numR==1) {
        cout << "Player 1 - X , Computer - O ,lets playyyyy :-)" << endl;
    }
    if(numR==2) {
        cout << "Computer - X , Player 1 - O ,lets playyyyy :-)" << endl;
        usleep(0.5 * microsecond);//sleeps for 0.5 second
        player++;
    }
    while(end==false) {
        play=false;
        printBoard();
        while(play==false) {
            int choose=0;
            char temp;
            if(player%2==0) {
                cout << "Player 1 , choose number: " ;
                temp='X';
                cin >> choose;
            }
            else {
                bool flagAttack=false;
                bool flagC=false;
                cout << "Computer choosen number: " ;
                temp='O';
                if(step==0) {
                    choose = (rand() % 9 + 1);
                    step++;
                }
                else {
                    if(flagAttack==false) {
                        if(f1==true && f2==true && num1=='O' && num2=='0' && flagA[0]==false) {
                            choose=3;
                            flagAttack=true;
                            flagA[0]=true;
                        }
                        if(f1==true && f3==true && num1=='0' && num3=='0' && flagA[1]==false) {
                            choose=2;
                            flagAttack=true;
                            flagA[1]=true;
                        }
                        if(f1==true && f5==true && num1=='0' && num5=='0' && flagA[2]==false) {
                            choose=9;
                            flagAttack=true;
                            flagA[2]=true;
                        }
                        if(f1==true && f9==true && num1=='O' && num9=='O' && flagA[3]==false) {
                            choose=5;
                            flagAttack=true;
                            flagA[3]=true;
                        }
                        if(f1==true && f4==true && num1=='O' && num4=='O' && flagA[4]==false) {
                            choose=7;
                            flagAttack=true;
                            flagA[4]=true;
                        }
                        if(f1==true && f7==true && num1=='O' && num7=='O' && flagA[5]==false) {
                            choose=4;
                            flagAttack=true;
                            flagA[5]=true;
                        }
                        if(f2==true && f3==true && num2=='O' && num3=='O' && flagA[6]==false) {
                            choose=1;
                            flagAttack=true;
                            flagA[6]=true;
                        }
                        if(f2==true && f5==true && num2=='O' && num5=='O' && flagA[7]==false) {
                            choose=8;
                            flagAttack=true;
                            flagA[7]=true;
                        }
                        if(f2==true && f8==true && num2=='O' && num8=='O' && flagA[8]==false) {
                            choose=5;
                            flagAttack=true;
                            flagA[8]=true;
                        }
                        if(f3==true && f5==true && num3=='O' && num5=='O' && flagA[9]==false) {
                            choose=7;
                            flagAttack=true;
                            flagA[9]=true;
                        }
                        if(f3==true && f7==true && num3=='O' && num7=='O' && flagA[10]==false) {
                            choose=5;
                            flagAttack=true;
                            flagA[10]=true;
                        }
                        if(f3==true && f6==true && num3=='O' && num6=='O' && flagA[11]==false) {
                            choose=9;
                            flagAttack=true;
                            flagA[11]=true;
                        }
                        if(f3==true && f9==true && num3=='O' && num9=='O' && flagA[12]==false) {
                            choose=6;
                            flagAttack=true;
                            flagA[12]=true;
                        }
                        if(f4==true && f5==true && num4=='O' && num5=='O' && flagA[13]==false) {
                            choose=6;
                            flagAttack=true;
                            flagA[13]=true;
                        }
                        if(f4==true && f6==true && num4=='O' && num6=='O' && flagA[14]==false) {
                            choose=5;
                            flagAttack=true;
                            flagA[14]=true;
                        }
                        if(f4==true && f7==true && num4=='O' && num7=='O' && flagA[15]==false) {
                            choose=1;
                            flagAttack=true;
                            flagA[15]=true;
                        }
                        if(f5==true && f6==true && num5=='O' && num6=='O' && flagA[16]==false) {
                            choose=4;
                            flagAttack=true;
                            flagA[16]=true;
                        }
                        if(f5==true && f7==true && num5=='O' && num7=='O' && flagA[17]==false) {
                            choose=3;
                            flagAttack=true;
                            flagA[17]=true;
                        }
                        if(f5==true && f8==true && num5=='O' && num8=='O' && flagA[18]==false) {
                            choose=2;
                            flagAttack=true;
                            flagA[18]=true;
                        }
                        if(f5==true && f9==true && num5=='O' && num9=='O' && flagA[19]==false) {
                            choose=1;
                            flagAttack=true;
                            flagA[19]=true;
                        }
                        if(f6==true && f9==true && num6=='O' && num9=='O' && flagA[20]==false) {
                            choose=3;
                            flagAttack=true;
                            flagA[20]=true;
                        }
                        if(f7==true && f8==true && num7=='O' && num8=='O' && flagA[21]==false) {
                            choose=9;
                            flagAttack=true;
                            flagA[21]=true;
                        }
                        if(f7==true && f9==true && num7=='O' && num9=='O' && flagA[22]==false) {
                            choose=3;
                            flagAttack=true;
                            flagA[22]=true;
                        }
                        if(f8==true && f9==true && num8=='O' && num9=='O' && flagA[23]==false) {
                            choose=7;
                            flagAttack=true;
                            flagA[23]=true;
                        }
                        if(flagAttack==false) {
                            if(f1==true && f2==true && num1=='X' && num2=='X' && flags[0]==false) {
                                choose=3;
                                flagC=true;
                                flags[0]=true;
                            }
                            if(f1==true && f3==true && num1=='X' && num3=='X' && flags[1]==false) {
                                choose=2;
                                flagC=true;
                                flags[1]=true;
                            }
                            if(f1==true && f5==true && num1=='X' && num5=='X' && flags[2]==false) {
                                choose=9;
                                flagC=true;
                                flags[2]=true;
                            }
                            if(f1==true && f9==true && num1=='X' && num9=='X' && flags[3]==false) {
                                choose=5;
                                flagC=true;
                                flags[3]=true;
                            }
                            if(f1==true && f4==true && num1=='X' && num4=='X' && flags[4]==false) {
                                choose=7;
                                flagC=true;
                                flags[4]=true;
                            }
                            if(f1==true && f7==true && num1=='X' && num7=='X' && flags[5]==false) {
                                choose=4;
                                flagC=true;
                                flags[5]=true;
                            }
                            if(f2==true && f3==true && num2=='X' && num3=='X' && flags[6]==false) {
                                choose=1;
                                flagC=true;
                                flags[6]=true;
                            }
                            if(f2==true && f5==true && num2=='X' && num5=='X' && flags[7]==false) {
                                choose=8;
                                flagC=true;
                                flags[7]=true;
                            }
                            if(f2==true && f8==true && num2=='X' && num8=='X' && flags[8]==false) {
                                choose=5;
                                flagC=true;
                                flags[8]=true;
                            }
                            if(f3==true && f5==true && num3=='X' && num5=='X' && flags[9]==false) {
                                choose=7;
                                flagC=true;
                                flags[9]=true;
                            }
                            if(f3==true && f7==true && num3=='X' && num7=='X' && flags[10]==false) {
                                choose=5;
                                flagC=true;
                                flags[10]=true;
                            }
                            if(f3==true && f6==true && num3=='X' && num6=='X' && flags[11]==false) {
                                choose=9;
                                flagC=true;
                                flags[11]=true;
                            }
                            if(f3==true && f9==true && num3=='X' && num9=='X' && flags[12]==false) {
                                choose=6;
                                flagC=true;
                                flags[12]=true;
                            }
                            if(f4==true && f5==true && num4=='X' && num5=='X' && flags[13]==false) {
                                choose=6;
                                flagC=true;
                                flags[13]=true;
                            }
                            if(f4==true && f6==true && num4=='X' && num6=='X' && flags[14]==false) {
                                choose=5;
                                flagC=true;
                                flags[14]=true;
                            }
                            if(f4==true && f7==true && num4=='X' && num7=='X' && flags[15]==false) {
                                choose=1;
                                flagC=true;
                                flags[15]=true;
                            }
                            if(f5==true && f6==true && num5=='X' && num6=='X' && flags[16]==false) {
                                choose=4;
                                flagC=true;
                                flags[16]=true;
                            }
                            if(f5==true && f7==true && num5=='X' && num7=='X' && flags[17]==false) {
                                choose=3;
                                flagC=true;
                                flags[17]=true;
                            }
                            if(f5==true && f8==true && num5=='X' && num8=='X' && flags[18]==false) {
                                choose=2;
                                flagC=true;
                                flags[18]=true;
                            }
                            if(f5==true && f9==true && num5=='X' && num9=='X' && flags[19]==false) {
                                choose=1;
                                flagC=true;
                                flags[19]=true;
                            }
                            if(f6==true && f9==true && num6=='X' && num9=='X' && flags[20]==false) {
                                choose=3;
                                flagC=true;
                                flags[20]=true;
                            }
                            if(f7==true && f8==true && num7=='X' && num8=='X' && flags[21]==false) {
                                choose=9;
                                flagC=true;
                                flags[21]=true;
                            }
                            if(f7==true && f9==true && num7=='X' && num9=='X' && flags[22]==false) {
                                choose=3;
                                flagC=true;
                                flags[22]=true;
                            }
                            if(f8==true && f9==true && num8=='X' && num9=='X' && flags[23]==false) {
                                choose=7;
                                flagC=true;
                                flags[23]=true;
                            }
                            if(flagC==false) {
                                choose = (rand() % 9 + 1);
                            }
                        }
                    }
                }
            }
            switch (choose) {
                case 1: {
                    if(f1==false) {
                        Function1(1,temp);
                        player++;
                        break;
                    }
                    else{
                        cout << endl <<"***** Error! This cell is already selected *****" << endl;
                    }
                    break;
                }
                case 2: {
                    if(f2==false) {
                        Function1(2,temp);
                        player++;
                        break;
                    }
                    else{
                        cout << endl <<"***** Error! This cell is already selected *****" << endl;
                    }
                    break;
                }
                case 3: {
                    if(f3==false) {
                        Function1(3,temp);
                        player++;
                        break;
                    }
                    else{
                        cout << endl <<"***** Error! This cell is already selected *****" << endl;
                    }
                    break;
                }
                case 4: {
                    if(f4==false) {
                        Function1(4,temp);
                        player++;
                        break;
                    }
                    else{
                        cout << endl <<"***** Error! This cell is already selected *****" << endl;
                    }
                    break;
                }
                case 5: {
                    if(f5==false) {
                        Function1(5,temp);
                        player++;
                        break;
                    }
                    else{
                        cout << endl <<"***** Error! This cell is already selected *****" << endl;
                    }
                    break;
                }
                case 6: {
                    if(f6==false) {
                        Function1(6,temp);
                        player++;
                        break;
                    }
                    else{
                        cout << endl <<"***** Error! This cell is already selected *****" << endl;
                    }
                    break;
                }
                case 7: {
                    if(f7==false) {
                        Function1(7,temp);
                        player++;
                        break;
                    }
                    else{
                        cout << endl <<"***** Error! This cell is already selected *****" << endl;
                    }
                    break;
                }
                case 8: {
                    if(f8==false) {
                        Function1(8,temp);
                        player++;
                        break;
                    }
                    else{
                        cout << endl <<"***** Error! This cell is already selected *****" << endl;
                    }
                    break;
                }
                case 9: {
                    if(f9==false) {
                        Function1(9,temp);
                        player++;
                        break;
                    }
                    else{
                        cout << endl <<"***** Error! This cell is already selected *****" << endl;
                    }
                    break;
                }
            }
            play=true;
            if(endgame()==true) {
                end=true;
            }
            if(end==true) {
                if(end==true) {
                    string Res;
                    if(winner==1)
                        Res="player 1 is the winner !";
                    else if(winner==2)
                        Res="Computer is the winner !" ;
                    else
                        Res="Draw !" ;
                    printRes(Res);
                }
            }
        }
    }
    delete[] flags;
    delete[] flagA;
}

void Game::printBoard() {
    cout << endl ;
    cout << " _______________________ " << endl;
    cout << "|       |       |       |" << endl;
    cout << "|" << "   " << num1<<"   " << "|" << "   " << num2 <<"   " << "|" << "   " << num3 << "   " << "|" << endl;
    cout << "|_______|_______|_______|" << endl;
    cout << "|       |       |       |" << endl;
    cout << "|" << "   " << num4<<"   " << "|" << "   " << num5 <<"   " << "|" << "   " << num6 << "   " << "|" << endl;
    cout << "|_______|_______|_______|" << endl;
    cout << "|       |       |       |" << endl;
    cout << "|" << "   " << num7<<"   " << "|" << "   " << num8 <<"   " << "|" << "   " << num9 << "   " << "|" << endl;
    cout << "|_______|_______|_______|" << endl << endl;
};

void Game::printRes(string A) {
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << A << endl <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
}
bool Game::endgame() {
    if(f1==true & f2==true & f3==true) {
        if(num1=='X' && num2=='X' && num3=='X') {
            printBoard();
            usleep(3 * microsecond);//sleeps for 3 second
            cout << "Game End !" << endl;
            winner=1;
            return true;
        }
        if(num1=='O' && num2=='O' && num3=='O') {
            printBoard();
            usleep(3 * microsecond);//sleeps for 3 second
            cout << "Game End !" << endl;
            winner=2;
            return true;
        }
    }
    if(f4==true & f5==true & f6==true) {
        if(num4=='X' && num5=='X' && num6=='X') {
            printBoard();
            usleep(3 * microsecond);//sleeps for 3 second
            cout << "Game End !" << endl;
            winner=1;
            return true;
        }
        if(num4=='O' && num5=='O' && num6=='O') {
            printBoard();
            usleep(3 * microsecond);//sleeps for 3 second
            cout << "Game End !" << endl;
            winner=2;
            return true;
        }
    }
    if(f7==true & f8==true & f9==true) {
        if(num7=='X' && num8=='X' && num9=='X') {
            printBoard();
            usleep(3 * microsecond);//sleeps for 3 second
            cout << "Game End !" << endl;
            winner=1;
            return true;
        }
        if(num7=='O' && num8=='O' && num9=='O') {
            printBoard();
            usleep(3 * microsecond);//sleeps for 3 second
            cout << "Game End !" << endl;
            winner=2;
            return true;
        }
    }
    if(f1==true & f4==true & f7==true) {
        if(num1=='X' && num4=='X' && num7=='X') {
            printBoard();
            usleep(3 * microsecond);//sleeps for 3 second
            cout << "Game End !" << endl;
            winner=1;
            return true;
        }
        if(num1=='O' && num4=='O' && num7=='O') {
            printBoard();
            usleep(3 * microsecond);//sleeps for 3 second
            cout << "Game End !" << endl;
            winner=2;
            return true;
        }
    }
    if(f2==true & f5==true & f8==true) {
        if(num2=='X' && num5=='X' && num8=='X') {
            printBoard();
            usleep(3 * microsecond);//sleeps for 3 second
            cout << "Game End !" << endl;
            winner=1;
            return true;
        }
        if(num2=='O' && num5=='O' && num8=='O') {
            printBoard();
            usleep(3 * microsecond);//sleeps for 3 second
            cout << "Game End !" << endl;
            winner=2;
            return true;
        }
    }
    if(f3==true & f6==true & f9==true) {
        if(num3=='X' && num6=='X' && num9=='X') {
            printBoard();
            usleep(3 * microsecond);//sleeps for 3 second
            cout << "Game End !" << endl;
            winner=1;
            return true;
        }
        if(num3=='O' && num6=='O' && num9=='O') {
            printBoard();
            usleep(3 * microsecond);//sleeps for 3 second
            cout << "Game End !" << endl;
            winner=2;
            return true;
        }
    }
    if(f1==true & f5==true & f9==true) {
        if(num1=='X' && num5=='X' && num9=='X') {
            printBoard();
            usleep(3 * microsecond);//sleeps for 3 second
            cout << "Game End !" << endl;
            winner=1;
            return true;
        }
        if(num1=='O' && num5=='O' && num9=='O') {
            printBoard();
            usleep(3 * microsecond);//sleeps for 3 second
            cout << "Game End !" << endl;
            winner=2;
            return true;
        }
    }
    if(f3==true & f5==true & f7==true) {
        if(num3=='X' && num5=='X' && num7=='X') {
            printBoard();
            usleep(3 * microsecond);//sleeps for 3 second
            cout << "Game End !" << endl;
            winner=1;
            return true;
        }
        if(num3=='O' && num5=='O' && num7=='O') {
            printBoard();
            usleep(3 * microsecond);//sleeps for 3 second
            cout << "Game End !" << endl;
            winner=2;
            return true;
        }
    }
    if(f1==true && f2==true && f3==true && f4==true && f5==true && f6==true && f7==true && f8==true && f9==true ) {
        printBoard();
        usleep(3 * microsecond);//sleeps for 3 second
        cout << "Game End !" << endl;
        winner=0;
        return true;
    }

   return false;
};

void Game::welcome() {
    cout << "TTTTTTTTTTTTT    IIIIII         CCCC          TTTTTTTTTTTTT         AA            KK     KK" << endl;
    usleep(0.4 * 1000000);//sleeps for 0.4 second
    cout << "     TT            II         CC                   TT              AAAA           KK   KK  " << endl;
    usleep(0.4 * 1000000);//sleeps for 0.4 second
    cout << "     TT            II       CC                     TT             AA  AA          KK KK    " << endl;
    usleep(0.4 * 1000000);//sleeps for 0.4 second
    cout << "     TT            II      CC                      TT            AA    AA         KKK      " << endl;
    usleep(0.4 * 1000000);//sleeps for 0.4 second
    cout << "     TT            II     CC                       TT           AA      AA        KK       " << endl;
    usleep(0.4 * 1000000);//sleeps for 0.4 second
    cout << "     TT            II      CC                      TT          AAAAAAAAAAAA       KKK      " << endl;
    usleep(0.4 * 1000000);//sleeps for 0.4 second
    cout << "     TT            II       CC                     TT         AA          AA      KK KK    " << endl;
    usleep(0.4 * 1000000);//sleeps for 0.4 second
    cout << "     TT            II         CC                   TT        AA            AA     KK   KK  " << endl;
    usleep(0.4 * 1000000);//sleeps for 0.4 second
    cout << "     TT          IIIIII         CCCC               TT       AA              AA    KK     KK" << endl;
    cout <<endl<<endl;
    usleep(3 * 1000000);//sleeps for 3 second
}

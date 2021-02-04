#include <iostream>
#include "Player.h"

using namespace std;

Player::Player()    //Definir el constructor Player, de la clase Player
{
    x = 1;
    y = 1;
}

void Player::call_input()
{
    char userInput = ' ';
    cin >> userInput;

    lastX = x;
    lastY = y;

    switch(userInput)
    {
    case 'w':
        y--;
        break;

    case 's':
        //y+ va hacia abajo
        y++;    
        break;

    case 'a':
        x--;
        break;

    case 'd':
        x++;
        break;
    }
}

void Player::return_last_position()
{
    x = lastX;
    y = lastY;
}
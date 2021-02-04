#include <iostream>
#include "Player.h"
#include "MapCell.h"
#include "GameMap.h"

using namespace std;

int main()
{
    Player Hero;
    GameMap Map;

    Map.draw_intro();
    Map.Draw();

    cout << "Controls: press W, S, A, D then enter to move UP, DOWN, LEFT, and RIGHT respectively" << endl;
    
    while(Map.isGameOver == false)
    {
        Hero.call_input();

        //Hero info updated
        if(Map.set_player_cell(Hero.x, Hero.y)) //la funcion set_player_cell es booleana, si permite el movimiento regresa un true
        {
            if(Map.isGameOver == false)
            {
                cout << Hero.x << "," << Hero.y << endl;
                if(Map.prevLevel == 0 && Map.mapLevel == 1)
                {
                    cout << "Subiendo" << endl;

                    Hero.x = 7;
                    Hero.y = 13;

                    Map.set_player_cell(Hero.x, Hero.y);
                    Map.Draw();
                    
                    Map.prevLevel = Map.mapLevel;
                }
                else if(Map.prevLevel == 1 && Map.mapLevel == 2)
                {
                    cout << "Subiendo" << endl;
                    Map.Draw();
                    Hero.x = 7;
                    Hero.y = 13;
                    
                    Map.prevLevel = Map.mapLevel;
                }
                else if(Map.prevLevel == 2 && Map.mapLevel == 1)
                {
                    cout << "Bajando" << endl;
                    Map.Draw();
                    Hero.x = 7;
                    Hero.y = 13;
                    
                    Map.prevLevel = Map.mapLevel;
                }
                else if(Map.prevLevel == 1 && Map.mapLevel == 0)
                {
                    cout << "Bajando" << endl;
                    
                    Hero.x = 7;
                    Hero.y = 13;
                    
                    Map.set_player_cell(Hero.x, Hero.y);
                    Map.Draw();
                    
                    Map.prevLevel = Map.mapLevel;
                }
                else
                {
                    //dibuja el mapa con la coordenada del movimiento   
                    Map.Draw();
                }
                
            }
        }
        else
        {
            Hero.return_last_position();        //reemplaza el la coordenada del movimiento no permitido con la ultima coordenada permitida
            Map.Draw();                         //dibuja el mapa con la ultima ubicacion del jugador antes de colisionar
        }
    }

    return 0;
}
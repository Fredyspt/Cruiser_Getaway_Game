#ifndef GAMEMAP_H
#define GAMEMAP_H

#include "MapCell.h"

class GameMap
{
public:
    GameMap();

    bool isGameOver;
    int mapLevel;
    int prevLevel;

    void draw_intro();
    void draw_victory();
    void Draw();

    //Obtiene las coordenadas de player y actualiza el mapa
    bool set_player_cell(int playerX, int playerY);

    MapCell* PlayerCell;
    MapCell cells[15][10];   //[Filas][Columnas] Se crea el arreglo bidimensional vacio

protected:
    void load_map_from_file(int level);

private:
};

#endif  //GAMEMAP_H
#include <iostream>
#include <fstream>
#include "GameMap.h"

using namespace std;

GameMap::GameMap()
{
    PlayerCell = NULL; //Esto se asegura que se limpie lo que tenia el apuntador al iniciar.
    isGameOver = false;
    mapLevel = 0;
    load_map_from_file(mapLevel);
}

void GameMap::draw_intro()
{
    string line;    //Aqui se ira almacenando cada linea del .txt
    int row = 0;
    ifstream MyFile("Intro.txt");

    if(MyFile.is_open())
    {
        while(getline(MyFile, line))
        {
            cout << line << endl;
        }
        cin >> line;
    }
    else
    {
        cout << "Fatal error: Intro file could not be loaded" << endl;
    }
}

void GameMap::draw_victory()
{
    string line;    //Aqui se ira almacenando cada linea del .txt
    ifstream MyFile("Victory.txt");

    if(MyFile.is_open())
    {
        while(getline(MyFile, line))
        {
            cout << line << endl;
        }
        cin >> line;
    }
    else
    {
        cout << "Fatal error: Victory file could not be loaded" << endl;
    }
}

void GameMap::Draw()
{
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << cells[i][j].id; //Dibuja el caracter id en cada coordenada del arreglo bidimensional
        }
        cout << endl;
    }
}

bool GameMap::set_player_cell(int playerX, int playerY)
{
    if(cells[playerY][playerX].is_blocked() == false)   //si el id de las coordenadas X y Y del objeto cells, no es 1, permite el movimiento
    {
        if(cells[playerY][playerX].id == '$')
        {
            draw_victory();
            isGameOver = true;
            
        }
        else if(cells[playerY][playerX].id == 30)   //Subir de nivel
        {
            mapLevel++;
            prevLevel = mapLevel - 1;
            load_map_from_file(mapLevel);
            PlayerCell = &cells[playerY][playerX];
            PlayerCell = NULL;
        }
        else if(cells[playerY][playerX].id == 31)   //Bajar de nivel
        {
            mapLevel--;
            prevLevel = mapLevel + 1;
            load_map_from_file(mapLevel);
            PlayerCell = &cells[playerY][playerX];
            PlayerCell = NULL;
        }
        else
        {
            //Al volver a entrar al loop, verifica si el apuntador no esta vacio, si tiene algo, coloca un ' ', y despues procede a pintar el 3
            if(PlayerCell != NULL)
            {
                PlayerCell->id = ' ';
            }

            //PlayerCell obtiene la coordenada en la que esta el jugador
            //Se dibuja primero Y y luego X porque son Filas(y) y Columnas(x)
            PlayerCell = &cells[playerY][playerX]; 
            PlayerCell->id = 3;
        }
        return true;
    }
    else
    {
        return false;
    }
}

void GameMap::load_map_from_file(int level)
{
    /*
    Esta parte se puede comentar una vez creado el archivo con este codigo.

    ofstream FileCreated("Map.txt");    //Se crea el archivo

    if(FileCreated.is_open())           //Verifica si se creo correctamente
    {

    }
    else
    {
        cout << "Fatal error: Map file could not be loaded" << endl;
    }
    */

    string line;    //Aqui se ira almacenando cada linea del .txt
    string mapFile = "";
    int row = 0;

    switch (level)
    {
    case 0:
        mapFile = "Level_0.txt";
        break;

    case 1: 
        mapFile = "Level_1.txt";
        break;

    case 2: 
        mapFile = "Level_2.txt";
        break;
    }

    ifstream MyFile(mapFile.c_str());

    if(MyFile.is_open())
    {
        while(getline(MyFile, line))
        {
            for(int column = 0; column < line.length(); column++)
            {
                if(line[column] == '0')
                {
                    cells[row][column].id = ' ';
                }
                else if(line[column] == '1')
                {
                    cells[row][column].id = 178;
                }
                else if(line[column] == 'U')
                {
                    cells[row][column].id = 30;
                }
                else if(line[column] == 'D')
                {
                    cells[row][column].id = 31;
                }
                else if(line[column] == 'P')
                {
                    cells[row][column].id = 3;
                }
                else 
                {
                    cells[row][column].id = line[column];   
                }
            }
            row++;
        }
    }
    else
    {
        cout << "Fatal error: Map file could not be loaded" << endl;
    }
}
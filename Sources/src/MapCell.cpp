#include "MapCell.h"

MapCell::MapCell()
{
    id = 0; //Este sera el valor que se dibujara en cada coordenada del arreglo bidimensional
}

bool MapCell::is_blocked()
{
    if(id == 178)
    {
        return true;
    }
    else
    {
        return false;
    }
}

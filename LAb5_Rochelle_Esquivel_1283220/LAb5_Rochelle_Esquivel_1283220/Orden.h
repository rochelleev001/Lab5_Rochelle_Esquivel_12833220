#pragma once
#include "Pokemon.h"

ref class Orden
{
    //obtenido de: https://codemyn.blogspot.com/2019/08/metodos-de-ordenamiento-quicksort-en-c.html
    void Orden::Quicksort(array <Pokemon^>^ miPokedex, int primero, int ultimo);

    void Orden::Shellsort(array <Pokemon^>^ miPokedex, int primero, int ultimo);

};


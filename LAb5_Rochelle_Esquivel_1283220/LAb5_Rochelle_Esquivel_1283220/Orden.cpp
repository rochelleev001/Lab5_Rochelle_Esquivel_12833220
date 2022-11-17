#include "Orden.h"
#include "MyForm.h"

void Orden::Quicksort(array <Pokemon^>^ miPokedex, int primero, int ultimo) {

    int array_size;
    int cant_Pokemon;
    int central, i, j;
    double pivote;
    central = (primero + ultimo) / 2;
    pivote = cant_Pokemon[central];
    i = primero;
    j = ultimo;
    do
    {
        while (cant_Pokemon[i] < pivote) i++;
        while (cant_Pokemon[j] > pivote) j--;
        if (i <= j)
        {
            double temp;
            temp = cant_Pokemon[i];
            cant_Pokemon[i] = cant_Pokemon[j]; 
            cant_Pokemon[j] = temp;
            i++;
            j--;
        }
    }

    while (i <= j);
    if (primero < j)
        Quicksort(cant_Pokemon, primero, j); 
    if (i < ultimo)
        Quicksort(cant_Pokemon, i, ultimo); 

}

void Orden::Shellsort(array <Pokemon^>^ miPokedex, int Numero) {
    int i, j, k, incremento, aux;

    incremento = Numero / 2;

    while (incremento > 0) {
        for (i = incremento + 1; i <= Numero; i++) {
            j = i - incremento;
            while (j > 0) {
                if (cant_Pokemon[j] >= cant_Pokemon[j + incremento]) {
                    aux = cant_Pokemon[j];
                    cant_Pokemon[j] = cant_Pokemon[j + incremento];
                    cant_Pokemon[j + incremento] = aux;
                }
                else {
                    j = 0;
                }
                j = j - incremento;
            }
        }
        incremento = incremento / 2;
    }
}
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "ListaPunteos.h"
#include "ArbolJugadores.h"
#include "ColaFichas.h"
#include "ListaDobleDiccionario.h"

using namespace std;

int main()
{

    setlocale(LC_ALL,"Spanish");
    ArbolJugadores *lista = new ArbolJugadores();
    string dato = "";
    int opcion;
    int points;
    do{
        dato ="";
        cout << "1. Ingresar jugador" << endl;
        cout << "2. Ingresar puntos jugador" << endl;
        cout << "3. ver puntos jugador" << endl;
        cout << "4. ver mejores punteos" << endl;
        cin >> opcion;
        switch (opcion) {
        case 1:
            cout << "ingresar nombre" << endl;
            cin >> dato;
            lista->insertNewPlayer(dato);
            break;
        case 2:
        {
            cout << "ingrese nombre del jugador" << endl;
            cin >> dato;
            cout << "Ingrese sus puntos" << endl;
            cin >> points;
            Player *temp = lista->searchPlayer(dato);
            if(temp == NULL){
                cout << "No se encontro jugador" << endl;
            }else{
                temp->newPoints(points);
            }
        }
            break;
        case 3:
        {
            cout << "ingrese nombre del jugador" << endl;
            cin >> dato;
            if(lista->searchPlayer(dato) == NULL){
                cout << "No se encontro jugador" << endl;
            }else{
                lista->searchPlayer(dato)->getLista()->playerPointsGraph();
            }
        }
            break;
        case 4:
            lista->getBestPoints()->bestPointsGraph();
            break;
        }
    }while(opcion != 0);
    lista->createGraphTree();

    int salis;
    cin >> salis;
    return 0;
}

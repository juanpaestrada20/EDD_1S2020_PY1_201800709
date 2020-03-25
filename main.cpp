#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "ListaPunteos.h"
#include "ArbolJugadores.h"
#include "ColaFichas.h"
#include "ListaDobleDiccionario.h"
#include "ListaDobleFichasJugador.h"

using namespace std;

int main()
{

    setlocale(LC_ALL,"Spanish");
    Cola *lista = new Cola();
    FichasJugador *fichas = new FichasJugador();
    string dato = "";
    int opcion;
    lista->crearFichas();
    lista->createGraph();

    do{
        dato ="";
        cout << "1. obtener fichas" << endl;
        cout << "2. cambiar Ficha" << endl;
        cout << "3. Otra ficha" << endl;
        cout << "4. colocar ficha" << endl;
        cin >> opcion;
        switch (opcion) {
        case 1:
        {
            int a = 0;
            while(a < 7){
                fichas->getFichas(lista->desEnColar());
                a++;
            }
            lista->createGraph();
            fichas->graphHand("juan");
        }
            break;
        case 2:
        {
            fichas->graphHand("juan");
            cout << "Ingrese la letra " << endl;
            cin >> dato;
            lista->enColar(fichas->colocarFicha(dato));
            fichas->eliminarFicha(dato);
            fichas->getFichas(lista->desEnColar());
            lista->createGraph();
            fichas->graphHand("juan");
        }
            break;
        case 3:
        {
            fichas->getFichas(lista->desEnColar());
            lista->createGraph();
            fichas->graphHand("juan");
        }
            break;
        case 4:
        {
            fichas->graphHand("juan");
            cin >> dato;
            Ficha *temp = fichas->colocarFicha(dato);
            cout << "se coloco la ficha: " << temp->letra << endl;
        }
            break;
        }
    }while(opcion != 0);

    int salis;
    cin >> salis;
    return 0;
}

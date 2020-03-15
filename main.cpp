#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "ListaPunteos.h"
#include "ArbolJugadores.h"
#include "ColaFichas.h"

using namespace std;

int main()
{

    setlocale(LC_ALL,"Spanish");
    Cola *fichas = new Cola();

    cout << "===========" << endl;
    fichas->crearFichas();
    for(int i = 0; i < 96 ; i++){
        cout << fichas->desEnColar()->getLetra() << endl;
    }

    return 0;
}

#ifndef LISTAPUNTEOS_H
#define LISTAPUNTEOS_H
#include <string>
#include <iostream>

using namespace std;

class NodoLista{
public:
    int punteo;
    NodoLista *siguiente;
    NodoLista(int punteo){
        this->punteo = punteo;
        this->siguiente = NULL;
    }
};

class ListaSimple{
private:
    NodoLista *cabeza;
    NodoLista *cola;
    int size;
public:
    ListaSimple(){
        cabeza = NULL;
        cola = NULL;
        size = 0;
    }
    void insertPoints(int puntos){
        if(cabeza==NULL){
            cabeza = new NodoLista(puntos);
            cola = cabeza;
        }else if(cola->punteo >= puntos){
            NodoLista *nuevo = new NodoLista(puntos);
            cola->siguiente = nuevo;
            cola = nuevo;
        }else if(cabeza->punteo <= puntos){
            NodoLista *nuevo = new NodoLista(puntos);
            NodoLista *aux = cabeza;
            cabeza = nuevo;
            nuevo->siguiente = aux;
        }else{
            NodoLista *actual = cabeza->siguiente;
            NodoLista *anterior = cabeza;
            while(actual != NULL){
                if(actual->punteo <= puntos && anterior->punteo >= puntos){
                    NodoLista *nuevo = new NodoLista(puntos);
                    anterior->siguiente = nuevo;
                    nuevo->siguiente = actual;
                    break;
                }
                anterior = anterior->siguiente;
                actual = actual->siguiente;
            }
        }
        size++;
    }
    void showPoint(){
        if(size == 0){
            cout << "No hay puntos para mostar" << endl;
        }else{
            NodoLista *aux = cabeza;
            while(aux != NULL){
                cout << aux->punteo << " , ";
                aux = aux->siguiente;
            }
        }
    }

};

#endif // LISTAPUNTEOS_H

#ifndef ARBOLJUGADORES_H
#define ARBOLJUGADORES_H
#include <string>
#include <iostream>
#include "ListaPunteos.h"

using namespace std;

class Player{
private:
    string nombre;
    ListaSimple *puntos;
public:
    Player(string nombre){
        this->nombre = nombre;
        puntos = new ListaSimple();
    }
    Player(){};
    string getNombre(){
        return  nombre;
    }
    ListaSimple *getLista(){
        return puntos;
    }
    void newPoints(int points){
        puntos->insertPoints(points);
    }
};

class NodoArbol{
private:
    Player jugador;
    NodoArbol *izquierda;
    NodoArbol *derecha;
public:
    NodoArbol(Player jugador){
        this->jugador = jugador;
        izquierda = NULL;
        derecha = NULL;
    }
    void setIzquierda(NodoArbol *n){
        izquierda = n;
    }
    void setDerecha(NodoArbol *n){
        derecha = n;
    }
    string getNombre(){
        return jugador.getNombre();
    }
    NodoArbol *getIzquierda(){
        return izquierda;
    }
    NodoArbol *getDerecha(){
        return derecha;
    }
};

class ArbolJugadores{
private:
    NodoArbol *raiz;
public:
    ArbolJugadores(){
        raiz = NULL;
    }
    NodoArbol *insertPlayer(Player jugador, NodoArbol *n){
        if(n == NULL){
            n = new NodoArbol(jugador);
            return n;
        }else {
            if(n->getNombre() > jugador.getNombre()){
                NodoArbol *temp = this->insertPlayer(jugador.getNombre(),n->getIzquierda());
                n->setIzquierda(temp);
            }else if(n->getNombre() < jugador.getNombre()){
                NodoArbol *temp = this->insertPlayer(jugador.getNombre(),n->getDerecha());
                n->setDerecha(temp);
            }
            return n;
        }
    }
    void insertNewPlayer(string dato){
        Player jugador = *new Player(dato);
        raiz = insertPlayer(jugador, raiz);
    }
    void recorrerInorder(NodoArbol *n){
        if(n != NULL){
            recorrerInorder(n->getIzquierda());
            cout << n->getNombre() << endl;
            recorrerInorder(n->getDerecha());
        }
    }
    void recorrerPreorder(NodoArbol *n){
        if(n != NULL){
            cout << n->getNombre() << endl;
            recorrerPreorder(n->getIzquierda());
            recorrerPreorder(n->getDerecha());
        }
    }
    void recorrerPostorder(NodoArbol *n){
        if(n != NULL){
            recorrerPostorder(n->getIzquierda());
            recorrerPostorder(n->getDerecha());
            cout << n->getNombre() << endl;
        }
    }
    NodoArbol *getRaiz(){
        return raiz;
    }
    void setRaiz(NodoArbol *n){
        raiz = n;
    }

};

#endif // ARBOLJUGADORES_H

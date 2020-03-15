#ifndef COLAFICHAS_H
#define COLAFICHAS_H

#include <string>
#include <stdio.h>
#include <iostream>
#include <clocale>

using namespace std;

class Ficha{
private:
    string letra;
    int punteo;
public:
    Ficha(string letra, int punteo){
        this->letra = letra;
        this->punteo = punteo;
    }
    Ficha(){}
    string getLetra(){
        return letra;
    }
    int getPunteo(){
        return punteo;
    }
};

class NodoCola{
private:
    Ficha *ficha;
    NodoCola *siguiente;
public:
    NodoCola(Ficha *ficha){
        this->ficha = ficha;
        siguiente = NULL;
    }
    Ficha *getFicha(){
        return ficha;
    }
    NodoCola *getSiguiente(){
        return siguiente;
    }
    void setSiguiente(NodoCola *n){
        siguiente = n;
    }
};

class Cola{
private:
    NodoCola *first;
    NodoCola *last;
    Ficha *fichero[];
public:
    Cola(){
        first = NULL;
        last = NULL;
        setlocale(LC_ALL,"Spanish");
    }
    void enColar(Ficha *ficha){
        if(first == NULL){
            first = new NodoCola(ficha);
            last = first;
        }
        else {
            NodoCola *temp = new NodoCola(ficha);
            last->setSiguiente(temp);
            last=temp;
        }
    }
    Ficha *desEnColar(){
        if(first == NULL){
            cout << "No hay Fichas" << endl;
            return first->getFicha();
        }
        else{
            NodoCola *temp = first;
            first = first->getSiguiente();
            return temp->getFicha();
        }
    }
    void crearFichas(){
        int i = 0;
        int pos;
        bool libre[95];
        while (i<95) {
            libre[i] = false;
            if(i<12){
                fichero[i] = new Ficha("a", 1);
            }
            else if(i>=12 && i<24){
                fichero[i] = new Ficha("e", 1);
            }
            else if(i>=24 && i< 33){
                fichero[i] = new Ficha("o", 1);
            }
            else if(i>=33 && i<39){
                fichero[i] = new Ficha("i", 1);
            }
            else if(i>=39 && i<45){
                fichero[i] = new Ficha("s", 1);
            }
            else if(i>=45 && i<50){
                fichero[i] = new Ficha("n", 1);
            }
            else if(i>=50 && i<54){
                fichero[i]= new Ficha("l", 1);
            }
            else if(i>=54 && i<59){
                fichero[i]= new Ficha("r", 1);
            }
            else if(i>=59 && i<64){
                fichero[i]= new Ficha("u", 1);
            }
            else if(i>=64 && i<68){
                fichero[i]= new Ficha("t", 1);
            }
            else if(i>=68 && i<73){
                fichero[i]= new Ficha("d", 2);
            }
            else if(i>=73 && i<75){
                fichero[i]= new Ficha("g", 2);
            }
            else if(i>=75 && i<79){
                fichero[i]= new Ficha("c", 3);
            }
            else if(i>=79 && i<81){
                fichero[i]= new Ficha("b", 3);
            }
            else if(i>=81 && i<83){
                fichero[i]= new Ficha("m", 3);
            }
            else if(i>=83 && i<85){
                fichero[i]= new Ficha("p", 3);
            }
            else if(i>=85 && i<87){
                fichero[i]= new Ficha("h", 4);
            }
            else if(i== 87){
                fichero[i]= new Ficha("f", 4);
            }
            else if(i==88 ){
                fichero[i]= new Ficha("v", 4);
            }
            else if(i==89 ){
                fichero[i]= new Ficha("y", 4);
            }
            else if(i==90 ){
                fichero[i]= new Ficha("q", 5);
            }
            else if(i==91 ){
                fichero[i]= new Ficha("j", 8);
            }
            else if(i==92 ){
                fichero[i]= new Ficha("ñ", 8);
            }
            else if(i==93 ){
                fichero[i]= new Ficha("x", 8);
            }
            else if(i==94 ){
                fichero[i]= new Ficha("z", 8);
            }
            i++;
        }
        Ficha *desordenado[95];
        for(int j = 0; j < 95; j++){
            do{
                pos = (rand() % 95);
            }while(libre[pos]);
            desordenado[j] = fichero[pos];
            libre[pos]=true;
        }
        for(int l = 0; l < 95; l++){
            this->enColar(desordenado[l]);
        }
    }
};

#endif // COLAFICHAS_H

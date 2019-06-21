#include "Militar.h"
#include <vector>
using std::vector;

#ifndef NODOARBOL_H
#define NODOARBOL_H

class NodoArbol{
    public:
        Militar* militar;
        vector<NodoArbol*> nodos_hijos;

        NodoArbol(Militar*);

        Militar* getMilitar();
        vector<NodoArbol*> getNodos_hijos();

        void setNodosHijos(vector<NodoArbol*>);

        void agregarHijo(NodoArbol*);
        
        string toString();

};
#endif
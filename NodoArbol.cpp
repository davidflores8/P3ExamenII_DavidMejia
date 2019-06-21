#include "NodoArbol.h"
#include <sstream>
using std::stringstream;


NodoArbol::NodoArbol(Militar* militar_2){
    militar=militar_2;
}

Militar* NodoArbol::getMilitar(){
    return militar;
}

vector<NodoArbol*> NodoArbol::getNodos_hijos(){
    return nodos_hijos;
}

string NodoArbol::toString(){
    stringstream retorno;
    retorno<<militar->toString();
    if(nodos_hijos.size()==0){
        return retorno.str();
    }
    else
    {
        for (int i = 0; i <nodos_hijos.size(); i++)
        {
            retorno<<"  "<<nodos_hijos[i]->toString();
        }
        return retorno.str();
    }
    
}
    
void NodoArbol::setNodosHijos(vector<NodoArbol*> hijos){
    nodos_hijos=hijos;
}

void NodoArbol::agregarHijo(NodoArbol* nodo){
    nodos_hijos.push_back(nodo);
}
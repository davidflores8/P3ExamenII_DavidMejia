#include "Militar.h"
#include <sstream>
using std::stringstream;

Militar::Militar(string name, string code, string age, string range){
    nombre=name;
    codigo=code;
    edad=age;
    rango=range;
}

string Militar::getRango(){
    return rango;
}

string Militar::toString(){
    stringstream retorno;
    retorno<<"Nombre: "<<nombre<<" -- Codigo: "<<codigo<<" -- Edad: "<<edad<<" -- Rango: "<<rango;
    return retorno.str();
}

string Militar::getNombre(){
    return nombre;
}
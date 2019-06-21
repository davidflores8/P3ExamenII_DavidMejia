#include <string>
using std::string;

#include <vector>
using std::vector;


#ifndef MILITAR_H
#define MILITAR_H

class Militar{
    public:
        string nombre;
        string codigo;
        string edad;
        string rango;


        Militar(string, string, string, string);

        string getNombre();

        string getRango();

        string toString();

};
#endif
#include "Militar.h"
#include "NodoArbol.h"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

void PreOrden(NodoArbol*, string, vector<NodoArbol*>&);
void agregarMayor(NodoArbol*&, NodoArbol*);
void agregar(NodoArbol*&, vector<NodoArbol*>&);
NodoArbol* crearMilitar(string);



int main(){

    Militar* general=new Militar("Yagabarish Skrobernov", "M_17", "72", "General");
    NodoArbol* raiz=new NodoArbol(general);
    vector<NodoArbol*> militarTipoActual;
    int opcion=1;
    while(opcion>0 && opcion<3){
        cout<<"1. Agregar militares"<<endl;
        cout<<"2. Visualizar ejercito"<<endl;
        cout<<"3. Salir"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:{
                agregar(raiz,militarTipoActual);
            }
            break;
            case 2:{
                    string fileName;
                    cout<<"Ingrese el nombre del archivo para guardar su partida: "<<endl;
                    cin>>fileName;
            }
        }
    }


    return 0;
}

void printNode(NodoArbol* raiz){
    cout<<raiz->toString()<<endl;
    for (int i = 0; i <raiz->getNodos_hijos().size(); i++)
    {
        printNode(raiz->getNodos_hijos()[i]);    
    }
    
}


void PreOrden(NodoArbol*nodo, string rango, vector<NodoArbol*>&militar_tipo_Actual){
    if(nodo->getMilitar()->getRango()==rango){
       militar_tipo_Actual=nodo->getNodos_hijos();
    }

    for (int i = 0; i <nodo->getNodos_hijos().size(); i++)
    {
            PreOrden(nodo->getNodos_hijos()[i], rango, militar_tipo_Actual);
    }
}



void agregarMayor(NodoArbol*&raiz, NodoArbol* mayor){
    raiz->getNodos_hijos().push_back(mayor);
}



void agregar(NodoArbol*&raiz, vector<NodoArbol*>&militar_tipo_Actual){
    int opcion;
    cout<<"Que quiere agregar?"<<endl;
    cout<<"1. Mayor\n2. Capitan\n3. Teniente\n4. Sargento\n5. Cabo\n6. Soldado"<<endl;
    cin>>opcion;
    if(opcion==1){
        NodoArbol* mayor=crearMilitar("Mayor");
        agregarMayor(raiz, mayor);
    }
    else if (opcion==2){

        NodoArbol* capitan=crearMilitar("Capitan");

        PreOrden(raiz, "Mayor", militar_tipo_Actual);

        if(militar_tipo_Actual.size()==0){

            cout<<"No hay Mayores disponibles"<<endl;
        }
        else{
            for (int i = 0; i <militar_tipo_Actual.size(); i++)
            {
                cout<<i<<") "<<militar_tipo_Actual[i]->getMilitar()->getNombre()<<endl;
            }
            int indice_a_agregar;
            cin>>indice_a_agregar;
            militar_tipo_Actual[indice_a_agregar]->agregarHijo(capitan);

        }
    }

    else if (opcion==3){
         NodoArbol* teniente=crearMilitar("Teniente");

        PreOrden(raiz, "Capitan", militar_tipo_Actual);

        if(militar_tipo_Actual.size()==0){

            cout<<"No hay Capitanes disponibles"<<endl;
        }
        else{
            for (int i = 0; i <militar_tipo_Actual.size(); i++)
            {
                cout<<i<<") "<<militar_tipo_Actual[i]->getMilitar()->getNombre()<<endl;
            }
            int indice_a_agregar;
            cin>>indice_a_agregar;
            militar_tipo_Actual[indice_a_agregar]->agregarHijo(teniente);
        }

    }

    else if (opcion==4){
         NodoArbol* sargento=crearMilitar("Sargento");

        PreOrden(raiz, "Teniente", militar_tipo_Actual);

        if(militar_tipo_Actual.size()==0){

            cout<<"No hay Tenientes disponibles"<<endl;
        }
        else{
            for (int i = 0; i <militar_tipo_Actual.size(); i++)
            {
                cout<<i<<") "<<militar_tipo_Actual[i]->getMilitar()->getNombre()<<endl;
            }
            int indice_a_agregar;
            cin>>indice_a_agregar;
            militar_tipo_Actual[indice_a_agregar]->agregarHijo(sargento);
        }

    }

    else if (opcion==5){
         NodoArbol* cabo=crearMilitar("Cabo");

        PreOrden(raiz, "Sargento", militar_tipo_Actual);

        if(militar_tipo_Actual.size()==0){

            cout<<"No hay Sargentos disponibles"<<endl;
        }
        else{
            for (int i = 0; i <militar_tipo_Actual.size(); i++)
            {
                cout<<i<<") "<<militar_tipo_Actual[i]->getMilitar()->getNombre()<<endl;
            }
            int indice_a_agregar;
            cin>>indice_a_agregar;
            militar_tipo_Actual[indice_a_agregar]->agregarHijo(cabo);
        }

    }
    else if (opcion==6){
         NodoArbol* soldado=crearMilitar("Soldado");

        PreOrden(raiz, "Cabo", militar_tipo_Actual);

        if(militar_tipo_Actual.size()==0){

            cout<<"No hay Cabos disponibles"<<endl;
        }
        else{
            for (int i = 0; i <militar_tipo_Actual.size(); i++)
            {
                cout<<i<<") "<<militar_tipo_Actual[i]->getMilitar()->getNombre()<<endl;
            }
            int indice_a_agregar;
            cin>>indice_a_agregar;
            militar_tipo_Actual[indice_a_agregar]->agregarHijo(soldado);
        }

    }
    
    militar_tipo_Actual.clear();


}

NodoArbol* crearMilitar(string range){
    string nombre, edad, codigo, rango;
    cout<<"Ingrese el nombre: "<<endl;
    cin>>nombre;
    cout<<"Ingrese la edad: "<<endl;
    cin>>edad;
    cout<<"Ingrese el codigo: "<<endl;
    cin>>codigo;
    Militar* nuevo_militar=new Militar(nombre,codigo, edad, range);
    NodoArbol* nuevo_nodo=new NodoArbol(nuevo_militar);
    return nuevo_nodo;

}
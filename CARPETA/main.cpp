//
//  main.cpp
//  PRÁCTICA SISTEMA BANCARIO
//
//  Created by Eduardo Ros on 16/10/23.
//
#include <fstream>
#include <string>
#include <iostream>

#include "Interfaz.hpp"
using namespace std;

int main(){
    //Usamos un error absurdo para que el programa tenga por lo menos un try catch
    //Pedimos el codigo postal. Si el codigo postal tiene más de 5 caracteres entonces me lanza la excepcion. Sino, me ejecuta el programa. Todos los codigos postales españoles tienen 5 dígitos.
    string codigoPostal;
    cout << "Introduzca su código postal" << endl;
    cin >> codigoPostal;
    
    try{
        if (codigoPostal.size() == 5){
            interfaz();
        }
        else {
            throw exception();
        }
    }
    
    catch(exception& a){
        cout << "Ha introducido un código postal incorrecto" << endl;
    }

    return 0;
}

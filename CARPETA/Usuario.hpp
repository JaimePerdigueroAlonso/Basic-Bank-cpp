//
//  class Usuario.hpp
//  PRÁCTICA SISTEMA BANCARIO
//
//  Created by Eduardo Ros and Jaime Perdiguero on 7/11/23.
//

#ifndef class_Usuario_hpp
#define class_Usuario_hpp

#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

class Usuario {
public:
    virtual void contacto() = 0;
protected:
    string Nombre;
    string Apellido1;
    string Apellido2;
    string FechaDeNacimiento;
    string dni;
    string contraseña;
    string comprobacionContraseña;
    double saldo;
};

#endif /* class_Usuario_hpp */

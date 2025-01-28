//
//  UsuarioRegistrado.hpp
//  PRÁCTICA SISTEMA BANCARIO
//
//  Created by Eduardo Ros on 7/11/23.
//

#ifndef UsuarioRegistrado_hpp
#define UsuarioRegistrado_hpp

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <vector>
#include "Usuario.hpp"
using namespace std;

class UsuarioRegistrado : public Usuario{

public:
    int menuUsuarioRegistrado();
    bool leeBaseDeDatosYcompara (string dniEntrada, string contraseñaEntrada);
    void ConsultarSaldo(string dniEntrada);
    void RealizarIngreso(string dniEntrada, double cantidad);
    void RealizarRetirada(string dniEntrada, double cantidad);
    void RealizarTransferencia(string dniEntrada, string dniSalida, double cantidad);
    void contacto();

};

#endif /* UsuarioRegistrado_hpp */

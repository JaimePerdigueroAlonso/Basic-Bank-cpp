//
//  UsuarioNoRegistrado.hpp
//  PRÁCTICA SISTEMA BANCARIO
//
//  Created by Eduardo Ros and Jaime Perdiguero on 7/11/23.
//

#ifndef UsuarioNoRegistrado_hpp
#define UsuarioNoRegistrado_hpp

#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>
#include "Usuario.hpp"
using namespace std;

class UsuarioNoRegistrado : public Usuario{
    bool coincidenContraseñas = true;
    
public:
    void datosEntradaRegistro();
    void datosIntroducidos();
    void contacto();
};

#endif /* UsuarioNoRegistrado_hpp */

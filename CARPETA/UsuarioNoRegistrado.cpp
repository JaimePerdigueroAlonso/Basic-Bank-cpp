//
//  UsuarioNoRegistrado.cpp
//  PRÁCTICA SISTEMA BANCARIO
//
//  Created by Eduardo Ros on 7/11/23.
//

#include "UsuarioNoRegistrado.hpp"

void UsuarioNoRegistrado :: contacto(){
    cout << "Como usted no esta registrado, el teléfono de contacto es este: " << endl;
    cout << "638 454 876" << endl;
}

void UsuarioNoRegistrado :: datosEntradaRegistro(){
    cout << "----------------------------------------------------------------" << endl;
    cout << "Para realizar el registro vamos a necesitar los siguientes datos" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "Inserte su Nombre" << endl;
    cin >> Nombre;
    cout << "Inserte su primer apellido" << endl;
    cin >> Apellido1;
    cout << "Inserte su segundo apellido" << endl;
    cin >> Apellido2;
    cout << "Inserte su fecha de nacimiento ejemplo -> (13/08/2003)" << endl;
    cin >> FechaDeNacimiento;
    cout << "Inserte el número de su documento de identidad (Corresponderá con sus credenciales de acceso)" << endl;
    cin >> dni;
    cout << "Desea añadir fondos a su cuenta? (Si/No)" << endl;
    string respuesta;
    cin >> respuesta;
    if (respuesta == "Si" || respuesta == "SI" || respuesta == "si"){
        cout << "Inserte el saldo de apertura de la cuenta" << endl;
        cin >> saldo;
    } else {
        saldo = 0;
    }
    while (coincidenContraseñas == true){
        cout << "Inserte su contraseña" << endl;
        cin >> contraseña;
        cout << "Por seguridad, vuelva a escribir la contraseña" << endl;
        cin >> comprobacionContraseña;
        
        if (contraseña == comprobacionContraseña){
            cout << "Las contraseñas coinciden" << endl;
            coincidenContraseñas = false;
        }else {
            cout << "Las contraseñas no coinciden" << endl;
            cout << "Inserte las contraseñas de nuevo por favor" << endl;
            coincidenContraseñas = true;
        }
    }
    
    
}

void UsuarioNoRegistrado :: datosIntroducidos(){
    // Tengo que hacer un txt ::app para que me guarde los datos del registro en el txt y asi ese usuario pasa a estar en la base de datos
    string datosCorrectos;
    cout << "-----------------------------------------" << endl;
    cout << "Los datos introducidos son los siguientes" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Nombre: " << Nombre << endl;
    cout << "Primer Apellido: " << Apellido1 << endl;
    cout << "Segundo Apellido: " << Apellido2 << endl;
    cout << "Fecha de Nacimiento: " << FechaDeNacimiento << endl;
    cout << "Número Documento identidad: " << dni << endl;
    cout << "Saldo de apertura de cuenta: " << saldo << endl;
    cout << "¿Son correctos los datos? (Si/No)" << endl;
    cin >> datosCorrectos;
    
    if (datosCorrectos == "Si" || datosCorrectos == "SI" || datosCorrectos == "si"){
        ofstream baseDeDatos("/Users/eduros/Documents/EDUARDO/CUNEF/3 AÑO/1º CUATRI/PROYECTOS DE PROGRAMACIÓN/MIS BASES DE DATOS/BaseDeDatos.txt", ios::app);//abrimos archivo y añadimos info nueva
        ofstream baseDeDatosSALDOS("/Users/eduros/Documents/EDUARDO/CUNEF/3 AÑO/1º CUATRI/PROYECTOS DE PROGRAMACIÓN/MIS BASES DE DATOS/BaseDeDatosSALDOS.txt", ios::app);//abrimos archivo y añadimos info nueva
        if (baseDeDatos.is_open()){
            cout << "Guardando Datos" << endl;
            baseDeDatos << Nombre << "|" << Apellido1 << "|" << Apellido2 << "|" << FechaDeNacimiento << "|" << dni << "|" << contraseña << "|" <<comprobacionContraseña << "|"<< endl;
            baseDeDatos.close();
        }
        
        if (baseDeDatosSALDOS.is_open()){
            baseDeDatosSALDOS << saldo << endl;
            baseDeDatosSALDOS.close();
        }
    }
}



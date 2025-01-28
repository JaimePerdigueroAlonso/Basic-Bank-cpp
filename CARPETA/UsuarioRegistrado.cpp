//
//  UsuarioRegistrado.cpp
//  PRÁCTICA SISTEMA BANCARIO
//
//  Created by Eduardo Ros on 7/11/23.
//

#include "UsuarioRegistrado.hpp"

using namespace std;

void UsuarioRegistrado::contacto(){
    cout << "Como usted esta registrado, el teléfono de contacto es este: " << endl;
    cout << "638 454 678" << endl;
}

int UsuarioRegistrado :: menuUsuarioRegistrado(){
    int opcion;
    bool opcionvalida= true;
    while (opcionvalida == true){
        cout << "Escoja la acción que desea realizar" << endl;
        cout << "-----------------------------------" << endl;
        cout << "1.Consultar Saldo" << endl;
        cout << "2.Realizar un ingreso" << endl;
        cout << "3.Realizar una retirada" << endl;
        cout << "4.Realizar una transferencia" << endl;
        cout << "5.Obtener teléfono de soporte" << endl;
        cout << "6.Salir" << endl;
        cout << "-----------------------------------" << endl;
        cout << "                                   " << endl;
        
        cin >> opcion;
        
        if (opcion > 6  || opcion < 1){
            cout << "Opción no valida, inserte de nuevo lo que quiere realizar" << endl ;
            opcionvalida = true;
        }else{
            opcionvalida = false;
        }
    }
        
    return opcion;
}

bool UsuarioRegistrado :: leeBaseDeDatosYcompara(string dniEntrada, string contraseñaEntrada){
    bool UsuarioCorrecto = true;
    vector <string> vectorDnis;
    vector <string> vectorContraseñas;
    ifstream BaseDeDatos;
    
    BaseDeDatos.open("/BaseDeDatos.txt", ios::out); //abrimos archivo para leer
    if (BaseDeDatos.is_open()) {
        string linea;
        while (getline(BaseDeDatos, linea)) {
            stringstream ss(linea);
            getline(ss,Nombre,'|'); //Le digo que Nombre es la primera palabra que vea hasta que encuentre '|'
            getline(ss,Apellido1,'|'); //Le digo que Apellido1 es la palabra que encuentre hasta el siguiente '|'
            getline(ss,Apellido2,'|');
            getline(ss,FechaDeNacimiento,'|');
            getline(ss,dni,'|');
            getline(ss,contraseña,'|');
            getline(ss,comprobacionContraseña, '|');

            vectorDnis.push_back(dni);
            vectorContraseñas.push_back(contraseña);
        }
        BaseDeDatos.close();
    }
    for (int i=0 ;i<vectorDnis.size();i++){
        if (dniEntrada == vectorDnis[i] && contraseñaEntrada == vectorContraseñas[i]){
            UsuarioCorrecto = true;
            break;
            
        }
        else{
            UsuarioCorrecto = false;
        }
    }
return UsuarioCorrecto;
}

void UsuarioRegistrado::ConsultarSaldo(string dniEntrada){
    vector <string> vectorDnis;
    vector <double> vectorSaldos;
    ifstream BaseDeDatos;
    ifstream BaseDeDatosSALDOS;
    BaseDeDatos.open("/BaseDeDatos.txt", ios::out);
    BaseDeDatosSALDOS.open("/BaseDeDatosSALDOS.txt", ios::out);
    if (BaseDeDatos.is_open()){
        string linea;
        while(getline(BaseDeDatos,linea)){
            stringstream ss(linea);
            getline(ss, Nombre, '|');
            getline(ss,Apellido1,'|'); //Le digo que Apellido es la palabra que encuentre hasta el siguiente '|'
            getline(ss,Apellido2,'|');
            getline(ss,FechaDeNacimiento,'|');
            getline(ss,dni,'|');
            getline(ss,contraseña,'|');
            getline(ss,comprobacionContraseña, '|');
            
            vectorDnis.push_back(dni);
        }
        BaseDeDatos.close();
    }
    
    if (BaseDeDatosSALDOS.is_open()){
        string lineaSALDOS;
        while(getline(BaseDeDatosSALDOS,lineaSALDOS)){
            istringstream iss(lineaSALDOS);
            int numero;
            if (iss >> numero) {
            // Agregar el número al vector
                vectorSaldos.push_back(numero);
            }
        }
        BaseDeDatosSALDOS.close();
    }
    
    for (int i=0 ;i<vectorDnis.size();i++){
        if (dniEntrada == vectorDnis[i]){
            cout << "" << endl;
            cout << "El saldo disponible en la cuenta es: "<< vectorSaldos[i] << "€" << endl;
            break;
        }
    }
}


void UsuarioRegistrado::RealizarIngreso(string dniEntrada, double cantidad){
    vector <string> vectorDnis;
    vector <double> vectorSaldos;
    ifstream BaseDeDatos;
    ifstream BaseDeDatosSALDOS;
    
    BaseDeDatosSALDOS.open("/BaseDeDatosSALDOS.txt");
    ofstream BaseDeDatosSALDOS_TEMPORAL("/BaseDeDatosSALDOS_TEMPORAL.txt");
    BaseDeDatos.open("/BaseDeDatos.txt", ios::out);
    
    if (BaseDeDatos.is_open()){
        string linea;
        while(getline(BaseDeDatos,linea)){
            stringstream ss(linea);
            getline(ss, Nombre, '|');
            getline(ss,Apellido1,'|'); //Le digo que Apellido1 es la palabra que encuentre hasta el siguiente '|'
            getline(ss,Apellido2,'|');
            getline(ss,FechaDeNacimiento,'|');
            getline(ss,dni,'|');
            getline(ss,contraseña,'|');
            getline(ss,comprobacionContraseña, '|');
            
            vectorDnis.push_back(dni);
        }
        BaseDeDatos.close();
    }
    
    if (!BaseDeDatosSALDOS.is_open() || !BaseDeDatosSALDOS_TEMPORAL.is_open()) {
        cout << "Error al abrir los archivos" << endl;
    }
    
    if (BaseDeDatosSALDOS.is_open()){
        string lineaSALDOS;
        while(getline(BaseDeDatosSALDOS,lineaSALDOS)){
            istringstream iss(lineaSALDOS);
            double numero;
            if (iss >> numero) {
            // Agregar el número al vector
                vectorSaldos.push_back(numero);
            }
        }
        BaseDeDatosSALDOS.close();
    }
    
    for (int i =0; i<vectorSaldos.size();i++){
        if(dniEntrada == vectorDnis[i]){
            vectorSaldos[i] = vectorSaldos[i] += cantidad;
        }
    }
    
    for (int i = 0; i<vectorSaldos.size();i++){
        BaseDeDatosSALDOS_TEMPORAL << vectorSaldos[i] << endl;
    }

        BaseDeDatos.close();
        BaseDeDatosSALDOS.close();
        BaseDeDatosSALDOS_TEMPORAL.close();
        
        remove("/BaseDeDatosSALDOS.txt");
        rename("/BaseDeDatosSALDOS_TEMPORAL.txt", "/BaseDeDatosSALDOS.txt");
}


void UsuarioRegistrado::RealizarRetirada(string dniEntrada, double cantidad){
    vector <string> vectorDnis;
    vector <double> vectorSaldos;
    ifstream BaseDeDatos;
    ifstream BaseDeDatosSALDOS;
    
    BaseDeDatosSALDOS.open("/BaseDeDatosSALDOS.txt");
    ofstream BaseDeDatosSALDOS_TEMPORAL("/BaseDeDatosSALDOS_TEMPORAL.txt");
    BaseDeDatos.open("/BaseDeDatos.txt", ios::out);
    
    if (BaseDeDatos.is_open()){
        string linea;
        while(getline(BaseDeDatos,linea)){
            stringstream ss(linea);
            getline(ss, Nombre, '|');
            getline(ss,Apellido1,'|'); //Le digo que Apellido es la palabra que encuentre hasta el siguiente '|'
            getline(ss,Apellido2,'|');
            getline(ss,FechaDeNacimiento,'|');
            getline(ss,dni,'|');
            getline(ss,contraseña,'|');
            getline(ss,comprobacionContraseña, '|');
            
            vectorDnis.push_back(dni);
        }
        BaseDeDatos.close();
    }
    
    if (!BaseDeDatosSALDOS.is_open() || !BaseDeDatosSALDOS_TEMPORAL.is_open()) {
        cout << "Error al abrir los archivos" << endl;
    }

    if (BaseDeDatosSALDOS.is_open()){
        string lineaSALDOS;
        while(getline(BaseDeDatosSALDOS,lineaSALDOS)){
            istringstream iss(lineaSALDOS);
            double numero;
            if (iss >> numero) {
            // Agregar el número al vector
                vectorSaldos.push_back(numero);
            }
        }
        BaseDeDatosSALDOS.close();
    }
    
    for (int i =0; i<vectorSaldos.size();i++){
        if(dniEntrada == vectorDnis[i]){
            vectorSaldos[i] = vectorSaldos[i] -= cantidad;
        }
    }
    
    for (int i = 0; i<vectorSaldos.size();i++){
        BaseDeDatosSALDOS_TEMPORAL << vectorSaldos[i] << endl;
    }

        BaseDeDatos.close();
        BaseDeDatosSALDOS.close();
        BaseDeDatosSALDOS_TEMPORAL.close();
        
        remove("/BaseDeDatosSALDOS.txt");
        rename("BaseDeDatosSALDOS_TEMPORAL.txt", "/BaseDeDatosSALDOS.txt");
}


void UsuarioRegistrado::RealizarTransferencia(string dniEntrada, string dniSalida, double cantidad){
    vector <string> vectorDnis;
    vector <double> vectorSaldos;
    ifstream BaseDeDatos;
    ifstream BaseDeDatosSALDOS;
    
    BaseDeDatosSALDOS.open("/BaseDeDatosSALDOS.txt");
    ofstream BaseDeDatosSALDOS_TEMPORAL("/BaseDeDatosSALDOS_TEMPORAL.txt");
    BaseDeDatos.open("/BaseDeDatos.txt", ios::out);
    
    if (BaseDeDatosSALDOS.is_open()){
        string lineaSALDOS;
        while(getline(BaseDeDatosSALDOS,lineaSALDOS)){
            istringstream iss(lineaSALDOS);
            double numero;
            if (iss >> numero) {
            // Agregar el número al vector
                vectorSaldos.push_back(numero);
            }
        }
    }
    
    if (BaseDeDatos.is_open()){
        string linea;
        while(getline(BaseDeDatos,linea)){
            stringstream ss(linea);
            getline(ss, Nombre, '|');
            getline(ss,Apellido1,'|'); //Le digo que Apellido es la palabra que encuentre hasta el siguiente '|'
            getline(ss,Apellido2,'|');
            getline(ss,FechaDeNacimiento,'|');
            getline(ss,dni,'|');
            getline(ss,contraseña,'|');
            getline(ss,comprobacionContraseña, '|');
            
            vectorDnis.push_back(dni);
        }
    }
    
    if (cantidad > 0){
        for(int i= 0; i < vectorDnis.size();i++){
            if (dniEntrada == vectorDnis[i]){
                vectorSaldos[i] = vectorSaldos[i] -= cantidad;
            }
        }
        for(int i= 0; i < vectorDnis.size();i++){
            if (dniSalida == vectorDnis[i]){
                vectorSaldos[i] = vectorSaldos[i] += cantidad;
            }
        }
        
        for (int i= 0; i<vectorSaldos.size();i++){
            BaseDeDatosSALDOS_TEMPORAL << vectorSaldos[i] << endl;
        }
        
        }else {
                cout << "No podemos realizar transferencias de importes negativos" << endl;
            }
    BaseDeDatos.close();
    BaseDeDatosSALDOS.close();
    BaseDeDatosSALDOS_TEMPORAL.close();
    
    remove("/BaseDeDatosSALDOS.txt");
    rename("/BaseDeDatosSALDOS_TEMPORAL.txt", "/BaseDeDatosSALDOS.txt");
}



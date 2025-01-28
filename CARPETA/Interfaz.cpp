//
//  Interfaz.cpp
//  PRACTICA SISTEMA BANCARIO
//
//  Created by Eduardo Ros on 29/11/23.
//

#include "Interfaz.hpp"

void interfaz(){
    UsuarioRegistrado UR; //PARA ACCEDER A LAS FUNCIONES DE USUARIO REGISTRADO
    UsuarioNoRegistrado UNR; //PARA ACCEDER A LAS FUNCIONES DE USUARIO NO REGISTRADO

    string registradoOnoregistrado;
    cout << "------------------------------------" << endl;
    cout << "             Bienvenido             " << endl;
    cout << "¿Es usted usuario del banco? (Si/No)" << endl;
    cout << "------------------------------------" << endl;
    cin >> registradoOnoregistrado;
    while (registradoOnoregistrado != "Si" && registradoOnoregistrado != "SI" && registradoOnoregistrado != "si" && registradoOnoregistrado != "No" && registradoOnoregistrado != "NO" && registradoOnoregistrado != "no"){
        cout << "No se ha registrado bien su respuesta" << endl;
        cout << "------------------------------------" << endl;
        cout << "¿Es usted usuario del banco? (Si/No)" << endl;
        cout << "------------------------------------" << endl;
        cin >> registradoOnoregistrado;
    }
    
    if(registradoOnoregistrado == "Si" || registradoOnoregistrado == "SI" || registradoOnoregistrado == "si"){
        bool repetirDatosEntrada = true;
        while(repetirDatosEntrada == true){ //BUCLE QUE SE ME REPITE SI ALGUNA CREDENCIAL ES INCORRECTA
            int opcion;
            bool enviarMenuDeNuevo = true;
            string dni;
            string contraseña;
            cout << "Introduzca su numero de identificación por favor" << endl;
            cin >> dni;
            cout << "Intruduzca su clave de acceso / contraseña" << endl;
            cin >> contraseña;
            
            if (UR.leeBaseDeDatosYcompara(dni,contraseña) == true){ //Recoge true o false de la funcion y me lo ejecuta en funcion de la salida
                while (enviarMenuDeNuevo == true){ // BUCLE QUE ME ENVÍA EL MENU HASTA QUE EL USUARIO DESEE SALIR (OPCION 5)
                    opcion = UR.menuUsuarioRegistrado();
                    switch (opcion){
                        case 1:
                            UR.ConsultarSaldo(dni);
                            break;
                            
                        case 2:
                            double saldoAañadir;
                            cout << "Introduzca la cantidad que desea ingresar: " << endl;
                            cin >> saldoAañadir;
                            UR.RealizarIngreso(dni,saldoAañadir);
                            break;
                            
                        case 3:
                            double saldoAretirar;
                            cout << "Introduzca la cantidad que desea retirar: " << endl;
                            cin >> saldoAretirar;
                            UR.RealizarRetirada(dni, saldoAretirar);
                            break;
                            

                        case 6:
                            cout << "¡Hasta luego!" << endl;
                            enviarMenuDeNuevo = false; // Lo uso para que no me entre en el while y me vuelva a enviar el menú
                            registradoOnoregistrado = "MENSAJE PARA ACABAR";
                            break;
                            
                        case 5:
                            UR.contacto();
                            break;
                        case 4:
                            double saldoAtransferir;
                            string dniSalida;
                            cout << "Introduzca el DNI del destinatario" << endl;
                            cin >> dniSalida;
                            cout << "Introduzca el saldo que desea transferir" << endl;
                            
                            cin >> saldoAtransferir;
                            UR.RealizarTransferencia(dni, dniSalida, saldoAtransferir);
                            break;
                        
                        
                    
                        
                        
                            
                            
                            
                    }
                    repetirDatosEntrada = false; // Lo uso para que no me pida más veces los datos de entrada
                }
                
            }else{
                    cout <<"Ha introducido algún dato erróneo" << endl;

            }
        }
    }
    
    if(registradoOnoregistrado == "No" || registradoOnoregistrado == "NO" || registradoOnoregistrado == "no"){
        string seRegistra;
        cout << "¿Desea registrarse? (Si/No)" << endl;
        cin >> seRegistra;
        
        if (seRegistra == "Si" || seRegistra == "SI" || seRegistra == "si"){
            UNR.datosEntradaRegistro();
            UNR.datosIntroducidos();
            registradoOnoregistrado = "Si";
            
        }else{
            cout << "Hasta luego" << endl;
            UNR.contacto();
            registradoOnoregistrado = "Si";
        }
    }
    
}

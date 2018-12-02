#include "persona.h"
#include <string>

//Constructor de persona
Persona::Persona(string dni, string nombre, string apellidos, int telefono, string direccion, string email){
    dni_ = setDNI(dni);
    nombre_ = nombre;
    apellidos_ = apellidos;
    telefono_ = setTelefono(telefono);
    direccion_ = direccion;
    email_ = email;
}

//Comprobacion de telefono correcto
bool Persona::setTelefono(int nuevo_telefono){
    if ((nuevo_telefono > 100000000) && (nuevo_telefono < 999999999)){
        telefono_ = nuevo_telefono;
        return true;
    }
    else{
        return false;
    }

}
//Funcion auxiliar que devuelve la letra de DNI
char letraDNI(int dni){
    int letra;
    letra = dni%23;
    string letras = "TRWAGMYFPDXBNJZSQVHLCKE";
    return letras[letra];
}

//Comprobacion de DNI correcto
bool Persona::setDNI(string nuevo_dni){
    if (nuevo_dni.size()!=9){
        return false;
    }
    if(nuevo_dni[8] != letraDNI(stoi(nuevo_dni))){
        return false;
    }
    dni_ = nuevo_dni;
    return true;
}

//Return del nombre completo
string Persona::getApellidosyNombre() const {
    string nombrecompleto;
    nombrecompleto = nombre_ + " " + apellidos_;
    return nombrecompleto;

}
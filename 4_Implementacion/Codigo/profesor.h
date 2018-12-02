//Archivo de cabecera de la clase Profesor
//José Márquez Doblas
//La clase Profesor es una subclase de Persona

#ifndef PROFESOR_H
#define PROFESOR_H

#include "persona.h"

class Profesor :public Persona{
  private:
    string fichero_;
    bool coordinador_;

  public:
    //Constructor
    Profesor(string dni, string nombre, string fichero, string apellidos,
    int telefono=0, string direccion="", string email="", 
    bool coordinador=false):Persona(dni, nombre, apellidos, telefono, direccion, email){
      coordinador_ = coordinador;
      fichero_ = fichero;
    };

    //Modificadores
    inline bool setCoordinador();
    inline void setfichero(int nuevo_fichero){fichero_=nuevo_fichero;};

    //Observadores
    inline bool getCoordinador(){return coordinador_;};
    inline string getFicheroo(){return fichero_;};
};

#endif

//Archivo de cabecera de la clase Profesor
//José Márquez Doblas
//La clase Profesor es una subclase de Persona

#ifndef PROFESOR_H
#define PROFESOR_H

#include "persona.h"
using std::ostream;
using std::istream;

class Profesor :public Persona{
  private:
    string fichero_;
    bool coordinador_;
    string contrasena_;

  public:
    //Constructor
    Profesor(string dni, string nombre, string fichero, string apellidos,
    int telefono=0, string direccion="", string email="", 
    bool coordinador=false):Persona(dni, nombre, apellidos, telefono, direccion, email){
      coordinador_ = coordinador;
      fichero_ = fichero;
    };

    //Modificadores
    inline bool CambiarCoordinador();
	inline void setCoordinador(bool nuevo_coordinador);
    inline void setFichero(string nuevo_fichero){fichero_ = nuevo_fichero;};
    inline void setContrasena(string nuevo_password){contrasena_=nuevo_password;};

    //Observadores
    inline bool getCoordinador() const {return coordinador_;};
    inline string getFichero() const {return fichero_;};

	//Operadores
	friend ostream &operator<<(ostream &output_stream, const Profesor &profesor);
	friend istream &operator>>(istream &input_stream, Profesor &profesor);
};

#endif

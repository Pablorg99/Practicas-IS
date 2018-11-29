//Archivo de cabecera de la clase Alumno
//Manuel Alejandro Luque León
//La clase Alumno es una subclase de Persona

#ifndef ALUMNO_H
#define ALUMNO_H

#include "persona"

class Alumno :public Persona{
  private:
    int curso_;
    int Nequipo_;
    bool lider_;

  public:
    //Constructor
    Alumno(string dni, string nombre, string apellidos,
    int telefono=0, string direccion="", string email="",
    int curso=0, int Nequipo=0, bool lider=false);

    //Modificadores
    inline void setcurso(int nuevo_curso){curso_ = nuevo_curso;};
    inline void setNequipo(int nuevo_Nequipo){Nequipo_=nuevo_Nequipo;};
    inline void(bool nuevo_lider){lider_=nuevo_lider;};

    //Observadores
    inline int getcurso(){return dni_;};
    inline int getNequipo(){return Nequipo_;};
    inline bool getlider(){return lider_;};
};

#endif

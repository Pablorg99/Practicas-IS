//Archivo de cabecera de la clase Alumno
//Manuel Alejandro Luque León
//La clase Alumno es una subclase de Persona

#ifndef ALUMNO_H
#define ALUMNO_H

#include "persona.h"
using std::ostream;
using std::istream;

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
		inline void setCurso(int nuevo_curso){curso_ = nuevo_curso;};
		inline void setNequipo(int nuevo_Nequipo){Nequipo_=nuevo_Nequipo;};
		void setLider(bool nuevo_lider);
		void cambiaLider();
		bool unicoLider();
		//Observadores
		inline int getCurso() const {return curso_;};
		inline int getNequipo() const {return Nequipo_;};
		inline bool getLider() const {return lider_;};

		//Operadores
		friend ostream &operator<<(ostream &output_stream, const Alumno &alumno);
		friend istream &operator>>(istream &input_stream, Alumno &alumno);
};

#endif
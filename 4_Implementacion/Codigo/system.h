

#ifndef SYSTEM_H
#define SYSTEM_H

#include "alumno.h"
#include "profesor.h"
#include "database.h"
#include <string>

class System{
    private:
        Database BDsistema_;
        Profesor usuario_;
    public:
        System();
        void LeeCredenciales(string ficheroCredenciales);
        void start(Profesor usuario);
        Profesor getUsuarioByCredencial(string credencial);
        bool RegistroCoordinador();
        Profesor RegistroProfesor();
        bool ModificarProfesor();
		list <Alumno> BuscarAlumnos();
		list <Alumno> SeleccionarUnEquipo(int n_equipo);
		list <Alumno> SeleccionarNumeroAlumnos(int n_alumnos);
		int PedirParametro();
		string PedirValor(int parametro);
		void FormatearBD();
		void MostrarAlumno(list <Alumno> listalumno);
		bool InsertarAlumno();
        list<Profesor> BuscarProfesor();

};

#endif
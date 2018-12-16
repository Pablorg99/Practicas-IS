

#ifndef SYSTEM_H
#define SYSTEM_H

#include "alumno.h"
#include "profesor.h"
#include "database.h"
#include <string>

class System{
    private:
        Profesor usuario_;
        Database BDsistema_;
        list<Alumno> alumnos_;
    public:
        System(string ficheroCredenciales, Profesor &usuario, Database BDsistema);
        int menuPrincipal();
		bool InsertarAlumno();
		list <Alumno> BuscarAlumnos();
		list <Alumno> SeleccionarUnEquipo(int n_equipo);
		list <Alumno> SeleccionarNumeroAlumnos(int n_alumnos);
		int PedirParametro();
		string PedirValor(int parametro);
		int subMenuBuscar();
		void MostrarAlumno();
		list<Alumno> ModificarAlumno();
		void BorrarAlumnos(list<Alumno> list_seleccion_alumnos);
        Profesor RegistroProfesor();
		list<Profesor> BuscarProfesor();
        Profesor RegistroCoordinador();
        bool ModificarProfesor();
		bool EliminarAyudante();
		void GenerarBackup();
		void CargarBackup();
		void FormatearBD();
		string primerInicio();

};

#endif
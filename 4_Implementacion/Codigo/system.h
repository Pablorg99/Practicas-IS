

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
        list<Alumno> alumnos_;
    public:
        System::System(string ficheroCredenciales, Profesor &usuario, Database BDsistema);
        //Profesor getUsuarioByCredencial(string credencial);
        bool RegistroCoordinador();
        Profesor RegistroProfesor();
        bool ModificarProfesor();
		list <Alumno> BuscarAlumnos();
		list <Alumno> SeleccionarUnEquipo(int n_equipo);
		list <Alumno> SeleccionarNumeroAlumnos(int n_alumnos);
		void GenerarBackup();
		void CargarBackup();
		int PedirParametro();
		string PedirValor(int parametro);
		void FormatearBD();
		void MostrarAlumno();
		bool InsertarAlumno();
        list<Profesor> BuscarProfesor();
        int menuPrincipal();
        int subMenuBuscar();
        list<Alumno> ModificarAlumno();
        void BorrarAlumnos(list<Alumno> list_seleccion_alumnos);

};

#endif


#ifndef SYSTEM_H
#define SYSTEM_H

#include "alumno.h"
#include "profesor.h"
#include "alumno.h"
#include "database.h"
#include <string>

class System{
    private:
        Database BDsistema_;
        Profesor usuario_;
    public:
        system();
        void LeeCredenciales(string ficheroCredenciales);
        void start(Profesor usuario);
        Profesor getUsuarioByCredencial(string credencial);
        bool RegistroCoordinador();
        Profesor RegistroProfesor();
        bool ModificarProfesor();
<<<<<<< HEAD
		list <Alumno> BuscarAlumnos();
		list <Alumno> SeleccionarUnEquipo(int n_equipo);
		list <Alumno> SeleccionarNumeroAlumnos(int n_alumnos);
		int PedirParametro();
		string PedirValor(int parametro);
		void FormatearBD();
		void MostrarAlumno(list <Alumno> listalumno);
		bool InsertarAlumno();
=======
        list<Alumno> BuscarAlumnos();
>>>>>>> d53eea6bfd48b01f0076b5525fa57800fb0424c4

};

#endif
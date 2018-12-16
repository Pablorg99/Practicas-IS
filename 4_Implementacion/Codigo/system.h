

#ifndef SYSTEM_H
#define SYSTEM_H

#include "profesor.h"
#include "alumno.h"
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
        list<Alumno> BuscarAlumnos();

};

#endif
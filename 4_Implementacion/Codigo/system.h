

#ifndef SYSTEM_H
#define SYSTEM_H

#include "profesor.h"
#include "database.h"
#include <string>

class system{
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

};

#endif
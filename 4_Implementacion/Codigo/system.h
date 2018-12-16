

#ifndef SYSTEM_H
#define SYSTEM_H

#include "profesor.h"
#include <string>

class system{
    private:
        std::string BDusuarios_;
        Profesor usuario_;
    public:
        system();
        void LeeCredenciales(string ficheroCredenciales);
        void start(Profesor usuario);
        Profesor getUsuarioByCredencial(string credencial);
        void RegistroCoordinador();
        Profesor RegistroProfesor();
};

#endif
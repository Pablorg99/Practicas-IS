

#ifndef SYSTEM_H
#define SYSTEM_H

#include "profesor.h"
#include <string>

class system{
    private:
        std::string BDusuarios_;
    public:
        system();
        void LeeCredenciales(string ficheroCredenciales);
        void start(Profesor usuario);
        Profesor getUsuarioByCredencial(string credencial);
        bool registro();
        Profesor RegistroProfesor();

};

#endif
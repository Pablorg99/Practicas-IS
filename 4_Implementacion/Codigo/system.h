

#ifndef SYSTEM_H
#define SYSTEM_H

#include "profesor.h"

class system{
    public:
        void LeeCredenciales(string ficheroCredenciales);
        void start(Profesor usuario);
        Profesor getUsuarioByCredencial(string credencial);

};

#endif
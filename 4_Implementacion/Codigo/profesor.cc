#include "profesor.h"


bool Profesor::setCoordinador(){
    if(coordinador_){
        coordinador_ = false;
    }
    else{
        coordinador_ = true;
    }
    return coordinador_;
}
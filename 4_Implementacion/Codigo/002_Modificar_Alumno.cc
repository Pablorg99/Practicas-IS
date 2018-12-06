#include "alumno.h"
#include "009_Buscar_Alumnos.cc" //esto habra que hacer con el .h de Buscar_Alumnos



ModificaAlumno(){

    string straux;
    int intaux;
    list <Alumno> listalumno = BuscarAlumnos();

    for(int i = 0; i < aux.length(); i++){

        int opcion;

        do {
          cout << "¿Qué parámetro desea modificar?" << endl;
          cout << "\t1. DNI:" << alumno.getTelefono() << endl;
          cout << "\t2. Nombre:" << alumno.getTelefono() << endl;
          cout << "\t3. Apellidos:" << alumno.getTelefono() << endl;
          cout << "\t4. Teléfono:" << alumno.getTelefono() << endl;
          cout << "\t5. Dirección:" << alumno.getDireccion() << endl;
          cout << "\t6. Email:" << alumno.getEmail() << endl;
          cout << "\t7. Último curso matriculado:" << alumno.getCurso() << endl;
          cout << "\t8. Nº de equipo:" << alumno.getNequipo() << endl;
          cout << "\t9. Líder de equipo:";
          if(alumno.getLider()){cout << "Sí" <<endl;}
          else{cout << "No" << endl;}
          cout << "\t0. Guardar alumno y salir." << endl;
          cout << endl;             //Para que no quede tan apelotonado


          cout << "Opción número: ";
          cin >> opcion;

         switch (opcion) {
             case '1':
                 cout << "DNI:  ";
                 cin >> intaux;
                 listalumno[i].setDNI(intaux);
                 cout << "\n";
                 break;

             case '2':
                 cout << "Nombre:  ";
                 cin >> intaux;
                 listalumno[i].setNombre(intaux);
                 cout << "\n";
                 break;

             case '3':
                 cout << "Apellidos:  ";
                 cin >> intaux;
                 listalumno[i].setApellido(intaux);
                 cout << "\n";
                 break;

             case '4':
                 cout << "Teléfono:  ";
                 cin >> intaux;
                 listalumno[i].setTelefono(intaux);
                 cout << "\n";
                 break;

             case '5':
                 cout << "Dirección:  ";
                 cin >> straux;
                 listalumno[i].setDireccion(straux);
                 cout << "\n";
                 break;
             case '6':
                 cout << "Email:  ";
                 cin >> straux;
                 listalumno[i].setEmail(straux);
                 cout << "\n";
                 break;

             case '7':
                 cout << "Último curso matriculado:  ";
                 cin >> intaux;
                 listalumno[i].setCurso(intaux);
                 cout << "\n";
                 break;

             case '8':
                 cout << "Nº de equipo:  ";
                 cin >> intaux;
                 listalumno[i].setNequipo(intaux);
                 cout << "\n";
                 break;

             case '9':
                 listalumno[i].cambiaLider();         //setLider cambia el valor de lider_ cada vez que se ejecuta
                 cout << "\n";
                 break;

             case '7':
                 cout << "Alumno editado correctamente.\n";
                 cout << "\n";
                 break;

             default: cout <<opcion << " no es una opción válida del menú.\n";

             cout << endl;
            }
        }while (opcion != 0 );

    }
    //Falta guardarlo
}

#include "system.h"
#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>

using std::cout;
using std::cin;
using std::endl;

System::System(string ficheroCredenciales, Profesor &usuario, Database BDsistema) : usuario_(usuario), BDsistema_(BDsistema) {
    
	std::ifstream aux_stream_student(BDsistema.getStudentsDB());

	if(!aux_stream_student.is_open()){
		std::cout<<"Creando BD Alumnos"<<std::endl;
		std::ofstream new_stream_student(BDsistema.getStudentsDB());
	}
	std::ifstream aux_stream_user(BDsistema.getUsersDB());
	if(!aux_stream_user.is_open()){
		std::cout<<"Creando BD Usuarios"<<std::endl;
		std::ofstream new_stream_user(BDsistema.getUsersDB());
		ficheroCredenciales = primerInicio();
	}

	std::ifstream fichero;
    fichero.open(ficheroCredenciales);
    //Lee las credenciales
    std::string credencial;
    getline(fichero, credencial); 

    usuario_ = BDsistema_.getUserByCredentials(credencial);

    int status;
    status = menuPrincipal();
    exit(status);
}

string System::primerInicio(){ 
	//La primera vez que se inicia es sistema se registra el profesor coordinador
	Profesor usuario("dni", "nombre", "fichero", "apellido");
	usuario = RegistroCoordinador();

	string nombreFichero;
	nombreFichero = usuario.getDNI() + "_CDL.txt"; 

	//Se crea tambien su archivo de credenciales
	std::ofstream new_stream_user(nombreFichero);
	string credenciales = usuario.getDNI() + "," + usuario.getNombre();
	new_stream_user << credenciales;

	return nombreFichero;
}


Profesor System::RegistroCoordinador(){
    Profesor coordinador("dni", "nombre", "fichero", "apellido");

    coordinador = RegistroProfesor();
    coordinador.CambiarCoordinador(); //Tiene que ser True
    //Guardamos al profesor 
	BDsistema_.deleteUser(coordinador.getDNI());
    BDsistema_.addUser(coordinador);
	return coordinador;
}

int System::menuPrincipal(){
    int opcion;
    do{
			system("clear");
			cout << "Sistema de gestion del alumnado" << endl;
			cout << endl;
			cout << "\t1. Insertar nuevo alumno " << endl;
			cout << "\t2. Buscar alumnos " << endl;
			cout << "\t3. Registrar nuevo profesor " << endl;
			cout << "\t4. Modificar profesor " << endl;
			cout << "\t5. Eliminar profesor " << endl;
            cout << "\t6. Crear Backup de alumnos" <<endl;
            cout << "\t7. Cargar Backup de alumnos" <<endl;
            cout << "\t8. Formatear base de datos de alumnos" <<endl;
            cout << "\t0. Salir" <<endl;
            cout << endl;             //Para que no quede tan apelotonado

			cout << "Opción número: ";
            cin >> opcion;

            switch(opcion){
                case 1:
                    if(!InsertarAlumno()){ 
                        cout<<"Alumno ya existente"<<endl;
                    }
					cin.ignore();
					cin.get();
					break;
                case 2:
                    alumnos_ = BuscarAlumnos();
                    return subMenuBuscar();
                case 3:
                    RegistroProfesor();
					break;
                case 4:
                    ModificarProfesor();
					break;
                case 5:
                    cout<<"Hola, Work in progress"<<endl;
					break;
                case 6:
                    if(usuario_.getCoordinador()){
                        GenerarBackup();
                    }
                    else{cout<<"No tiene premisos para realizar esta operacion"<<endl;}
					break;
                case 7:
                    if(usuario_.getCoordinador()){
                        CargarBackup();
                    }
                    else{cout<<"No tiene premisos para realizar esta operacion"<<endl;}
					break;
                case 8:
                    if(usuario_.getCoordinador()){
                        FormatearBD();
                    }
                    else{cout<<"No tiene premisos para realizar esta operacion"<<endl;}
					break;
                case 0:
                    return 0;

                default:
                    cout<<"No ha seleccionado un operacion posible"<<endl;
					break;
            }
            
    }while(opcion!=0);
	return opcion;
}

//Devuelve true si el alumno es añadido correctamente, false en caso contrario
bool System::InsertarAlumno(){
	cout << "--Insertar alumno--" << endl;
	Alumno alumno("dniaux", "nombreaux", "straux");
	int intaux;
	string straux;

	//Introduce DNI
	cout << "DNI:  ";
	cin >> straux;
	while(!alumno.setDNI(straux)){
		cout<<"DNI incorrecto, introduzcalo de nuevo\n"<<endl;
		cout << "DNI:  ";
		cin >> straux;
	}

	//Introduce Nombre
	cout << "Nombre:  ";
	cin >> straux;
	alumno.setNombre(straux);

	//Introduce Apellido
	cout << "Apellidos:  ";
	getchar();
	getline(cin, straux);
	alumno.setApellido(straux);

	int opcion;

	do {
		cout << "¿Qué otro parámetro desea rellenar?" << endl;
		cout << endl;
		cout << "\t1. Teléfono:" << alumno.getTelefono() << endl;
		cout << "\t2. Dirección:" << alumno.getDireccion() << endl;
		cout << "\t3. Email:" << alumno.getEmail() << endl;
		cout << "\t4. Último curso matriculado:" << alumno.getCurso() << endl;
		cout << "\t5. Nº de equipo:" << alumno.getNequipo() << endl;
		cout << "\t6. Líder de equipo:";
		if(alumno.getLider()){cout << "Sí" <<endl;}
		else{cout << "No" << endl;}
		cout << "\t7. Guardar alumno y salir." << endl;
		cout << endl;             //Para que no quede tan apelotonado


		cout << "Opción número: ";
		cin >> opcion;

		switch (opcion) {
			case 1:
				cout << "Teléfono:  ";
				cin >> intaux;
				alumno.setTelefono(intaux);
				cout << "\n";
				break;

			case 2:
				cout << "Dirección:  ";
				cin >> straux;
				alumno.setDireccion(straux);
				cout << "\n";
				break;

			case 3:
				cout << "Email:  ";
				cin >> straux;
				alumno.setEmail(straux);
				cout << "\n";
				break;

			case 4:
				cout << "Último curso matriculado:  ";
				cin >> intaux;
				alumno.setCurso(intaux);
				cout << "\n";
				break;

			case 5:
				cout << "Nº de equipo:  ";
				cin >> intaux;
				alumno.setNequipo(intaux);
				cout << "\n";
				break;

			case 6:
				alumno.cambiaLider();         //setLider cambia el valor de lider_ cada vez que se ejecuta
				cout << "\n";
				break;

			case 7:
				cout << "Registrando alumno...\n";
				break;

			default:
				cout <<opcion << " no es una opción válida del menú.\n";
				cout << endl;
		}
	}while (opcion != 7 );
	if(BDsistema_.addStudent(alumno)) {
		cout << "Alumno guardado correctamente. Pulse intro para continuar." << endl;
		return true;
	}
	else return false;
}

list <Alumno> System::BuscarAlumnos() {
    
	list <Alumno> void_list;
	int opcion_submenu;

	while(true) {
		cout << endl;
		cout << "Indica el tipo de selección que quieres hacer:" << endl;
		cout << endl;
		cout << "\t1. Todos los alumnos registrados." << endl;
		cout << "\t2. Un equipo." << endl;
		cout << "\t3. Un número determinado de alumnos." << endl;
		cout << "\t4. Un único alumno." << endl;
		cout << "\t5. Volver al menú principal." << endl;
		
		cout << endl;
		cout << "Opción número: ";
		cin >> opcion_submenu;
		
		switch (opcion_submenu) {
			case 1:
				return BDsistema_.getAllStudents();    
				break;

			case 2:
				int n_equipo;
				cout << "Introduzca el número del equipo que desea seleccionar: ";
				cin >> n_equipo;
				return SeleccionarUnEquipo(n_equipo);
				break;

			case 3:
				int n_alumnos;
				cout << "Introduzca el número de alumnos que desea seleccioanr: ";
				cin >> n_alumnos;
				return SeleccionarNumeroAlumnos(n_alumnos);
				break;
			
			case 4:
				return SeleccionarNumeroAlumnos(1);
				break;
			
			case 5:
				return void_list;
				break;
			
			default:
				cout << "Elija una opción del menú." << endl;
		}
	}
	return void_list;
}

list <Alumno> System::SeleccionarUnEquipo(int n_equipo) {
	list <Alumno> list_aux;
	Alumno alumno_aux("dni", "nombre", "apellidos");
	std::ifstream input_stream;
	
	input_stream.open(BDsistema_.getStudentsDB());
	while(input_stream >> alumno_aux) {
		if(alumno_aux.getNequipo() == n_equipo) {
			cout << alumno_aux.getApellidosyNombre() << " seleccionado" << endl;
			list_aux.push_back(alumno_aux);	
		}
	}
	
	return list_aux;
}

list <Alumno> System::SeleccionarNumeroAlumnos(int n_alumnos) {
	list <Alumno> list_aux;
	Alumno alumno_aux("dni", "nombre", "apellidos");
	int parametro;
	string valor;

	parametro = PedirParametro();
	//Sale de la función si PedirParametro devuelve 0
	if(!parametro) return list_aux;
	
	for(int i = 0; i < n_alumnos; i++) {
		valor = PedirValor(parametro);
		alumno_aux = BDsistema_.getStudentByValue(valor, parametro);
		cout << alumno_aux.getApellidosyNombre() << " seleccionado" << endl;
		list_aux.push_back(alumno_aux);
	}
	
	return list_aux;
}

int System::PedirParametro() {
	int opcion_parametro;
	
	while(true) {	
		cout << "Por qué parametro desea buscar:" << endl;
		cout << "\t1. DNI." << endl;
		cout << "\t2. Nombre." << endl;
		cout << "\t3. Apellidos." << endl;
		cout << "\t4. Cancelar Búsqueda." << endl;
		cin >> opcion_parametro;

		switch (opcion_parametro) {
			case 1:
				return 1;
				break;

			case 2:
				return 2;
				break;
			
			case 3:
				return 3;
				break;

			case 4:
				return 0;
				break;
		
			default:
				cout << "Elija una opción del menú." << endl;
		}
	}
}

string System::PedirValor(int parametro) {
	string valor;

	switch (parametro) {
		case 1:
			cout << "Introduzca un DNI: ";
			cin >> valor;
			return valor;
			break;

		case 2:
			cout << "Introduzca un nombre: ";
			cin >> valor;
			return valor;
			break;

		case 3:
			cout << "Introduzca unos apellidos: ";
			cin >> valor;
			return valor;
			break;
	}
	return "";
}

int System::subMenuBuscar(){
    int opcion;
    do{
			cout << endl;
			cout << "SubMenu de busqueda" << endl;
			cout << endl;
			cout << "\t1. Modificar Alumnos" << endl;
			cout << "\t2. Borrar Alumnos " << endl;
			cout << "\t3. Mostrar Alumnos " << endl;
            cout << "\t0. Salir" <<endl;
            cout << endl;             //Para que no quede tan apelotonado

			cout << "Opción número: ";
            cin >> opcion;
            switch(opcion){
                case 1:
                    ModificarAlumno();
                    BorrarAlumnos(alumnos_);
                    for(list <Alumno>::iterator it = alumnos_.begin(); it != alumnos_.end(); it++){
                        BDsistema_.addStudent(*it);
                    }
                    return menuPrincipal();
                case 2:
                    BorrarAlumnos(alumnos_);
                    return menuPrincipal();
                case 3:
                    MostrarAlumno();
                case 0:
                    return menuPrincipal();
                default:
                    cout<<"No ha seleccionado una opcion posible"<<endl;

            }
    }while(opcion!=0);
	return 0;
}

void System::MostrarAlumno(){ 
    cout << "---------------------------------------------" << endl;
    cout << endl;
    list<Alumno> listalumno = alumnos_;

    for(list <Alumno>::iterator it = listalumno.begin(); it != listalumno.end(); it++){
        cout << "\t DNI: " << it->getDNI() << endl;
        cout << "\t Nombre: " << it->getNombre() << endl;
        cout << "\t Apellidos: " << it->getApellidos() << endl;
        cout << "\t Teléfono: " << it->getTelefono() << endl;
        cout << "\t Dirección: " << it->getDireccion() << endl;
        cout << "\t Email: " << it->getEmail() << endl;
        cout << "\t Último curso matriculado: " << it->getCurso() << endl;
        cout << "\t Nº de equipo: " << it->getNequipo() << endl;
        cout << "\t Líder de equipo: ";
        if(it->getLider()){cout << "Sí" <<endl;}
        else{cout << "No" << endl;}
        cout << endl;
    }

    cout << "---------------------------------------------" << endl;
	cout << "Pulse intro para continuar. ";
	cin.ignore();
	cin.get();
}

list<Alumno> System::ModificarAlumno(){

	string straux;
	int intaux;
	list <Alumno> listalumno = alumnos_;

	for(list <Alumno>::iterator it = listalumno.begin(); it != listalumno.end(); it++){

		int opcion;

		do {
			cout << "¿Qué parámetro desea modificar?" << endl;
			cout << endl;
			cout << "\t1. DNI: " << it->getTelefono() << endl;
			cout << "\t2. Nombre: " << it->getTelefono() << endl;
			cout << "\t3. Apellidos: " << it->getTelefono() << endl;
			cout << "\t4. Teléfono: " << it->getTelefono() << endl;
			cout << "\t5. Dirección: " << it->getDireccion() << endl;
			cout << "\t6. Email: " << it->getEmail() << endl;
			cout << "\t7. Último curso matriculado: " << it->getCurso() << endl;
			cout << "\t8. Nº de equipo: " << it->getNequipo() << endl;
			cout << "\t9. Líder de equipo: ";
			if(it->getLider()){cout << "Sí" <<endl;}
			else{cout << "No" << endl;}
			cout << "\t0. Guardar alumno y salir." << endl;
			cout << endl;             //Para que no quede tan apelotonado

			cout << "Opción número: ";
			cin >> opcion;

			switch (opcion) {
				case '1':
					cout << "DNI:  ";
					cin >> straux;
					while(!(*it).setDNI(straux)){
						cout << "Formato de DNI incorrecto, introduzcalo de nuevo."<< endl;
						cout << "DNI:  ";
						cin >> straux;
					}
					cout << "\n";
					break;

				case '2':
					cout << "Nombre:  ";
					cin >> straux;
					(*it).setNombre(straux);
					cout << "\n";
					break;

				case '3':
					cout << "Apellidos:  ";
					cin >> straux;
					(*it).setApellido(straux);
					cout << "\n";
					break;

				case '4':
					cout << "Teléfono:  ";
					cin >> intaux;
					(*it).setTelefono(intaux);
					cout << "\n";
					break;

				case '5':
					cout << "Dirección:  ";
					cin >> straux;
					(*it).setDireccion(straux);
					cout << "\n";
					break;

				case '6':
					cout << "Email:  ";
					cin >> straux;
					(*it).setEmail(straux);
					cout << "\n";
					break;

				case '7':
					cout << "Último curso matriculado:  ";
					cin >> intaux;
					(*it).setCurso(intaux);
					cout << "\n";
					break;

				case '8':
					cout << "Nº de equipo:  ";
					cin >> intaux;
					(*it).setNequipo(intaux);
					cout << "\n";
					break;

				case '9':
					(*it).cambiaLider();         //setLider cambia el valor de lider_ cada vez que se ejecuta
					cout << "\n";
					break;

				case '0':
					cout << "Alumno editado correctamente.\n";
					cout << "\n";
					break;

				default:
					cout <<opcion << " no es una opción válida del menú.\n";
					cout << endl;
			}
		}while (opcion != 0 );

	}
    return listalumno;
	//La funcion interna se encargará de guardarlo en la base de datos--
}

void System::BorrarAlumnos(list <Alumno> list_seleccion_alumnos) {
	list <Alumno> :: iterator alumno_seleccion = list_seleccion_alumnos.begin();
	list <Alumno> list_alumnos_bd; 
	list <Alumno> :: iterator alumno_bd;
	list_alumnos_bd = BDsistema_.getAllStudents();
	for(alumno_bd = list_alumnos_bd.begin(); alumno_bd != list_alumnos_bd.end(); alumno_bd++) {
		if(alumno_bd->getDNI() == alumno_seleccion->getDNI()) {
			/*Erase devuelve un nuevo valor disponible para el iterador y
			hay que asignarlo, porque el iterador se sigue usando en el
			bucle, si no se hace se producirá un segmentation fault*/
			alumno_bd = list_alumnos_bd.erase(alumno_bd);
			alumno_seleccion++;
		}
	}
	BDsistema_.WriteStudentsDB(list_alumnos_bd); 
}

Profesor System::RegistroProfesor(){
	Profesor ayudante("dni", "nombre", "fichero", "apellidos");
	cout << "--Registrar Profesor--" << endl;
	string straux;
	int intaux;

	//Introduce DNI
	cout << "DNI:  ";
	cin >> straux;
	//Comprobaciónd e formato de DNI
	while(!ayudante.setDNI(straux)){
		cout << "Error. Formato de DNI incorrecto."<<endl;
		cout << "Introduzcalo de nuevo." << endl;
		cout << "DNI: ";
		cin >> straux;
	}

	//Introduce Nombre
	cout << "Nombre:  ";
	cin >> straux;
	ayudante.setNombre(straux);

	//Introduce Apellido
	cout << "Apellido:  ";
	cin >> straux;
	ayudante.setApellido(straux);

	string fichero_credencial = ayudante.getDNI() + "_CDL.txt";
	ayudante.setFichero(fichero_credencial);

	int opcion;

	do {
		cout << "¿Qué otro parámetro desea rellenar?" << endl;
		cout << "\t1. Teléfono:" << ayudante.getTelefono() << endl;
		cout << "\t2. Dirección:" << ayudante.getDireccion() << endl;
		cout << "\t3. Email:" << ayudante.getEmail() << endl;
		cout << "\t4. Guardar profesor y salir." << endl;
		cout << endl;             //Para que no quede tan apelotonado

		cout << "Opción número: ";
		cin >> opcion;

		switch (opcion) {
			case 1:
				cout << "Teléfono:  ";
				cin >> intaux;
				ayudante.setTelefono(intaux);
				cout << "\n";
				break;

			case 2:
				cout << "Dirección:  ";
				cin >> straux;
				ayudante.setDireccion(straux);
				cout << "\n";
				break;
			case 3:
				cout << "Email:  ";
				cin >> straux;
				ayudante.setEmail(straux);
				cout << "\n";
				break;

			case 4:
				BDsistema_.addUser(ayudante); 
				cout << "Profesor guardado correctamente.\n";
				cout << "\n";
				break;

			default: cout << opcion << " no es una opción válida del menú.\n";

			cout << endl;
		}
	}while (opcion != 4 );
	return ayudante;
}


bool System::ModificarProfesor(){

	string straux;
	int intaux; 
	list <Profesor> listprofesor = BuscarProfesor();
    Profesor new_profesor("dni", "nombre", "fichero", "apellidos");

    if (!usuario_.getCoordinador()){
        cout << "No tiene permisos para realizar esta acción" <<endl;
        return false;
    }

	for(list <Profesor>::iterator it = listprofesor.begin(); it != listprofesor.end(); it++){

		int opcion;

		do {
			cout << "¿Qué parámetro desea modificar?" << endl;
			cout << endl;
			cout << "\t1. DNI: " << it->getDNI() << endl;
			cout << "\t2. Nombre: " << it->getNombre() << endl;
			cout << "\t3. Apellidos: " << it->getApellidos() << endl;
			cout << "\t4. Teléfono: " << it->getTelefono() << endl;
			cout << "\t5. Dirección: " << it->getDireccion() << endl;
			cout << "\t6. Email: " << it->getEmail() << endl;
			cout << "\t7. Coordinador: ";
			if(it->getCoordinador()){cout << "Sí" <<endl;}
			else{cout << "No" << endl;}
			cout << "\t0. Guardar profesor y salir." << endl;
			cout << endl;             //Para que no quede tan apelotonado

			cout << "Opción número: ";
			cin >> opcion;

			switch (opcion) {
				case 1:
					cout << "DNI:  ";
					cin >> straux;
					(*it).setDNI(straux);
					cout << "\n";
					break;

				case 2:
					cout << "Nombre:  ";
					cin >> straux;
					(*it).setNombre(straux);
					cout << "\n";
					break;

				case 3:
					cout << "Apellidos:  ";
					cin >> straux;
					(*it).setApellido(straux);
					cout << "\n";
					break;

				case 4:
					cout << "Teléfono:  ";
					cin >> intaux;
					(*it).setTelefono(intaux);
					cout << "\n";
					break;

				case 5:
					cout << "Dirección:  ";
					cin >> straux;
					(*it).setDireccion(straux);
					cout << "\n";
					break;

				case 6:
					cout << "Email:  ";
					cin >> straux;
					(*it).setEmail(straux);
					cout << "\n";
					break;

				case 7:
					(*it).CambiarCoordinador();         //setLider cambia el valor de lider_ cada vez que se ejecuta
					cout << "\n";
					break;

				case 0:
                    //ATENCION esta parte no está hecha
                    BDsistema_.deleteUser(it->getDNI());
                    new_profesor = *it; 
                    BDsistema_.addUser(new_profesor);
					cout << "Profesor editado y guardado correctamente.\n"; //Falta la comprobación de errores
					cout << "\n";
					return true;
					break;

				default:
					cout <<opcion << " no es una opción válida del menú.\n";
					cout << endl;
			}
		}while (opcion != 0 );
	}
	return true;
}

list<Profesor> System::BuscarProfesor(){
    string dni;
    Profesor user("dni", "nombre", "fichero", "apellido");
    cout << "Introduzca el dni del usuario" << endl;
    cin >> dni;
    user = BDsistema_.getUserByDNI(dni);
    list<Profesor> profesores;
    profesores.push_back(user);
    return profesores;
}

/*
void EliminarAyudante(){ //Sin terminar
    string dniaux, dniaux2;
    do {
        cout << "DNI del profesor ayudante a borrar: ";
        cin >> dniaux;
        cout << "Introduzcalo de nuevo para comprobarlo: ";
        cin >> dniaux2;
        if(! (dniaux == dniaux2) ){
            cout << "Error, los DNI introducidos no coinciden. Introduzcalos de nuevo.\n";
        }
    } while(! (dniaux == dniaux2) );

}
*/

void System::GenerarBackup() {
	string line;
	std::ifstream input_file_stream;
	input_file_stream.open(BDsistema_.getStudentsDB());
	std::ofstream output_file_stream;
	output_file_stream.open(BDsistema_.getStudentsDBBackup(), ostream::binary);
	while(getline(input_file_stream, line)) {
		line += "\n";
		output_file_stream.write(line.c_str(), line.size());
	}
	input_file_stream.close();
	output_file_stream.close();
}

void System::CargarBackup() {
	char line[200];
	std::ifstream input_file_stream;
	input_file_stream.open(BDsistema_.getStudentsDBBackup(), istream::binary);
	std::ofstream output_file_stream;
	output_file_stream.open(BDsistema_.getStudentsDB()); 
	while(!input_file_stream.eof()) {
		input_file_stream.read(line, 200);
		output_file_stream << line;
	}
	input_file_stream.close();
	output_file_stream.close();
}

void System::FormatearBD() {
	std::ofstream BD_file_stream;
	BD_file_stream.open(BDsistema_.getStudentsDB());
    BD_file_stream.close();
}
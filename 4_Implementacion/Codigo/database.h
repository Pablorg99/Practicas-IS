#ifndef DATABASE_H
#define DATABASE_H

#include "alumno.h"
#include <list>
using std::list;

class Database {
	private:
		string Students_DB;
		string Students_DB_Backup;
		string Users_DB; 
	public:
		Database();
		//Getters
		inline string getStudentsBD() const {return Students_DB;}
		inline string getStudentsBDBackup() const {return Students_DB_Backup;}
		inline string getUsersBD() const {return Users_DB;}
		bool addStudent(Alumno &new_student);
		list <Alumno> getAllStudents();
		Alumno getStudentByValue(string value, int parameter);
		bool CompareValueAndStudent(Alumno &alumno_aux, string value, int parameter);
		bool WriteDataBase(list <Alumno> new_students_list);
		void deleteUser(string user_dni);
		void addUser(Profesor new_user);

};



#endif

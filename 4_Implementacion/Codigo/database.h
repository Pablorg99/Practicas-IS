#ifndef DATABASE_H
#define DATABASE_H

#include "profesor.h"
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
		inline string getStudentsDB() const {return Students_DB;}
		inline string getStudentsDBBackup() const {return Students_DB_Backup;}
		inline string getUsersDB() const {return Users_DB;}
		bool addStudent(Alumno &new_student);
		list <Alumno> getAllStudents();
		Alumno getStudentByValue(string value, int parameter);
		bool CompareValueAndStudent(Alumno &alumno_aux, string value, int parameter);
		void WriteStudentsDB(list <Alumno> new_students_list);
		void addUser(Profesor new_user);
		void deleteUser(string user_dni);
		void WriteUsersDB(list <Profesor> new_users_list);
};



#endif

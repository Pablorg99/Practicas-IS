#include "alumno.h"
#include <fstream>
using std::ifstream;
using std::ofstream;

void GenerarBackup() {
	string line;
	ifstream input_file_stream;
	input_file_stream.open(BD);
	ofstream output_file_stream;
	output_file_stream.open(BD_BACKUP, ostream::binary);
	while(!input_file_stream.eof()) {
		getline(input_file_stream, line);
		line += "\n";
		output_file_stream.write(line.c_str(), line.size());
	}
	input_file_stream.close();
	output_file_stream.close();
}

void CargarBackup(string filename) {
	char line[200];
	ifstream input_file_stream;
	input_file_stream.open(BD_BACKUP, istream::binary);
	ofstream output_file_stream;
	output_file_stream.open(filename);
	while(!input_file_stream.eof()) {
		input_file_stream.read(line, 200);
		output_file_stream << line;
	}
	input_file_stream.close();
	output_file_stream.close();
}
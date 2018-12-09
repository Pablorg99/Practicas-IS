#include "alumno.h"
#include <fstream>
using std::ifstream;
using std::ofstream;


void FormatearBD() {
	ofstream BD_file_stream;
	BD_file_stream.open(BD);
    BD_file_stream.close();
}
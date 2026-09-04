#include <iostream>
#include "EmpleadoEntity.h"

using namespace std;

enum class Estado {
    NO_ADOPTADO = 0,
    ADOPTADO = 1
};

class PerroEntity {
public:	
	int id;
    string nombre;
    int edad;
    string raza;
    string energia;
    string diagnostico;
    Estado estado;
	string telefono;
	string correo
	



private:
	void setNombre(string nombre) {
		this->nombre = nombre;
	}
};
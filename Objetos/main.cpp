#include "Persona.hpp"

using namespace std;

int main() {
	Direccion direccion("Argentina", "Buenos Aires", "CABA", "San Martin", 1234);
	Persona p1("123123", "Juan", "Perez", direccion);
	Persona p2("321321", "Fulana", "Perez", direccion);

	cout << p1.toString() << endl;
	cout << p2.toString() << endl;


	direccion.setEstado("Cordoba");


	cout << p1.toString() << endl;
	cout << p2.toString() << endl;
}

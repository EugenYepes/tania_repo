#include "Persona.hpp"

using namespace std;

int main() {
	Direccion direccion("Argentina", "Buenos Aires", "CABA", "San Martin", 1234);

	Motor motor(2.0, 4, 250.0, 180.0);
	Auto auto1("Toyota", "Corolla", "Rojo", motor, "ABC123");

	Persona p1("123123", "Juan", "Perez", direccion, auto1);
	Persona p2("321321", "Fulana", "Perez", direccion);

	cout << p1.toString() << endl;
	cout << p2.toString() << endl;


	direccion.setEstado("Cordoba");


	cout << p1.toString() << endl;
	cout << p2.toString() << endl;
}

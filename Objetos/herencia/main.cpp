#include <iostream>
#include "Persona.hpp"

using namespace std;

int main() {
	Persona p("Juan", 30);
	Estudiante e("Maria", 19, "Informatica");

	cout << p.toString() << endl;
	cout << e.toString() << endl;
	return 0;
}
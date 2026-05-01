#include <iostream>

using namespace std;

int main() {

	int numero = 0;

	do {
		cout << "Ingrese un numero de un digito: ";
		cin >> numero;
		if (numero < -9 || numero > 9) {
			cout << "Numero invalido, intente nuevamente" << endl;
		}
	} while (numero < -9 || numero > 9);
	cout << "El numero ingresado es: " << numero << endl;

	return 0;
}
#include <iostream>
using namespace std;

void intercambio(int* a, int* b);

int main()
{
	int variable = 10;
	int* puntero = &variable;

	cout << "Valor de variable: " << variable << endl;
	cout << "Direccion de variable: " << puntero << endl;
	cout << "Valor apuntado por puntero: " << *puntero << endl;
	*puntero = 20;
	cout << "Valor de variable despues de modificar a traves del puntero: " << variable << endl;


	int a = 5;
	int b = 10;
	cout << "Antes del intercambio: a = " << a << ", b = " << b << endl;
	intercambio(&a, &b);
	cout << "Despues del intercambio: a = " << a << ", b = " << b << endl;

	return 0;
}

void intercambio(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

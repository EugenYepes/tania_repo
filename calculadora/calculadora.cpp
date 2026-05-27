#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int potencia(int base, int exponente);
int squareRoot(int numero);
double squareRootNewton(double numero);
void ingresoDatos(int *operando_1, int *operando_2);
string opcionToSimbolo(int opcion);

typedef struct {
	int operando_1;
	int operando_2;
	int resultado;
	string operador;
} Operacion;

int main()
{
	int opcion;
	int operando_1;
	int operando_2;
	double resultado;
	std::vector<Operacion> historial;
	Operacion op;
	int pos = 1;

	do
	{
		cout << "Seleccione una opcion" << endl;
		cout << "1 - sumar" << endl;
		cout << "2 - restar" << endl;
		cout << "3 - multiplar" << endl;
		cout << "4 - dividir" << endl;
		cout << "5 - potencia" << endl;
		cout << "6 - raiz cuadrada" << endl;
		cout << "7 - mostrar historial" << endl;
		cout << "8 - eliminar elemento" << endl;
		cout << "0 - para salir" << endl;

		cin >> opcion;

		if (opcion != 0)
		{

			switch (opcion)
			{
			case 1:
				ingresoDatos(&operando_1, &operando_2);
				resultado = operando_1 + operando_2;
				break;
			case 2:
				ingresoDatos(&operando_1, &operando_2);
				resultado = operando_1 - operando_2;
				break;
			case 3:
				ingresoDatos(&operando_1, &operando_2);
				resultado = operando_1 * operando_2;
				break;
			case 4:
				ingresoDatos(&operando_1, &operando_2);
				resultado = operando_1 / operando_2;
				break;
			case 5: 
				ingresoDatos(&operando_1, &operando_2);
				// resultado = pow(operando_1, operando_2);
				resultado = potencia(operando_1, operando_2);
				break;
			case 6:
				cout << "Ingrese 1 número" << endl;
				cin >> operando_1;
				// resultado = sqrt(operando_1);
				// raiz enesima = pow(operando_1, 1.0 / operando_2);
				resultado = squareRootNewton(operando_1);
				break;
			case 7:
				for (Operacion op : historial) {
					cout << "[" << pos << "] " << op.operando_1 << " " << op.operador << " " << op.operando_2 << " = " << op.resultado << endl;
					pos++;
				}
				pos = 1;
				break;
			case 8:
				cout << "Seleccion que elemento eliminar";
				cin >> pos;
				historial[pos - 1] = op;
				break;
			default:
				cout << "Opcion no valida" << endl;
				break;
			}

			if (opcion >= 1 && opcion <= 6) {
				Operacion op;
				op.operando_1 = operando_1;
				op.operador = opcionToSimbolo(opcion);
				op.operando_2 = operando_2;
				op.resultado = resultado;
				historial.push_back(op);
			}
			
			cout << "El resultado es " << resultado << endl;
		}
	} while (opcion != 0);

	return 0;
}

void ingresoDatos(int *operando_1, int *operando_2) {
	cout << "Ingrese 2 números" << endl;
	cin >> *operando_1;
	cin >> *operando_2;
}

string opcionToSimbolo(int opcion) {
	switch (opcion)
	{
	case 1:
		return "+";
	case 2:
		return "-";
	case 3:
		return "*";
	case 4:
		return "/";
	case 5:
		return "^";
	case 6:
		return "sqrt";
	default:
		return "?";
	}
}

int potencia(int base, int exponente) {
	int resultado = 1;
	for (int i = 0; i < exponente; i++) {	
		resultado = resultado * base; // resultado *= base;
	}
	return resultado;
}

int squareRoot(int numero) {
	int resultado = 0;
	while (resultado * resultado < numero) {
		resultado++;
	}
	return resultado;
}

double squareRootNewton(double numero) {
	
	double estimacion = numero;
	double presicion = 0.00001;

	while((estimacion * estimacion - numero) > presicion || (numero - estimacion * estimacion) > presicion) {
		estimacion = 0.5 * (estimacion + numero / estimacion);
	}
	return estimacion;
}

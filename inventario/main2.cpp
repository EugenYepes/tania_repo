#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <optional>
#include <cmath>

using namespace std;

typedef struct
{
	int ID;
	double valor;
	string Producto;
	unsigned int cantidad;
} Item;


int stringToInt(string s);
int potencia(int base, int exponente);
double stringToDouble(string s);
vector<string> stringSplit(string s, char split);
void mostrar(vector<Item> array);

int main()
{
	ifstream file("data.csv");
	vector<Item> datos;
	string line;

	if (!file.is_open())
	{
		cout << "ocurrio un error y no se pudo abrir el archivo" << endl;
		return -1;
	}

	getline(file, line);

	while (getline(file, line))
	{
		vector<string> Partes = stringSplit(line, ',');
		if (Partes.size() == 4) {
			Item item;
			item.ID = stringToInt (Partes[0]); 
			item.valor = stringToDouble (Partes [1]);
			item.Producto = Partes [2];
			item.cantidad = stringToInt (Partes [3]);
			datos.push_back(item);
		}
		 	
	}

	mostrar(datos);
	cout << "Ingrese el id del producto a modificar" << endl;
	int idIngresado;
	cin >> idIngresado;
	// idIngresado = 3
	// recorro cada elemento, para cada uno reviso si el id coincide, si coincide lo encontre y finalizo el recorrido
	int cont = 0;
	while (cont < datos.size() && datos[cont].ID != idIngresado)
	{
		cont++;
	}
	
	if (cont < datos.size()) {
		cout << "Elemento encontrado " << datos[cont].Producto << endl;
	} else {
		cout << "Elemento NO encontrado" << endl;
	}
	

	file.close();
	return 0;
}

std::optional<Item> buscarItemById(vector<Item> &array, int id) {
	int cont = 0;
	while (cont < array.size() && array[cont].ID != id)
	{
		cont++;
	}

	if (cont < array.size()) {
		return std::optional<Item>(array[cont]);
	} else {
		return std::nullopt;
	}
}

void mostrar(vector<Item> array) {

	for (Item item : array) {
		cout << item.ID << " " << item.valor << " " << item.Producto << " " << item.cantidad << endl;

	}
}


std::vector<string> stringSplit(string s, char split)
{
	vector<string> result;
	string aux = "";
	for (unsigned int i = 0; i < s.size(); i++)
	{
		if (s[i] == split)
		{
			result.push_back(aux);
			aux = "";
		}
		else
		{
			aux += s[i];
		}
	}
	result.push_back(aux);
	return result;
}


int stringToInt(string s) {
	int contPotencia = s.size() - 1;
	int numero = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		char letra = s[i];
		numero += (letra - '0') * potencia(10, contPotencia); // numero = numero + algo
		contPotencia--;
	}

	return numero;
}


double stringToDouble(string s) {
	
	vector<string> partes = stringSplit(s, '.');
	
	int parteEntera = stringToInt(partes[0]);

    double parteDecimal = (double) parteEntera;
	if (partes.size() >= 2) {
		for (unsigned int i = 0; i < partes[1].size(); i++) {
			char letra = partes[1][i];

			parteDecimal += (letra - '0') * pow(10, -(i + 1)); 
		}
	}

    return parteDecimal;
}

int potencia(int base, int exponente) {
	int resultado = 1;
	for (int i = 0; i < exponente; i++) {	
		resultado = resultado * base; // resultado *= base;
	}
	return resultado;
}


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
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
Item *buscarItemById(vector<Item> &productos, int id);
void cargarVenta(vector<Item> &caja, vector<Item> &inventario);
void actualizarCantidad(vector<Item> &inventario, Item *itemActualizar, int cantActualizar);
void guardarInventario(vector<Item> &inventario);

int main()
{
	ifstream file("data.csv");
	vector<Item> inventario;
	string line;
	double total = 0.0;

	if (!file.is_open())
	{
		cout << "ocurrio un error y no se pudo abrir el archivo" << endl;
		return -1;
	}

	getline(file, line);

	while (getline(file, line))
	{
		vector<string> Partes = stringSplit(line, ',');
		if (Partes.size() == 4)
		{
			Item item;
			item.ID = stringToInt(Partes[0]);
			item.valor = stringToDouble(Partes[1]);
			item.Producto = Partes[2];
			item.cantidad = stringToInt(Partes[3]);
			inventario.push_back(item);
		}
	}

	mostrar(inventario);
	vector<Item> caja = inventario;
	for (int i = 0; i < caja.size(); i++)
	{
		caja[i].cantidad = 0;
	}
	mostrar(inventario);
	mostrar(caja);

	/*
	cout << "Ingrese el id del producto a modificar" << endl;
	int idIngresado;
	cin >> idIngresado;

	Item* encontrado = buscarItemById(inventario, idIngresado);
	if (encontrado != NULL) {
		cout << "Elemento encontrado " << encontrado->Producto << endl;
	} else {
		cout << "Elemento NO encontrado" << endl;
	}
	*/
	int opcion;
	do
	{
		cout << "Ingresa la opcion a elegir" << endl;
		cout << "1 - Ingresar venta" << endl;
		cout << "2 - Cierre de caja" << endl;
		cout << "0 - Salir" << endl;

		cin >> opcion;

		switch (opcion)
		{
		case 1:
			// ingresar el codigo del product, buscarlo, si lo encontro, cargar cuanto se vendio
			mostrar(inventario);
			cargarVenta(caja, inventario);
			cout << "Caja" << endl;
			mostrar(caja);
			break;
		case 2:
			// cierre de caja
			mostrar(caja);
			// motrar totales
			for (int i = 0; i < inventario.size(); i++)
			{
				total += (caja[i].cantidad * caja[i].valor);
				inventario[i].cantidad -= caja[i].cantidad;
				caja[i].cantidad = 0;
			}
			cout << "Total vendido del dia $" << total << endl;
			cout << "inventario actualizado" << endl;
			mostrar(inventario);
			break;
		case 0:
			// salir
			guardarInventario(inventario);
			break;
		default:
			break;
		}
	} while (opcion != 0);

	file.close();
	return 0;
}

void guardarInventario(vector<Item> &inventario)
{
	ofstream file("data.csv");
	if (!file.is_open())
	{
		cout << "ocurrio un error y no se pudo abrir el archivo" << endl;
		return;
	}

	file << "ID,Valor,Producto,Cantidad\n";

	for (Item &item : inventario)
	{
		file << item.ID << ","
			<< item.valor << ","
			<< item.Producto << ","
			<< item.cantidad << "\n";
	}
	file.close();
}

void cargarVenta(vector<Item> &caja, vector<Item> &inventario)
{
	int idIngresado;
	int cantVentida;
	do
	{
		cout << "Ingrese el id del producto a modificar, 0 para salir." << endl;
		cin >> idIngresado;

		Item *encontrado = buscarItemById(caja, idIngresado);
		if (encontrado != NULL)
		{
			cout << "Elemento encontrado " << encontrado->Producto << endl;
			cout << "ingrese la cantidad vendida" << endl;
			cin >> cantVentida;
			actualizarCantidad(inventario, encontrado, cantVentida);
		}
		else
		{
			cout << "Elemento NO encontrado" << endl;
		}

	} while (idIngresado != 0);
}

void actualizarCantidad(vector<Item> &inventario, Item *itemCaja, int cantActualizar)
{
	Item *productoInventario = buscarItemById(inventario, itemCaja->ID);
	if (productoInventario != NULL && ((cantActualizar + itemCaja->cantidad) <= productoInventario->cantidad)) // validar si hay stock
	{
		cout << "Exito, producto cargado" << endl;
		itemCaja->cantidad += cantActualizar;
	}
	else
	{
		cout << "No hay mas productos disponibles para vender" << endl;
	}
}

Item *buscarItemById(vector<Item> &productos, int id)
{
	int cont = 0;
	while (cont < productos.size() && productos[cont].ID != id)
	{
		cont++;
	}

	if (cont < productos.size())
	{
		return &(productos[cont]);
	}
	else
	{
		return NULL;
	}
}

void mostrar(vector<Item> array)
{

	for (Item item : array)
	{
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

int stringToInt(string s)
{
	int contPotencia = s.size() - 1;
	int numero = 0;
	for (unsigned int i = 0; i < s.size(); i++)
	{
		char letra = s[i];
		numero += (letra - '0') * potencia(10, contPotencia); // numero = numero + algo
		contPotencia--;
	}

	return numero;
}

double stringToDouble(string s)
{

	vector<string> partes = stringSplit(s, '.');

	int parteEntera = stringToInt(partes[0]);

	double parteDecimal = (double)parteEntera;
	if (partes.size() >= 2)
	{
		for (unsigned int i = 0; i < partes[1].size(); i++)
		{
			char letra = partes[1][i];

			parteDecimal += (letra - '0') * pow(10, -(i + 1));
		}
	}

	return parteDecimal;
}

int potencia(int base, int exponente)
{
	int resultado = 1;
	for (int i = 0; i < exponente; i++)
	{
		resultado = resultado * base; // resultado *= base;
	}
	return resultado;
}

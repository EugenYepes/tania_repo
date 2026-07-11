#include "funciones.h"
#include <fstream>
#include <cmath>

// --- FUNCIONES AUXILIARES (Reutilizando el código de clases anteriores) ---

int potencia(int base, int exponente) {
	int resultado = 1;
	for (int i = 0; i < exponente; i++) {	
		resultado *= base;
	}
	return resultado;
}

int stringToInt(string s) {
	int contPotencia = s.size() - 1;
	int numero = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		char letra = s[i];
		numero += (letra - '0') * potencia(10, contPotencia);
		contPotencia--;
	}
	return numero;
}

double stringToDouble(string s) {
	vector<string> partes = stringSplit(s, '.');
	int parteEntera = stringToInt(partes[0]);
    double parteDecimal = (double) parteEntera;
	if (partes.size() >= 2) {
		for (int i = 0; i < (int) partes[1].size(); i++) {
			char letra = partes[1][i];
			double pot = pow(10, -(i + 1));
			parteDecimal += (letra - '0') * pot; 
		}
	}
    return parteDecimal;
}

vector<string> stringSplit(string s, char split) {
	vector<string> result;
	string aux = "";
	for (unsigned int i = 0; i < s.size(); i++) {
		if (s[i] == split) {
			result.push_back(aux);
			aux = "";
		} else {
			aux += s[i];
		}
	}
	result.push_back(aux);
	return result;
}

// --- FUNCIONES PRINCIPALES DEL INVENTARIO ---

void cargarInventario(vector<Producto> &inventario, string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "No se encontro un inventario previo. Se creara uno al guardar." << endl;
        return; // Salimos si no existe el archivo aun
    }

    string linea;
    // Leemos el archivo linea por linea
    while (getline(archivo, linea)) {
        if (linea.empty()) continue; // Ignoramos lineas vacias

        // Separamos la linea por comas
        vector<string> partes = stringSplit(linea, ',');
        
        // Verificamos que tenga los 4 campos (id, nombre, precio, cantidad)
        if (partes.size() == 4) {
            Producto p;
            p.id = stringToInt(partes[0]);
            p.nombre = partes[1];
            p.precio = stringToDouble(partes[2]);
            p.cantidad = stringToInt(partes[3]);
            
            // Lo agregamos al vector
            inventario.push_back(p);
        }
    }
    archivo.close();
    cout << "Inventario cargado exitosamente." << endl;
}

void mostrarInventario(vector<Producto> &inventario) {
    if (inventario.empty()) {
        cout << "El inventario esta vacio." << endl;
        return;
    }

    cout << "\n--- INVENTARIO ACTUAL ---" << endl;
    for (unsigned int i = 0; i < inventario.size(); i++) {
        cout << "ID: " << inventario[i].id 
             << " | Nombre: " << inventario[i].nombre 
             << " | Precio: $" << inventario[i].precio 
             << " | Cantidad en stock: " << inventario[i].cantidad << endl;
    }
}

void agregarProducto(vector<Producto> &inventario) {
    Producto p;
    cout << "Ingrese el ID del nuevo producto: ";
    cin >> p.id;
    cout << "Ingrese el nombre: ";
    cin >> p.nombre;
    cout << "Ingrese el precio: ";
    cin >> p.precio;
    cout << "Ingrese la cantidad inicial: ";
    cin >> p.cantidad;

    inventario.push_back(p);
    cout << "Producto agregado con exito." << endl;
}

void venderProducto(vector<Producto> &inventario) {
    int idBuscar;
    cout << "Ingrese el ID del producto que desea vender: ";
    cin >> idBuscar;

    bool encontrado = false;
    for (unsigned int i = 0; i < inventario.size(); i++) {
        if (inventario[i].id == idBuscar) {
            encontrado = true;
            if (inventario[i].cantidad > 0) {
                inventario[i].cantidad--; // Restamos 1 al stock
                cout << "Venta registrada! Nueva cantidad de " << inventario[i].nombre << ": " << inventario[i].cantidad << endl;
            } else {
                cout << "Error: No hay stock suficiente de " << inventario[i].nombre << "." << endl;
            }
            break; // Terminamos el ciclo ya que encontramos el producto
        }
    }

    if (!encontrado) {
        cout << "Error: Producto no encontrado." << endl;
    }
}

void guardarInventario(vector<Producto> &inventario, string nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para guardar." << endl;
        return;
    }

    // Escribimos cada producto en el archivo, separado por comas
    for (unsigned int i = 0; i < inventario.size(); i++) {
        archivo << inventario[i].id << "," 
                << inventario[i].nombre << "," 
                << inventario[i].precio << "," 
                << inventario[i].cantidad << "\n";
    }
    
    archivo.close();
}

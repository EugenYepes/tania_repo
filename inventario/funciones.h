#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Definimos el struct para representar un Producto
typedef struct {
    int id;
    string nombre;
    double precio;
    int cantidad;
} Producto;

// Funciones principales del inventario
// Nota: Usamos '&' para pasar el vector por referencia (así los cambios se guardan)
void cargarInventario(vector<Producto> &inventario, string nombreArchivo);
void mostrarInventario(vector<Producto> &inventario);
void agregarProducto(vector<Producto> &inventario);
void venderProducto(vector<Producto> &inventario);
void guardarInventario(vector<Producto> &inventario, string nombreArchivo);

// Funciones auxiliares reutilizadas de clases anteriores
vector<string> stringSplit(string s, char split);
int stringToInt(string s);
double stringToDouble(string s);
int potencia(int base, int exponente);

#endif

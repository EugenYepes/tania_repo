#include <iostream>
#include <vector>
#include "funciones.h"

using namespace std;

int main() {
    vector<Producto> inventario;
    
    // 1. Cargar inventario desde el archivo (si existe)
    cargarInventario(inventario, "inventario.csv");

    int opcion;
    do {
        cout << "\n--- SISTEMA DE INVENTARIO ---" << endl;
        cout << "1. Ver productos" << endl;
        cout << "2. Agregar producto" << endl;
        cout << "3. Vender producto (restar cantidad)" << endl;
        cout << "0. Guardar y salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarInventario(inventario);
                break;
            case 2:
                agregarProducto(inventario);
                break;
            case 3:
                venderProducto(inventario);
                break;
            case 0:
                guardarInventario(inventario, "inventario.csv");
                cout << "Datos guardados. Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
                break;
        }
    } while (opcion != 0);

    return 0;
}

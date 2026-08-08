#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

void abrirArchivo(const string& nombreArchivo) {
    ifstream archivo;

    // Configura el stream para lanzar std::ios_base::failure ante fallos (failbit) o errores graves (badbit)
    archivo.exceptions(ifstream::failbit | ifstream::badbit);

    // Lanza ios_base::failure automáticamente si no existe o no se puede abrir
    archivo.open(nombreArchivo);

    string primeraLinea;
    // Lanza ios_base::failure si no se puede leer o el archivo está vacío
    getline(archivo, primeraLinea);

    // Validación de lógica de negocio (sigue requiriendo throw explícito)
    if (primeraLinea != "FORMATO_ESPERADO") {
        throw runtime_error("Formato inválido: se esperaba 'FORMATO_ESPERADO'.");
    }

    cout << "El archivo se abrió correctamente y el formato es válido." << endl;
}

int main() {
    const string nombreArchivo = "datos.txt";

    try {
        abrirArchivo(nombreArchivo);
    } catch (const ios_base::failure& e) {
        cout << "Error de E/S (archivo no existe, sin permisos o vacío): " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "Error de formato: " << e.what() << endl;
    } catch (const exception& e) {
        cout << "Error no esperado: " << e.what() << endl;
    }

    cout << "El programa continúa después del manejo de la excepción." << endl;
    return 0;
}
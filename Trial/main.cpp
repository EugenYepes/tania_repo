#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    // ifstream file("data.csv");
    // vector<double> datos;
    // string line;

    // if (!file.is_open()) {
    //     cerr << "Error: No se pudo abrir el archivo data.csv" << endl;
    //     return 1;
    // }

    // getline(file, line);

    // string valorStr;
    // while (getline(file, valorStr, ',')) {
    //     try {
    //         datos.push_back(stod(valorStr));
    //     } catch (...) {
    //         continue;
    //     }
    // }
    // file.close();

    // if (datos.empty()) {
    //     cout << "No se cargaron datos." << endl;
    //     return 0;
    // }

	// double suma = 0.0;
	// for (size_t i = 0; i < datos.size(); i++) {
	// 	suma += datos[i];
	// }

    // double promedio = suma / datos.size();

	// double max_valor = 0.0;
	// for (size_t i = 0; i < datos.size(); i++) {
	// 	if (datos[i] > max_valor) {
	// 		max_valor = datos[i];
	// 	}
	// }
    
    // cout << "--- Reporte de Procesamiento de Datos ---" << endl;
    // cout << "Registros cargados: " << datos.size() << endl;
    // cout << "Valor Maximo:       " << max_valor << endl;
    // cout << "Promedio General:   " << promedio << endl;
    // cout << "-----------------------------------------" << endl;

    // return 0;

	cout << "Hola mundo" << endl;
	return 0;
}
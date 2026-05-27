#include <iostream>
#include <vector>
using namespace std;

int main() {
	// int vector[100];

	std::vector<int> numeros(1);
	numeros[0] = 10;

	cout << numeros[0];
	
	// cout << *vector << endl;
	// cout << vector[0] << endl;

	// cout << *(vector + 1) << endl;
	// cout << vector[1] << endl;

	// cout << *(vector + 2) << endl;
	// cout << vector[2] << endl;
	return 0;
}
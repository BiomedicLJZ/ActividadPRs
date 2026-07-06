#include <iostream>

int main() {
	const int filas = 3;
	const int valorcompartido = 3;
	const int columnas = 3;
	
	/*
	std::cout << "Escribir el número de filas de la primera matriz: " << std::endl;
	std::cin >> filas;
	std::cout << "Escribir el número de columnas de la primera matriz: " << std::endl;
	std::cin >> valorcompartido;
	std::cout << "La segunda matriz debe tener " << valorcompartido << " filas para poder hacer la multiplicación." << std::endl;
	std::cout << "Escribir el número de columnas de la segunda matriz: " << std::endl;
	std::cin >> columnas;
	*/
	
	auto* m1 = new float[filas][valorcompartido];
	auto* m2 = new float[valorcompartido][columnas];
	
	std::cout << "PRIMERA MATRIZ" << std::endl;
	for (int j = 0; j < valorcompartido; ++j) {	
		for (int i = 0; i < filas; ++i) {
			std::cout << "Fila " << (i + 1) << ", columna " << (j + 1) << ": " << std::endl;
			std::cin >> m1[i][j];
		}
	}
	
	std::cout << "SEGUNDA MATRIZ" << std::endl;
	for (int j = 0; j < columnas; ++j) {	
		for (int i = 0; i < valorcompartido; ++i) {
			std::cout << "Fila " << (i + 1) << ", columna " << (j + 1) << ": " << std::endl;
			std::cin >> m1[i][j];
		}
	}
	
	auto* m3 = new float[filas][columnas];
	
	for (int j = 0; j < columnas; ++j) {	
		for (int i = 0; i < filas; ++i) {
			m3[i][j] = 0;
		}
	}
	
	for (int k = 0; k < valorcompartido; ++k) {	
		for (int j = 0; j < columnas; ++j) {	
			for (int i = 0; i < filas; ++i) {
				m3[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	
	std::cout << "La matriz resultante es: " << std::endl;
	for (int j = 0; j < columnas; ++j) {	
		for (int i = 0; i < filas; ++i) {
			std::cout << "	" << m3[i][j];
		}
		std::cout << std::endl;
	}
	
	delete[] m1;
	delete[] m2;
	delete[] m3;
	
	return 0;
}

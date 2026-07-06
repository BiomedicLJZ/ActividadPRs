#include <cstdlib>
#include <iostream>

// Programa para calcular el producto de dos matrices
// Eduardo Flores [eduardo55722], 2026-07-06

int main() {
	int filas;
	int valorcompartido;
	int columnas;
	
	// Leer tamaños de las matrices
	std::cout << "Escribir el número de filas de la primera matriz: " << std::endl;
	if (!(std::cin >> filas) || filas <= 0) {
		std::cerr << "Error: el número de filas debe ser un entero > 0." << std::endl;
		return 1;
	}
	std::cout << "Escribir el número de columnas de la primera matriz: " << std::endl;
	if (!(std::cin >> valorcompartido) || valorcompartido <= 0) {
		std::cerr << "Error: el número de columnas debe ser un entero > 0." << std::endl;
		return 1;
	}
	std::cout << "La segunda matriz debe tener " << valorcompartido << " filas para poder hacer la multiplicación." << std::endl;
	std::cout << "Escribir el número de columnas de la segunda matriz: " << std::endl;
	if (!(std::cin >> columnas) || columnas <= 0) {
		std::cerr << "Error: el número de columnas debe ser un entero > 0." << std::endl;
		return 1;
	}
	
	// Inicializar arreglos para las matrices 1 y 2
	auto* m1 = static_cast<float*>(calloc((filas * valorcompartido), sizeof(float)));
	auto* m2 = static_cast<float*>(calloc((valorcompartido * columnas), sizeof(float)));
	if (!m1 || !m2) {
		std::cerr << "Error: no se pudo reservar memoria para las matrices." << std::endl;
		free(m1);
		free(m2);
		return 1;
	}
	// Leer primera matriz
	std::cout << "PRIMERA MATRIZ" << std::endl;
	for (int j = 0; j < filas; ++j) {
		for (int i = 0; i < valorcompartido; ++i) {
			std::cout << "Fila " << (j + 1) << ", columna " << (i + 1) << ": " << std::endl;
			std::cin >> *(m1 + (j * valorcompartido) + i);
		}
	}
	
	// Leer segunda matriz
	std::cout << "SEGUNDA MATRIZ" << std::endl;
	for (int j = 0; j < valorcompartido; ++j) {
		for (int i = 0; i < columnas; ++i) {
			std::cout << "Fila " << (j + 1) << ", columna " << (i + 1) << ": " << std::endl;
			std::cin >> *(m2 + (j * columnas) + i);
		}
	}
	
	// Mostrar primera matriz
	std::cout << "\nPrimera matriz: " << std::endl;
	for (int i = 0; i < (filas * valorcompartido); ++i) {
		std::cout << "	" << *(m1 + i);
		if (i % valorcompartido == (valorcompartido - 1)) {
			std::cout << std::endl;
		}
	}
	
	// Mostrar segunda matriz
	std::cout << "\nSegunda matriz: " << std::endl;
	for (int i = 0; i < (valorcompartido * columnas); ++i) {
		std::cout << "	" << *(m2 + i);
		if (i % columnas == (columnas - 1)) {
			std::cout << std::endl;
		}
	}
	
	// Inicializar matriz resultado
	auto* m3 = static_cast<float*>(calloc((filas * columnas), sizeof(float)));
	
	// `calloc` ya inicializa la matriz resultado con ceros; no es necesario rellenarla manualmente.
	
	// Calcular valores individuales de la matriz resultado
	for (int k = 0; k < valorcompartido; ++k) {
		for (int j = 0; j < filas; ++j) {
			for (int i = 0; i < columnas; ++i) {
				*(m3 + (j * columnas) + i) += (*(m1 + (j * valorcompartido) + k)) * (*(m2 + (k * columnas) + i));
			}
		}
	}
	
	// Mostrar matriz resultado
	std::cout << "\nLa matriz resultante es: " << std::endl;
	for (int i = 0; i < (filas * columnas); ++i) {
		std::cout << "	" << *(m3 + i);
		if (i % columnas == (columnas - 1)) {
			std::cout << std::endl;
		}
	}
	
	// Liberar memoria ocupada por los arreglos
	free(m1);
	free(m2);
	free(m3);

	return 0;
}

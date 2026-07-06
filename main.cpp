#include <iostream>

int main() {
	int filas;
	int valorcompartido;
	int columnas;

	std::cout << "Escribir el número de filas de la primera matriz: " << std::endl;
	std::cin >> filas;
	std::cout << "Escribir el número de columnas de la primera matriz: " << std::endl;
	std::cin >> valorcompartido;
	std::cout << "La segunda matriz debe tener " << valorcompartido << " filas para poder hacer la multiplicación." << std::endl;
	std::cout << "Escribir el número de columnas de la segunda matriz: " << std::endl;
	std::cin >> columnas;

	auto* m1 = static_cast<float*>(calloc((filas * valorcompartido), sizeof(float)));
	auto* m2 = static_cast<float*>(calloc((valorcompartido * columnas), sizeof(float)));

	std::cout << "PRIMERA MATRIZ" << std::endl;
	for (int j = 0; j < filas; ++j) {
		for (int i = 0; i < valorcompartido; ++i) {
			std::cout << "Fila " << (j + 1) << ", columna " << (i + 1) << ": " << std::endl;
			std::cin >> *(m1 + (j * valorcompartido) + i);
		}
	}

	std::cout << "SEGUNDA MATRIZ" << std::endl;
	for (int j = 0; j < valorcompartido; ++j) {
		for (int i = 0; i < columnas; ++i) {
			std::cout << "Fila " << (j + 1) << ", columna " << (i + 1) << ": " << std::endl;
			std::cin >> *(m2 + (j * columnas) + i);
		}
	}

	std::cout << "===================" << std::endl;
	for (int i = 0; i < (filas * valorcompartido); ++i) {
		std::cout << "	" << *(m1 + i);
		if (i % valorcompartido == (valorcompartido - 1)) {
			std::cout << std::endl;
		}
	}
	std::cout << "===================" << std::endl;
	for (int i = 0; i < (valorcompartido * columnas); ++i) {
		std::cout << "	" << *(m2 + i);
		if (i % columnas == (columnas - 1)) {
			std::cout << std::endl;
		}
	}

	auto* m3 = static_cast<float*>(calloc((filas * columnas), sizeof(float)));

	for (int i = 0; i < (filas * columnas); ++i) {
		*(m3 + i) = 0;
	}

	for (int k = 0; k < valorcompartido; ++k) {
		std::cout << "===================" << std::endl;
		for (int j = 0; j < filas; ++j) {
			for (int i = 0; i < columnas; ++i) {
				std::cout << (*(m3 + (j * filas) + i)) << " >> ";
				*(m3 + (j * filas) + i) += (*(m1 + (j * valorcompartido) + k)) * (*(m2 + (k * columnas) + i));
				std::cout << (*(m3 + (j * filas) + i)) << " (" << (*(m1 + (j * valorcompartido) + k)) << " * " << (*(m2 + (k * columnas) + i)) << ")" << std::endl;
			}
		}
	}

	std::cout << "La matriz resultante es: " << std::endl;
	for (int i = 0; i < (filas * columnas); ++i) {
		std::cout << "	" << *(m3 + i);
		if (i % columnas == (columnas - 1)) {
			std::cout << std::endl;
		}
	}

	free(m1);
	free(m2);
	free(m3);

	return 0;
}

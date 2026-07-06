#include <iostream>
#include <vector>

std::vector<std::vector<int>> multiplicarMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int filasA = A.size();
    int columnasA = A[0].size();
    int columnasB = B[0].size();

    std::vector<std::vector<int>> C(filasA, std::vector<int>(columnasB, 0));

    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasB; j++) {
            for (int k = 0; k < columnasA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

void imprimirMatriz(const std::vector<std::vector<int>>& M) {
    for (const auto& fila : M) {
        for (int val : fila) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int filasA, columnasA, filasB, columnasB;

    std::cout << "Ingrese el numero de filas de la matriz A: ";
    std::cin >> filasA;
    std::cout << "Ingrese el numero de columnas de la matriz A: ";
    std::cin >> columnasA;
    std::cout << "Ingrese el numero de filas de la matriz B: ";
    std::cin >> filasB;
    std::cout << "Ingrese el numero de columnas de la matriz B: ";
    std::cin >> columnasB;

    if (columnasA != filasB) {
        std::cout << "No se puede multiplicar: las columnas de A deben ser iguales a las filas de B." << std::endl;
        return 0;
    }

    std::vector<std::vector<int>> A(filasA, std::vector<int>(columnasA));
    std::vector<std::vector<int>> B(filasB, std::vector<int>(columnasB));

    std::cout << "Ingrese los valores de la matriz A:" << std::endl;
    for (int i = 0; i < filasA; i++) {
        for (int j = 0; j < columnasA; j++) {
            std::cout << "A[" << i + 1 << "][" << j + 1 << "]: ";
            std::cin >> A[i][j];
        }
    }

    std::cout << "Ingrese los valores de la matriz B:" << std::endl;
    for (int i = 0; i < filasB; i++) {
        for (int j = 0; j < columnasB; j++) {
            std::cout << "B[" << i + 1 << "][" << j + 1 << "]: ";
            std::cin >> B[i][j];
        }
    }

    std::vector<std::vector<int>> C = multiplicarMatrices(A, B);

    std::cout << "Resultado:" << std::endl;
    imprimirMatriz(C);

    return 0;
}

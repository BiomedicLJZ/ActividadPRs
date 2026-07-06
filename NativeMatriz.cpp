#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A,
                                     const vector<vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int rowsB = B.size();
    int colsB = B[0].size();

    if (colsA != rowsB) {
        throw invalid_argument("Las matrices no se pueden multiplicar.");
    }

    vector<vector<int>> C(rowsA, vector<int>(colsB, 0));

    // Multiplicación ingenua
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

void printMatrix(const vector<vector<int>>& M) {
    for (const auto& row : M) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> B = {
        {5, 6},
        {7, 8}
    };

    try {
        vector<vector<int>> C = multiplyMatrices(A, B);

        cout << "Resultado de la multiplicación:" << endl;
        printMatrix(C);
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
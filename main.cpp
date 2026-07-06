#include <iostream>

void Matrices (int Af,int Ac,int Bf,int Bc);
int main() {

    int  Af,Ac, Bf, Bc; //Valores para el tamanio de la matriz

    std::cout << "Bienvenido la calculadora de la multipliacion ingenua de matrices" << std::endl;

    std::cout << "Ingrese el tamanio de la fila de la primera matriz: "<<std::endl;
    std::cin >> Af;
    std::cout << "Ingrese el tamanio de la columna de la primera matriz: "<<std::endl;
    std::cin >> Ac;

    std::cout << "Ingrese el tamanio de la fila de la segunda matriz: "<<std::endl;
    std::cin >> Bf;
    std::cout << "Ingrese el tamanio de la columna de la segunda matriz: "<<std::endl;
    std::cin >> Bc;

    Matrices (Af,Ac,Bf,Bc);




    return 0;
}

void Matrices (int Af,int Ac,int Bf,int Bc) {
    //Arreglo de punteros a arreglos, para crear matrices donde cada fila tiene un tamanio diferente
    int** matrizA = new int*[Af];  //new int*[Af] crea espacio para Af filas (punteros a filas).

    for (int i = 0; i < Af; i++) {
        matrizA[i] = new int[Ac]; //new int[Ac] crea una fila con Ac columnas
    }

    //Llenar matrizA
    for (int i = 0; i < Af; i++) {
        for (int j = 0; j < Ac; j++) {
            std::cout << "MatrizA \n Fila " << i + 1
            << ", Columna " << j + 1<< std::endl;
            std::cin >> matrizA[i][j];
        }
    }

    //Se crea Arreglo de punteros a arreglos para matrizB
    int** matrizB = new int*[Bf];

    for (int i = 0; i < Bf; i++) {
        matrizB[i] = new int[Bc];
    }

    //Llenar matrizB
    for (int i = 0; i < Bf; i++) {
        for (int j = 0; j < Bc; j++) {
            std::cout << "MatrizB \n Fila " << i + 1
            << ", Columna " << j + 1<< std::endl;
            std::cin >> matrizB[i][j];
        }
      }

    if (Ac==Bf) {
        int** matrizC = new int*[Af];

    for (int i = 0; i < Af; i++) {
    matrizC[i] = new int[Bc];
        }

        for (int i = 0; i < Af; i++) {
        for (int j = 0; j < Bc; j++) {
         matrizC[i][j]=0;
            for (int k = 0; k < Ac; k++) {
             matrizC[i][j] += matrizA[i][k] * matrizB[k][j];    }
             std::cout << "MatrizC: " << matrizC[i][j] << std::endl;
        }
    }

        for (int i = 0; i < Af; i++) {
            delete[] matrizC[i];
        }
        delete[] matrizC;

         }
    else {
        std::cout << "La matrizA no tiene el mismo numero de columnas a las filas de la matrizB por lo que la operacion no es posible" << std::endl;
    }


        for (int i = 0; i < Af; i++) {
        delete[] matrizA[i];
    }
    delete[] matrizA;

    for (int i = 0; i < Bf; i++) {
        delete[] matrizB[i];
    }
    delete[] matrizB;
}
#include <iostream>
#include <vector>

void ingresarMatriz(std::vector<std::vector<int>>& matriz, int numeroDeFilas, int numeroDeColumnas);
std::vector<std::vector<int>> multiplicarMatrices(const std::vector<std::vector<int>>& matriz1,const std::vector<std::vector<int>>& matriz2,int numeroDeFilasMatriz1,int numeroDeColumnasMatriz1,int numeroDeColumnasMatriz2);
void mostrarMatriz(const std::vector<std::vector<int>>& matriz);



int main() {

    int numeroDeFilasMatriz1, numeroDeColumnasMatriz1;
    int numeroDeFilasMatriz2, numeroDeColumnasMatriz2;


    std::cout << "MULTIPLICADOR DE MATRICES\n";


    std::cout << "Ingrese el numero de filas de la primera matriz: ";
    std::cin >> numeroDeFilasMatriz1;

    std::cout << "Ingrese el numero de columnas de la primera matriz: ";
    std::cin >> numeroDeColumnasMatriz1;


    std::cout << "Ingrese el numero de filas de la segunda matriz: ";
    std::cin >> numeroDeFilasMatriz2;

    std::cout << "Ingrese el numero de columnas de la segunda matriz: ";
    std::cin >> numeroDeColumnasMatriz2;



    if (numeroDeColumnasMatriz1 == numeroDeFilasMatriz2) {

        //Es una matriz dinamica usando std::vector, el primero vector que es numeroDeFilasMatriz1 pues vaya, representa las filas
        //y el que dice vector<int> representa una fila con el numero de columnas que como se puede ver es el que ingreso el usuario.
        //y esto basicamente al generar los varios vector<int> de que es uno por cada fila, todos se  almacenan dentro de la matriz1,
        //asi haciendo que el tamanno de la matriz sea definido.
        std::vector<std::vector<int>> matriz1(numeroDeFilasMatriz1,std::vector<int>(numeroDeColumnasMatriz1));


        std::vector<std::vector<int>> matriz2(numeroDeFilasMatriz2,std::vector<int>(numeroDeColumnasMatriz2));



        std::cout << "\nIngrese la primera matriz:\n";
        ingresarMatriz(matriz1,numeroDeFilasMatriz1,numeroDeColumnasMatriz1);



        std::cout << "\nIngrese la segunda matriz:\n";
        ingresarMatriz(matriz2,numeroDeFilasMatriz2,numeroDeColumnasMatriz2);



        std::vector<std::vector<int>> resultado = multiplicarMatrices(matriz1,matriz2,numeroDeFilasMatriz1,numeroDeColumnasMatriz1,numeroDeColumnasMatriz2);
        std::cout << "\nResultado de la multiplicacion:\n";
        mostrarMatriz(resultado);
    }
    else if (numeroDeColumnasMatriz1 > numeroDeFilasMatriz2) {
        std::cout << "\nNo se pueden multiplicar las matrices.\n";
        std::cout << "El numero de columnas de la primera matriz es mayor "
                     "al numero de filas de la segunda matriz.\n";
    }
    else if (numeroDeColumnasMatriz1 < numeroDeFilasMatriz2) {
        std::cout << "\nNo se pueden multiplicar las matrices.\n";
        std::cout << "El numero de columnas de la primera matriz es menor "
                     "al numero de filas de la segunda matriz.\n";
    }
    else {
        std::cout << "No se que hiciste para llegar aqui.\n";
    }

    return 0;
}

//filas y columnas la verdad es redundante que pongas la referencia, no es necesario que trabaje sobre ellas, por lo que
//solamente se va a utilizar en la matriz, para trabajar directamente en ella y asi meter los valores.
void ingresarMatriz(std::vector<std::vector<int>>& matriz, int numeroDeFilas, int numeroDeColumnas) {

    //En este simplemente se meten los datos hasta que i sea menor que le numero de filas, basicamente es mi filtro el numero de filas
    //para que no vaya mas alla del vector.
    for (int i = 0; i < numeroDeFilas; i++) {
        for (int j = 0; j < numeroDeColumnas; j++) {
            std::cout << "Matriz[" << i << "][" << j << "]: ";
            std::cin >> matriz[i][j];
        }
    }
}

std::vector<std::vector<int>> multiplicarMatrices(const std::vector<std::vector<int>>& matriz1,const std::vector<std::vector<int>>& matriz2,int numeroDeFilasMatriz1,int numeroDeColumnasMatriz1,int numeroDeColumnasMatriz2) {

    //Estoy creando un nuevo vector de acuerdo al numero de filas de la matriz 1 y el numero de columnas de la matriz 2.
    std::vector<std::vector<int>> resultado(numeroDeFilasMatriz1,std::vector<int>(numeroDeColumnasMatriz2, 0));

    //Esto hace que para cada posicion de la matriz llamada resultado, pues se toma una fila de la primera matriz y una columna de la segunda
    //se multiplican y se suman, y pues esa suma se guarda en la posicion que este resultado.
    for (int i = 0; i < numeroDeFilasMatriz1; i++) {

        for (int j = 0; j < numeroDeColumnasMatriz2; j++) {

            for (int k = 0; k < numeroDeColumnasMatriz1; k++) {

                resultado[i][j] += matriz1[i][k] * matriz2[k][j];

            }
        }
    }
    return resultado;
}

void mostrarMatriz(const std::vector<std::vector<int>>& matriz) {

    for (int i = 0; i < matriz.size(); i++) {

        std::cout << "| ";

        for (int j = 0; j < matriz[i].size(); j++) {

            std::cout << matriz[i][j] << " ";

        }

        std::cout << "|" << std::endl;
    }
}
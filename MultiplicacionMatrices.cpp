#include <iostream>
#include <limits>
#include <string>
using namespace std;

//ESTE VALOR ES UN ESPACIO DE MEMORIA CONSTANTE PARA TODA MATRIZ GENERADA (TIENE LA DESVENTAJA DE LIMITAR EL SIZE DE LA MATRIZ A SOLO 100 COMPONENTES)
int const maximaCapacidad = 100;

void crearMatriz(int matriz[maximaCapacidad][maximaCapacidad], int &filas, int &columnas, string x, string y);
void multiplicacion(int mA[maximaCapacidad][maximaCapacidad], int mB[maximaCapacidad][maximaCapacidad], int mAB[maximaCapacidad][maximaCapacidad], int nFilasA, int nColumnasA, int nColumnasB, string x);


int main()
{
    //VARIABLES DECORATIVAS
    string x = "======================================================\n", y = "------------------------------------------------------\n";

    //VARIABLES MATRIZ A
    int filasA = 0;
    int columnasA = 0;
    int matrizA[maximaCapacidad][maximaCapacidad];

    //VARIABLES MATRIZ B
    int filasB =  0;
    int columnasB = 0;
    int matrizB[maximaCapacidad][maximaCapacidad];

    //VARIABLES MATRIZ AB
    int matrizAB[maximaCapacidad][maximaCapacidad];



    cout << x << "          --- MULTIPLICACION DE MATRICES ---" << "\n"
                 "                   (Tamano Variable)\n" << x;


    do                                                                      //Este do es quien se encarga de verificar que las matrices puedan multiplicarse cumpliendo (ColumnasA == FilasB)
    {                                                                       //y ademas solicitar los datos de las matrices a multiplicar.
        //MATRIZ A
        cout << "                    --- MATRIZ A ---\n" << y;
        crearMatriz(matrizA, filasA, columnasA, x, y);


        //MATRIZ B
        cout << "                    --- MATRIZ B ---\n" << y;
        crearMatriz(matrizB, filasB, columnasB, x, y);


        if (columnasA != filasB)
        {
            cout << "ERROR. El numero de columnas de A no corresponde\n"
                    "       al numero de filas de B\n" << x;
        }
    }while (columnasA != filasB);



    //MULTPLICACION DE MATRICES
    cout << "           MULTIPLICACION DE MATRICES\n" << y;
    multiplicacion(matrizA, matrizB, matrizAB, filasA, columnasA, columnasB, x);


    return 0;
}


void crearMatriz(int matriz[maximaCapacidad][maximaCapacidad], int &filas, int &columnas, string x, string y)
{
    do
    {
        cout << "Ingrese el numero de filas de la matriz: ";
        cin >> filas;

        if (!cin || filas < 1 || filas > maximaCapacidad)
        {
            cout << "ERROR. Ingresa un entero entre 1 y " << maximaCapacidad << ".\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }while (!cin || filas < 1 || filas > maximaCapacidad);

    do
    {
        cout << "Ingrese el numero de columnas de la matriz: ";
        cin >> columnas;

        if (!cin || columnas < 1 || columnas > maximaCapacidad)
        {
            cout << "ERROR. Ingresa un entero entre 1 y " << maximaCapacidad << ".\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }while (!cin || columnas < 1 || columnas > maximaCapacidad);

    cout << y;


    for (int i = 0; i < filas; i++)                                     //Este for recorre las filas de la matriz     ]
    {                                                                   //                                            |--> Esto provoca que, primero se recorran todas las
        for (int j = 0; j < columnas; j++)                              //Este for recorre las columnas de la amatriz ]    columnas de la matriz antes de cambiar de fila.
        {
            cout << "Componente [" <<i<<"][" <<j<<"]: ";
            while (!(cin >>matriz[i][j]))                               //Registro de cada camponente de la matriz
            {
                cout << "ERROR. Ingresa un numero valido: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    cout << y <<"Matriz Guardada Exitosamente.\n";

    for (int i = 0; i < filas; i++)                                     //]
    {                                                                   //]
        cout << "| ";                                                   //]
        for (int j = 0; j < columnas; j++)                              //]
        {                                                               //]--> Esta pedazo de codigo realiza lo mismo que lo mencionado arriba, pero
            cout << matriz[i][j] << " ";                                //]    con el proposito de imprimir la matriz previamente registrada.
        }                                                               //]
        cout << "|\n";                                                  //]
    }                                                                   //]

    cout << "\n" << x;
}



void multiplicacion(int mA[maximaCapacidad][maximaCapacidad], int mB[maximaCapacidad][maximaCapacidad], int mAB[maximaCapacidad][maximaCapacidad], int nFilasA, int nColumnasA, int nColumnasB, string x)
{
    for (int i = 0; i < nFilasA; i++)                                   //]--> Este pedazo recorre cada componente de la amtriz A, ya que ocupamos
    {                                                                   //]--> que vaya en secuencia para despues multplicarlos por los componentes
        for (int j = 0; j < nColumnasB; j++)                            //]--> de la matriz B
        {                                                               //]
            mAB[i][j] = 0;                                              //]--> Ademas aqui inicializamos una nueva matriz, siendo el producto de AB donde se guardaran los valores, Esta matriz sigue el mismo orden que cuando registramos una matriz arriba.

            for (int k = 0; k < nColumnasA; k++)                        //]--> Aqui tomamos solo de referencia la Columna de la matiz B, la cual sera la primera en terminar su bucle antes de que se cambie de fila en la amtriz A.
            {
                mAB[i][j] += mA[i][k] * mB[k][j];                       //]--> El acomodo ma[i][k] * mB[k][j] matematicamente te dice:
            }                                                           //]    Para la primera iteraccion de k --> al componente 0 de mAB le voy a sumar: (mA[0][0] = 2) * (mb[0][0] = 3) = 6
        }                                                               //]    Para la segunda iteraccion de k --> al componente 0 de mAB le voy a sumar: (mA[0][1] = 2) * (mb[1][0] = 4) = 8
    }                                                                   //]    Tu componente mAB[0][0] = 14

                                                                        //]    Despues de ello, j aumenta y se repite el mismo proceso para mAB[0][1].

    for (int i = 0; i < nFilasA; i++)
    {
        cout << "| ";
        for (int j = 0; j < nColumnasB; j++)
        {
            cout << mAB[i][j] << " ";
        }
        cout << "|\n";
    }

    cout << "\n" << x;
}
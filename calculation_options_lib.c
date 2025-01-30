#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "matrix_calculator_lib.h"
#include "calculation_options_lib.h"

void mostrarMenu() 
{
    printf("\n========== CALCULADORA DE MATRICES ==========\n");
    printf("Por favor, selecciona una opción:\n");
    printf("\n--- Operaciones Básicas ---\n");
    printf("1. Sumar dos matrices\n");
    printf("2. Restar dos matrices\n");
    printf("3. Multiplicar dos matrices\n");
    printf("4. Multiplicar matriz por escalar\n");
    
    printf("\n--- Operaciones Avanzadas ---\n");
    printf("5. Calcular determinante\n");
    printf("6. Calcular matriz transpuesta\n");
    printf("7. Calcular matriz adjunta\n");
    printf("8. Calcular matriz inversa\n");

    printf("\n--- Operaciones con Archivos ---\n");
    printf("9. Guardar matriz en un archivo\n");
    printf("10. Cargar matriz desde un archivo\n");

    printf("\n0. Salir\n");
    printf("\n=============================================\n");
    printf("Tu selección: ");
}

int obtenerOpcion() {
    uint8_t opcion;
    if (scanf("%hhu", &opcion) != 1) 
	{
        printf("\nError: Entrada no válida. Intenta de nuevo.\n");
        while (getchar() != '\n'); // Limpiar el buffer
        return -1; // Retorna -1 para indicar error
    }
    return opcion;
}

// Implementaciones de las opciones

void handle_matrix_addition() {
    printf("\n--- Suma de Matrices ---\n");

    uint8_t rows, cols;
    printf("Ingresa el número de filas: ");
    scanf("%hhu", &rows);
    printf("Ingresa el número de columnas: ");
    scanf("%hhu", &cols);

    double** matrix_a = crearMatriz(rows, cols);
    double** matrix_b = crearMatriz(rows, cols);

    printf("\nIngresa los elementos de la primera matriz:\n");
    llenarMatriz(matrix_a, rows, cols);
    printf("\nIngresa los elementos de la segunda matriz:\n");
    llenarMatriz(matrix_b, rows, cols);

    double** result = sumaDeMatrices(matrix_a, matrix_b, rows, cols);

    printf("\nResultado de la suma:\n");
    mostrarMatriz(result, rows, cols);

    liberarMatriz(matrix_a, rows);
    liberarMatriz(matrix_b, rows);
    liberarMatriz(result, rows);
}

void handle_matrix_subtraction() {
    printf("\n--- Resta de Matrices ---\n");

    uint8_t rows, cols;
    printf("Ingresa el número de filas: ");
    scanf("%hhu", &rows);
    printf("Ingresa el número de columnas: ");
    scanf("%hhu", &cols);

    double** matrix_a = crearMatriz(rows, cols);
    double** matrix_b = crearMatriz(rows, cols);

    printf("\nIngresa los elementos de la primera matriz:\n");
    llenarMatriz(matrix_a, rows, cols);
    printf("\nIngresa los elementos de la segunda matriz:\n");
    llenarMatriz(matrix_b, rows, cols);

    double** result = restaDeMatrices(matrix_a, matrix_b, rows, cols);

    printf("\nResultado de la resta:\n");
    mostrarMatriz(result, rows, cols);

    liberarMatriz(matrix_a, rows);
    liberarMatriz(matrix_b, rows);
    liberarMatriz(result, rows);
}

void handle_matrix_multiplication() 
{
    printf("\n--- Multiplicación de Matrices ---\n");
    uint8_t askCharging;
    do{
        printf("Ingrese si desea cargar la matriz resultado del archivo\n1: 'SI'\n0: 'NO'\nSu eleccion:\t");
        scanf("%hhu", &askCharging);
        if(askCharging != 1 && askCharging != 0)
        {
            printf("\nSr Usuario, se le explico claramente que debe seleccionar:\n'1' si desea cargar la matriz del archivo y '0' si no desea cargarla.\nSin lugar a dudas ¡A usted no le funciona la materia gris!\n");
        }
    }while(askCharging != 1 && askCharging != 0);
    uint8_t rows_a, N, cols_b;
    if(askCharging == 0) // NO desea CARGAR.
    {
        do{
            printf("\nIngresa el número de filas de la primera matriz:\t");
            scanf("%hhu", &rows_a);
            if(rows_a == 0)
            {
                printf("\nSr Usuario: El numero de filas de una matriz es estrictamente positivo.\nSin lugar a dudas, ¡Usted es retrasado!\n");
            }
        }while(rows_a == 0);
        
        do{
            printf("\nIngresa el número de columnas de la primera matriz y el número de columnas de la segunda matriz:\t");
            scanf("%hhu", &N);
            if(N == 0)
            {
                printf("\nSr Usuario: El numero de filas y de columnas de una matriz es estrictamente positivo.\nSin lugar a dudas, ¡Usted es retrasado!\n");
            }
        }while(N == 0);
        
        do{
            printf("\nIngresa el número de columnas de la segunda matriz:\t");
            scanf("%hhu", &cols_b);
            if(cols_b == 0)
            {
                printf("\nSr Usuario: El numero de columnas de una matriz es estrictamente positivo.\nSin lugar a dudas, ¡Usted es retrasado!\n");
            }
        }while(cols_b == 0);
        
    }
    if(askCharging == 1) // SI desea CARGAR.
    {
        char chargingPlace;
        do{
            printf("\nIngrese donde desea cargar la matriz del archivo:\nA: Matriz A\nB: Matriz B:\nSu eleccion:\t");
            scanf("%c", &chargingPlace);
            if(chargingPlace != 'A' && chargingPlace != 'B')
            {
                printf("\nSr Usuario, se le explico claramente que debe seleccionar:\n'A' si desea cargar la matriz del archivo en la matriz A y 'B' si  desea cargar la matriz del archivo en la matriz B.\nSin lugar a dudas ¡A usted no le funciona la materia gris!\n");
            }
        }while(chargingPlace != 'A' && chargingPlace != 'B');
        if(chargingPlace == 'A')
        {
            leerDimensionesMatriz("matrizResultado.txt", &rows_a, &N);
            printf("\nIngresa el número de columnas de la segunda matriz:\t");
            scanf("%hhu", &cols_b);
        }
        if(chargingPlace == 'B')
        {
            printf("\nIngresa el número de filas de la primera matriz:\t");
            scanf("%hhu", &rows_a);
            leerDimensionesMatriz("matrizResultado.txt", &N, &cols_b);
        }
    }

    double** matrix_a = crearMatriz(rows_a, N);
    double** matrix_b = crearMatriz(N, cols_b);

    if(askCharging == 0)
    {
        printf("\nIngresa los elementos de la primera matriz:\n");
        llenarMatriz(rows_a, N, matrix_a);
        printf("\nMatriz A:\n");
        mostrarMatriz(rows_a, N, matrix_a);
        printf("\nIngresa los elementos de la segunda matriz:\n");
        llenarMatriz(N, cols_b, matrix_b);
        printf("\nMatriz B:\n");
        mostrarMatriz(N, cols_b, matrix_b);
    }
    if(askCharging == 1)
    {
        if(chargingPlace == 'A')
        {
            cargarMatriz("matrizResultado.txt", matrix_a, &rows_a, &N);
            printf("\nMatriz A:\n");
            mostrarMatriz(rows_a, N, matrix_a);
            printf("\nIngresa los elementos de la segunda matriz:\n");
            llenarMatriz(N, cols_b, matrix_b);
            printf("\nMatriz B:\n");
            mostrarMatriz(N, cols_b, matrix_b);
        }
        if(chargingPlace == 'B')
        {
            printf("\nIngresa los elementos de la primera matriz:\n");
            llenarMatriz(rows_a, N, matrix_a);
            printf("\nMatriz A:\n");
            mostrarMatriz(rows_a, N, matrix_a);
            cargarMatriz("matrizResultado.txt", matrix_b, &N, &cols_b);
            printf("\nMatriz B:\n");
            mostrarMatriz(N, cols_b, matrix_b);
        }

    }
    
    double** result = crearMatriz(rows_a, cols_b);
    productoDeMatrices(rows_a, cols_b, N, matrix_a, matrix_b, result);

    printf("\nResultado de la multiplicación:\n");
    mostrarMatriz(rows_a, cols_b, result);

    liberarMatriz(matrix_a, rows_a);
    liberarMatriz(matrix_b, N);
    liberarMatriz(result, rows_a);
}

void handle_matrix_transpose() {
    printf("\n--- Transponer una Matriz ---\n");

    uint8_t rows, cols;
    printf("Ingresa el número de filas: ");
    scanf("%hhu", &rows);
    printf("Ingresa el número de columnas: ");
    scanf("%hhu", &cols);

    double** matrix = crearMatriz(rows, cols);

    printf("\nIngresa los elementos de la matriz:\n");
    llenarMatriz(matrix, rows, cols);

    double** result = transponerMatriz(matrix, rows, cols);

    printf("\nResultado de la transposición:\n");
    mostrarMatriz(result, cols, rows);

    liberarMatriz(matrix, rows);
    liberarMatriz(result, cols);
}

void handle_matrix_determinant() {
    printf("\n--- Determinante de una Matriz ---\n");

    uint8_t size;
    printf("Ingresa el tamaño de la matriz (cuadrada): ");
    scanf("%hhu", &size);

    double** matrix = crearMatriz(size, size);

    printf("\nIngresa los elementos de la matriz:\n");
    llenarMatriz(matrix, size, size);

    double determinant = calcularDeterminante(matrix, size);

    printf("\nEl determinante de la matriz es: %d\n", determinant);

    liberarMatriz(matrix, size);
}

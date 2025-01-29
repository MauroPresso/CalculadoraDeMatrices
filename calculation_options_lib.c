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
    int opcion;
    if (scanf("%d", &opcion) != 1) 
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

void handle_matrix_multiplication() {
    printf("\n--- Multiplicación de Matrices ---\n");

    uint8_t rows_a, cols_a, rows_b, cols_b;
    printf("Ingresa el número de filas de la primera matriz: ");
    scanf("%hhu", &rows_a);
    printf("Ingresa el número de columnas de la primera matriz: ");
    scanf("%hhu", &cols_a);

    printf("\nIngresa el número de filas de la segunda matriz: ");
    scanf("%hhu", &rows_b);
    printf("Ingresa el número de columnas de la segunda matriz: ");
    scanf("%hhu", &cols_b);

    if (cols_a != rows_b) {
        printf("\nError: El número de columnas de la primera matriz debe ser igual al número de filas de la segunda matriz.\n");
        return;
    }

    double** matrix_a = crearMatriz(rows_a, cols_a);
    double** matrix_b = crearMatriz(rows_b, cols_b);

    printf("\nIngresa los elementos de la primera matriz:\n");
    llenarMatriz(matrix_a, rows_a, cols_a);
    printf("\nIngresa los elementos de la segunda matriz:\n");
    llenarMatriz(matrix_b, rows_b, cols_b);

    double** result = productoDeMatrices(matrix_a, rows_a, cols_a, matrix_b, rows_b, cols_b);

    printf("\nResultado de la multiplicación:\n");
    mostrarMatriz(result, rows_a, cols_b);

    liberarMatriz(matrix_a, rows_a);
    liberarMatriz(matrix_b, rows_b);
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

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

    int** matrix_a = create_matrix(rows, cols);
    int** matrix_b = create_matrix(rows, cols);

    printf("\nIngresa los elementos de la primera matriz:\n");
    input_matrix(matrix_a, rows, cols);
    printf("\nIngresa los elementos de la segunda matriz:\n");
    input_matrix(matrix_b, rows, cols);

    int** result = add_matrices(matrix_a, matrix_b, rows, cols);

    printf("\nResultado de la suma:\n");
    print_matrix(result, rows, cols);

    free_matrix(matrix_a, rows);
    free_matrix(matrix_b, rows);
    free_matrix(result, rows);
}

void handle_matrix_subtraction() {
    printf("\n--- Resta de Matrices ---\n");

    uint8_t rows, cols;
    printf("Ingresa el número de filas: ");
    scanf("%hhu", &rows);
    printf("Ingresa el número de columnas: ");
    scanf("%hhu", &cols);

    int** matrix_a = create_matrix(rows, cols);
    int** matrix_b = create_matrix(rows, cols);

    printf("\nIngresa los elementos de la primera matriz:\n");
    input_matrix(matrix_a, rows, cols);
    printf("\nIngresa los elementos de la segunda matriz:\n");
    input_matrix(matrix_b, rows, cols);

    int** result = subtract_matrices(matrix_a, matrix_b, rows, cols);

    printf("\nResultado de la resta:\n");
    print_matrix(result, rows, cols);

    free_matrix(matrix_a, rows);
    free_matrix(matrix_b, rows);
    free_matrix(result, rows);
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

    int** matrix_a = create_matrix(rows_a, cols_a);
    int** matrix_b = create_matrix(rows_b, cols_b);

    printf("\nIngresa los elementos de la primera matriz:\n");
    input_matrix(matrix_a, rows_a, cols_a);
    printf("\nIngresa los elementos de la segunda matriz:\n");
    input_matrix(matrix_b, rows_b, cols_b);

    int** result = multiply_matrices(matrix_a, rows_a, cols_a, matrix_b, rows_b, cols_b);

    printf("\nResultado de la multiplicación:\n");
    print_matrix(result, rows_a, cols_b);

    free_matrix(matrix_a, rows_a);
    free_matrix(matrix_b, rows_b);
    free_matrix(result, rows_a);
}

void handle_matrix_transpose() {
    printf("\n--- Transponer una Matriz ---\n");

    uint8_t rows, cols;
    printf("Ingresa el número de filas: ");
    scanf("%hhu", &rows);
    printf("Ingresa el número de columnas: ");
    scanf("%hhu", &cols);

    int** matrix = create_matrix(rows, cols);

    printf("\nIngresa los elementos de la matriz:\n");
    input_matrix(matrix, rows, cols);

    int** result = transpose_matrix(matrix, rows, cols);

    printf("\nResultado de la transposición:\n");
    print_matrix(result, cols, rows);

    free_matrix(matrix, rows);
    free_matrix(result, cols);
}

void handle_matrix_determinant() {
    printf("\n--- Determinante de una Matriz ---\n");

    uint8_t size;
    printf("Ingresa el tamaño de la matriz (cuadrada): ");
    scanf("%hhu", &size);

    int** matrix = create_matrix(size, size);

    printf("\nIngresa los elementos de la matriz:\n");
    input_matrix(matrix, size, size);

    int determinant = calculate_determinant(matrix, size);

    printf("\nEl determinante de la matriz es: %d\n", determinant);

    free_matrix(matrix, size);
}

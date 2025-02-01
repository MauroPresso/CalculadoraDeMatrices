#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "matrix_calculator_lib.h"
#include "calculation_options_lib.h"

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- //
// PROCEDIMIENTO QUE MANEJAN LA SUMA DE MATRICES.
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- //

void handle_matrix_addition(void) 
{
    printf("\n--- Suma de Matrices ---\n");

    uint8_t rows, cols;
    uint8_t askCharging, askSaving;
    
    // Pregunta si quiere CARGAR la matriz del archivo.
    askCharging = preguntaSiCargar();

    if(askCharging == 0) // NO desea CARGAR.
    {
        // Ingresa el numero de filas de las matrices.
        do{
            printf("\nIngresa el numero de filas de las matrices:\t");
            scanf("%hhu", &rows);
            if(rows == 0)
            {
                Beep(900,500);
                printf("\nSr Usuario: El numero de filas de una matriz es estrictamente positivo.\nSin lugar a dudas, ¡Usted es retrasado!\n");
            }
            if(rows > 255)
            {
                Beep(900,500);
                printf("\nSr Usuario: Esta calculadora soporta como mucho matrices de 255x255. Disculpe los inconvenientes.\n");
            }
        }while(rows == 0 || rows > 255);
        
        // Ingresa el numero de columnas de las matrices.
        do{
            printf("\nIngresa el numero de columnas de las matrices:\t");
            scanf("%hhu", &cols);
            if(cols == 0)
            {
                Beep(900,500);
                printf("\nSr Usuario: El numero de columnas de una matriz es estrictamente positivo.\nSin lugar a dudas, ¡Usted es retrasado!\n");
            }
            if(cols > 255)
            {
                Beep(900,500);
                printf("\nSr Usuario: Esta calculadora soporta como mucho matrices de 255x255. Disculpe los inconvenientes.\n");
            }
        }while(cols == 0 || cols > 255); 
    }

    if(askCharging == 1) // SI desea CARGAR.
    {
        leerDimensionesMatriz("matrizResultado.txt", &rows, &cols);
    }

    double** matrix_a = crearMatriz(rows, cols);
    double** matrix_b = crearMatriz(rows, cols);

    if(askCharging == 0)
    {
        printf("\nIngresa los elementos de la Matriz A:\n");
        llenarMatriz(rows, cols, matrix_a);
        printf("\nMatriz A:\n");
        mostrarMatriz(rows, cols, matrix_a);
        
        printf("\nIngresa los elementos de la Matriz B:\n");
        llenarMatriz(rows, cols, matrix_b);
        printf("\nMatriz B:\n");
        mostrarMatriz(rows, cols, matrix_b);
    }
    
    if(askCharging == 1)
    {
        cargarMatriz("matrizResultado.txt", &matrix_a, &rows, &cols);
        printf("\nMatriz A:\n");
        mostrarMatriz(rows, cols, matrix_a);

        printf("\nIngresa los elementos de la Matriz B:\n");
        llenarMatriz(rows, cols, matrix_b);
        printf("\nMatriz B:\n");
        mostrarMatriz(rows, cols, matrix_b);
    }

    double** result = crearMatriz(rows, cols);
    
    sumaDeMatrices(rows, cols, matrix_a, matrix_b, result);
    printf("\nResultado de la suma:\n");
    mostrarMatriz(rows, cols, result);

    askSaving = preguntaSiGuardar();
    if(askSaving == 1)
    {
        guardarMatriz(result, rows, cols, "matrizResultado.txt");
    }

    liberarMatriz(matrix_a, rows);
    liberarMatriz(matrix_b, rows);
    liberarMatriz(result, rows);

    matrix_a = NULL;
    matrix_b = NULL;
    result = NULL;
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- //
// PROCEDIMIENTO QUE MANEJAN LA RESTA DE MATRICES.
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- //

void handle_matrix_subtraction(void) 
{
    printf("\n--- Resta de Matrices ---\n");

    uint8_t rows, cols;
    uint8_t askCharging, askSaving;
    char chargingPlace;

    // Pregunta si quiere CARGAR la matriz del archivo.
    askCharging = preguntaSiCargar();
    
    if(askCharging == 0) // NO desea CARGAR.
    {
        // Ingresa el numero de filas de las Matrices.
        do{
            printf("\nIngresa el numero de filas de las Matrices:\t");
            scanf("%hhu", &rows);
            if(rows == 0)
            {
                Beep(900,500);
                printf("\nSr Usuario: El numero de filas de una matriz es estrictamente positivo.\nSin lugar a dudas, ¡Usted es retrasado!\n");
            }
            if(rows > 255)
            {
                Beep(900,500);
                printf("\nSr Usuario: Esta calculadora soporta como mucho matrices de 255x255. Disculpe los inconvenientes.\n");
            }
        }while(rows == 0 || rows > 255);
        // Ingresa el numero de columnas de las Matrices.
        do{
            printf("\nIngresa el numero de columnas de las Matrices:\t");
            scanf("%hhu", &cols);
            if(cols == 0)
            {
                Beep(900,500);
                printf("\nSr Usuario: El numero de columnas de una matriz es estrictamente positivo.\nSin lugar a dudas, ¡Usted es retrasado!\n");
            }
            if(cols > 255)
            {
                Beep(900,500);
                printf("\nSr Usuario: Esta calculadora soporta como mucho matrices de 255x255. Disculpe los inconvenientes.\n");
            }
        }while(cols == 0 || cols > 255); 
    }
    
    if(askCharging == 1) // SI desea CARGAR.
    {
        // Lee del archivo las dimensiones de la matriz.
        leerDimensionesMatriz("matrizResultado.txt", &rows, &cols);
    }

    // Declaro las Matrices A y B.
    double** matrix_a = crearMatriz(rows, cols);
    double** matrix_b = crearMatriz(rows, cols);

    if(askCharging == 0) // NO desea CARGAR.
    {
        // Llena y Muestra la Matriz A.
        printf("\nIngresa los elementos de la Matriz A:\n");
        llenarMatriz(rows, cols, matrix_a);
        printf("\nMatriz A:\n");
        mostrarMatriz(rows, cols, matrix_a);
        // Llena y Muestra la Matriz B.
        printf("\nIngresa los elementos de la Matriz B:\n");
        llenarMatriz(rows, cols, matrix_b);
        printf("\nMatriz B:\n");
        mostrarMatriz(rows, cols, matrix_b);
    }
    
    if(askCharging == 1) // SI desea CARGAR.
    {
        // Pregunta donde quiere CARGAR la matriz.
        chargingPlace = preguntaDondeCargar();
        // La matriz proveniente del archivo se carga en la Matriz A.
        if(chargingPlace == 'A')
        {
            // Carga y Muestra la Matriz A.
            cargarMatriz("matrizResultado.txt", &matrix_a, &rows, &cols);
            printf("\nMatriz A:\n");
            mostrarMatriz(rows, cols, matrix_a);
            // Llena y Muestra la Matriz B.
            printf("\nIngresa los elementos de la Matriz B:\n");
            llenarMatriz(rows, cols, matrix_b);
            printf("\nMatriz B:\n");
            mostrarMatriz(rows, cols, matrix_b);
        }
        
        // La matriz proveniente del archivo se carga en la Matriz B.
        if(chargingPlace == 'B')
        {
            // Llena y Muestra la Matriz A.
            printf("\nIngresa los elementos de la Matriz A:\n");
            llenarMatriz(rows, cols, matrix_a);
            printf("\nMatriz A:\n");
            mostrarMatriz(rows, cols, matrix_a);
            // Carga y Muestra la Matriz B.
            cargarMatriz("matrizResultado.txt", &matrix_b, &rows, &cols);
            printf("\nMatriz B:\n");
            mostrarMatriz(rows, cols, matrix_b);
        }
    }
    
    // Declaro la Matriz Resultado.
    double** result = crearMatriz(rows, cols);

    restaDeMatrices(rows, cols, matrix_a, matrix_b, result);

    printf("\nResultado de la resta:\n");
    mostrarMatriz(rows, cols, result);

    liberarMatriz(matrix_a, rows);
    liberarMatriz(matrix_b, rows);
    liberarMatriz(result, rows);

    matrix_a = NULL;
    matrix_b = NULL;
    result = NULL;
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- //
// PROCEDIMIENTO QUE MANEJAN LA MULTIPLICACION ENTRE MATRICES.
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- //

void handle_matrix_multiplication(void) 
{
    printf("\n--- Multiplicación de Matrices ---\n"); // Este printf lo agrego solo por estetica.
    
    // Declaro las variables fuera de las estructuras de control para poder seguir utilizandolas fuera de estas ultimas.
    uint8_t rows_a, N, cols_b;
    uint8_t askCharging, askSaving;
    char chargingPlace;
    
    // Pregunta si quiere CARGAR la matriz del archivo.
    askCharging = preguntaSiCargar();
    
    if(askCharging == 0) // NO desea CARGAR.
    {
        // Ingresa el numero de filas de la Matriz A.
        do{
            printf("\nIngresa el numero de filas de la Matriz A:\t");
            scanf("%hhu", &rows_a);
            if(rows_a == 0)
            {
                Beep(900,500);
                printf("\nSr Usuario: El numero de filas de una matriz es estrictamente positivo.\nSin lugar a dudas, ¡Usted es retrasado!\n");
            }
            if(rows_a > 255)
            {
                Beep(900,500);
                printf("\nSr Usuario: Esta calculadora soporta como mucho matrices de 255x255. Disculpe los inconvenientes.\n");
            }
        }while(rows_a == 0 || rows_a > 255);
        
        // Ingresa el numero de columnas de la Matriz A y el numero de filas de la Matriz B.
        do{
            printf("\nIngresa el numero de columnas de la Matriz A y el numero de columnas de la Matriz B:\t");
            scanf("%hhu", &N);
            if(N == 0)
            {
                Beep(900,500);
                printf("\nSr Usuario: El numero de filas y de columnas de una matriz es estrictamente positivo.\nSin lugar a dudas, ¡Usted es retrasado!\n");
            }
            if(N > 255)
            {
                Beep(900,500);
                printf("\nSr Usuario: Esta calculadora soporta como mucho matrices de 255x255. Disculpe los inconvenientes.\n");
            }
        }while(N == 0 || N > 255);
        
        // Ingresa el numero de columnas de la Matriz B.
        do{
            printf("\nIngresa el numero de columnas de la Matriz B:\t");
            scanf("%hhu", &cols_b);
            if(cols_b == 0)
            {
                Beep(900,500);
                printf("\nSr Usuario: El numero de columnas de una matriz es estrictamente positivo.\nSin lugar a dudas, ¡Usted es retrasado!\n");
            }
            if(cols_b > 255)
            {
                Beep(900,500);
                printf("\nSr Usuario: Esta calculadora soporta como mucho matrices de 255x255. Disculpe los inconvenientes.\n");
            }
        }while(cols_b == 0 || cols_b > 255); 
    }
    
    if(askCharging == 1) // SI desea CARGAR.
    {
        // Pregunta donde quiere CARGAR la matriz.
        chargingPlace = preguntaDondeCargar();
        
        // La matriz proveniente del archivo se carga en la Matriz A.
        if(chargingPlace == 'A')
        {
            // Lee del archivo las dimensiones de la Matriz A.
            leerDimensionesMatriz("matrizResultado.txt", &rows_a, &N);
            // Ingresa el numero de columnas de la Matriz B.
            do{
                printf("\nIngresa el numero de columnas de la Matriz B:\t");
                scanf("%hhu", &cols_b);
                if(cols_b == 0)
                {
                    Beep(900,500);
                    printf("\nSr Usuario: El numero de columnas de una matriz es estrictamente positivo.\nSin lugar a dudas, ¡Usted es retrasado!\n");
                }
                if(cols_b > 255)
                {
                    Beep(900,500);
                    printf("\nSr Usuario: Esta calculadora soporta como mucho matrices de 255x255. Disculpe los inconvenientes.\n");
                }
            }while(cols_b == 0 || cols_b > 255); 
        }
        
        // La matriz proveniente del archivo se carga en la Matriz B.
        if(chargingPlace == 'B')
        {
            // Ingresa el numero de filas de la Matriz A.
            do{
                printf("\nIngresa el numero de filas de la Matriz A:\t");
                scanf("%hhu", &rows_a);
                if(rows_a == 0)
                {
                    Beep(900,500);
                    printf("\nSr Usuario: El numero de filas de una matriz es estrictamente positivo.\nSin lugar a dudas, ¡Usted es retrasado!\n");
                }
                if(rows_a > 255)
                {
                    Beep(900,500);
                    printf("\nSr Usuario: Esta calculadora soporta como mucho matrices de 255x255. Disculpe los inconvenientes.\n");
                }
            }while(rows_a == 0 || rows_a > 255);
            // Lee del archivo las dimensiones de la Matriz B.
            leerDimensionesMatriz("matrizResultado.txt", &N, &cols_b);
        }
    }

    // Declaro las Matrices A y B.
    double** matrix_a = crearMatriz(rows_a, N);
    double** matrix_b = crearMatriz(N, cols_b);

    if(askCharging == 0) // NO desea CARGAR.
    {
        // Llena y Muestra la Matriz A.
        printf("\nIngresa los elementos de la Matriz A:\n");
        llenarMatriz(rows_a, N, matrix_a);
        printf("\nMatriz A:\n");
        mostrarMatriz(rows_a, N, matrix_a);
        // Llena y Muestra la Matriz B.
        printf("\nIngresa los elementos de la Matriz B:\n");
        llenarMatriz(N, cols_b, matrix_b);
        printf("\nMatriz B:\n");
        mostrarMatriz(N, cols_b, matrix_b);
    }
    
    if(askCharging == 1) // SI desea CARGAR.
    {
        // La matriz proveniente del archivo se carga en la Matriz A.
        if(chargingPlace == 'A')
        {
            // Carga y Muestra la Matriz A.
            cargarMatriz("matrizResultado.txt", &matrix_a, &rows_a, &N);
            printf("\nMatriz A:\n");
            mostrarMatriz(rows_a, N, matrix_a);
            // Llena y Muestra la Matriz B.
            printf("\nIngresa los elementos de la Matriz B:\n");
            llenarMatriz(N, cols_b, matrix_b);
            printf("\nMatriz B:\n");
            mostrarMatriz(N, cols_b, matrix_b);
        }
        
        // La matriz proveniente del archivo se carga en la Matriz B.
        if(chargingPlace == 'B')
        {
            // Llena y Muestra la Matriz A.
            printf("\nIngresa los elementos de la Matriz A:\n");
            llenarMatriz(rows_a, N, matrix_a);
            printf("\nMatriz A:\n");
            mostrarMatriz(rows_a, N, matrix_a);
            // Carga y Muestra la Matriz B.
            cargarMatriz("matrizResultado.txt", &matrix_b, &N, &cols_b);
            printf("\nMatriz B:\n");
            mostrarMatriz(N, cols_b, matrix_b);
        }

    }
    
    // Declaro la Matriz Resultado.
    double** result = crearMatriz(rows_a, cols_b);
    
    // Calculo el producto de Matrices.
    productoDeMatrices(rows_a, cols_b, N, matrix_a, matrix_b, result);

    // Muestro la Matriz Resultado.
    printf("\nResultado de la multiplicación:\n");
    mostrarMatriz(rows_a, cols_b, result);

    // Pregunta si quiere GUARDAR la matriz del archivo.
    askSaving = preguntaSiGuardar();

    if(askSaving == 1) // SI desea GUARDAR.
    {
        guardarMatriz(result, rows_a, cols_b, "matrizResultado.txt");
    }

    // Libero la memoria dinamica.
    liberarMatriz(matrix_a, rows_a);
    liberarMatriz(matrix_b, N);
    liberarMatriz(result, rows_a);

    // Quitando punteros residuales.
    matrix_a = NULL;
    matrix_b = NULL;
    result = NULL;
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- //
// PROCEDIMIENTO QUE MANEJAN LA TRANSPOSICION DE UNA MATRIZ.
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- //

void handle_matrix_transpose(void) 
{
    printf("\n--- Transponer una Matriz ---\n");

    uint8_t rows, cols;
    printf("Ingresa el número de filas: ");
    scanf("%hhu", &rows);
    printf("Ingresa el número de columnas: ");
    scanf("%hhu", &cols);

    double** matrix = crearMatriz(rows, cols);

    printf("\nIngresa los elementos de la matriz:\n");
    llenarMatriz(rows, cols, matrix);

    double** result = crearMatriz(cols, rows);
    transponerMatriz(matrix, result, rows, cols);

    printf("\nResultado de la transposición:\n");
    mostrarMatriz(cols, rows, result);

    liberarMatriz(matrix, rows);
    liberarMatriz(result, cols);

    matrix = NULL;
    result = NULL;
}

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- //
// PROCEDIMIENTO QUE MANEJAN EL CALCULO DE EL DETERMINANTE DE UNA MATRIZ (CUADRADA).
// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- //

void handle_matrix_determinant(void) 
{
    printf("\n--- Determinante de una Matriz ---\n");
    uint8_t askCharging;
    uint8_t rows, cols;
    uint8_t size;
    // Pregunta si quiere CARGAR la matriz del archivo.
    askCharging = preguntaSiCargar();

    if(askCharging == 0)
    {
        do{
            printf("\nIngrese el orden de la matriz cuadrada:\t");
            scanf("%hhu", &size);
            if(size == 0)
            {
                Beep(900,500);
                printf("\nSr Usuario: El orden de una matriz cuadrada debe ser estrictamente positivo. Sin lugar a dudas, ¡Usted es retrasado! \n");
            }
        }while(size == 0);
    }
    
    if(askCharging == 1)
    {
        leerDimensionesMatriz("matrizResultado.txt", &rows, &cols);
        if(rows != cols)
        {
            Beep(900,500);
            printf("\nNO es posible calcular el determinante ya que la matriz del archivo no es cuadrada.\n");
            return;
        }
        else
        {
            size = rows;
        }
    }

    double** matrix = crearMatriz(size, size);

    if(askCharging == 0)
    {
        printf("\nIngresa los elementos de la matriz:\n");
        llenarMatriz(size, size, matrix);
        printf("\nMatriz:\n");
        mostrarMatriz(size, size, matrix);
    }

    if(askCharging == 1)
    {
        cargarMatriz("matrizResultado.txt", &matrix, &size, &size);
        printf("\nMatriz:\n");
        mostrarMatriz(size, size, matrix);
    }

    double determinante = calcularDeterminante(size, matrix);

    printf("\nEl determinante de la matriz es:\t%lf\n", determinante);

    liberarMatriz(matrix, size);

    matrix = NULL;
}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "matrix_calculator_lib.h"
#include "calculation_options_lib.h"

int main() 
{
    uint8_t opcion;
    do {
        opcion = obtenerOpcionMenu();
        switch (opcion) 
		{
            case 0:
                printf("\nSaliendo del programa...\n");
                break; // El break es para que no siga ejecutando secuencialmente los otros casos.
            case 1:
                printf("\n[Operación seleccionada] Suma de matrices.\n");
                handle_matrix_addition();
                break;
            case 2:
                printf("\n[Operación seleccionada] Resta de matrices.\n");
                handle_matrix_substraction();
                break;
            case 3:
                printf("\n[Operación seleccionada] Multiplicación de matrices.\n");
                handle_matrices_multiplication();
                break;
            case 4:
                printf("\n[Operación seleccionada] Multiplicación por escalar.\n");
                handle_matrix_and_scalar_multiplication();
                break;
            case 5:
                printf("\n[Operación seleccionada] Transposición de matriz.\n");
                handle_matrix_transpose();
                break;
            case 6:
                printf("\n[Operación seleccionada] Cálculo del determinante.\n");
                handle_matrix_determinant();
                break;
            case 7:
                printf("\n[Operación seleccionada] Cálculo de matriz inversa.\n");
                handle_matrix_inverse();
                break;
            // default: sentencia; /*opcional porque estoy seguro que todos los valores de el selector estan incluidos en las etiquetas case*/
        }
    } while (opcion != 0);
    printf("\n¡Gracias por usar la calculadora!\n");
    return 0;
}
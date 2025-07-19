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
        if(opcion == 0)
        {
            printf("\nSaliendo del programa...\n");
            printf("\nGracias por usar la calculadora!\n");
            return 0;
        }
        if(opcion == 1)
        {
            handle_matrix_addition();
        }
        if(opcion == 2)
        {
            handle_matrix_subtraction();
        }
        if(opcion == 3)
        {
            handle_matrices_multiplication();
        }
        if(opcion == 4)
        {
            handle_matrix_and_scalar_multiplication();
        }
        if(opcion == 5)
        {
            handle_matrix_transpose();
        }
        if(opcion == 6)
        {
            handle_matrix_determinant();
        }
        if(opcion == 7)
        {
            handle_matrix_inverse();
        }
    } while (opcion != 0);
}
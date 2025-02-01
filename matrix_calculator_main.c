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
                // Llamar a la función correspondiente
                break;
            case 2:
                printf("\n[Operación seleccionada] Resta de matrices.\n");
                break;
            case 3:
                printf("\n[Operación seleccionada] Multiplicación de matrices.\n");
                break;
            case 4:
                printf("\n[Operación seleccionada] Multiplicación por escalar.\n");
                break;
            case 5:
                printf("\n[Operación seleccionada] Transposición de matriz.\n");
                break;
            case 6:
                printf("\n[Operación seleccionada] Cálculo del determinante.\n");
                break;
            case 7:
                printf("\n[Operación seleccionada] Cálculo de matriz inversa.\n");
                break;
            // default: sentencia; /*opcional porque estoy seguro que todos los valores de el selector estan incluidos en las etiquetas case*/
        }
    } while (opcion != 0);
    printf("\n¡Gracias por usar la calculadora!\n");
    return 0;
}
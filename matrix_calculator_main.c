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
                printf("\n[Operación seleccionada] Cálculo del determinante.\n");
                break;
            case 6:
                printf("\n[Operación seleccionada] Transposición de matriz.\n");
                break;
            case 7:
                printf("\n[Operación seleccionada] Cálculo de matriz adjunta.\n");
                break;
            case 8:
                printf("\n[Operación seleccionada] Cálculo de matriz inversa.\n");
                break;
            case 0:
                printf("\nSaliendo del programa. ¡Gracias por usar la calculadora!\n");
                break;
        }
    } while (opcion != 0);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "matrix_calculator_lib.h"
#include "calculation_options_lib.h"


void mostrarMenu() {
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
    if (scanf("%d", &opcion) != 1) {
        printf("\nError: Entrada no válida. Intenta de nuevo.\n");
        while (getchar() != '\n'); // Limpiar el buffer
        return -1; // Retorna -1 para indicar error
    }
    return opcion;
}

int main() {
    int opcion;

    do {
        mostrarMenu();
        opcion = obtenerOpcion();

        switch (opcion) {
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
            case 9:
                printf("\n[Operación seleccionada] Guardar matriz en archivo.\n");
                break;
            case 10:
                printf("\n[Operación seleccionada] Cargar matriz desde archivo.\n");
                break;
            case 0:
                printf("\nSaliendo del programa. ¡Gracias por usar la calculadora!\n");
                break;
            default:
                printf("\nOpción no válida. Intenta de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}

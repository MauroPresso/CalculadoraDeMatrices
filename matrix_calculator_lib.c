#include "matrix_calculator_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void mostrarMatriz(int f, int c, double **m)
{
	for(int i = 0 ; i < f ; i++){
		for(int j = 0 ; j < c ; j++){
			printf("%0.4lf\t",m[i][j]);
		}
		printf("\n");
	}
}

void llenarMatriz(int f, int c, double **m)
{
	for(int i = 0 ; i < f ; i++)
	{
		for(int j = 0 ; j < c ; j++)
		{
			printf("\nIngrese valor para M[%d][%d]: ",i+1,j+1);
			scanf("%lf",&m[i][j]);
		}
	}
}

void sumaDeMatrices(int f, int c, double **matrizA, double **matrizB, double **matrizSuma)
{
	for(int i=0;i<f;i++){
		for(int j=0;j<c;j++){
			matrizSuma[i][j]=matrizA[i][j]+matrizB[i][j];
		}
	}
}

void restaDeMatrices(int f, int c, double **matrizA, double **matrizB, double **matrizResta)
{
	for(int i=0;i<f;i++){
		for(int j=0;j<c;j++){
			matrizResta[i][j]=matrizA[i][j]-matrizB[i][j];
		}
	}
}

void productoDeMatrices(int filA, int columB, int n, double **matrizA, double **matrizB, double **matrizProducto) 
{
	for (int i = 0; i < filA; i++) {
		for (int j = 0; j < columB; j++) {
			matrizProducto[i][j] = 0;
			for (int k = 0; k < n; k++) {
				matrizProducto[i][j] = matrizProducto[i][j] + matrizA[i][k] * matrizB[k][j];
			}
		}
	}
}

void matrizPorEscalar(double n, int f, int c, double **m, double **p)
{
	for(int i=0;i<f;i++){
		for(int j=0;j<c;j++){
			p[i][j]=n*m[i][j];
		}
	}
}

void identidad(int n, double **m)
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				m[i][j]=1;
			}
			else{
				m[i][j]=0;
			}
		}
	}
}

void guardarMatriz(double **matriz, int f, int c, const char *nombreArchivo)
{
	FILE *archivo;
	archivo=fopen(nombreArchivo,"wt");
	if (archivo == NULL) {
		Beep(900,500);
		printf("No se pudo abrir el archivo.\n");
		exit(1); // Sale del programa.
	}
	// Escribir las dimensiones de la matriz en el archivo
	fprintf(archivo, "%d %d\n", f, c);
	// Escribir los elementos de la matriz en el archivo
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			fprintf(archivo, "%lf ", matriz[i][j]);
		}
		fprintf(archivo, "\n");
	}
	fclose(archivo);
}

void cargarMatriz(const char *nombreArchivo, double ***matriz, int *f, int *c)
{
	FILE *archivo = fopen(nombreArchivo, "rt");
	if (archivo == NULL) {
		Beep(900,500);
		fprintf(stderr, "No se pudo abrir el archivo %s\n", nombreArchivo);
		exit(EXIT_FAILURE);
	}
	// Leer el número de filas y columnas desde el archivo
	fscanf(archivo, "%d %d", f, c);
	// Asignar memoria para la matriz
	*matriz = (double **)malloc(*f * sizeof(double *));
	for (int i = 0; i < *f; i++) {
		(*matriz)[i] = (double *)malloc(*c * sizeof(double));
	}
	// Leer los elementos de la matriz desde el archivo
	for (int i = 0; i < *f; i++) {
		for (int j = 0; j < *c; j++) {
			fscanf(archivo, "%lf", &(*matriz)[i][j]);
		}
	}
	// Cerrar el archivo
	fclose(archivo);
	// Libero memoria dinámica
	free(*matriz);
}

double calcularDeterminante(int n, double **matriz)
{
	if (n == 1) {
		return matriz[0][0];
	} else if (n == 2) {
		return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
	} else {
		double determinante = 0;
		int h, i, j;
		for (h = 0; h < n; h++) { // h representa las columnas de la matriz original que se eliminan para hacer la submatriz.
			// SUBMATRIZ.
			/*if(h==n) // Ya se calculó el determinante, libera la memoria dinámica de la submatriz.
			{
				free(submatriz);
			}*/
			//asignamos la memoria dinamica para almacenar el vector que almacenara los
			//vectores (submatriz)
			double **submatriz = (double **) malloc(sizeof(double *) * (n - 1));
			for(int i = 0 ; i < n ; i++){
				submatriz[i] = (double *) malloc(sizeof(double *) * (n - 1));
			}
			// Representa la submatriz que se obtiene al eliminar la primera fila y la columna h de la matriz original. 
			// Esto se hace para calcular el determinante de la submatriz.
			for (i = 1; i < n; i++) { // i representa las filas de la submatriz, por eso arranca en 1 (porque se quitó la primera fila).
				for (j = 0; j < n; j++) { // j representa las columnas de la submatriz por eso arranca en cero y no puede ser igual que h porque la columna h-ésima se quitó.
					//Los bucles for anidados con variables i y j se utilizan para copiar los elementos de la matriz original matriz a la submatriz, 
					// excluyendo la primera fila y la columna h, 
					// "if (j < h)" para las columnas anteriores a h y "if (j > h)" para las columnas posteriores a h.
					if (j < h) {
						submatriz[i - 1][j] = matriz[i][j];
					} else if (j > h) {
						submatriz[i - 1][j - 1] = matriz[i][j];
					}
				}
			}
			// Se verifica si h es par o impar con "if(h%2==0)". 
			// Esto se hace para aplicar la regla de los signos, donde los signos se alternan para cada columna.
			if (h % 2 == 0) {
				determinante = determinante + (matriz[0][h] * calcularDeterminante(n - 1, submatriz));
			} else {
				determinante = determinante - (matriz[0][h] * calcularDeterminante(n - 1, submatriz));
			}
			// El resultado parcial se acumula en la variable determinante. Luego, el bucle continúa con la siguiente columna.
		}
		// Después de que el bucle for haya recorrido todas las columnas, la función devuelve el valor calculado en determinante, que es el determinante de la matriz original.
		return determinante;
	}
}
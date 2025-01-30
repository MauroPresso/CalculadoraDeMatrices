#include "matrix_calculator_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <windows.h>

// Función para crear una matriz dinámica de tamaño filas x columnas
double** crearMatriz(uint8_t filas, uint8_t columnas) 
{
    double **matriz = (double **)malloc(filas * sizeof(double *));
    for (uint8_t i = 0; i < filas; i++) 
	{
        matriz[i] = (double *)malloc(columnas * sizeof(double));
    }
    return matriz;
}

// Función para liberar la memoria de una matriz
void liberarMatriz(double **matriz, uint8_t filas) 
{
    for (uint8_t i = 0; i < filas; i++) 
	{
        free(matriz[i]);
    }
    free(matriz);
}

void mostrarMatriz(uint8_t f, uint8_t c, double **m)
{
	for(uint8_t i = 0 ; i < f ; i++)
	{
		for(uint8_t j = 0 ; j < c ; j++)
		{
			if(m[i][j]==0)
			{
				printf("%0.4lf\t",0.0000);
			}
			else
			{
				printf("%0.4lf\t",m[i][j]);
			}
		}
		printf("\n");
	}
}

void llenarMatriz(uint8_t f, uint8_t c, double **m)
{
	for(uint8_t i = 0 ; i < f ; i++)
	{
		for(uint8_t j = 0 ; j < c ; j++)
		{
			printf("\nIngrese valor para M[%hhu][%hhu]: ",i+1,j+1);
			scanf("%lf",&m[i][j]);
		}
	}
}

void sumaDeMatrices(uint8_t f, uint8_t c, double **matrizA, double **matrizB, double **matrizSuma)
{
	for(uint8_t i=0;i<f;i++)
	{
		for(uint8_t j=0;j<c;j++)
		{
			matrizSuma[i][j]=matrizA[i][j]+matrizB[i][j];
		}
	}
}

void restaDeMatrices(uint8_t f, uint8_t c, double **matrizA, double **matrizB, double **matrizResta)
{
	for(uint8_t i=0;i<f;i++)
	{
		for(uint8_t j=0;j<c;j++)
		{
			matrizResta[i][j]=matrizA[i][j]-matrizB[i][j];
		}
	}
}

void productoDeMatrices(uint8_t filA, uint8_t columB, uint8_t n, double **matrizA, double **matrizB, double **matrizProducto) 
{
	for (uint8_t i = 0; i < filA; i++) 
	{
		for (uint8_t j = 0; j < columB; j++) 
		{
			matrizProducto[i][j] = 0;
			for (uint8_t k = 0; k < n; k++) 
			{
				matrizProducto[i][j] = matrizProducto[i][j] + matrizA[i][k] * matrizB[k][j];
			}
		}
	}
}

void matrizPorEscalar(double n, uint8_t f, uint8_t c, double **m, double **p)
{
	for(uint8_t i=0;i<f;i++)
	{
		for(uint8_t j=0;j<c;j++)
		{
			p[i][j]=n*m[i][j];
		}
	}
}

void identidad(uint8_t n, double **m)
{
	for(uint8_t i=0;i<n;i++)
	{
		for(uint8_t j=0;j<n;j++)
		{
			if(i==j)
			{
				m[i][j]=1;
			}
			else
			{
				m[i][j]=0;
			}
		}
	}
}

void guardarMatriz(double **matriz, uint8_t f, uint8_t c, const char *nombreArchivo)
{
	FILE *archivo;
	archivo=fopen(nombreArchivo,"wt");
	if (archivo == NULL) 
	{
		Beep(900,500);
		printf("No se pudo abrir el archivo.\n");
		exit(1); // Sale del programa.
	}
	// Escribir las dimensiones de la matriz en el archivo
	fprintf(archivo, "%hhu %hhu\n", f, c);
	// Escribir los elementos de la matriz en el archivo
	for (uint8_t i = 0; i < f; i++) 
	{
		for (uint8_t j = 0; j < c; j++) 
		{
			fprintf(archivo, "%lf ", matriz[i][j]);
		}
		fprintf(archivo, "\n");
	}
	fclose(archivo);
}

void leerDimensionesMatriz(const char *nombreArchivo, uint8_t *f, uint8_t *c)
{
	FILE *archivo = fopen(nombreArchivo, "rt");
	if (archivo == NULL) 
	{
		Beep(900,500);
		fprintf(stderr, "No se pudo abrir el archivo %s\n", nombreArchivo);
		exit(EXIT_FAILURE);
	}
	// Leer el número de filas y columnas desde el archivo
	fscanf(archivo, "%hhu %hhu", f, c);
	// Cerrar el archivo
	fclose(archivo);
}

void cargarMatriz(const char *nombreArchivo, double ***matriz, uint8_t *f, uint8_t *c)
{
	FILE *archivo = fopen(nombreArchivo, "rt");
	if (archivo == NULL) 
	{
		Beep(900,500);
		fprintf(stderr, "No se pudo abrir el archivo %s\n", nombreArchivo);
		exit(EXIT_FAILURE);
	}
	// Leer el número de filas y columnas desde el archivo
	fscanf(archivo, "%hhu %hhu", f, c);
	// Asignar memoria para la matriz
	(*matriz) = (double **)malloc(*f * sizeof(double *));
	for (uint8_t i = 0; i < *f; i++) 
	{
		(*matriz)[i] = (double *)malloc(*c * sizeof(double));
	}
	// Leer los elementos de la matriz desde el archivo
	for (uint8_t i = 0; i < *f; i++) 
	{
		for (uint8_t j = 0; j < *c; j++) 
		{
			fscanf(archivo, "%lf", &(*matriz)[i][j]);
		}
	}
	// Cerrar el archivo
	fclose(archivo);
}

double calcularDeterminante(uint8_t n, double **matriz)
{
	if (n == 1) 
	{
		return matriz[0][0];
	} 
	else if (n == 2) 
	{
		return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
	} 
	else 
	{
		double determinante = 0;
		uint8_t h, i, j;
		// SUBMATRIZ.
		double **submatriz = crearMatriz((n-1), (n-1));
		// Representa la submatriz que se obtiene al eliminar la primera fila y la columna h de la matriz original. 
		// Esto se hace para calcular el determinante de la submatriz.
		for (h = 0; h < n; h++) 
		{ // h representa las columnas de la matriz original que se eliminan para hacer la submatriz.
			for (i = 1; i < n; i++) 
			{ // i representa las filas de la submatriz, por eso arranca en 1 (porque se quitó la primera fila).
				for (j = 0; j < n; j++) 
				{ // j representa las columnas de la submatriz por eso arranca en cero y no puede ser igual que h porque la columna h-ésima se quitó.
					//Los bucles for anidados con variables i y j se utilizan para copiar los elementos de la matriz original matriz a la submatriz, 
					// excluyendo la primera fila y la columna h, 
					// "if (j < h)" para las columnas anteriores a h y "if (j > h)" para las columnas posteriores a h.
					if (j < h) 
					{
						submatriz[i - 1][j] = matriz[i][j];
					} 
					else if (j > h) 
					{
						submatriz[i - 1][j - 1] = matriz[i][j];
					}
				}
			}
			// Se verifica si h es par o impar con "if(h%2==0)". 
			// Esto se hace para aplicar la regla de los signos, donde los signos se alternan para cada columna.
			if (h % 2 == 0) 
			{
				determinante = determinante + (matriz[0][h] * calcularDeterminante(n - 1, submatriz));
			} 
			else 
			{
				determinante = determinante - (matriz[0][h] * calcularDeterminante(n - 1, submatriz));
			}
			// El resultado parcial se acumula en la variable determinante. Luego, el bucle continúa con la siguiente columna.
		}
		// Después de que el bucle for haya recorrido todas las columnas, la función devuelve el valor calculado en determinante, que es el determinante de la matriz original.
		liberarMatriz(submatriz, (n-1));
		return determinante;
	}
}

// Función para calcular la transpuesta de una matriz de tamaño filas x columnas
void transponerMatriz(double **matriz, double **transpuesta, uint8_t filas, uint8_t columnas) 
{
    for (uint8_t i = 0; i < filas; i++) 
	{
        for (uint8_t j = 0; j < columnas; j++) 
		{
            transpuesta[j][i] = matriz[i][j];
        }
    }
}

void calcularAdjunta(uint8_t n, double **matriz, double **adjunta) 
{
    if (n == 1) 
	{
        adjunta[0][0] = 1;
		return;
    }
	// SUBMATRIZ.
	double **submatriz = crearMatriz(n - 1, n - 1);
    uint8_t i,j,h;
	uint8_t sub_i,sub_j;
	uint8_t fila,columna;
	for (i = 0; i < n; i++) 
	{
        for (j = 0; j < n; j++) 
		{
            sub_i = 0;
			for (fila = 0; fila < n; fila++)
			{
				if(fila!=i)
				{
					sub_j = 0;
					for (columna = 0; columna < n; columna++)
					{
						if(columna!=j)
						{
							submatriz[sub_i][sub_j] = matriz[fila][columna];
							sub_j++;
						}
					}
					sub_i++;
				}
				
			}
            // Calcular el cofactor y almacenarlo en la adjunta
            double cofactor = calcularDeterminante(n - 1, submatriz);
			if ((i + j) % 2 == 0) 
			{
				adjunta[i][j] = cofactor;
			} 
			else 
			{
				adjunta[i][j] = -cofactor;
			}
        }
    }
    liberarMatriz(submatriz, n - 1);
}

void invertirMatriz(uint8_t n, double determinante, double** matriz, double** transpuesta, double** adjunta, double** inversa)
{
	transponerMatriz(matriz,transpuesta,n,n);
	calcularAdjunta(n,transpuesta,adjunta);
	matrizPorEscalar((1/determinante),n,n,adjunta,inversa);
}
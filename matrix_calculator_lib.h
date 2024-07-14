#pragma once

void mostrarMatriz(int f, int c, int **m);

void llenarMatriz(int f, int c, int **m);

void sumaDeMatrices(int f, int c, int **matrizA, int **matrizB, int **matrizSuma);

void restaDeMatrices(int f, int c, int **matrizA, int **matrizB, int **matrizResta);

void productoDeMatrices(int filA, int columB, int n, int **A, int **B, int **P);

void matrizPorEscalar(int n, int f, int c, int **m, int **p);

void identidad(int n, int **m);	

void guardarMatriz(int **matriz, int f, int c, const char *nombreArchivo);

void cargarMatriz(const char *nombreArchivo, int ***matriz, int *f, int *c);

int calcularDeterminante(int n, int **matriz);
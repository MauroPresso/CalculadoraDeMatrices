#pragma once

double** crearMatriz(int filas, int columnas);

void liberarMatriz(double **matriz, int filas);

void mostrarMatriz(int f, int c, double **m);

void llenarMatriz(int f, int c, double **m);

void sumaDeMatrices(int f, int c, double **matrizA, double **matrizB, double **matrizSuma);

void restaDeMatrices(int f, int c, double **matrizA, double **matrizB, double **matrizResta);

void productoDeMatrices(int filA, int columB, int n, double **A, double **B, double **P);

void matrizPorEscalar(double n, int f, int c, double **m, double **p);

void identidad(int n, double **m);	

void guardarMatriz(double **matriz, int f, int c, const char *nombreArchivo);

void cargarMatriz(const char *nombreArchivo, double ***matriz, int *f, int *c);

double calcularDeterminante(int n, double **matriz);

void transponerMatriz(double **matriz, double **transpuesta, int filas, int columnas);

void calcularAdjunta(int n, double **matriz, double **adjunta);
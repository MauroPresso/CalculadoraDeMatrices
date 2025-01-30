#pragma once
#include <stdint.h>

double** crearMatriz(uint8_t filas, uint8_t columnas);

void liberarMatriz(double **matriz, uint8_t filas);

void mostrarMatriz(uint8_t f, uint8_t c, double **m);

void llenarMatriz(uint8_t f, uint8_t c, double **m);

void sumaDeMatrices(uint8_t f, uint8_t c, double **matrizA, double **matrizB, double **matrizSuma);

void restaDeMatrices(uint8_t f, uint8_t c, double **matrizA, double **matrizB, double **matrizResta);

void productoDeMatrices(uint8_t filA, uint8_t columB, uint8_t n, double **A, double **B, double **P);

void matrizPorEscalar(double n, uint8_t f, uint8_t c, double **m, double **p);

void identidad(uint8_t n, double **m);	

void guardarMatriz(double **matriz, uint8_t f, uint8_t c, const char *nombreArchivo);

void leerDimensionesMatriz(const char *nombreArchivo, uint8_t *f, uint8_t *c);

void cargarMatriz(const char *nombreArchivo, double ***matriz, uint8_t *f, uint8_t *c);

double calcularDeterminante(uint8_t n, double **matriz);

void transponerMatriz(double **matriz, double **transpuesta, uint8_t filas, uint8_t columnas);

void calcularAdjunta(uint8_t n, double **matriz, double **adjunta);

void invertirMatriz(uint8_t n, double determinante, double** matriz, double** transpuesta, double** adjunta, double** inversa);
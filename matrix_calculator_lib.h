#pragma once
#include <stdint.h>

/** @file lib.h
 *  @brief Declaraciones de funciones para la manipulación de matrices dinámicas en una calculadora de matrices.
 */

/** @brief Muestra el menú de opciones en pantalla. */
void mostrarMenu(void);

/** @brief Obtiene la opción seleccionada del menú.
 *  @return Opción seleccionada.
 */
uint8_t obtenerOpcionMenu(void);

/** @brief Pregunta si se desea cargar una matriz.
 *  @return 1 si se desea cargar, 0 en caso contrario.
 */
uint8_t preguntaSiCargar(void);

/** @brief Pregunta dónde se desea cargar la matriz.
 *  @return Caracter que indica la ubicación de carga.
 */
char preguntaDondeCargar(void);

/** @brief Pregunta si se desea guardar una matriz.
 *  @return 1 si se desea guardar, 0 en caso contrario.
 */
uint8_t preguntaSiGuardar(void);

/** @brief Crea una matriz dinámica de tamaño especificado.
 *  @param filas Número de filas.
 *  @param columnas Número de columnas.
 *  @return Puntero a la matriz creada.
 */
double** crearMatriz(uint8_t filas, uint8_t columnas);

/** @brief Libera la memoria de una matriz dinámica.
 *  @param matriz Puntero a la matriz.
 *  @param filas Número de filas de la matriz.
 */
void liberarMatriz(double **matriz, uint8_t filas);

/** @brief Muestra una matriz en pantalla.
 *  @param f Número de filas.
 *  @param c Número de columnas.
 *  @param m Puntero a la matriz.
 */
void mostrarMatriz(uint8_t f, uint8_t c, double **m);

/** @brief Permite al usuario llenar una matriz con valores.
 *  @param f Número de filas.
 *  @param c Número de columnas.
 *  @param m Puntero a la matriz.
 */
void llenarMatriz(uint8_t f, uint8_t c, double **m);

/** @brief Guarda una matriz en un archivo.
 *  @param matriz Puntero a la matriz.
 *  @param f Número de filas.
 *  @param c Número de columnas.
 *  @param nombreArchivo Nombre del archivo de destino.
 */
void guardarMatriz(double **matriz, uint8_t f, uint8_t c, const char *nombreArchivo);

/** @brief Lee las dimensiones de una matriz desde un archivo.
 *  @param nombreArchivo Nombre del archivo de origen.
 *  @param f Puntero donde se almacenará el número de filas.
 *  @param c Puntero donde se almacenará el número de columnas.
 */
void leerDimensionesMatriz(const char *nombreArchivo, uint8_t *f, uint8_t *c);

/** @brief Carga una matriz desde un archivo.
 *  @param nombreArchivo Nombre del archivo de origen.
 *  @param matriz Puntero donde se almacenará la matriz cargada.
 *  @param f Puntero donde se almacenará el número de filas.
 *  @param c Puntero donde se almacenará el número de columnas.
 */
void cargarMatriz(const char *nombreArchivo, double ***matriz, uint8_t *f, uint8_t *c);

/** @brief Suma dos matrices.
 *  @param f Número de filas.
 *  @param c Número de columnas.
 *  @param matrizA Primera matriz.
 *  @param matrizB Segunda matriz.
 *  @param matrizSuma Matriz donde se almacenará el resultado.
 */
void sumaDeMatrices(uint8_t f, uint8_t c, double **matrizA, double **matrizB, double **matrizSuma);

/** @brief Resta dos matrices.
 *  @param f Número de filas.
 *  @param c Número de columnas.
 *  @param matrizA Primera matriz.
 *  @param matrizB Segunda matriz.
 *  @param matrizResta Matriz donde se almacenará el resultado.
 */
void restaDeMatrices(uint8_t f, uint8_t c, double **matrizA, double **matrizB, double **matrizResta);

/** @brief Multiplica dos matrices.
 *  @param filA Número de filas de la primera matriz.
 *  @param columB Número de columnas de la segunda matriz.
 *  @param n Dimensión compartida para la multiplicación.
 *  @param A Primera matriz.
 *  @param B Segunda matriz.
 *  @param P Matriz donde se almacenará el producto.
 */
void productoDeMatrices(uint8_t filA, uint8_t columB, uint8_t n, double **A, double **B, double **P);

/** @brief Multiplica una matriz por un escalar.
 *  @param n Escalar.
 *  @param f Número de filas.
 *  @param c Número de columnas.
 *  @param m Matriz original.
 *  @param p Matriz donde se almacenará el resultado.
 */
void matrizPorEscalar(double n, uint8_t f, uint8_t c, double **m, double **p);

/** @brief Calcula el determinante de una matriz cuadrada.
 *  @param n Tamaño de la matriz.
 *  @param matriz Matriz de entrada.
 *  @return Determinante de la matriz.
 */
double calcularDeterminante(uint8_t n, double **matriz);

/** @brief Calcula la transpuesta de una matriz.
 *  @param matriz Matriz de entrada.
 *  @param transpuesta Matriz donde se almacenará la transpuesta.
 *  @param filas Número de filas de la matriz original.
 *  @param columnas Número de columnas de la matriz original.
 */
void transponerMatriz(double **matriz, double **transpuesta, uint8_t filas, uint8_t columnas);

/** @brief Calcula la matriz adjunta.
 *  @param n Tamaño de la matriz.
 *  @param matriz Matriz de entrada.
 *  @param adjunta Matriz donde se almacenará la adjunta.
 */
void calcularAdjunta(uint8_t n, double **matriz, double **adjunta);

/** @brief Calcula la inversa de una matriz.
 *  @param n Tamaño de la matriz.
 *  @param determinante Determinante de la matriz.
 *  @param matriz Matriz de entrada.
 *  @param transpuesta Matriz transpuesta.
 *  @param adjunta Matriz adjunta.
 *  @param inversa Matriz donde se almacenará la inversa.
 */
void invertirMatriz(uint8_t n, double determinante, double** matriz, double** transpuesta, double** adjunta, double** inversa);

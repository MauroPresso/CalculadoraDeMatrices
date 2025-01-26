#include "matrix_calculator_lib.h"
#include "calculation_options_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char option_selector(char* op)
{
    do{
		printf("\n\nSr Usuario, ingrese que operacion desea realizar:\na. Suma de matrices.\nb. Resta de matrices.\nc. Multiplicacion entre matrices.\nd. Multiplicacion entre matriz y un escalar.\ne. Matriz identidad.\nf. Determinante de una matriz.\ng. Matriz Transpuesta.\nh. Matriz Adjunta.\ni. Matriz Inversa.\nj. Salir del programa\n\n");
		scanf("%c",&op);
		fflush(stdin);
		if(op!='a' && op!='b' && op!='c' && op!='d' && op!='e' && op!='f' && op!='g')
		{
            Beep(900,500);
		}
	} while(op!='a' && op!='b' && op!='c' && op!='d' && op!='e' && op!='f' && op!='g' && op!='h' && op!='i' && op!='j');
    return op;
}

int ask_for_saving(int* preguntaGuardar)
{
   
	do{
		printf("\nSr Usuario: si usted desea usted GUARDAR la matriz resultado en un archivo, ingrese '1'. Caso contrario, ingrese '0': ");
		scanf("%d",&preguntaGuardar);
		fflush(stdin);
		printf("\nADVERTENCIA: Solo se puede GUARDAR en un archivo la matriz resultado.");
		Beep(900,500);
		if(preguntaGuardar!=0 && preguntaGuardar!=1)
		{
			Beep(900,500);
		}
	} while(preguntaGuardar!=0 && preguntaGuardar!=1);
    return preguntaGuardar;
}

void opcion_suma(int preguntaGuardar)
{
    banderaPositivos=0;
	do{
		printf("\nADVERTENCIA: Si desea CARGAR la matriz resultado de un archivo mas adelante, la cantidad de filas y de columnas de las matrices a sumar deben coincidir con las dimensiones de la matriz resultado del archivo.");
		Beep(900,500);
		printf("\nIngrese el numero de filas: ");
		scanf("%d",&filas); 
		printf("Ingrese el numero de columnas: ");
		scanf("%d",&columnas);
		if(filas>0 && columnas>0)
        {
			banderaPositivos=1;
		}
		else
        {
			printf("\nEl numero de filas y de columnas deben ser positivos\n");
		    Beep(900,500);
		}
	} while(banderaPositivos==0);
	printf("\n\n");
	// MATRIZ A.
	double **A = crearMatriz(filas, columnas);
	// MATRIZ B.
	double **B = crearMatriz(filas, columnas);
	// MATRIZ R.
	double **R = crearMatriz(filas, columnas);
	// Pregunta si quiere cargar.
	do{
		printf("\nSr Usuario: si usted desea usted CARGAR la matriz resultado de un archivo ahora, ingrese '1'. Caso contrario, ingrese '0': ");
		Beep(900,500);
		scanf("%d",&preguntaCargar);
		fflush(stdin);
		if(preguntaCargar!=0 && preguntaCargar!=1)
		{
			Beep(900,500);
		}
	} while(preguntaCargar!=0 && preguntaCargar!=1);
	if(preguntaCargar==0)
	{
		printf("\nIngrese los coeficientes para la matriz A:\n");
		llenarMatriz(filas,columnas,A);
	}
	if(preguntaCargar==1)
	{
		cargarMatriz("matrizResultado.txt",&A,&filas,&columnas);
	}
	//llamar a sus funciones
	printf("\nIngrese los coeficientes para la matriz B:\n");
	llenarMatriz(filas,columnas,B);
	printf("\nMatriz A:\n");
	mostrarMatriz(filas,columnas,A);
	printf("\nMatriz B:\n");
	mostrarMatriz(filas,columnas,B);
	sumaDeMatrices(filas,columnas,A,B,R);
	printf("\nMatriz SUMA:\n");
	mostrarMatriz(filas,columnas,R);
	if(preguntaGuardar==1)
	{
		guardarMatriz(R,filas,columnas,"matrizResultado.txt");
	}
	// Libero memoria dinámica
	liberarMatriz(A, filas);
    liberarMatriz(B, filas);
	liberarMatriz(R, filas);
}
#include "matrix_calculator_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() 
{
	int N;
	int filas,columnas;
	int banderaPositivos;
	int preguntaGuardar;
	int preguntaCargar;
	char op;
	do{
		// Pregunta por la operación.
		do{
			printf("\n\nSr Usuario, ingrese que operacion desea realizar:\na. Suma de matrices.\nb. Resta de matrices.\nc. Multiplicacion entre matrices.\nd. Multiplicacion entre matriz y un escalar.\ne. Matriz identidad.\nf. Determinante de una matriz.\ng. Matriz Transpuesta.\nh. Matriz Adjunta.\ni. Matriz Inversa.\nj. Salir del programa\n\n");
			scanf("%c",&op);
			fflush(stdin);
			if(op!='a' && op!='b' && op!='c' && op!='d' && op!='e' && op!='f' && op!='g')
			{
				Beep(900,500);
			}
		} while(op!='a' && op!='b' && op!='c' && op!='d' && op!='e' && op!='f' && op!='g' && op!='h' && op!='i' && op!='j');
		// Pregunta si quiere guardar.
		if(op=='a' || op=='b' || op=='c' || op=='d' || op=='e' || op=='f' || op=='g' || op=='h' || op=='i')
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
		}
		
		if(op=='a')
		{
			banderaPositivos=0;
			do{
				printf("\nADVERTENCIA: Si desea CARGAR la matriz resultado de un archivo mas adelante, la cantidad de filas y de columnas de las matrices a sumar deben coincidir con las dimensiones de la matriz resultado del archivo.");
				Beep(900,500);
				printf("\nIngrese el numero de filas: ");
				scanf("%d",&filas); 
				printf("Ingrese el numero de columnas: ");
				scanf("%d",&columnas);
				if(filas>0 && columnas>0){
					banderaPositivos=1;
				}
				else{
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
			do
			{
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
		if(op=='b')
		{
			banderaPositivos=0;
			do{
				printf("\nADVERTENCIA: Si desea CARGAR la matriz resultado de un archivo mas adelante, la cantidad de filas y de columnas de las matrices a restar deben coincidir con las dimensiones de la matriz resultado del archivo.");
				Beep(900,500);
				printf("\nIngrese el numero de filas: ");
				scanf("%d",&filas); 
				printf("Ingrese el numero de columnas: ");
				scanf("%d",&columnas);
				if(filas>0 && columnas>0){
					banderaPositivos=1;
				}
				else{
					Beep(900,500);
					printf("El numero de filas y de columnas deben ser positivos\n");
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
			if(preguntaCargar==0){
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
			restaDeMatrices(filas,columnas,A,B,R);
			printf("\nMatriz RESTA (A - B):\n");
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
		if(op=='c')
		{
			int filasA, columnasB;
			banderaPositivos=0;
			do{
				printf("\nADVERTENCIA: Si desea CARGAR en la matriz a multiplicar la matriz resultado de un archivo mas adelante, la cantidad de filas y de columnas de la 1ra matriz a multiplicar debe coincidir con la cantidad de filas y de columnas de la matriz resultado del archivo.");
				Beep(900,500);
				printf("\nIngrese el numero de filas de la matriz A: ");
				scanf("%d",&filasA);
				printf("Ingrese el numero de columnas de la matriz A y el numero de filas de la matriz B: ");
				scanf("%d",&N);
				printf("Ingrese el numero de columnas de la matriz B: ");
				scanf("%d",&columnasB);
				if(filasA>0 && columnasB>0 && N>0){
					banderaPositivos=1;
				}
				else
				{
					printf("Los valores ingresados deben ser todos positivos");
					Beep(900,500);
				}
			} while(banderaPositivos==0);
			printf("\n\n");
			// MATRIZ A.
			double **A = crearMatriz(filasA, N);
			// MATRIZ B.
			double **B = crearMatriz(N, columnasB);
			// MATRIZ R.
			double **R = crearMatriz(filasA, columnasB);
			// Pregunta si quiere cargar.
			do{
				printf("\nSr Usuario: si usted desea usted CARGAR la matriz resultado de un archivo ahora, ingrese '1'. Caso contrario, ingrese '0': ");
				Beep(900,500);
				scanf("%d",&preguntaCargar);
				if(preguntaCargar!=0 && preguntaCargar!=1)
				{
					Beep(900,500);
				}
			} while(preguntaCargar!=0 && preguntaCargar!=1);
			if(preguntaCargar==0){
				printf("\nIngrese los coeficientes para la matriz A:\n");
				llenarMatriz(filasA,N,A);
			}
			if(preguntaCargar==1)
			{
				cargarMatriz("matrizResultado.txt",&A,&filasA,&N);
			}
			//llamar a sus funciones
			printf("\nIngrese los coeficientes para la matriz B:\n");
			llenarMatriz(N,columnasB,B);
			printf("\nMatriz A:\n");
			mostrarMatriz(filasA,N,A);
			printf("\nMatriz B:\n");
			mostrarMatriz(N,columnasB,B);
			productoDeMatrices(filasA,columnasB,N,A,B,R);
			printf("\nMatriz PRODUCTO:\n");
			mostrarMatriz(filasA,columnasB,R);
			if(preguntaGuardar==1)
			{
				guardarMatriz(R,filasA,columnasB,"matrizResultado.txt");
			}
			// Libero memoria dinámica
			liberarMatriz(A, filasA);
			liberarMatriz(B, N);
			liberarMatriz(R, filasA);
		}
		if(op=='d')
		{
			banderaPositivos=0;
			do{
				printf("\nADVERTENCIA: Si desea CARGAR la matriz resultado de un archivo mas adelante, la cantidad de filas y de columnas de las matriz a multiplicar deben coincidir con las dimensiones de la matriz resultado del archivo.");
				Beep(900,500);
				printf("Ingrese la cantidad de filas de la matriz: ");
				scanf("%d",&filas);
				printf("Ingrese la cantidad de columnas de la matriz: ");
				scanf("%d",&columnas);
				if(filas>0 && columnas>0){
					banderaPositivos=1;
				}
				else{
					printf("La cantidad de filas y columnas de una matriz deben ser siempre positivos.\n.");
					Beep(900,500);
				}
			} while(banderaPositivos==0);
			// MATRIZ A.
			double **A = crearMatriz(filas, columnas);
			// MATRIZ R.
			double **R = crearMatriz(filas, columnas);
			// Escalar
			double escalar;
			printf("\nIngrese un escalar:\n");
			scanf("%lf",&escalar);
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
			if(preguntaCargar==0){
				printf("\nIngrese los coeficientes para la matriz A:\n");
				llenarMatriz(filas,columnas,A);
			}
			if(preguntaCargar==1)
			{
				cargarMatriz("matrizResultado.txt",&A,&filas,&columnas);
			}
			//llamar a sus funciones.
			printf("\nMatriz A:\n");
			mostrarMatriz(filas,columnas,A);
			matrizPorEscalar(escalar,filas,columnas,A,R);
			printf("\nEl producto entre la matriz y el escalar es:\n");
			mostrarMatriz(filas,columnas,R);
			if(preguntaGuardar==1)
			{
				guardarMatriz(R,filas,columnas,"matrizResultado.txt");
			}
			// Libero memoria dinámica
			liberarMatriz(A, filas);
			liberarMatriz(R, filas);
		}
		if(op=='e')
		{
			do{
				printf("\nIngrese un orden para la matriz identidad:\n");
				scanf("%d",&N);
			} while(N<=0);
			// MATRIZ IDENTIDAD.
			double **R = crearMatriz(N, N);
			//llamar a sus funciones.
			identidad(N,R);
			printf("\nMatriz IDENTIDAD:\n");
			mostrarMatriz(N,N,R);
			if(preguntaGuardar==1)
			{
				guardarMatriz(R,N,N,"matrizResultado.txt");
			}
			// Libero memoria dinamica
			liberarMatriz(R, N);
		}
		if(op=='f')
		{
			do {
				printf("\nADVERTENCIA: Si desea CARGAR una matriz de un archivo mas adelante, la matriz debe ser CUADRADA y luego debe ingresar su orden.\n");
				Beep(900,500);
				printf("Ingrese el orden de la matriz (debe ser estrictamente positivo): ");
				scanf("%d", &N);
				if(N <= 0)
				{
					Beep(900,500);
				}
			} while (N <= 0);
			printf("\n\n");
			// MATRIZ A.
			double **A = crearMatriz(N, N);
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
			if(preguntaCargar==0){
				printf("\nIngrese los coeficientes para la matriz A:\n");
				llenarMatriz(N,N,A);
			}
			if(preguntaCargar==1)
			{
				cargarMatriz("matrizResultado.txt",&A,&N,&N);
			}
			printf("\nMatriz A:\n");
			mostrarMatriz(N,N,A);
			double det;
			det = calcularDeterminante(N,A); 
			printf("\n\nEl determinante de la matriz es: %0.4lf\n", det);
			// Libero la memoria dinámica.
			liberarMatriz(A, N);
		}
		if(op=='g')
		{
			banderaPositivos=0;
			do{
				printf("\nADVERTENCIA: Si desea CARGAR la matriz resultado de un archivo mas adelante, la cantidad de filas y de columnas de las matriz a multiplicar deben coincidir con las dimensiones de la matriz resultado del archivo.\n");
				Beep(900,500);
				printf("\nIngrese la cantidad de filas de la matriz: ");
				scanf("%d",&filas);
				printf("\nIngrese la cantidad de columnas de la matriz: ");
				scanf("%d",&columnas);
				if(filas>0 && columnas>0){
					banderaPositivos=1;
				}
				else{
					printf("\nLa cantidad de filas y columnas de una matriz deben ser siempre positivos.\n.");
					Beep(900,500);
				}
			} while(banderaPositivos==0);
			// MATRIZ A.
			double **A = crearMatriz(filas, columnas);
			// MATRIZ R.
			double **T = crearMatriz(columnas, filas);
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
			if(preguntaCargar==0){
				printf("\nIngrese los coeficientes para la matriz A:\n");
				llenarMatriz(filas,columnas,A);
			}
			if(preguntaCargar==1)
			{
				cargarMatriz("matrizResultado.txt",&A,&filas,&columnas);
			}
			//llamar a sus funciones.
			printf("\nMatriz A:\n");
			mostrarMatriz(filas,columnas,A);
			transponerMatriz(A,T,filas,columnas);
			printf("\nLa matriz transpuesta de A es:\n");
			mostrarMatriz(columnas,filas,T);
			if(preguntaGuardar==1)
			{
				guardarMatriz(T,filas,columnas,"matrizResultado.txt");
			}
			// Libero memoria dinámica
			liberarMatriz(A, filas);
			liberarMatriz(T, columnas);
		}
		if(op=='h')
		{
			do {
				printf("\nADVERTENCIA: Si desea CARGAR una matriz de un archivo mas adelante, la matriz debe ser CUADRADA y luego debe ingresar su orden.\n");
				Beep(900,500);
				printf("Ingrese el orden de la matriz (debe ser estrictamente positivo): ");
				scanf("%d", &N);
				if(N <= 0)
				{
					Beep(900,500);
				}
			} while (N <= 0);
			printf("\n\n");
			// MATRIZ M.
			double **M = crearMatriz(N, N);
			// MATRIZ A.
			double **A = crearMatriz(N, N);
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
			if(preguntaCargar==0){
				printf("\nIngrese los coeficientes para la matriz M:\n");
				llenarMatriz(N,N,M);
			}
			if(preguntaCargar==1)
			{
				cargarMatriz("matrizResultado.txt",&M,&N,&N);
			}
			printf("\nMatriz M:\n");
			mostrarMatriz(N,N,M);
			calcularAdjunta(N,M,A);
			printf("\nLa matriz adjunta de M es:\n");
			mostrarMatriz(N,N,A);
			if(preguntaGuardar==1)
			{
				guardarMatriz(A,filas,columnas,"matrizResultado.txt");
			}
			// Libero memoria dinámica
			liberarMatriz(M, filas);
			liberarMatriz(A, filas);
		}
		if(op=='i')
		{
			do {
				printf("\nADVERTENCIA: Si desea CARGAR una matriz de un archivo mas adelante, la matriz debe ser CUADRADA y luego debe ingresar su orden.\n");
				Beep(900,500);
				printf("Ingrese el orden de la matriz (debe ser estrictamente positivo): ");
				scanf("%d", &N);
				if(N <= 0)
				{
					Beep(900,500);
				}
			} while (N <= 0);
			printf("\n\n");
			// MATRIZ M.
			double **M = crearMatriz(N, N);
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
			if(preguntaCargar==0){
				printf("\nIngrese los coeficientes para la matriz M:\n");
				llenarMatriz(N,N,M);
			}
			if(preguntaCargar==1)
			{
				cargarMatriz("matrizResultado.txt",&M,&N,&N);
			}
			printf("\nMatriz M:\n");
			mostrarMatriz(N,N,M);
			double det;
			det = calcularDeterminante(N,M); 
			if(det==0)
			{
				printf("El determinante es cero. Por lo tanto, la matriz es inversible");
			}
			else
			{
				// MATRIZ T.
				double **T = crearMatriz(N, N);
				// MATRIZ T.
				double **A = crearMatriz(N, N);
				// MATRIZ I.
				double **I = crearMatriz(N, N);
				invertirMatriz(N,det,M,T,A,I);
				printf("\nLa matriz inversa de M es:\n");
				mostrarMatriz(N,N,I);
				// Libero la memoria dinámica
				liberarMatriz(T, N);
				liberarMatriz(A, N);
				liberarMatriz(I, N);
			}
			// Libero la memoria dinámica
			liberarMatriz(M, N);
		}
	} while(op!='j');
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <conio.h>
#define ESC 27

void mostrarMenu ();
int cargarArregloEnteros (int A[], int dimension);
void mostrarArregloEnteros (int A[], int dimension);
int sumarElementos (int A[], int validos);
void pasarElementos (int A[], int validos, Pila *dada);
int cargarArregloReal (float A[], int dim);
void mostrarArregloReal (float a[], int dimension);
float sumaArregloReales (float A[], int cant);
void mostrarArregloChar (char C[], int validos);
int buscarElemento (char C[], int validos, int dato);
void funcionBuscaElemento (char a[], int v);
int insertaChar (char C[], int v);
char buscaMaximoChar (char C[], int dimension);
int capicua (int C[], int validos);
void invertirArregloInt (int A[], int validos);
int buscaPosMenor (int A[], int v, int c);
void ordenPorSeleccion (int A[], int validos);
int insertarElemento ();
void ordenPorInsercion (int A[], int v);
void ordenArreglosChar (char A[], char B[], char C[], int validosA, int validosB, int validosC);

const int dimension = 20;

int main()
{
    int arregloEnteros [dimension];
    float arregloReal [100];
    float sumaReales=0;
    int ejercicio, option, cantidad=0, sum=0, elemento=0, cantidadreales=0;
    char texto[10] = "abrcdkwkfs";
    char textoOrdenado [7] = "adgkmq";
    char arregloOrdenado [5] = "cegkp";
    char arregloOrdenado2 [5] = "bfior";
    char arregloFinal [10];
    Pila dada;
    inicpila(&dada);

    do {
        system("cls");
        mostrarMenu();
        scanf("%d", &ejercicio);
        switch (ejercicio) {
            case 1:
                cantidad = cargarArregloEnteros(arregloEnteros, dimension);
                break;
            case 2:
                mostrarArregloEnteros(arregloEnteros, cantidad);
                break;
            case 3:
                sum = sumarElementos(arregloEnteros, cantidad);
                printf("\nLa suma de los elementos es de %d", sum);
                break;
            case 4:
                pasarElementos(arregloEnteros, cantidad, &dada);
                printf("\nLa pila dada contiene los elementos: \n");
                mostrar(&dada);
                break;
            case 5:
                cantidadreales = cargarArregloReal(arregloReal, 100);
                mostrarArregloReal(arregloReal, cantidadreales);
                sumaReales = sumaArregloReales(arregloReal, cantidadreales);
                printf("\nLa suma del arreglo de reales es de: %.2f", sumaReales);
                break;
            case 6:
                funcionBuscaElemento(texto, 10);
                mostrarArregloChar(texto, 10);
                break;
            case 7:
                insertaChar(textoOrdenado, 6);
                mostrarArregloChar(textoOrdenado, 7);
                break;
            case 8:
                printf("\nEl maximo del arreglo char es: %c", buscaMaximoChar(texto, 10));
                mostrarArregloChar(texto, 10);
                break;
            case 9:
                mostrarArregloEnteros(arregloEnteros, cantidad);
                if ( capicua(arregloEnteros, cantidad) == 1){
                    printf("\nEs capicua\n");
                } else {
                    printf("\nNo es capicua\n");
                }
                break;
            case 10:
                mostrarArregloEnteros(arregloEnteros, cantidad);
                invertirArregloInt(arregloEnteros, cantidad);
                mostrarArregloEnteros(arregloEnteros, cantidad);
                break;
            case 11:
                ordenPorSeleccion(arregloEnteros, cantidad);
                mostrarArregloEnteros(arregloEnteros, cantidad);
                break;
            case 12:
                ordenPorInsercion(arregloEnteros, cantidad);
                mostrarArregloEnteros(arregloEnteros, cantidad);
                break;
            case 13:
                ordenArreglosChar(arregloOrdenado, arregloOrdenado2, arregloFinal, 5, 5, 10);
                mostrarArregloChar(arregloFinal, 10);
                break;
            default:
                printf("\nOpcion incorrecta\n");
        }
        printf("\n\t\t\tAprete un boton para continuar...\n\n");
        printf("\t\t\tPresione ESC para salir...");
        option=getch();
    } while (option!=ESC);

    return 0;
}

/// Menu del switch

void mostrarMenu ()
{
    printf("\n\t\t\tTRABAJO PRACTICO NUMERO 4\n\n");
    printf("1) Cargar arreglo de enteros\n");
    printf("2) Mostrar arreglo de enteros\n");
    printf("3) Sumar arreglo de enteros\n");
    printf("4) Pasar los elementos de un arreglo a una pila\n");
    printf("5) Cargar un arreglo de reales, mostrarlo y sumar sus elementos\n");
    printf("6) Buscar si una letra esta en un arreglo char\n");
    printf("7) Insertar una letra en un arreglo de char ordenado\n");
    printf("8) Buscar el maximo de un arreglo char\n");
    printf("9) El arreglo de enteros es capicua ?\n");
    printf("10) Invertir el arreglo de enteros\n");
    printf("11) Ordenar por seleccion el arreglo de enteros\n");
    printf("12) Ordenar por insercion el arreglo de enteros\n");
    printf("13) Ordenar dos arreglos de char e intercalarlos en uno nuevo\n");

}

/// EJERCICIO 1. Cargar un arreglo por teclado

int cargarArregloEnteros (int A[], int dimension)
{
    int i=0;
    char control='s';

    while (i<dimension && control == 's') {
        printf("\nCargando el arreglo de enteros\n");
        printf("\nIngrese un valor: ");
        scanf("%d", &A[i]);
        i++;
        system("cls");
        printf("\nDesea ingresar otro elemento?(s/n)\n");
        fflush(stdin);
        scanf("%c", &control);
    }
    return i;
}

/// EJERCICIO 2. Mostrar el arreglo cargado.

void mostrarArregloEnteros (int A[], int validos)
{
    int i=0;

    printf("\nContenido del arreglo: \n");

    while (i<validos)
    {
        printf("|%d|", A[i]);
        i++;
    }
}

/// EJERCICIO 3. Sumar los elementos del arreglo.

int sumarElementos (int A[], int validos)
{
    int i=0, suma=0;

    while (i<validos) {
        suma = suma + A[i];
        i++;
    }
    return suma;
}

/// EJERCICIO 4. Pasar los elementos del arreglo a una pila.

void pasarElementos (int A[], int validos, Pila *dada)
{
    int i=0;

    while (i<validos) {
        apilar(dada, A[i]);
        i++;
    }
}

/// EJERCICIO 5.

/// Cargar un arreglo de reales.

int cargarArregloReal (float A[], int dim)
{
    int i=0;
    char control = 's';

    while (control== 's' && i<dim)
    {
        printf("\nIngrese un real al arreglo: \n");
        scanf("%f", &A[i]);
        i++;
        system("cls");
        printf("\Desea ingresar otro elemento? (s/n)\n");
        fflush(stdin);
        scanf("%c", &control);
    }
    return i;
}

/// Mostrar arreglo de real

void mostrarArregloReal (float a[], int validos)
{
    int i=0;
    printf("\nContenido del arreglo: \n");
    while (i<validos)
    {
        printf("|%.2f|", a[i]);
        i++;
    }
}

/// Sumar los elementos del arreglo de reales.

float sumaArregloReales (float A[], int cant)
{
    int i=0;
    float suma=0;

    while (i<cant){
        suma = suma + A[i];
        i++;
    }
    return suma;
}

/// EJERCICIO 6.

/// Mostrar arreglo de char.

void mostrarArregloChar (char C[], int validos)
{
    int i=0;

    printf("\nContenido del arreglo: \n");

    while (i<validos)
    {
        printf("|%c|", C[i]);
        i++;
    }
}

/// Buscar un elemento en el arreglo de char

int buscarElemento (char C[], int validos, int dato)
{
    int i=0;
    int flag=0;

    while (i<validos && flag == 0) {
        if (C[i] == dato) {
            flag = 1;
        } else {
            i++;
        }
    }
    return flag;
}

void funcionBuscaElemento (char a[], int v)
{
    int buscado;
    char letra;

    printf("\nIngrese la letra que desea buscar: \n");
    fflush(stdin);
    scanf("%c", &letra);

    buscado = buscarElemento(a, v, letra);

    if (buscado) {
        printf("\n El elemento %c se encuentra en el arreglo\n", letra);
    } else {
        printf("\n El elemento %c NO se encuentra en el arreglo\n", letra);
    }
}

/// EJERCICIO 7.

/// Insertar una letra en un arreglo ordenado.

int insertaChar (char C[], int v)
{
    int i = v - 1;
    char letra;

    printf("\nIngrese la letra que desea incluir en el arreglo: \n");
    fflush(stdin);
    scanf("%c", &letra);

    while (i>=0 && letra<C[i]) {
        C[i+1] = C[i];
        i--;
    }
    C[i+1] = letra;

    return v+1;
}

/// EJERCICIO 8.

/// Obtener el maximo caracter de un arreglo dado.

char buscaMaximoChar (char C[], int dimension)
{
    int i=0;
    char elemento;
    char aux;

    elemento = C[i];

    for (i=1; i<dimension; i++) {
        if (elemento<C[i]) {
            elemento = C[i];
        }
    }
    return elemento;
}

/// EJERCICIO 9.

/// Averiguar si el arreglo es capicua.

int capicua (int C[], int validos)
{
    int i=0;
    int v = validos - 1;
    int flag=1;

    while (i<=v && flag==1){
        if (C[i]==C[v]){
            flag=1;
        } else {
            flag=0;
        }
        i++;
        v--;
    }
    return flag;
}

/// EJERCICIO 10.

/// Invierte los elementos del arreglo.

void invertirArregloInt (int A[], int validos)
{
    int i=0;
    int v = validos - 1;
    int aux;

    for (i=0; i<(validos/2); i++) {
        aux = A[i];
        A[i] = A[v];
        A[v] = aux;
        v--;
    }
}

/// EJERCICIO 11.

/// Ordenar el arreglo por seleccion.

int buscaPosMenor (int A[], int v, int c)  /// Le paso con la variable c, el comienzo del arreglo (o sea cero)
{
    int menor= A[c];    /// Guarda el menor elemento
    int posMenor = c;   /// Guarda la posicion del menor elemento
    int i=c+1;          /// Arranca desde 1.

    while (i<v){
        if (A[i]<menor) {
            menor = A[i];   /// Guardo el valor del arreglo
            posMenor=i;     /// Guardo la posicion del menor
        }
        i++;
    }
    return posMenor;
}

/// Ordenar el arreglo de enteros por seleccion.

void ordenPorSeleccion (int A[], int validos)
{
    int i=0;
    int aux=0;
    int pos = 0;

    while (i<validos) {
        pos = buscaPosMenor(A, validos, i);
        aux = A[i];
        A[i] = A[pos];
        A[pos] = aux;
        i++;
    }
}

/// Ordenar por insercion.

/// Elemento a insertar
int insertarElemento ()
{
    int elemento=0;

    printf("\nIngrese el elemento a insertar al arreglo: \n");
    scanf("%d", &elemento);

    return elemento;
}

/// v es la ultima posicion.
void ordenPorInsercion (int A[], int v)
{
    int i = v;
    int dato;
    ordenPorSeleccion(A, v);
    dato = insertarElemento();

    while (i>=0 && A[i]>dato) {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = dato;
}

/// EJERCICIO 12.

void ordenArreglosChar (char A[], char B[], char C[], int validosA, int validosB, int validosC)
{
    int i=0, j=0, n=0;

    while (i<validosA && j<validosB && n<validosC) {
        if (A[i]<=B[j]) {
            C[n] = A[i];
            i++;
        } else {
            C[n] = B[j];
            j++;
        }
        n++;
    }

    if (n<validosC && i>j) {
        C[n] = B[j];
    } else {
        C[n] = A[i];
    }
}

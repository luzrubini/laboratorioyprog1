#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alumnos.h"

#define TAM 5
char mostrarMenu(char[]);


int main()
{
    int legajo[TAM]= {1,2,3,4,5}, nota1[TAM]= {5,8,4,9,7}, nota2[TAM]= {3,4,9,5,7};
    float promedio[TAM]= {4,6,6.5,4,8};
    char nombre[TAM][50]= {"Luis", "Maria","Jose", "Alberto", "Roberto"};
    int i;

    char opcion;

    do
    {
        opcion = mostrarMenu("\n1.Alta\n2.Mostrar\n3.Bajas\n4.Modificar\n5.Ordenar\n6.Salir.Elija una opcion: ");
        switch(opcion)
        {
            case '1':
                altaAlumno(legajo, nombre, nota1, nota2, promedio, TAM);
                break;
            case '2':
                mostrarAlumnos(legajo, nombre, nota1, nota2, promedio, TAM);
                break;
            case '3':
                eliminarAlumno(legajo, nombre, nota1, nota2, promedio, TAM);
                break;
            case '4':
                modificarAlumno(legajo, nombre, nota1, nota2, promedio, TAM);
                break;
            case '5':
                ordenarAlumnos(legajo, nombre, nota1, nota2, promedio, TAM);
                break;
        }
    }
    while(opcion!='6');

    return 0;
}

char mostrarMenu(char texto[])
{
    char opcion;
    printf("%s", texto);
    opcion = getche();
    return opcion;
}


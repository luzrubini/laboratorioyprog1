#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Alumnos.h"

#define TAM 6


char mostrarMenu(char[]);


int main()
{

   char opcion;
   eAlumno lista[TAM];
   int i;
   for(i=0;i<TAM;i++)
   {
       lista[i].estado=0;
   }


    do
    {
        opcion = mostrarMenu("\n1.Alta\n2.Mostrar\n3.Bajas\n4.Modificar\n5.Ordenar\n6.Salir.Elija una opcion: ");

        switch(opcion)
        {
            case '1':
                /*altaAlumno(lista, TAM);*/
                inicializarAlumno(lista,TAM);
                break;
                /*
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
                break;*/
        }


    }while(opcion!='6');

    return 0;
}

char mostrarMenu(char texto[])
{
    char opcion;
    printf("%s", texto);
    opcion = getche();
    return opcion;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "funcionesMostrar.h"
#include "funcionesABM.h"
#include "funcionesValidacion.h"
#define TAMI 5
#define TAMC 10
#define TAMCI 10

int main()
{
    system("color 0f");
    char seguir='s';
    int opcion;

    eInterprete interprete[TAMI];
    eCancion cancion [TAMC];
    eCancionInterprete cancionInterprete[TAMCI];
    inicializarEstados(interprete,cancion,cancionInterprete,TAMI,TAMC);

    while(seguir=='s')
    {
        printf("1- Agregar Interprete\n");
        printf("2- Agregar Cancion\n");
        printf("3- Imprimir lista de canciones\n");
        printf("4- Imprimir lista de interpretes\n");
        printf("5- Imprimir lista de canciones por interprete\n");
        printf("6- Borrar Interprete\n");
        printf("7- Borrar Cancion\n");
        printf("8- Modificar interprete\n");
        printf("9- Modificar Cancion\n");
        printf("10- Mostrar canciones de artistas argentinos\n");
        printf("11- Mostrar duracion total de canciones por artista\n");
        printf("12- Mostrar artista con mas canciones\n");
        printf("13- Salir\n");

        scanf("%d",&opcion);


        switch(opcion)
        {
            case 1:
                //altaInterprete(interprete,TAMI);
                inicializarInterprete(interprete,TAMI);
                break;
            case 2:
                //altaCancion(cancion,TAMC);
                inicializarCancion(cancion,TAMC);
                break;
            case 3:
                system("cls");
                 mostrarCancion(cancion,interprete,TAMC,TAMI);
                break;
            case 4:
                system("cls");
                mostrarInterprete(interprete, TAMI);
                break;
            case 5:
                system("cls");
                mostrarCancionPorInterprete(interprete,cancion,TAMC,TAMI);
                break;
            case 6:
                system("cls");
                borrarInterprete(interprete,TAMI);
                break;
            case 7:
                system("cls");
                borrarCancion(cancion,TAMC);
                break;
            case 8:
                system("cls");
                modificarInterprete(interprete,TAMI);
                break;
            case 9:
                system("cls");
                modificarCancion(cancion,TAMC);
                break;
            case 10:
                system("cls");
                mostrarCancionesArgentinos(cancion,interprete,TAMC,TAMI);
                break;
            case 11:
                mostrarDuracionPorInterprete(interprete,cancion,TAMC,TAMI);
                break;
            case 12:
                InterpreteConMasCanciones(interprete,cancion,TAMC,TAMI);
                break;
            case 13:
                seguir = 'n';
                break;
        }

        system("pause");
        system("cls");
    }

    return 0;
}







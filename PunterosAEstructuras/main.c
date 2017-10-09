#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 5

int main()
{
    system("color 0f");
    char seguir='s';
    int opcion;
    ePersona persona[TAM];

    while(seguir=='s')
    {
        printf("1- Alta Persona\n");
        printf("2- Modificar datos Persona\n");
        printf("3- Baja Persona\n");
        printf("4- Ordenar/Mostrar Persona\n");
        printf("5- Salir\n");
        scanf("%d",&opcion);
        while(opcion<1 || opcion>5)
        {
            printf("Error! Ingrese una opcion valida: ");
            scanf("%d",&opcion);
        }
        switch(opcion)
        {
            case 1:
                cargarPersona(&persona,TAM);
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                seguir = 'n';
                break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}

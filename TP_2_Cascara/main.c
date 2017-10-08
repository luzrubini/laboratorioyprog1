#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 6


int main()
{
    char seguir='s';
    int opcion=0;
    EPersona Persona[TAM];
    inicializarEstado(Persona,TAM);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);


        switch(opcion)
        {
            case 1:
                altaPersona(Persona,TAM);
                //inicializarPersona(Persona,TAM);
                break;

            case 2:
                //borrarPersona(Persona,TAM);
                break;
            case 3:
                ordenarPersonas(Persona,TAM);
                mostrarPersona(Persona,TAM);
                break;
            case 4:

                break;
            case 5:

                seguir = 'n';
                break;
        }
    }

    return 0;
}

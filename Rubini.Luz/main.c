#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define TAMC 20
#define TAMA 40

int main()
{
    eCliente cliente[TAMC];
    eAlquiler alquiler[TAMA];
    eEquipos equipos[3];
    inicializarEstadoCliente(cliente,TAMC);
    inicializarEstadoAlquiler(alquiler,TAMA);
    inicializarCliente(cliente);
    inicializarAlquiler(alquiler,cliente);


    system("color 0f");
    char seguir='s';
    int opcion;

    while(seguir=='s')
    {
        printf("1- Alta del cliente\n");
        printf("2- Modificar datos del cliente\n");
        printf("3- Baja del cliente\n");
        printf("4- Nuevo alquiler\n");
        printf("5- Fin del alquiler\n");
        printf("6- Informar:\n");
        printf("7- Salir\n");

        scanf("%d",&opcion);
        while(opcion<1 || opcion>7)
        {
            printf("Error! Ingrese una opcion valida: ");
            scanf("%d",&opcion);
        }


        switch(opcion)
        {
            case 1:
                altaCliente(cliente,TAMC);
                break;
            case 2:
                modificarCliente(cliente,TAMC);
                break;
            case 3:
                eliminarCliente(cliente,TAMC);
                break;
            case 4:
                nuevoAlquiler(cliente,alquiler,TAMA,TAMC);
                break;
            case 5:
                finAlquiler(alquiler,cliente,TAMA);
                break;
            case 6:
                informar(cliente,alquiler,TAMA,TAMC,equipos);
                break;
            case 7:
            seguir = 'n';
                break;
        }

        system("pause");
        system("cls");
    }

    return 0;
}

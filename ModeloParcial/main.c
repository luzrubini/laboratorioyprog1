#include <stdio.h>
#include <stdlib.h>
#define TAMA 5
#define TAMR 10
#include "lib.h"
int main()
{
    system("color 0f");
    char seguir='s';
    int opcion;

    eAbonado abonado[TAMA];
    eReclamo reclamo[TAMR];
    inicializarEstadoReclamo(reclamo,TAMR);

    while(seguir=='s')
    {
        printf("1- Alta abonado\n");
        printf("2- Modificar datos del abonado\n");
        printf("3- Baja del abonado\n");
        printf("4- Nueva llamada\n");
        printf("5- Fin llamada\n");
        printf("6- Informar:\n");
        printf("7- Salir\n");

        scanf("%d",&opcion);


        switch(opcion)
        {
            case 1:
                //altaAbonado(abonado,TAMA);
                inicializarAbonado(abonado,TAMA);
                break;
            case 2:
                modificarAbonado(abonado,TAMA);
                break;
            case 3:
                eliminarAbonado(abonado,TAMA);
                break;
            case 4:
                nuevaLlamada(abonado,reclamo,TAMR);
                break;
            case 5:
                finLlamada(reclamo,abonado,TAMR);
                break;
            case 6:
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



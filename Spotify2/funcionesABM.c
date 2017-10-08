#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#include "funcionesMostrar.h"
#include "funcionesABM.h"
#include "funcionesValidacion.h"


void altaInterprete(eInterprete interprete[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(interprete[i].estado==0)
        {
            printf("Ingrese Id del interprete: ");
            scanf("%d",&interprete[i].idInterprete);
            printf("Ingrese Nombre del interprete: ");
            fflush(stdin);
            gets(interprete[i].nombre);
            printf("Ingrese Nacionalidad: ");
            fflush(stdin);
            gets(interprete[i].nacionalidad);
            interprete[i].estado=1;
            break;
        }

    }
        if(i==tam)
        {
            printf("No hay mas espacio.\n");
        }

}
void altaCancion(eCancion cancion[],eCancionInterprete cancionInterprete[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(cancion[i].estado==0)
        {
            printf("Ingrese Id del la cancion: ");
            scanf("%d",&cancion[i].idCancion);
            printf("Ingrese Nombre de la cancion: ");
            fflush(stdin);
            gets(cancion[i].titulo);
            printf("Ingrese interprete: ");
            scanf("%d",&cancion[i].interprete);
            printf("Ingrese duracion: ");
            scanf("%f",&cancion[i].duracion);
            cancion[i].estado=1;
            cancionInterprete[i].idCancion=cancion[i].idCancion;
            cancionInterprete[i].idInterprete=cancion[i].interprete;
            break;
        }

    }
        if(i==tam)
        {
            printf("No hay mas espacio.\n");
        }


}
void modificarCancion(eCancion cancion[],int tam)
{
    int idCancion;
    int i;
    char rta;
    printf("Ingrese id:");
    scanf("%d",&idCancion);
    for(i=0;i<tam;i++)
    {
        if(cancion[i].estado==1 && cancion[i].idCancion==idCancion)
        {
            printf("Cancion: %d\nTitulo:%s\nNumero de interprete: %d\nDuracion: %.2f\n\n",cancion[i].idCancion,cancion[i].titulo,cancion[i].interprete,cancion[i].duracion);
            printf("Desea modificar esta cancion?");
            rta=getche();
            if(rta=='s')
            {
                printf("Ingrese Id del la cancion: ");
                scanf("%d",&cancion[i].idCancion);
                printf("Ingrese Nombre de la cancion: ");
                fflush(stdin);
                gets(cancion[i].titulo);
                printf("Ingrese interprete: ");
                scanf("%d",&cancion[i].interprete);
                printf("Ingrese duracion: ");
                scanf("%f",&cancion[i].duracion);
                cancion[i].estado=1;
                break;
            }
            else if(rta!='s')
            {
                printf("No se han realizado modificaciones");
                break;
            }
        }
    }
    if(cancion[i].estado==0 && cancion[i].idCancion!=idCancion)
    {
        printf("Esa cancion no existe/n");
    }
}
void modificarInterprete(eInterprete interprete[],int tam)
{
    int idInterprete;
    int i;
    char rta;
    printf("Ingrese id:");
    scanf("%d",&idInterprete);
    for(i=0;i<tam;i++)
    {
        if(interprete[i].estado==1 && interprete[i].idInterprete==idInterprete)
        {
            printf("id: %d\nNombre: %s\nNacionalidad: %s\n\n",interprete[i].idInterprete,interprete[i].nombre,interprete[i].nacionalidad);
            printf("Desea modificar este interprete?");
            rta=getche();
            if(rta=='s')
            {
                printf("Ingrese Id del interprete: ");
                scanf("%d",&interprete[i].idInterprete);
                printf("Ingrese Nombre del interprete: ");
                fflush(stdin);
                gets(interprete[i].nombre);
                printf("Ingrese Nacionalidad: ");
                fflush(stdin);
                gets(interprete[i].nacionalidad);
                interprete[i].estado=1;
                break;
            }
            else if(rta!='s')
            {
                printf("No se han realizado modificaciones");
                break;
            }
        }
    }
    if(interprete[i].estado==0 && interprete[i].idInterprete!=idInterprete)
    {
        printf("Ese interprete no existe/n");
    }
}
void borrarCancion(eCancion cancion[],int tam)
{
    int idCancion;
    int i;
    char rta;
    printf("Ingrese id:");
    scanf("%d",&idCancion);
    for(i=0;i<tam;i++)
    {
        if(cancion[i].estado==1 && cancion[i].idCancion==idCancion)
        {
            printf("Cancion: %d\nTitulo:%s\nNumero de interprete: %d\nDuracion: %.2f\n\n",cancion[i].idCancion,cancion[i].titulo,cancion[i].interprete,cancion[i].duracion);
            printf("Desea eliminar esta cancion?");
            rta=getche();
            if(rta=='s')
            {
                cancion[i].estado=0;
                printf("Cancion eliminada");
                break;
            }
            else if(rta!='s')
            {
                printf("No se han realizado modificaciones");
            }
        }
    }
    if(cancion[i].estado==0 && cancion[i].idCancion!=idCancion)
    {
        printf("Esa cancion no existe/n");
    }
}
void borrarInterprete(eInterprete interprete[],int tam)
{
    int idInterprete;
    int i;
    char rta;
    printf("Ingrese id:");
    scanf("%d",&idInterprete);
    for(i=0;i<tam;i++)
    {
        if(interprete[i].estado==1 && interprete[i].idInterprete==idInterprete)
        {
            printf("id: %d\nNombre: %s\nNacionalidad: %s\n\n",interprete[i].idInterprete,interprete[i].nombre,interprete[i].nacionalidad);
            printf("Desea eliminar este interprete?");
            rta=getche();
            if(rta=='s')
            {
                interprete[i].estado=0;
                break;
            }
            else if(rta!='s')
            {
                printf("No se han realizado modificaciones");
            }
        }
    }
    if(interprete[i].estado==0 && interprete[i].idInterprete!=idInterprete)
    {
        printf("Ese interprete no existe/n");
    }
}

#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void inicializarAbonado(eAbonado abonado[],int tam)
{
    int i;
    int id[5]={0,1,2,3,4};
    int numero[5]={42111898,15668615,15667026,15577104,42111856};
    char nombre[5][20]={"Luz","Melisa","Alec","Sebastian","Deniss"};
    char apellido[5][15]={"Rubini","Rubini","Lightwood","Verlac","Vasiljevs"};


    for(i=0;i<tam;i++)
    {
        abonado[i].id=id[i];
        abonado[i].numero=numero[i];
        strcpy(abonado[i].nombre,nombre[i]);
        strcpy(abonado[i].apellido,apellido[i]);
        strcpy(abonado[i].nombreApellido,abonado[i].apellido);
        strcat(abonado[i].nombreApellido,", ");
        strcat(abonado[i].nombreApellido,abonado[i].nombre);
        abonado[i].estado=1;

    }
}
/*void altaAbonado(eAbonado abonado[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(abonado[i].estado==0)
        {
            abonado[i].id=i;
            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(abonado[i].nombre);
            printf("Ingrese Apellido: ");
            fflush(stdin);
            gets(abonado[i].apellido);
            strcpy(abonado[i].nombreApellido,abonado[i].apellido);
            strcat(abonado[i].nombreApellido,", ");
            strcat(abonado[i].nombreApellido,abonado[i].nombre);
            printf("Ingrese numero: ");
            scanf("%d",&abonado[i].numero);

            abonado[i].estado=1;
            break;
        }

    }
        if(i==tam)
        {
            printf("No hay mas espacio.\n");
        }

}*/
void modificarAbonado(eAbonado abonado[],int tam)
{
    int idAbonado;
    int i;
    char rta;
    printf("Ingrese id:");
    scanf("%d",&idAbonado);
    for(i=0;i<tam;i++)
    {
        if(abonado[i].estado==1 && abonado[i].id==idAbonado)
        {
            mostrarAbonado(abonado,i);
            printf("Desea modificar este abonado?");
            rta=getche();
            if(rta=='s')
            {
                printf("Ingrese Nombre: ");
                fflush(stdin);
                gets(abonado[i].nombre);
                printf("Ingrese Apellido: ");
                fflush(stdin);
                gets(abonado[i].apellido);
                strcpy(abonado[i].nombreApellido,abonado[i].apellido);
                strcat(abonado[i].nombreApellido,", ");
                strcat(abonado[i].nombreApellido,abonado[i].nombre);
                printf("\nAbonado modificado!\n");
                break;
            }
            else if(rta!='s')
            {
                printf("\nNo se han realizado modificaciones\n");
                break;
            }
        }
    }
    if(abonado[i].estado==0 && abonado[i].id!=idAbonado)
    {
        printf("\nEse abonado no existe\n");
    }
}
void eliminarAbonado(eAbonado abonado[],int tam)
{
    int idAbonado;
    int i;
    char rta;
    printf("Ingrese id:");
    scanf("%d",&idAbonado);
    for(i=0;i<tam;i++)
    {
        if(abonado[i].estado==1 && abonado[i].id==idAbonado)
        {
            mostrarAbonado(abonado,i);
            printf("Desea eliminar este abonado?");
            rta=getche();
            if(rta=='s')
            {
                abonado[i].estado=0;
                printf("\nAbonado eliminado!\n");
                break;
            }
            else if(rta!='s')
            {
                printf("\nNo se han realizado modificaciones.\n");
                break;
            }
        }
    }
    if(abonado[i].estado==0 && abonado[i].id!=idAbonado)
    {
        printf("\nEse abonado no existe\n");
    }
}
void inicializarEstadoReclamo(eReclamo reclamo[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        reclamo[i].estado=0;
    }
}
void nuevaLlamada(eAbonado abonado[], eReclamo reclamo [],int tamR)
{
    int i;
    int numero;
    int contReclamo=0;
    printf("Ingrese numero del abonado: ");
    scanf("%d",&numero);
    for(i=0;i<tamR;i++)
    {
        if(reclamo[i].estado==0)
        {
            if(abonado[i].estado==1 && abonado[i].numero==numero)
            {
                reclamo[i].idAbonado=abonado[i].id;
                mostrarAbonado(abonado,i);
                motivoReclamo(reclamo,i);
                strcpy(reclamo[i].estadoDelReclamo,"EN CURSO");
                printf("Estado del reclamo: %s\n",reclamo[i].estadoDelReclamo);
                reclamo[i].numeroDeReclamo=contReclamo;
                printf("Numero de reclamo: %d\n",reclamo[i].numeroDeReclamo);
                reclamo[i].estado=1;
                contReclamo++;
                break;
            }
        }
    }
    if(i==tamR)
    {
        printf("No hay mas espacio.\n");
    }
}
void finLlamada(eReclamo reclamo [],eAbonado abonado[],int tamR)
{
    int i;
    int estadoReclamo;
    int numeroReclamo;

    printf("Ingrese numero de reclamo: ");
    scanf("%d",&numeroReclamo);
    for(i=0;i<tamR;i++)
    {

        if(reclamo[i].estado==1 && numeroReclamo==reclamo[i].numeroDeReclamo)
        {
            mostrarAbonado(abonado,i);
            mostrarReclamo(reclamo,i);
            printf("Ingrese tiempo de llamada: ");
            scanf("%f",&reclamo[i].tiempoDeLlamada);
            printf("Ingrese estado del reclamo:\n1)SOLUCIONADO\n2)NO SOLUCIONADO\n");
            scanf("%d",&estadoReclamo);
            if(estadoReclamo==1)
            {
                strcpy(reclamo[i].estadoDelReclamo,"SOLUCIONADO");
            }
            else if(estadoReclamo==2)
            {
                strcpy(reclamo[i].estadoDelReclamo,"NO SOLUCIONADO");
            }
            printf("%s",reclamo[i].estadoDelReclamo);
            break;
        }
    }
}
void mostrarAbonado(eAbonado abonado[],int i)
{
    printf("ID ABONADO\tAPELLIDO Y NOMBRE\tNUMERO\n");
    printf("%d\t%20s\t\t%d\n",abonado[i].id,abonado[i].nombreApellido,abonado[i].numero);
}
void mostrarReclamo(eReclamo reclamo[],int i)
{
    printf("MOTIVO DEL RECLAMO:\n %s\n",reclamo[i].motivo);
}
void motivoReclamo(eReclamo reclamo[],int i)
{
    int motivoReclamo;
    printf("Ingrese motivo del reclamo: 1)FALLA 3G 2)FALLA LTE 3)FALLA EQUIPO\n");
    scanf("%d",&motivoReclamo);
    if (motivoReclamo==1)
    {
        strcpy(reclamo[i].motivo,"FALLA 3G");
    }
    else
    {
        if(motivoReclamo==1)
        {
            strcpy(reclamo[i].motivo,"FALLA LTE");
        }
        else
        {
            strcpy(reclamo[i].motivo,"FALLA EQUIPO");
        }
    }
}

#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*void inicializarPersona(EPersona lista[], int tam)
{
    int i;
    int dni[6]={100,101,102,103,104,105};
    char nombres[6][50]={"Alfonsin","Alec","Isabelle","Simon","Sebastian","Magnus"};
    int edad[6]={7,8,5,9,6,8};

    for(i=0;i<tam;i++)
    {
        lista[i].dni=dni[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].edad=edad[i];
        lista[i].estado=1;

    }
}
*/
void altaPersona(EPersona listaPersonas[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(listaPersonas[i].estado==0)
        {
            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(listaPersonas[i].nombre);
            printf("Ingrese edad: ");
            scanf("%d",&listaPersonas[i].edad);
            printf("Ingrese DNI (sin puntos)");
            scanf("%d",&listaPersonas[i].dni);
            listaPersonas[i].estado=1;

            break;
        }
        else if(listaPersonas[i].estado==1)
        {
            printf("No hay mas espacio");
        }
    }

}

void inicializarEstado(EPersona listaPersonas[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        listaPersonas[i].estado=0;
    }
}

void mostrarPersona(EPersona listaPersonas[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(listaPersonas[i].estado==1)
        {
            printf("%s--%d--%d\n",listaPersonas[i].nombre,listaPersonas[i].edad,listaPersonas[i].dni);
        }
    }
}
void ordenarPersonas(EPersona listaPersonas[], int tam)
{
    EPersona    AuxEstructura;
    int i,j;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(listaPersonas[i].nombre,listaPersonas[j].nombre)>0)
            {
                AuxEstructura=listaPersonas[i];
                listaPersonas[i]=listaPersonas[j];
                listaPersonas[j]=AuxEstructura;
            }
        }
    }
}
/*void borrarPersona(EPersona listaPersonas[],int tam)
{
    int dni;
    int i;
    printf("Ingrese DNI:");
    scanf("%d",dni);
    for(i=0;i<tam;i++)
    {
        buscarPorDni(listaPersonas,dni);
    }
}
int buscarPorDni(EPersona listaPersonas [],int dni)
{
    int i;
    if(listaPersonas[i].dni==dni)
    {
       printf("%d",listaPersonas[i]);
    }
}*/

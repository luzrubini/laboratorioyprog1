#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargarPersona(ePersona* persona,int tam)
{
    int i;
    int dni;
    char nombre[40];
    int edad;
     for(i=0; i<5; i++)
    {
        printf("Ingrese el dni: ");
        scanf("%d", &dni);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);
        printf("Ingrese edad: ");
        scanf("%d", &edad);


        if(generarPersona(persona+i, dni, nombre, edad))
        {
            printf("Persona generada");
        }
        else
        {
            printf("Carga fallida");
        }
        break;
    }
}
int generarPersona(ePersona* persona,int dni,char nombre[],int edad)
{
    int retorno=0;
    if(persona!=NULL)
    {
        persona->dni=dni;
        strcpy(persona->nombre,nombre);
        persona->edad=edad;
        retorno=1;
    }
    return retorno;
}
void modificarPersona(ePersona* persona,int tam)
{
    int i;
    int dni;
    printf("Ingrese DNI:");
    scanf("%d",&dni);
    for(i=0;i<tam;i++)
    {
        if(dni==persona->dni)
        {
            printf("Ingrese el dni: ");
            scanf("%d", persona->dni);
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(persona->nombre);
            printf("Ingrese edad: ");
            scanf("%d", persona->edad);
        }
    }

}

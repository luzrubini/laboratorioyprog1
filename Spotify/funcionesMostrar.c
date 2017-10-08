#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#include "funcionesMostrar.h"
#include "funcionesValidacion.h"

void mostrarInterprete(eInterprete interprete[], int tam)
{
    printf("Interpretes: \n");
    int i;
    for(i=0;i<tam;i++)
    {
        if(interprete[i].estado==1)
        {
            printf("id: %d\nNombre: %s\nNacionalidad: %s\n\n",interprete[i].idInterprete,interprete[i].nombre,interprete[i].nacionalidad);
        }
    }
}
void mostrarCancionPorInterprete(eInterprete interprete[],eCancion cancion[],int tamC,int tamI)
{
    int i;
    int j;
    for(j=0;j<tamI;j++)
    {
        printf("%s\n",interprete[j].nombre);
        for(i=0;i<tamC;i++)
        {
            if(cancion[i].estado==1)
            {
                if(cancion[i].interprete==interprete[j].idInterprete)
                {
                    printf("Cancion: %d\nTitulo:%s\nDuracion: %.2f\n\n",cancion[i].idCancion,cancion[i].titulo,cancion[i].duracion);
                }
            }
        }
    }
}
void mostrarCancion(eCancion cancion[],eInterprete interprete[], int tamC,int tamI)
{
    int i;
    int j;
    printf("Canciones:\n");
    printf("Id\t\tTitulo\t\t\t\tInterprete\tDuracion\n");
    for(i=0;i<tamC;i++)
    {
        for(j=0;j<tamI;j++)
        {
            if(cancion[i].estado==1)
            {
                if(interprete[j].idInterprete==cancion[i].interprete)
                {
                printf("%4d\t%20s\t\t%20s\t%.2f\n",cancion[i].idCancion,cancion[i].titulo,interprete[j].nombre,cancion[i].duracion);
                }
            }
        }


    }
}
void mostrarCancionesArgentinos(eCancion cancion[],eInterprete interprete[],int tamC,int tamI)
{
    int i;
    int j;
    char nacionalidad[20]={"Argentino"};
    printf("Canciones:\n");
    printf("Id\t\tTitulo\t\t\t\tInterprete\tDuracion\n");
    for(i=0;i<tamC;i++)
    {
        for(j=0;j<tamI;j++)
        {
            if(cancion[i].estado==1 && strcmp(nacionalidad,interprete[j].nacionalidad)==0)
            {
                if(interprete[j].idInterprete==cancion[i].interprete)
                {
                printf("%4d\t%20s\t\t%20s\t%.2f\n",cancion[i].idCancion,cancion[i].titulo,interprete[j].nombre,cancion[i].duracion);
                }
            }
        }


    }
}
void mostrarDuracionPorInterprete(eInterprete interprete[],eCancion cancion[],int tamC,int tamI)
{
    int i;
    int j;
    char Nuevointerprete[20];
    float acumDuracion=0;
    printf("Ingrese nombre del interprete: ");
    fflush(stdin);
    gets(Nuevointerprete);

    for(j=0;j<tamI;j++)
    {

        for(i=0;i<tamC;i++)
        {
            if(cancion[i].estado==1 && strcmp(Nuevointerprete,interprete[j].nombre)==0)
            {
                if(interprete[j].idInterprete==cancion[i].interprete)
                {
                printf("%4d\t%20s\t\t%20s\t%.2f\n",cancion[i].idCancion,cancion[i].titulo,interprete[j].nombre,cancion[i].duracion);
                acumDuracion=acumDuracion+cancion[i].duracion;
                }
            }
        }
    }
    printf("DURACION TOTAL DE SUS TEMAS: %.2f\n",acumDuracion);
    if(i==tamI)
        {
            printf("No existe ese artista.\n");
        }
}
void InterpreteConMasCanciones(eInterprete interprete[],eCancion cancion[],int tamC,int tamI)
{
    int i;
    int j;
    int maximo;
    int flag=0;

    for(j=0;j<tamI;j++)
    {
        interprete[j].contador=0;
        for(i=0;i<tamC;i++)
        {
            if(cancion[i].estado==1)
            {
                if(interprete[j].idInterprete==cancion[i].interprete)
                {
                    interprete[j].contador++;
                }
            }
        }
        if(flag==0)
        {
            maximo=interprete[j].contador;
            flag=1;
        }
        else
        {
            if(maximo<interprete[j].contador)
            {
                maximo=interprete[j].contador;
            }
        }
    }
    printf("INTERPRETES CON MAS CANTIDAD DE CANCIONES:\nCantidad de canciones: %d\n",maximo);

    for(j=0;j<tamI;j++)
    {
        if(maximo==interprete[j].contador)
        {
            printf("%s\n",interprete[j].nombre);
        }
    }

}

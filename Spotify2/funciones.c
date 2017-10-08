#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#include "funcionesValidacion.h"


void inicializarInterprete(eInterprete interprete[], int tam)
{
    int i;
    int id[]={1,2,3,4,5};
    char nombre[][100]={"My Chemical Romance","Almendra","AC/DC","Queen","Panic! at the Disco"};
    char nacionalidad[][100]={"Estadounidense","Argentino","Australianos","Ingleses","Estadounidenses"};

    for(i=0;i<tam;i++)
    {
        interprete[i].idInterprete=id[i];
        strcpy(interprete[i].nombre,nombre[i]);
        strcpy(interprete[i].nacionalidad,nacionalidad[i]);
        interprete[i].estado=1;
    }
}
void inicializarCancion(eCancion cancion[], int tam)
{
    int i;
    int id[]={101,103,158,254,145,789,145,523,148,965};
    char titulo[][100]={"Helena","House of wolves","Fermin","Nicotine","Vegas Lights","Disenchanted","Somebody to love","The Jack","Muchacha ojos de papel","Sarah smiles"};
    int interprete[]={1,1,2,5,5,1,4,3,2,5};
    float duracion[]={3.22,5.55,3.17,4.55,6.41,4.55,7.15,5.45,6.53,4.23};

    for(i=0;i<tam;i++)
    {
        cancion[i].idCancion=id[i];
        strcpy(cancion[i].titulo,titulo[i]);
        cancion[i].interprete=interprete[i];
        cancion[i].duracion=duracion[i];
        cancion[i].estado=1;
    }
}
void inicializarEstados(eInterprete interprete[],eCancion cancion[],eCancionInterprete cancionInterprete[],int tam,int tamI)
{
    int i;
    int j;
    for(i=0;i<tam;i++)
    {
        interprete[i].estado=0;
        interprete[i].contador=0;
    }
    for(j=0;j<tamI;j++)
    {
        cancion[i].estado=0;
        cancionInterprete[i].estado=0;
    }
}

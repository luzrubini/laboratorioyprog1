#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5
typedef struct
{
    int legajo;
    char nombre[50];
    int nota;
}eRecursante;
void mostrarRecursante(eRecursante*);
eRecursante* newRecursante(int,char*,int);
int main()
{
    eRecursante* recursante;
    recursante=newRecursante(recursante->legajo,recursante->nombre,recursante->nota);
    if(recursante!=NULL)
    {
        recursante->legajo=1001;
        strcpy(recursante->nombre,"Ramiro Tapita");
        recursante->nota=8;
        mostrarRecursante(recursante);
    }
    else
    {
        printf("No se ha reservado espacio en memoria");
    }

    return 0;
}
eRecursante* newRecursante(int legajo,char nombre[],int nota)
{
    eRecursante* recursante;
    recursante->legajo=malloc(sizeof(i));
    recursante->nombre=malloc(sizeof(char[]));
    recursante->nota=malloc(sizeof(int));
    return recursante;
}
void mostrarRecursante(eRecursante* r)
{
    printf("%d--%s--%d",r->legajo,r->nombre,r->nota);
}

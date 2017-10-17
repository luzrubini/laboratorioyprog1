#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[15];
    int nota;
} eRecursante;

void mostrarRecursante(eRecursante*);

eRecursante* newRecursante();//Constructor por defecto
eRecursante* newRecursanteParametros(int, char[], int);// Constructor parametrizado


int main()
{
    eRecursante* pRecursante;

    eRecursante* lista[3];

    int legajo, nota;
    char nombre[15];

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(nombre);
    printf("Ingrese nota: ");
    scanf("%d", &nota);
    pRecursante = newRecursanteParametros(legajo, nombre, nota);
    if(pRecursante!=NULL)
    {
        lista[0] = pRecursante;
        mostrarRecursante(lista[0]);
    }
    else
    {
        printf("No hay espacio en memoria!!!");
    }




    return 0;
}

eRecursante* newRecursante()
{
    eRecursante* pRecursante;


    pRecursante = (eRecursante*) malloc(sizeof(eRecursante));
    if(pRecursante!=NULL)
    {
        pRecursante->legajo = 0;
        strcpy(pRecursante->nombre,"");
        pRecursante->nota = 0;

    }

    return pRecursante;
}
eRecursante* newRecursanteParametros(int legajo, char nombre[], int nota)
{
    eRecursante* pRecursante;


    pRecursante = newRecursante();
    if(pRecursante!=NULL)
    {
        pRecursante->legajo = legajo;
        strcpy(pRecursante->nombre, nombre);
        pRecursante->nota = nota;

    }

    return pRecursante;
}
void mostrarRecursante(eRecursante* r)
{
    printf("%d--%s--%d", r->legajo, r->nombre, r->nota);
}

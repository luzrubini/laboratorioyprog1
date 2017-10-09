#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dni;
    char nombre[20];
    float altura;
} ePersona;

int newPersona(ePersona*, int, char[], float);
void personaToString(ePersona*);

int main()
{

    ePersona listaPersonas[5];
    int i;
    int dni;
    char nombre[50];
    float altura;

    for(i=0; i<5; i++)
    {
        printf("Ingrese el dni: ");
        scanf("%d", &dni);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);
        printf("Ingrese la altura: ");
        scanf("%f", &altura);


        if(newPersona(listaPersonas+i, dni, nombre, altura))
        {
            printf("Persona generada con exito!!!");
        }
        else
        {
            printf("Carga fallida");
        }


    }
    printf("**************LISTA DE PERSONAS****************");
    for(i=0; i<5; i++)
    {
        personaToString(listaPersonas+i);
    }


    return 0;
}

int  newPersona(ePersona* miPersona, int dni, char nombre[], float altura)
{
    int retorno=0;
    if(miPersona!=NULL)
    {
        miPersona->dni = dni;
        strcpy(miPersona->nombre, nombre);
        miPersona->altura = altura;
        retorno = 1;
    }
    return retorno;

}
void personaToString(ePersona* miPersona)
{
    printf("%d--%s--%.2f\n",  miPersona->dni,  miPersona->nombre,  miPersona->altura);
}

#include <stdio.h>
#include "Alumnos.h"


void altaAlumno(int legajo[], char nombre[][50], int nota1[], int nota2[], float promedio[], int tam)
{
    int i;
    int flag=0;

    for(i=0; i<tam; i++)
    {
        if(legajo[i]==-1)
        {
            flag = 1;
            printf("Ingrese legajo: ");
            scanf("%d", &legajo[i]);
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nombre[i]);
            printf("Ingrese nota 1: ");
            scanf("%d", &nota1[i]);
            printf("Ingrese nota 2: ");
            scanf("%d", &nota2[i]);

            promedio[i] = (float)(nota1[i] + nota2[i])/2;
            break;
        }


    }
    if(flag==0)
    {
        printf ("No hay mas espacio");
    }
}

void mostrarAlumnos(int legajo[], char nombre[][50], int nota1[], int nota2[], float promedio[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(legajo[i]!=-1)
        {
            mostrar(legajo[i], nombre[i], nota1[i], nota2[i], promedio[i]);
        }

    }
}

void ordenarAlumnos(int legajo[], char nombre[][50], int nota1[], int nota2[], float promedio[], int tam)
{
    int i, j;
    int auxInt;
    char auxString[50];
    float auxFloat;
    int cont=0;
    for(i=0; i<tam-1; i++)
    {
        if(legajo[i]!=-1)
        {
            for(j=i+1; j<tam; j++)
            {
                if(legajo[j]!=-1)
                {
                    if(strcmp(nombre[i], nombre[j]) > 0)
                    {
                        strcpy(auxString, nombre[i]);
                        strcpy(nombre[i], nombre[j]);
                        strcpy(nombre[j], auxString);

                        auxInt = legajo[i];
                        legajo[i] = legajo[j];
                        legajo[j] = auxInt;

                        auxInt = nota1[i];
                        nota1[i] = nota1[j];
                        nota1[j] = auxInt;

                        auxInt = nota2[i];
                        nota2[i] = nota2[j];
                        nota2[j] = auxInt;

                        auxFloat = promedio[i];
                        promedio[i] = promedio[j];
                        promedio[j] = auxFloat;

                        cont++;
                    }
                }
            }
        }
    }
    printf("CANTIDAD: %d", cont);
}

void modificarAlumno(int legajo[], char nombre[][50], int nota1[], int nota2[], float promedio[], int tam)
{
    int auxInt;
    int i;
    char rta;
    int flag = 0;
    printf("Ingrese el legajo: ");
    scanf("%d", &auxInt);
    for(i=0; i<tam; i++)
    {

        if(legajo[i]==auxInt)//Lo encontro
        {
            flag = 1;
            mostrar(legajo[i], nombre[i], nota1[i], nota2[i], promedio[i]);
            printf("Ingrese la nueva nota: ");
            scanf("%d", &auxInt);

            printf("Desea realizar la siguiente modificacion: Nota anterior: %d, nueva nota: %d ?", nota1[i], auxInt);
            rta = getche();
            if(rta=='s')
            {
                nota1[i]=auxInt;
                promedio[i] = (float)(nota1[i] + nota2[i])/2;

            }
            else
            {
                printf("\nAccion cancelada por el usuario!!!\n");
            }

            break;
        }

    }
    if(flag == 0)
    {
        printf("Legajo inexistente!!!");
    }
}

void eliminarAlumno(int legajo[], char nombre[][50], int nota1[], int nota2[], float promedio[], int tam)
{
    int auxInt;
    int i;
    char rta;
    int flag = 0;
    printf("Ingrese el legajo: ");
    scanf("%d", &auxInt);
    for(i=0; i<tam; i++)
    {

        if(legajo[i]==auxInt)//Lo encontro
        {
            flag = 1;
            mostrar(legajo[i], nombre[i], nota1[i], nota2[i], promedio[i]);

            printf("Desea realizar eliminar al alumno");
            rta = getche();
            if(rta=='s')
            {
                legajo[i] = -1;
            }
            else
            {
                printf("\nAccion cancelada por el usuario!!!\n");
            }

            break;
        }

    }
    if(flag == 0)
    {
        printf("Legajo inexistente!!!");
    }
}


void mostrar(int legajo, char nombre[], int nota1, int nota2, float promedio)
{
    printf("\n%d--%s--%d--%d--%f\n", legajo, nombre, nota1, nota2, promedio);
}


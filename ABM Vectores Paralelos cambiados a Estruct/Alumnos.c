#include <stdio.h>
#include "Alumnos.h"

void inicializarAlumno(eAlumno lista[], int tam)
{
    int i;
    int legajos[6]={100,101,102,103,104,105};
    char nombres[6][50]={"Alfonsin","Alec","Isabelle","Simon","Sebastian","Magnus"};
    int notas1[6]={7,8,5,9,6,8};
    int notas2[6]={1,8,6,9,3,4};

    for(i=0;i<tam;i++)
    {
        lista[i].legajo=legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].nota1=notas1[i];
        lista[i].nota2=notas2[i];
        lista[i].promedio=(float)(lista[i].nota1+lista[i].nota2)/2;
        lista[i].estado=1;

    }
}
/*void altaAlumno(eAlumno lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            printf("Ingrese legajo: ");
            scanf("%d", &lista[i].legajo);
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(lista[i].nombre);
            printf("Ingrese nota 1: ");
            scanf("%d", &lista[i].nota1);
            printf("Ingrese nota 2: ");
            scanf("%d", &lista[i].nota2);

            lista[i].promedio = (float)(lista[i].nota1+lista[i].nota2)/2;
            break;
        }


    }
    if(lista[i].estado==1)
    {
        printf ("No hay mas espacio");
    }
}*/

void mostrarAlumnos(eAlumno lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            mostrar(lista*[i],tam);
        }

    }
}

/*void ordenarAlumnos(int legajo[], char nombre[][50], int nota1[], int nota2[], float promedio[], int tam)
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

*/
void mostrar(eAlumno lista[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
        printf("\n%d--%s--%d--%d--%f\n", lista[i].legajo, lista[i].nombre, lista[i].nota1, lista[i].nota2, lista[i].promedio);
        }
    }
}


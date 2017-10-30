#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parser.h"
#include "Employee.h"
#include <string.h>


/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    system("color 0f");
    char seguir='s';
    int opcion;
    int i;
    char nombre[51],apellido[51];
    int id,estado;
    int contador=0;
    Employee* aux;
    Employee* AuxEstructura=employee_new();
    FILE* miArchivo=NULL;
    ArrayList* lista=al_newArrayList();

    while(seguir=='s')
    {
        printf("1- Parse del archivo data.csv\n");
        printf("2- Listar Empleados\n");
        printf("3- Ordenar por nombre\n");
        printf("4- Agregar un elemento\n");
        printf("5- Elimina un elemento\n");
        printf("6- Borrar Interprete\n");
        printf("7- Listar Empleados (Desde/Hasta)\n");
        scanf("%d",&opcion);


        switch(opcion)
        {
            case 1:
                parserEmployee(miArchivo,lista);
                break;
            case 2:
                for(i=0;i<al_len(lista);i++)
                {
                    if(contador %250 == 0)
                    {
                       system("pause");
                    }
                    contador++;
                    aux=al_get(lista,i);
                    employee_print(aux);
                }
                break;
            case 3:
                break;
            case 4:
                printf("Ingrese Id: ");
                scanf("%d",&id);
                printf("Ingrese Nombre: ");
                fflush(stdin);
                gets(nombre);
                printf("Ingrese Apellido: ");
                fflush(stdin);
                gets(apellido);
                printf("Ingrese estado: ");
                scanf("%d",&estado);

                AuxEstructura->id=id;
                strcpy(AuxEstructura->name,nombre);
                strcpy(AuxEstructura->lastName,apellido);
                AuxEstructura->isEmpty=estado;
                al_add(lista,AuxEstructura);
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                seguir = 'n';
                break;
        }

        system("pause");
        system("cls");
    }


    return 0;
}

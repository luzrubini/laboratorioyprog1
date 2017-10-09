#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <string.h>
#include <ctype.h>
#include <conio.h>
void altaCliente(eCliente cliente[],int tam)
{
    int i;
    int dni;
    for(i=0;i<tam;i++)
    {
        if(cliente[i].estado==0)
        {
            cliente[i].id=(100+i);
            printf("Ingrese Nombre: ");
            fflush(stdin);
            gets(cliente[i].nombre);
            printf("Ingrese Apellido: ");
            fflush(stdin);
            gets(cliente[i].apellido);
            strcpy(cliente[i].nombreApellido,cliente[i].apellido);
            strcat(cliente[i].nombreApellido,", ");
            strcat(cliente[i].nombreApellido,cliente[i].nombre);
            printf("Ingrese dni: ");
            scanf("%d",&dni);
            dni=validarDNI(dni,cliente,tam);
            cliente[i].dni=dni;
            cliente[i].estado=1;
            break;
        }
    }
        if(i==tam)
        {
            printf("No hay mas espacio.\n");
        }
}
void nuevoAlquiler(eCliente cliente[], eAlquiler alquiler[],int tamA, int tamC)
{
    int i, j;
    int dni;
    for(i=0;i<tamA;i++)
    {
        if(alquiler[i].estado==0)
        {
            printf("Ingrese dni del cliente:");
            scanf("%d",&dni);
            for(j=0;j<tamC;j++)
            {
                 if(cliente[j].estado==1 && cliente[j].dni==dni)
                {
                    alquiler[i].idAlquiler=i+1;
                    alquiler[i].idCliente=cliente[j].id;
                    printf("Ingrese equipo a alquilar: 1)Amoladora-2)Mezcladora-3)Taladro\n");
                    scanf("%d",&alquiler[i].equipo);
                    printf("Ingrese nombre del operador: ");
                    fflush(stdin);
                    gets(alquiler[i].operador);
                    printf("Ingrese tiempo estimado de alquiler: ");
                    scanf("%f",&alquiler[i].tiempoEstimado);
                    alquiler[i].estadoAlquiler=4;
                    alquiler[i].estado=1;
                    cliente[j].contador++;
                    break;
                }
                else
                {
                    printf("Ese dni no existe!");
                    break;
                }
            }
            break;
        }
    }
    if(i==tamA)
    {
        printf("No hay mas espacio.\n");
    }
}
void inicializarContAcum(eEquipos equipo[])
{
    int i;
    for(i=0;i<3;i++)
    {
        equipo[i].cont=0;
        equipo[i].acum=0;
        equipo[i].equipo=i+1;
        equipo[i].promedioReal=0;
    }
}
void inicializarEstadoCliente(eCliente cliente[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        cliente[i].estado=0;
        cliente[i].contador=0;
    }
}
void inicializarEstadoAlquiler(eAlquiler alquiler[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        alquiler[i].estado=0;
    }
}
void modificarCliente(eCliente cliente[],int tam)
{
    int idCliente;
    int i;
    char rta;
    printf("Ingrese id del cliente:");
    scanf("%d",&idCliente);
    for(i=0;i<tam;i++)
    {
        if(cliente[i].estado==1 && cliente[i].id==idCliente)
        {
            mostrarCliente(cliente,i);
            printf("Desea modificar este cliente?");
            rta=tolower(getche());
            if(rta=='s')
            {
                printf("\nIngrese Nombre: ");
                fflush(stdin);
                gets(cliente[i].nombre);
                printf("Ingrese Apellido: ");
                fflush(stdin);
                gets(cliente[i].apellido);
                strcpy(cliente[i].nombreApellido,cliente[i].apellido);
                strcat(cliente[i].nombreApellido,", ");
                strcat(cliente[i].nombreApellido,cliente[i].nombre);
                printf("\nEl cliente se ha modificado!");
                break;
            }
            else if(rta!='s')
            {
                printf("\nNo se han realizado modificaciones\n");
                break;
            }
        }
    }
    if(cliente[i].estado==0 && cliente[i].id!=idCliente)
    {
        printf("\nEste cliente no existe\n");
    }
}
void eliminarCliente(eCliente cliente[],int tam)
{
    int idCliente;
    int i;
    char rta;
    printf("Ingrese id del cliente:");
    scanf("%d",&idCliente);
    for(i=0;i<tam;i++)
    {
        if(cliente[i].estado==1 && cliente[i].id==idCliente)
        {
            mostrarCliente(cliente,i);
            printf("Desea eliminar este cliente?");
            rta=tolower(getche());
            if(rta=='s')
            {
                cliente[i].estado=0;
                printf("\nEl cliente se ha eliminado!");
                break;
            }
            else if(rta!='s')
            {
                printf("\nNo se han realizado modificaciones\n");
                break;
            }
        }
    }
    if(cliente[i].estado==0 && cliente[i].id!=idCliente)
    {
        printf("\nEste cliente no existe\n");
    }
}
void mostrarAlquilerPorCliente(eCliente cliente[],eAlquiler alquiler[],int tamA,int tamC)
{
    int i;
    int j;
    for(j=0;j<tamC;j++)
    {
        if(cliente[j].estado==1)
        {
            printf("\n\nNombre y Apellido: %s\nDNI:%d\n",cliente[j].nombreApellido,cliente[j].dni);
            for(i=0;i<tamA;i++)
            {
                if(alquiler[i].estado==1)
                {
                    if(alquiler[i].idCliente==cliente[j].id)
                    {
                      printf("Equipo Alquilado:");
                      mostrarAlquiler(alquiler,i);
                    }
                }
            }
        }
    }
    printf("-----------------------------------\n");
}
void inicializarCliente(eCliente cliente [])
{
    int i;
    int id[5]={100,101,102,103,104};
    int dni[5]={40916811,13739143,11287330,50965841,26548369};
    char nombre[5][20]={"Luz","Melisa","Facundo","Sebastian","Sofi"};
    char apellido[5][15]={"Rubini","Arrua","Valls","Barberan","Ibaceta"};


    for(i=0;i<5;i++)
    {
        cliente[i].id=id[i];
        cliente[i].dni=dni[i];
        strcpy(cliente[i].nombre,nombre[i]);
        strcpy(cliente[i].apellido,apellido[i]);
        strcpy(cliente[i].nombreApellido,cliente[i].apellido);
        strcat(cliente[i].nombreApellido,", ");
        strcat(cliente[i].nombreApellido,cliente[i].nombre);
        cliente[i].estado=1;

    }
}
void inicializarAlquiler(eAlquiler alquiler[],eCliente cliente[])
{
    int i,j;
    int idAlquiler[8]={1,2,3,4,5,6,7,8};
    int idCliente[8]={100,101,102,100,103,104,102,104};
    int equipo[8]={1,2,3,3,2,1,2,1};
    float tiempoEstimado[8]={7.22,63.20,9.2,50.23,71.25,58.2,21.2,58};
    char operador[8][20]={"Lorena","Josias","Marcos","Lucas","Karen","Diana","Marcos","Diana"};


    for(i=0;i<8;i++)
    {
        alquiler[i].idAlquiler=idAlquiler[i];
        alquiler[i].idCliente=idCliente[i];
        alquiler[i].equipo=equipo[i];
        alquiler[i].tiempoEstimado=tiempoEstimado[i];
        strcpy(alquiler[i].operador,operador[i]);
        alquiler[i].estadoAlquiler=4;
        alquiler[i].estado=1;
        for(j=0;j<5;j++)
        {
            if(cliente[j].id==alquiler[i].idCliente)
            {
              cliente[j].contador++;
            }
        }
    }
}
void mostrarCliente(eCliente cliente[],int i)
{
    printf("Nombre y Apellido: %s\nDNI: %d\n",cliente[i].nombreApellido,cliente[i].dni);
}
void mostrarAlquiler(eAlquiler alquiler[],int i)
{
        switch(alquiler[i].equipo)
        {
        case Amoladora:
            printf("Amoladora\n");
            break;
        case Mezcladora:
            printf("Mezcladora\n");
            break;
        case Taladro:
            printf("Taladro\n");
            break;
        }

}
void clienteConMasAlquileres(eCliente cliente[],eAlquiler alquiler[],int tam)
{
    int j;
    int maximo;
    int flag=0;

    for(j=0;j<tam;j++)
    {

        if(flag==0)
        {
            maximo=cliente[j].contador;
            flag=1;
        }
        else
        {
            if(maximo<cliente[j].contador)
            {
                maximo=cliente[j].contador;
            }
        }
    }
    printf("CLIENTES CON MAYOR CANTIDAD DE ALQUILERES:\nCantidad de alquileres: %d\n",maximo);

    for(j=0;j<tam;j++)
    {
        if(maximo==cliente[j].contador)
        {
            mostrarCliente(cliente,j);
        }
    }
    printf("-----------------------------------\n");

}
void finAlquiler(eAlquiler alquiler[],eCliente cliente[],int tamA)
{
    int i,j;
    int idAlquiler;

    printf("Ingrese id de alquiler: ");
    scanf("%d",&idAlquiler);
    for(i=0;i<tamA;i++)
    {

        if(alquiler[i].estado==1 && idAlquiler==alquiler[i].idAlquiler)
        {
            for(j=0;j<5;j++)
            {
                if(cliente[j].id==alquiler[i].idCliente)
                {
                    mostrarCliente(cliente,j);
                    mostrarAlquiler(alquiler,j);
                    alquiler[i].estadoAlquiler=5;
                    printf("Ingrese tiempo de alquiler: ");
                    scanf("%f",&alquiler[i].tiempoReal);
                    printf("Fin de llamada realizado con exito! ");
                    break;
                }

            }
            break;
        }
    }
    if(i==tamA)
    {
        printf("Ese alquiler no existe");
    }
}
void equipoMasAlquilado(eAlquiler alquiler[], eEquipos equipos[],int tamA)
{
    int i, flag=0;
    int maximo;
    inicializarContAcum(equipos);
    for(i=0; i<tamA; i++)
    {
        switch(alquiler[i].equipo)
        {
            case Amoladora:
                equipos[0].cont++;
                break;
            case Mezcladora:
                equipos[1].cont++;
                break;
            case Taladro:
                equipos[2].cont++;
                break;
        }
    }
    for(i=0; i<3; i++)
    {
        if(flag==0 || equipos[i].cont>maximo)
        {
            maximo = equipos[i].cont;
            flag=1;
        }
    }
    printf("EQUIPOS MAS ALQUILADOS: \nCantidad: %d\n",maximo);
    for(i=0; i<3; i++)
    {
        if(maximo==equipos[i].cont)
        {
            switch(equipos[i].equipo)
            {
            case Amoladora:
                printf("Amoladora\n");
                break;
            case Mezcladora:
                printf("Mezcladora\n");
                break;
            case Taladro:
                printf("Taladro\n");
                break;
            }
        }

    }
    printf("-----------------------------------\n");
}
void promedioReal(eAlquiler alquiler[],eEquipos equipo[],int tamA)
{
    inicializarContAcum(equipo);
    int i;
    int flag=0;
    float maximo;
    for(i=0;i<tamA;i++)
    {

        if(alquiler[i].estadoAlquiler==Finalizado)
        {
            switch(alquiler[i].equipo)
            {
            case Amoladora:
                equipo[0].cont++;
                equipo[0].acum+=alquiler[i].tiempoReal;
                break;
            case Taladro:
                equipo[1].cont++;
                equipo[1].acum+=alquiler[i].tiempoReal;
                break;
            case Mezcladora:
                equipo[2].cont++;
                equipo[2].acum+=alquiler[i].tiempoReal;
                break;
            }


        }
    }

     for(i=0;i<3;i++)
    {
        equipo[i].promedioReal=equipo[i].acum/equipo[i].cont;
    }

    for(i=0;i<3;i++)
    {
        if(flag==0||equipo[i].promedioReal>maximo)
        {
            maximo=equipo[i].promedioReal;
            flag=1;
        }
    }

    printf("EQUIPOS CON PROMEDIO MAS ALTO DE REPARACION: \nPromedio: %f\n",maximo);
    for(i=0;i<3;i++)
    {
        if(maximo==equipo[i].promedioReal)
        {
            switch(equipo[i].equipo)
            {
            case Amoladora:
                printf("Amoladora\n");
                break;
            case Mezcladora:
                printf("Mezcladora\n");
                break;
            case Taladro:
                printf("Taladro\n");
                break;
            }
        }
    }
    printf("-----------------------------------\n");
}
void informar(eCliente cliente[],eAlquiler alquiler[],int tamA,int tamC,eEquipos equipo[])
{
    clienteConMasAlquileres(cliente,alquiler,tamC);
    mostrarAlquilerPorCliente(cliente,alquiler,tamA,tamC);
    equipoMasAlquilado(alquiler,equipo,tamA);
    promedioReal(alquiler,equipo,tamA);

}
int validarDNI(int dni,eCliente cliente[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
       while(dni==cliente[i].dni)
       {
            printf("Error! DNI Ya utilizado, reingrese dni: ");
            scanf("%d",&dni);
       }
    }
    return dni;
}

#include <stdio.h>
#include <stdlib.h>

#define FALLA_3G 1
#define FALLA_4G 2
#define FALLA_EQUIPO 3

#define INDETERMINADO 1
#define EN_CURSO 2
#define SIN_RESOLVER 3
#define RESUELTO 4

#define DISPONIBLE 0
#define NO_DISPONIBLE 1




typedef struct
{
    int idLlamada;
    int idAbonado;
    int motivo;
    int estado;
    int duracion;
    int flagEstado;

} sReclamo;

typedef struct
{
    unsigned int idAbonado;
    unsigned int numero;
    char nombre[50];
    char apellido[50];
    int flagEstado;

} sAbonado;

typedef struct
{
    int idAbonado;
    int cont;
} sRPC;

typedef struct
{
    int motivo;
    int cont;
    int acumT;
    float promedio;
} eMotivo;


void cargarAbonados(sAbonado[], int);
void inicializarReclamos(sReclamo[], int);
int crearReclamo(sReclamo[], int, int, sAbonado [], int );
int buscarLugar(sReclamo[],int);
int buscarAbonadoxTelefono(sAbonado[],int,int);
sReclamo newReclamo(int, int, int);
void mostrarReclamo(sReclamo,char[],char[]);
void mostrarTodos(sReclamo[], int, sAbonado[], int);

void finalizarLLamada(sReclamo[], int, sAbonado[], int, int);

void masReclamos(sReclamo[], sAbonado[],int,int);

void reclamoPorFalla(sReclamo[], int);
void reclamoPorFallaDuracion(sReclamo[], int);

void borrarPantalla();

int main()
{
    sAbonado abonados[5];
    sReclamo reclamos[5];
    int guardo;
    int i;
    int ultimoId=1;
    int telefono;
    int idAbonado;

    int opcion;


    inicializarReclamos(reclamos, 5);
    cargarAbonados(abonados, 5);


    do
    {
        printf("1. Alta ABONADO\n2. Modificar ABONADO\n3. Baja ABONADO\n4. Ingresar llamada\n5. Finalizar llamada\n6. Listar\n7.Salir\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 4:
            guardo = crearReclamo(reclamos,5, ultimoId, abonados, 5);
            if(guardo!=-1)
            {
                printf("Reclamo cargado correctamente");
                ultimoId++;
            }
            else
            {
                printf("Error en reclamo... llame luego");
            }


            break;
        case 5:
            printf("Ingrese numero de telefono: ");
            scanf("%d", &telefono);

            finalizarLLamada(reclamos, 5, abonados, 5, telefono);

            break;

        case 6:

            // mostrarReclamo(reclamos, 5, abonados,5);
            printf("Reclamos por clientes\n");

            masReclamos(reclamos,abonados,5,5);

            printf("\nmotivo con mas reclamos\n");
            reclamoPorFalla(reclamos, 5);

            printf("Reclamo que mas tarda en promedio: \n");
            reclamoPorFallaDuracion(reclamos,5);

            break;

        }
        borrarPantalla();
    }
    while(opcion!=7);




    return 0;
}

void cargarAbonados(sAbonado abonados[], int tamA)
{
    int idAbonado[5]= {1,2,3,4,5};
    int numero[5]= {222,333,444,555,666};
    char nombre[5][50]= {"jose","luisa","maria","jorge","luis"};
    char apellido[5][50]= {"Gonzalez","Ramirez","Perez","Lopez","Gomez"};
    int flagEstado[5]= {1,1,1,1,1};
    int i;

    for(i=0; i<tamA; i++)
    {
        abonados[i].idAbonado=idAbonado[i];
        abonados[i].flagEstado=flagEstado[i];
        abonados[i].numero = numero[i];
        strcpy(abonados[i].nombre, nombre[i]);
        strcpy(abonados[i].apellido, apellido[i]);
    }
}
void inicializarReclamos(sReclamo reclamos[], int tamR)
{
    int i;
    for(i=0; i<tamR; i++)
    {
        reclamos[i].estado = INDETERMINADO;
        reclamos[i].flagEstado = DISPONIBLE;
    }
}
int crearReclamo(sReclamo reclamos[], int tamR, int idLlamada, sAbonado abonados[], int tamA)
{
    int hayLugar;
    int motivo;
    int numero;
    int idAbonado;
    hayLugar = buscarLugar(reclamos, tamR);
    if(hayLugar!=-1)
    {
        printf("Ingrese numero de telefono: ");
        scanf("%d", &numero);
        idAbonado = buscarAbonadoxTelefono(abonados,tamA,numero);
        if(idAbonado!=-1)
        {

            printf("Cual es el motivo de su llamada: 1-3g...2-4g...3-Equipo");
            scanf("%d", &motivo);

            reclamos[hayLugar]=newReclamo(idLlamada,idAbonado,motivo);


        }
        else
        {
            printf("Numero inexistente!!");
        }

    }
    else
    {
        printf("Todas las lineas estan ocupadas!!!!!");
    }

    return hayLugar;
}

sReclamo newReclamo(int idLlamada, int idAbonado, int  motivo)
{
    sReclamo unReclamo;
    unReclamo.idLlamada = idLlamada;
    unReclamo.idAbonado = idAbonado;
    unReclamo.motivo = motivo;
    unReclamo.estado = EN_CURSO;
    unReclamo.flagEstado = NO_DISPONIBLE;
    return unReclamo;
}

int buscarLugar(sReclamo reclamos[],int tamR)
{
    int lugar = -1;
    int i;
    for(i=0; i<tamR; i++)
    {
        if(reclamos[i].flagEstado==DISPONIBLE)
        {
            lugar = i;
            break;
        }
    }


    return lugar;
}
int buscarAbonadoxTelefono(sAbonado abonados[],int tamA, int telefono)
{
    int i;
    int idRetorno = -1;
    for(i=0; i<tamA; i++)
    {
        if(telefono == abonados[i].numero)
        {
            idRetorno = abonados[i].idAbonado;
            break;
        }
    }
    return idRetorno;
}

void finalizarLLamada(sReclamo reclamos[], int tamR, sAbonado abonados[], int tamA, int tel)
{
    int idAbonado=-1, idLlamada;
    int i,j;
    int flag=0;
    char nombre[50], apellido[50];
    //idAbonado = buscarAbonadoxTelefono(abonados,tamA,tel);

    printf("Ingrese el id del reclamo: ");
    scanf("%d", &idLlamada);

    for(i=0; i<tamR; i++)
    {
        if(idLlamada==reclamos[i].idLlamada)
        {
            idAbonado=reclamos[i].idAbonado;

            break;
        }
    }

    if(idAbonado!=-1)
    {
        for(j=0; j<tamA; j++)
        {
            if(idAbonado == abonados[j].idAbonado)
            {
                strcpy(nombre, abonados[j].nombre);
                strcpy(apellido, abonados[j].apellido);
                break;
            }
        }

        for(i=0; i<tamR; i++)
        {
            if(idLlamada==reclamos[i].idLlamada)
            {


                mostrarReclamo(reclamos[i], nombre, apellido);

                printf("Ingrese tiempo insumido: ");
                scanf("%d", &reclamos[i].duracion);

                printf("Ingrese estado del reclamo: 3- Sin resolver o 4- Resuelto ");
                scanf("%d", &reclamos[i].estado);

            }
        }



    }
    else
    {
        printf("Su numero no tiene reclamos asociados!!!\n");

    }
}
void mostrarTodos(sReclamo reclamos[], int tamR, sAbonado abonados[], int tamA)
{
    /*int idLlamada;
    int idAbonado;
    int motivo;
    int estado;
    int duracion;*/
    int i,j ;
    char nombre[50], apellido[50];
    printf("Abonado--IdLlamada--Motivo--Duracion--Estado\n");
    for(i=0; i<tamR; i++)
    {
        if(reclamos[i].flagEstado==NO_DISPONIBLE)
        {
            for(j=0; j<tamA; j++)
            {
                if(reclamos[i].idAbonado == abonados[j].idAbonado)
                {
                    strcpy(nombre, abonados[j].nombre);
                    strcpy(apellido, abonados[j].apellido);
                    break;
                }
            }


            mostrarReclamo(reclamos[i], nombre, apellido);
        }

    }
}
void mostrarReclamo(sReclamo reclamo, char nombre[], char apellido[])
{
    printf("%s--%s--%d--%d--%d\n", nombre, apellido, reclamo.motivo, reclamo.duracion, reclamo.estado);
}

void masReclamos(sReclamo reclamos[], sAbonado abonados[],int tamR, int tamA)
{
    sRPC lista[5];
    int i, j, flag=0, maximo;
    for(i=0; i<tamA; i++)
    {
        lista[i].idAbonado=abonados[i].idAbonado;
        lista[i].cont = 0;
    }

    for(i=0; i<tamA; i++)
    {
        for(j=0; j<tamR; j++)
        {
            if(lista[i].idAbonado==reclamos[j].idAbonado)
            {
                lista[i].cont++;
            }
        }
    }

    for(i=0; i<tamA; i++)
    {
        if(flag==0 || lista[i].cont>maximo)
        {
            maximo = lista[i].cont;
            flag=1;
        }
    }

    for(i=0; i<tamA; i++)
    {
        if(lista[i].cont==maximo)
        {
            for(j=0; j<tamA; j++)
            {
                if(lista[i].idAbonado==abonados[j].idAbonado)
                {
                    printf("%s--%s\n", abonados[j].nombre, abonados[j].apellido);
                    break;
                }
            }
        }
    }

}

void reclamoPorFalla(sReclamo reclamos[], int tamR)
{
    int i, flag=0;
    float maximo;
    eMotivo motivos[3];
    for(i=0; i<3; i++)
    {
        motivos[i].motivo = i+1;
        motivos[i].cont=0;
        motivos[i].acumT=0;
    }

    for(i=0; i<tamR; i++)
    {


        switch(reclamos[i].motivo)
        {
        case FALLA_3G:
            motivos[0].cont++;

            break;
        case FALLA_4G:
            motivos[1].cont++;

            break;
        case FALLA_EQUIPO:
            motivos[2].cont++;

            break;
        }


    }



    for(i=0; i<3; i++)
    {
        if(flag==0 || motivos[i].cont>maximo)
        {
            maximo = motivos[i].cont;
            flag=1;
        }
    }

    for(i=0; i<3; i++)
    {
        if(maximo==motivos[i].cont)
        {
            switch(motivos[i].motivo)
            {
            case FALLA_3G:
                printf("Falla 3g\n");
                break;
            case FALLA_4G:
                printf("Falla 4g\n");
                break;
            case FALLA_EQUIPO:
                printf("Falla equipo\n");
                break;
            }
        }
    }
}
void reclamoPorFallaDuracion(sReclamo reclamos[], int tamR)
{
    int i, flag=0, maximo;
    eMotivo motivos[3];
    for(i=0; i<3; i++)
    {
        motivos[i].motivo = i+1;
        motivos[i].cont=0;
        motivos[i].acumT=0;
    }

    for(i=0; i<tamR; i++)
    {

        if(reclamos[i].estado==RESUELTO)
        {
            switch(reclamos[i].motivo)
            {
            case FALLA_3G:
                motivos[0].cont++;
                motivos[0].acumT+=reclamos[i].duracion;

                break;
            case FALLA_4G:
                motivos[1].cont++;
                motivos[1].acumT+=reclamos[i].duracion;
                break;
            case FALLA_EQUIPO:
                motivos[2].cont++;
                motivos[2].acumT+=reclamos[i].duracion;
                break;
            }


        }
    }

     for(i=0; i<3; i++)
    {
        motivos[i].promedio = (float)motivos[i].acumT/motivos[i].cont;
    }

    for(i=0; i<3; i++)
    {
        if(flag==0 || motivos[i].promedio>maximo)
        {
            maximo = motivos[i].promedio;
            flag=1;
        }
    }

    for(i=0; i<3; i++)
    {
        if(maximo==motivos[i].promedio)
        {
            switch(motivos[i].motivo)
            {
            case FALLA_3G:
                printf("Falla 3g\n");
                break;
            case FALLA_4G:
                printf("Falla 4g\n");
                break;
            case FALLA_EQUIPO:
                printf("Falla equipo\n");
                break;
            }
        }
    }
}
void borrarPantalla()
{
    system("pause");
    system("cls");
}

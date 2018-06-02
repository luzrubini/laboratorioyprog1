#include "funciones.h"

eAlumno* newAlumno()
{
    eAlumno* pAlumno;


    pAlumno = (eAlumno*) malloc(sizeof(eAlumno));
    if(pAlumno!=NULL)
    {
        pAlumno->legajo = 0;
        strcpy(pAlumno->nombre,"");
        pAlumno->nota = 0;

    }

    return pAlumno;
}
eAlumno* newAlumnoParametros(int legajo, char nombre[], int nota)
{
    eAlumno* pAlumno;


    pAlumno = newAlumno();
    if(pAlumno!=NULL)
    {
        pAlumno->legajo = legajo;
        strcpy(pAlumno->nombre, nombre);
        pAlumno->nota = nota;

    }

    return pAlumno;
}
void mostrarAlumno(eAlumno* r)
{

    printf("%d--%s--%d \n", r->legajo, r->nombre, r->nota);
}
eAlumno* cargarAlumno(eAlumno* pAlumno)
{
        int legajo, nota;
        char nombre[15];
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);
        printf("Ingrese nota: ");
        scanf("%d", &nota);
        pAlumno = newAlumnoParametros(legajo, nombre, nota);
}

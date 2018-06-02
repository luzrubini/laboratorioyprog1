#include "funciones.h"
#define TAM 5

int main()
{
    system("color 0f");
    eAlumno* pAlumno[TAM];
    eAlumno* pAlumnoAux = NULL;
    eAlumno* lista[TAM];

    int i, alumnosCargados=0;
    char seguir = 'n';

    do
    {
        printf("Alumno cargados %d de %d \n",alumnosCargados,TAM);
        pAlumno[alumnosCargados] = cargarAlumno(pAlumnoAux);
        printf("Desea cargar otro alumno? s/n");
        scanf("%s", &seguir);
        system("cls");
        alumnosCargados++;

    }while(seguir == 's' && alumnosCargados<TAM);

    printf("Alumnos cargados %d de %d \n",alumnosCargados,TAM);
    for(i=0 ; i<alumnosCargados ; i++)
    {
           if(pAlumno!=NULL)
        {
            lista[i] = pAlumno[i];
            mostrarAlumno(lista[i]);
        }
    }

    return 0;
}

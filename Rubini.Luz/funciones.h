#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[15];
    int nota;
} eAlumno;

void mostrarAlumno(eAlumno*);

eAlumno* newAlumno();//Constructor por defecto
eAlumno* newAlumnoParametros(int, char[], int);// Constructor parametrizado
eAlumno* cargarAlumno(eAlumno*);

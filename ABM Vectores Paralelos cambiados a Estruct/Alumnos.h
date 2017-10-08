
typedef struct
{
    int legajo;
    char nombre[50];
    int nota1;
    int nota2;
    float promedio;
    int estado;
}eAlumno;

void altaAlumno(eAlumno[], int);
void mostrarAlumnos(eAlumno[], int);
void ordenarAlumnos(eAlumno[], int);
void modificarAlumno(eAlumno[], int);
void eliminarAlumno(eAlumno[], int);
void inicializarAlumno(eAlumno[], int);
void mostrar(eAlumno[], int);

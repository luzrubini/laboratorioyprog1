typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    char nombreApellido[40];
    char nacionalidad[20];
    int competencias;

}ePatinador

typedef struct
{
    int id;
    int idPatinador;

}eCompetencia;

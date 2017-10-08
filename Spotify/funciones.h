typedef struct
{
    int idInterprete;
    char nombre [100];
    char nacionalidad[100];
    int estado;
    int contador;

}eInterprete;

typedef struct
{
    int idCancion;
    char titulo [100];
    int interprete;
    float duracion;
    int estado;

}eCancion;
void inicializarEstado(eInterprete[],int);
void inicializarEstadoCancion(eCancion[],int);
void inicializarInterprete(eInterprete[],int);
void inicializarCancion(eCancion[], int);


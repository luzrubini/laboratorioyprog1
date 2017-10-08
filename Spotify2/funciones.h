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

typedef struct
{
    int idCancion;
    int idInterprete;
    int estado;
}eCancionInterprete;

void inicializarEstados(eInterprete[],eCancion[],eCancionInterprete[],int,int);
void inicializarInterprete(eInterprete[],int);
void inicializarCancion(eCancion[], int);


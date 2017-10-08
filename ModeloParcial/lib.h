typedef struct
{
    int id; //Id auto-incrementable
    int numero;
    char nombre[20];
    char apellido[15];
    char nombreApellido[37];
    int estado;

}eAbonado;
typedef struct
{
    int numeroDeReclamo;
    char motivo[50];
    int idAbonado;
    char estadoDelReclamo[20];
    float tiempoDeLlamada;
    int estado;

}eReclamo;

void altaAbonado(eAbonado[],int);
void modificarAbonado(eAbonado[],int);
void eliminarAbonado(eAbonado[],int);
void nuevaLlamada(eAbonado[],eReclamo[],int);
void inicializarAbonado(eAbonado[],int);
void inicializarEstadoReclamo(eReclamo[],int);
void finLlamada(eReclamo[],eAbonado[],int);
void mostrarAbonado(eAbonado[],int);
void mostrarReclamo(eReclamo[],int);
void motivoReclamo(eReclamo[],int);


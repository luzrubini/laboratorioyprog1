typedef struct
{
    int dni;
    char nombre[40];
    int edad;
}ePersona;

void cargarPersona(ePersona*,int);
int generarPersona(ePersona*,int,char[],int);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 3
typedef struct
{
    int legajo;
    char nombre[50];
    float peso;
    char sintoma[30];
    int estado;
} ePaciente;

void mostrarPaciente(ePaciente);
void mostrarTodosLosPacientes(ePaciente[], int);
void cargarTodosLosPacientes(ePaciente[], int);
void inicializar(ePaciente[], int);

int main()
{

   ePaciente listaPacientes[TAM];
   int i;
   for(i=0;i<TAM;i++)
   {
       listaPacientes[i].estado=0;
   }

    inicializar(listaPacientes, TAM);
    //cargarTodosLosPacientes(listaPacientes,TAM);
    mostrarTodosLosPacientes(listaPacientes, TAM);


    return 0;
}

void mostrarPaciente(ePaciente paciente)
{
     printf("%d-%s-%f-%s\n", paciente.legajo, paciente.nombre, paciente.peso,paciente.sintoma);
}

void mostrarTodosLosPacientes(ePaciente lista[], int tam)
{
   int i;

    for(i=0; i<tam; i++)
   {
       mostrarPaciente(lista[i]);
   }
}

/*void cargarTodosLosPacientes(ePaciente lista[], int tam)
{
    int i;

     for(i=0; i<tam; i++)
   {
       printf("Ingrese legajo: ");
       scanf("%d", &lista[i].legajo);
       printf("Ingrese nombre: ");
       fflush(stdin);
       gets(lista[i].nombre);
       printf("Ingrese peso: ");
       scanf("%f", &lista[i].peso);
       printf("Ingrese sintoma: ");
       fflush(stdin);
       gets(lista[i].sintoma);
   }
}*/
void inicializar(ePaciente lista[], int tam)
{
    int i;
    int legajos[3]={10,11,12};
    char nombres[3][50]={"Alfonsin","Caro","Alec"};
    float pesos[3]={20,50,65};
    char sintomas[3][50]={"Dolor de cabeza","Dolor en la pierna","Vomitos"};
    int estados[3]={1,1,1};

    for(i=0;i<tam; i++)
  {
      lista[i].legajo = legajos[i];
      strcpy( lista[i].nombre, nombres[i]);
      lista[i].peso = pesos[i];
      strcpy( lista[i].sintoma, sintomas[i]);
      lista[i].estado = estados[i];
  }


}

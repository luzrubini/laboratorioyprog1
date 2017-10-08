#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int dni;
    int estado;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**void inicializarEstado(EPersona listaPersonas[],int tam)
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni);
/*void altaPersona(EPersona[],int);*/
void inicializarEstado(EPersona[],int);
void inicializarPersona(EPersona[],int);
void mostrarPersona(EPersona[],int);
void ordenarPersonas(EPersona[],int);
void borrarPersona(EPersona[],int);


#endif // FUNCIONES_H_INCLUDED

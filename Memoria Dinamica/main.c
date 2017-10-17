#include <stdio.h>
#include <stdlib.h>
#define T 5
int main()
{
    int* pInt ;
    int *pAux ;
    int i;
    int vector[5]={0};
    //pInt = (int*) malloc(sizeof(int)*T);
    pInt = calloc(T, sizeof(int));
    if(pInt!=NULL)
    {
        printf("Iniciales del puntero: \n");

       for(i=0; i<T; i++)
       {
           printf("%d\n",*(pInt+i));
       }

       for(i=0; i<T; i++)
       {
           printf("Ingrese un numero: ");
           scanf("%d", pInt+i);
       }
       printf("MUESTRO LOS 5 INICIALES:\n");
       for(i=0; i<T; i++)
       {
           printf("%d\n",*(pInt+i));
       }

       pAux = (int*) realloc(pInt, sizeof(int)* (T+5));
       if(pAux!=NULL)
       {
           pInt = pAux;

           for(i=T; i<T+5; i++)
           {
                printf("Ingrese un numero: ");
                scanf("%d", pInt+i);
           }

           printf("MUESTRO LOS 10:\n");
           for(i=0; i<T+5; i++)
           {
               printf("%d\n",*(pInt+i));
           }

           pInt = realloc(pInt, sizeof(int) * 3);

           printf("MUESTRO LOS 3 QUE ME QUEDAN:\n");
           for(i=0; i<3; i++)
           {
               printf("%d\n",*(pInt+i));
           }

            free(pInt);
            free(pAux);

       }
       else
       {
           printf("No se ha reservado espacio en memoria!!!");
       }




    }
    else
    {
        printf("No se ha reservado espacio en memoria!!!");
    }



    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    char id[500],name[500],lastName[500],isEmpty[500];
    Employee* empleado;

    if(pArrayListEmployee!=NULL)
    {
        pFile=fopen("data.csv","r");
        if(pFile!=NULL)
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,name,lastName,isEmpty);
            while(!feof(pFile))
            {
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,name,lastName,isEmpty);
                empleado=employee_new();
                empleado->id=atoi(id);
                strcpy(empleado->name,name);
                strcpy(empleado->lastName,lastName);
                if(strcmp(isEmpty,"true")==0)
                {
                    empleado->isEmpty=1;
                }
                else
                {
                    empleado->isEmpty=0;
                }
                al_add(pArrayListEmployee,empleado);
           }
        }
    }
    fclose(pFile);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "DataManager.h"

/** \brief crea un archivo "out" del ArrayList que recibe
 *
 * \param list ArrayList* es un puntero a un array
 * \param
 * \return retorna (-1) por default, (0) si se pudo crear el archivo.
 *
 */

int dm_dumpEmployeeList(ArrayList* list)
{
    int i;
    int retorno=-1;
    FILE* pFileFilteredEmployees = fopen("out.csv","wb");
    void* pEmployee=NULL;
    if(pFileFilteredEmployees!=NULL)
    {
            fprintf(pFileFilteredEmployees, "%s ,%s ,%s ,%s , %s \n", "ID", "NAME", "LASTNAME", "AGE" , "TYPE");
        for(i=0;i<al_len(list);i++)
        {
            pEmployee = al_get(list,i);
            fprintf(pFileFilteredEmployees,"%d ,%s, %s, %d, %d \n" , employee_getId(pEmployee),employee_getName(pEmployee),employee_getLastName(pEmployee),employee_getAge(pEmployee),employee_getType(pEmployee));
            retorno=0;
        }

    }
    fclose(pFileFilteredEmployees);
    return retorno;


}

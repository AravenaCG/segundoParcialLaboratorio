#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "validar.h"

/** \brief vuelva el contenido del archivo "DATA" en el ArrayList.
 *
 * \param   ÀrrayListEmployee ArrayList* es un puntero a un array donde se volcaran los datos de existir.
 * \param
 * \return \return retorna (-1) por default, (0) si se pudo cargar los datos en el ArrayList
 */


int parserEmployee(ArrayList* pArrayListEmployee)
{
    FILE *pFile;
    int retorno=-1;
    char id[50],name[50],lastName[50],age[50],type[50];
    Employee* auxEmployee;
    int idConverted;
    int ageConverted;
    int typeConverted;
 //   int auxAge;

    pFile = fopen("data.csv","r");

    if(pFile != NULL)

        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,name,lastName,age,type);
    while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,name,lastName,age,type);


    /*    if (val_validarNombre(name)==0)
        {
            if (val_validarNombre(lastName)==0)
            {
                if (esNumerico(type))
                {
                    if (esNumerico(id))
                    {
                        if (esNumerico(age)==0)
                        {
                            auxAge=atoi(age);
                            if (auxAge >0 && auxAge<150)
                       */   //  {
                                typeConverted = atoi(type);
                                ageConverted = atoi(age);
                                idConverted = atoi(id);
                      //          auxAge = atoi(age);
                                auxEmployee = employee_newContructor(idConverted,name,lastName,ageConverted,typeConverted);
                                al_add(pArrayListEmployee,auxEmployee);
                                retorno=0;
                       //     }
                       // }
                   // }
               // }
           // }


        //}



    }
    return retorno;
}

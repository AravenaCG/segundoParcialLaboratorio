#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include <string.h>



Employee* employee_new(void)
{
    return malloc(sizeof(Employee));

}


/** \brief devuelve un puntero a un  empleado ya seteando los campos del mismo
 *
 * \param id , name, lastName, age, type son los campos que recibe que corresponden a los mismos que tiene un Empleado definido en su estructura
 * \param
 * \return pEmployee puntero a empleado con los campos ya setteados
 *
 */

Employee* employee_newContructor(int id, char *name, char *lastName, int age,  int type)
{
    Employee* pEmployee = malloc(sizeof(Employee));
    if (pEmployee!=NULL)
    {
        employee_setName(pEmployee,name);
        employee_setLastName(pEmployee,lastName);
        employee_setId(pEmployee,id);
        employee_setAge(pEmployee, age);
        employee_setType(pEmployee,type);

    }
    return pEmployee;
}

/** \brief libera el espacion reservado para el empleado
 *
 * \param this Employee* puntero a empleado que va a ser liberado
 * \param
 * \return
 *
 */


void employee_delete(Employee* this)
{
    if (this != NULL)
        free(this);

}

/** \brief imprime un empleado
 *
 * \param this Employee* puntero a empleado
 * \param
 * \return
 *
 */


void employee_print(Employee* this)
{
    if (this!=NULL)
    {

        printf("ID: %d - NAME: %s- LASTNAME: %s - AGE: %d - TYPE : %d \n",employee_getId(this),
        employee_getName(this),employee_getLastName(this),employee_getAge(this),employee_getType(this));

    }
}

/** \brief filtra al empleado si es "PROGRAMADOR" y si tiene mas de 30 años
 *
 * \param item void* puntero
 * \param
 * \return (-1) por default , (1) si cumple las condiciones
 *
 */


int employee_filterEmployee(void* item)
{
    Employee* auxEmployee = (Employee*)item;
    int auxType;
    int auxAge;
    int retorno=-1;
    auxType = employee_getType(auxEmployee);
    auxAge = employee_getAge(auxEmployee);
    if (( auxType == 4 ) && ( auxAge >30))
    {
        retorno =1 ;
    }
    return retorno;
}

/** \brief obtiene un campo del Empleado
 *
 * \param this Employee* puntero a empleado
 * \param
 * \return el campo seleccionado
 *
 */

char* employee_getName(Employee* this)
{
    char* retorno= NULL;
    if (this != NULL)
    {
        retorno = this->name;

    }
    return retorno;
}

/** \brief settea un campo del Empleado
 *
 * \param this Employee* puntero a empleado
 * \param
 * \return (0) si se pudo settear
 *
 */


int employee_setName(Employee* this, char *name)
{
    int retorno = -1;
    if (this != NULL)
    {
        retorno = 0;
        strncpy(this->name,name,51);
    }
    return retorno;
}


/** \brief obtiene un campo del Empleado
 *
 * \param this Employee* puntero a empleado
 * \param
 * \return el campo que se desea
 *
 */
char* employee_getLastName(Employee* this)
{
    char* retorno= NULL;
    if (this != NULL)
    {
        retorno = this->lastName;

    }
    return retorno;
}

/** \brief settea un campo del Empleado
 *
 * \param this Employee* puntero a empleado
 * \param
 * \return (0) si se pudo settear
 *
 */

int employee_setLastName(Employee* this, char *lastName)
{
    int retorno = -1;
    if (this != NULL)
    {
        retorno = 0;
        strncpy(this->lastName,lastName,51);
    }
    return retorno;
}


/** \brief settea un campo del Empleado
 *
 * \param this Employee* puntero a empleado
 * \param
 * \return (0) si se pudo settear
 *
 */

int employee_setId(Employee* this, int id)
{
    int retorno = -1;
    if (this != NULL)
    {
        retorno = 0;
        this->id = id;
    }
    return retorno;
}


/** \brief obtiene un campo del Empleado
 *
 * \param this Employee* puntero a empleado
 * \param
 * \return el campo seleccionado
 *
 */
int employee_setAge(Employee* this, int age)
{
    int retorno = -1;
    if (this != NULL)
    {
        retorno = 0;
        this->age = age;
    }
    return retorno;
}


/** \brief obtiene un campo del Empleado
 *
 * \param this Employee* puntero a empleado
 * \param
 * \return el campo seleccionado
 *
 */
int employee_getAge(Employee* this)
{
        int retorno;
        retorno = this->age;
        return  retorno;

}

/** \brief obtiene un campo del Empleado
 *
 * \param this Employee* puntero a empleado
 * \param
 * \return el campo seleccionado
 *
 */

int employee_getId(Employee* this)
{
    int retorno =-1;
    if (this != NULL)
    {
        retorno = this->id;

    }
    return retorno;
}

/** \brief settea un campo del Empleado
 *
 * \param this Employee* puntero a empleado
 * \param
 * \return (0) si se pudo settear
 *
 */

int employee_setType(Employee* this, int type)

{
    int retorno=-1;
    if (this != NULL)
    {
        retorno = 0;
        this->type = type;
    }
    return retorno;
}


/** \brief obtiene un campo del Empleado
 *
 * \param this Employee* puntero a empleado
 * \param
 * \return el campo seleccionado
 *
 */
int employee_getType(Employee* this)
{
    int retorno;
    retorno = this->type;
    return retorno;
}




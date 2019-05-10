#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <conio.h>
#include <ctype.h>

typedef struct
{

    int id;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int sector;
    int isEmpty;

} eEmpleado;

/** \brief Es el menu de opciones
 *
 * \return int devuelve la opcion elegida
 *
 */
int menu();


/** \brief indica que todos los campos de la estructura estan vacios
 *
 * \param vec[] eEmpleado es el vector de la estructura
 * \param tam int es el tamaño del vector
 * \return void
 *
 */
void inicializarEmpleados(eEmpleado vec[], int tam);


/** \brief busca una estructura libre para completar con los datos ingresados
 *
 * \param vec[] eEmpleado es el vector de la estructura
 * \param tam int es el tamaño del vector
 * \return int devuelve si hay espacio libre o no
 *
 */
int buscarLibre(eEmpleado vec[], int tam);


/** \brief busca si existe algun empleado con el id ingresado por el usuario
 *
 * \param vec[] eEmpleado es el vector de la estructura
 * \param tam int es el tamaño del vector
 * \param id int id ingresado por el usuario para buscar algun empleado
 * \return int devuelve si encontro o no al empleado
 *
 */
int buscarEmpleado(eEmpleado vec[], int tam, int id);


/** \brief realiza el alta del empleado, almacenando los datos pedidos
 *
 * \param vec[] eEmpleado es el vector de la estructura
 * \param tam int es el tamaño del vector
 * \return void
 *
 */
void altaEmpleado(eEmpleado vec[], int tam);


/** \brief modifica el campo deseado de un empleado
 *
 * \param vec[] eEmpleado es el vector de la estructura
 * \param tam int es el tamaño del vector
 * \return void
 *
 */
void modificarEmpleado(eEmpleado vec[], int tam);


/** \brief realiza la baja del empleado
 *
 * \param vec[] eEmpleado es el vector de la estructura
 * \param tam int es el tamaño del vector
 * \return void
 *
 */
void bajaEmpleado(eEmpleado vec[], int tam);


/** \brief muestra el empleado que se pide por id
 *
 * \param vec[] eEmpleado es el vector de la estructura
 * \param tam int es el tamaño del vector
 * \return void
 *
 */
void mostrarEmpleado(eEmpleado vec[], int tam);

/** \brief muestra todos los empleados
 *
 * \param vec[] eEmpleado es el vector de la estructura
 * \param tam int es el tamaño del vector
 * \return void
 *
 */
void mostrarEmpleados(eEmpleado vec[], int tam);

//No pude realizar las funciones de listar alfabeticamente por sector y el promedio

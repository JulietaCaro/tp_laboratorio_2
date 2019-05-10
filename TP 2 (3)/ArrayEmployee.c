#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "ArrayEmployee.h"
#include "input.h"

void inicializarEmpleados(eEmpleado vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        vec[i].isEmpty = 0;
    }
}

int menu()
{
    int opcion;

    system("cls");
    printf("\n  *** MENU DE OPCIONES ***\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Modificacion Empleado\n");
    printf("3- Baja Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


int buscarLibre(eEmpleado vec[], int tam)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarEmpleado(eEmpleado vec[], int tam, int id)
{

    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if(vec[i].isEmpty == 1 && vec[i].id == id)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

void altaEmpleado(eEmpleado vec[], int tam)
{

    int indice;
    int id;
    int esta;


    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {

        printf("\nNo hay lugar en el sistema\n");
    }
    else
    {
        printf("Ingrese id: ");
        scanf("%d", &id);

        esta = buscarEmpleado(vec, tam, id);

        if( esta != -1)
        {
            printf("Existe un empleado de id %d en el sistema\n", id);
        }
        else
        {
            vec[indice].id = id;
            getString(vec[indice].nombre, "Ingrese el nombre del empleado: ", "El nombre excede el largo", 2, 51);
            getString(vec[indice].apellido, "Ingrese el apellido del empleado: ", "El apellido excede el largo", 2, 51);
            getFloat(&vec[indice].sueldo, "Ingrese el sueldo del empleado: ", "Debe ser mayor a cero", 1, 1000000);
            printf("\nSECTORES\n1.FINANZAS\n2.RRHH\n3. VENTAS\n4.LEGALES\n5.LIMPIEZA");
            getInt(&vec[indice].sector, "\nIngrese el sector del empleado: ", "\nNo existe", 1, 5);

            vec[indice].isEmpty = 1;

            printf("Alta empleado exitosa!!!\n\n");

        }
    }

}
void modificarEmpleado(eEmpleado vec[], int tam)
{
    int opcion;
    int indice;
    int id;

    printf("\n1. Nombre");
    printf("\n2. Apellido");
    printf("\n3. Sueldo");
    printf("\n4. Sector");

    printf("\n¿Que opcion desea modificar?: ");
    scanf("%d", &opcion);

    printf("\nIngrese el id del empleado a modificar: ");
    scanf("%d", &id);

    indice=buscarEmpleado(vec, tam, id);

    if(indice==-1)
    {
        printf("\nNo existe un empleado con ese id");
    }
    else
    {
        switch(opcion)
        {
        case 1:
            getString(vec[indice].nombre, "\nIngrese el nombre: ", "\nExcede el largo", 1, 51);
        break;

        case 2:
            getString(vec[indice].apellido, "\nIngrese el apellido: ", "\nExcede el largo", 1, 51);
        break;

        case 3:
            getFloat(&vec[indice].sueldo, "\nIngrese el sueldo: ", "\nExcede el limite", 1, 1000000);
        break;

        case 4:
            printf("\nSECTORES\n1.FINANZAS\n2.RRHH\n3. VENTAS\n4.LEGALES\n5.LIMPIEZA");
            getInt(&vec[indice].sector, "\nIngrese el sector: ", "\nNo existe", 1, 5);
        break;

        default:
            printf("\nNo existe esa opcion");
    }
}
}

void bajaEmpleado(eEmpleado vec[], int tam)
{
    int id;
    int confirmacion;

    printf("\nIngrese el id del empleado a bajar: ");
    scanf("%d", &id);

    for(int i=0; i<tam; i++)
    {
        if(id==vec[i].id)
        {
            printf("\n¿Desea dar de baja? s/n: ");
            confirmacion=getche();

            if(tolower(confirmacion)=='s')
            {
                printf("\nBaja exitosa!!!");
                vec[i].isEmpty=0;
                break;
            }
            else
            {
                printf("\nBaja cancelada");
                break;
            }
        }
        else
        {
            printf("\nNo existe ese id");
        }
    }
}

void mostrarEmpleado(eEmpleado vec[], int tam)
{
    int id;
    int indice;

    printf("\nIngrese el id del empleado a mostrar: ");
    scanf("%d", &id);

    indice = buscarEmpleado(vec, tam, id);

    if( indice == -1)
    {

        printf("\nNo existe un empleado con ese id");
    }
    else
    {
        printf("\n    NOMBRE          APELLIDO  SUELDO  SECTOR");

        printf("\n%10s %10s %10.2f %5d", vec[indice].nombre, vec[indice].apellido, vec[indice].sueldo, vec[indice].sector);
    }
}

void mostrarEmpleados(eEmpleado vec[], int tam)
{
    int contador;

     printf("\n    NOMBRE          APELLIDO  SUELDO  SECTOR");

     for(int i=0; i<tam; i++)
     {
         mostrarEmpleado(vec, tam);
        contador++;
     }
     if(contador==0)
     {
         printf("\nNo hay empleados para mostrar");
     }
}

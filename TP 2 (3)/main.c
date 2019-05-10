#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#define CANT_EMP 100
#include "ArrayEmployee.h"
#include "input.h"

int main()
{
    char seguir = 's';
    char confirma;

    eEmpleado listaEmp[CANT_EMP];

     do
    {
        switch(menu())
        {

        case 1:
            altaEmpleado(listaEmp, CANT_EMP);
            system("pause");
            break;

        case 2:
            modificarEmpleado(listaEmp, CANT_EMP);
            printf("\nModificacion exitosa!!!");
            system("pause");
         break;

        case 3:
            bajaEmpleado(listaEmp, CANT_EMP);
            system("pause");
        break;

        case 4:
            mostrarEmpleados(listaEmp, CANT_EMP);
            system("pause");
        break;

        case 5:
             printf("\nConfirma salida s/n?: ");
            fflush(stdin);
            confirma = getche();

            if( tolower(confirma) == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("\n Opcion invalida\n\n");
            system("break");
        }
    }
    while(seguir == 's');

    return 0;
}

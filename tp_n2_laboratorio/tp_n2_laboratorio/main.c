#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "delPercio.h"


int main()
{

    EPersona xPersona[20];
    char seguir='s';

    inicializarPersonas(xPersona,20);


    while(seguir=='s')
    {
        system("cls");


        switch(menu())
        {
            //1- Agregar persona
            case 1:
                altaPersona(xPersona,20);
                system("pause");
                break;


            //2- Borrar persona
            case 2:

                bajaPersona(xPersona, 20);
                break;


            //3- Imprimir lista ordenada por  nombre
            case 3:

               printf("\n\n                                  Nombre          Dni      Edad\n\n");

                ordenarPersona(xPersona);
                mostrarPersonas(xPersona,20);

                system("pause");
                break;


            //4- Imprimir grafico de edades
            case 4:
                graficoPersonas(xPersona);
                break;


            //5- Salir
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}


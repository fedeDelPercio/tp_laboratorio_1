#include <stdio.h>
#include <stdlib.h>
#include "delPercio.h"

int main()
{   //Variables
    char seguir='s';
    int opcion=0;
    float num1 = 0,num2 = 0;
    float resultado;
    int flag = 0;


    do
    {
        //Limpia pantalla
        system("cls");

        printf("\n1- Ingresar 1er operando (A=%.2f)\n",num1);
        printf("2- Ingresar 2do operando (B=%.2f)\n",num2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");


        // Pide operacion automaticamente
        if(flag == 0)
        {
                printf("\n Ingrese 1er operando: ");
                fflush(stdin);
                scanf("%f",&num1);

                printf("\n Ingrese 2do operando: ");
                fflush(stdin);
                scanf("%f",&num2);

                flag = 1;
        }

        // Pide opcion

        printf("\nIngrese opcion: ");
        scanf("%d",&opcion);

        //Valido opcion correcta

        while(opcion > 9 || opcion < 1)
        {
            printf("\nError opcion no valida - Reingrese: ");
            scanf("%d",&opcion);
        }




        switch(opcion)
        {
            case 1: //num1
                printf("Ingrese 1er operando: ");
                fflush(stdin);
                scanf("%f",&num1);
                break;

            case 2: //num2
                printf("Ingrese 2do operando: ");
                fflush(stdin);
                scanf("%f",&num2);
                break;

            case 3: //suma
                resultado = suma(num1,num2);
                printf("Resultado de suma: %.2f \n",resultado);
                system("pause");
                break;

            case 4: //resta
                resultado = resta(num1,num2);
                printf("Resultado de resta: %.2f \n",resultado);
                system("pause");
                break;

            case 5: //division

                while(num2 == 0)
                {
                    printf("\n 0 no es una opcion valida- Reingrese: ");
                    fflush(stdin);
                    scanf("%f",&num2);
                }

                resultado = division(num1,num2);
                printf("Resultado de division: %.2f \n",resultado);
                system("pause");

                break;

            case 6: //multiplicacion
                resultado = multiplicacion(num1,num2);
                printf("Resultado de multiplicacion: %.2f \n",resultado);
                system("pause");
                break;

            case 7: //factorial
                resultado = factorial(num1);
                printf("Resultado de factorial: %.2f \n",resultado);
                system("pause");
                break;

            case 8: //calcular todas las operaciones

                resultado = suma(num1,num2);
                printf("Resultado de suma: %.2f \n",resultado);

                resultado = resta(num1,num2);
                printf("Resultado de resta: %.2f \n",resultado);

                resultado = division(num1,num2);
                printf("Resultado de division: %.2f\n",resultado);

                resultado = multiplicacion(num1,num2);
                printf("Resultado de multiplicacion: %.2f \n",resultado);

                resultado = factorial(num1);
                printf("Resultado de factorial(operacion 1): %2.f \n",resultado);

                system("pause");

                break;

            case 9: //Cierra programa
                seguir = 'n';
                break;

        }




    }while(seguir=='s');


    return 0;

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;




int menu()
{
        int opcion = 0;


        //Menu Principal
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        printf("\n\n-> Ingrese opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        while(opcion < 0 || opcion > 5)
        {
        printf("\n\n->ERROR Reingrese opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
        }

        return opcion;
}




void mostrarPersona(EPersona unaPersona)
{
    printf("%40s   %10d       %3d\n",unaPersona.nombre, unaPersona.dni,unaPersona.edad);
}




void mostrarPersonas(EPersona personas[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(personas[i].estado == 1)
        {
            mostrarPersona(personas[i]);
        }
    }

    printf("\n\n");


}




void inicializarPersonas(EPersona personas[], int tam)
{
    int i;

     for(i=0; i<tam; i++)
    {
       personas[i].estado = 0;
    }

}




int buscarLibre(EPersona personas[], int tam)
{
    int indice =-1;
    int i;

    for(i=0; i< tam; i++)
    {
        if(personas[i].estado ==0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}




int buscarPersona(EPersona personas[], int tam, int dni)
{
    int indice =-1;
    int i;

    for(i=0; i< tam; i++)
    {
        if(personas[i].dni == dni)
        {
            indice = i;
            break;
        }
    }

    return indice;

}




void altaPersona(EPersona personas[], int tam)
{
    int indice;
    int dni;
    int esta;

    indice = buscarLibre(personas, tam);

    if(indice == -1)
    {
        printf("\nNo hay lugar disponible\n");
    }
    else
    {
        printf("\nIngrese DNI Persona: ");
        scanf("%d", &dni);

        while (dni < 1000000 || dni > 99999999)
        {
        printf("\nERROR Reingrese DNI Persona: ");
        scanf("%d", &dni);
        }


        esta = buscarPersona(personas, tam, dni);

        if(esta != -1)
        {
            printf("\nLa persona ya esta dada de alta en el sistema\n");
        }
        else
        {
            personas[indice].dni = dni;

            printf("\nIngrese el nombre de la persona: ");
            fflush(stdin);
            gets(personas[indice].nombre);

            printf("\nIngrese edad: ");
            scanf("%d", &personas[indice].edad);

            while (personas[indice].edad < 0 || personas[indice].edad > 100)
            {
            printf("\nERROR Reingrese edad: ");
            scanf("%d", &personas[indice].edad);
            }


            personas[indice].estado = 1;

            printf("\nPersona agregada con exito!!!\n\n");

        }
    }
}




void bajaPersona(EPersona personas[], int tam)
{
    int indice;
    int dni;
    char baja;

    printf("\nIngrese DNI persona: ");
    scanf("%d", &dni);

    indice = buscarPersona(personas, tam, dni);

    if(indice == -1)
    {
        printf("\nLa persona de dni %d no se encuentra en el sistema\n\n", dni);
    }
    else
    {
        printf("\nDatos de la Persona\n\n");
               printf("\n\n                                  Nombre          Dni      Edad\n\n");
        mostrarPersona(personas[indice]);

        printf("\n\nConfirma la baja de la persona: s/n ");
        fflush(stdin);
        scanf("%c", &baja);

        if(baja == 's')
        {
            personas[indice].estado = 2;

            printf("\n\nDado de baja correctamente ");
        }
        else
        {
            while(baja != 'n' && baja != 's')
            {

                printf("Error Reingrese caracter s/n: ");
                fflush(stdin);
                scanf("%c", &baja);


                if(baja == 's')
                {
                    personas[indice].estado = 2;

                    printf("\n\nDado de baja correctamente ");

                    break;
                }

                if(baja == 'n')
                {
                    printf("\n\nLa baja ha sido cancelada por el usuario\n\n");
                }

            }

        }

    }

      system("pause");
}




void ordenarPersona (EPersona personas[])
{
    int i;
    int j;
    EPersona auxPersona;

        for(i=0; i<19; i++)
        {
           for(j=i+1; j<20; j++)
           {
               if( strcmp(personas[i].nombre, personas[j].nombre)>0)
               {
                    auxPersona = personas[i];
                    personas[i] = personas[j];
                    personas[j] = auxPersona;
               }
           }

       }
}




int graficoPersonas(EPersona personas[])
{

    int i;
    int c19a35 =0;
    int c35 =0;
    int c18 =0;
    int mayor;
    int flag=0;

    for(i=0; i<20; i++)
    {
        if(personas[i].estado==1 && personas[i].edad < 19)
        {
            c18++;
        }
        if(personas[i].estado==1 && personas[i].edad > 18 && personas[i].edad < 36)
        {
            c19a35++;
        }
        if(personas[i].estado==1 && personas[i].edad > 35)
        {
            c35++;
        }

    }


    if(c18 >= c19a35 && c18 >= c35)
    {
        mayor = c18;
    }
    else
    {

        if(c19a35 >= c18 && c19a35 >= c35)
            {

            mayor = c19a35;

            }

        else
            {

            mayor = c35;

            }
    }

    printf("\n\n");

    for(i=mayor; i>0; i--)
    {
        if(i<20)
        {
            printf("%02d|",i);
        }

        else
            printf("%02d|",i);

        if(i<= c18)
        {
            printf("*");
        }

        if(i<= c19a35)
        {
            flag=1;
            printf("\t*");
        }

        if(i<= c35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }

        printf("\n");
    }
    printf("--|-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d\n", c18, c19a35, c35);

    system("pause");

    return 0;
}



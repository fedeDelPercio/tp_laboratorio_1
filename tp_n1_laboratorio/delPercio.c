#include <stdio.h>
#include <stdlib.h>
#include "delPercio.h"

//Desarrollos

float suma(float x, float y)
{
    float sumar = x + y;
    return sumar;
}


float resta(float x, float y)
{
    float restar = x - y;
    return restar;
}


float multiplicacion(float x ,float y)
{
    float multiplicar = x * y;
    return multiplicar;
}


float division(float x, float y)
{
    float dividir =(float) x/y;
    return dividir;
}


float factorial(float x)
{
    int i;
    float fact = 1;

    for(i = 1; i <= x; i++)
    {
        fact =fact * i;
    }

    return fact;

}



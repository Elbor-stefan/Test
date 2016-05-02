#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMITE_N_CONSECUTIVOS 5
#define LIMITE_N_ITERACION 3

/**regresa la incognita X**/
int obtenerConsecutivoInicial(int, int);
void mostrarOperacion(int, int);

int main(/**int argc, char** argv**/)
{
    int numeroEntero, numerosConsecutivos, resultadoDeLaIncognita;
    double numeroDeDoblePresicion, errorDePresicion;

    numeroEntero = 0;
    numeroDeDoblePresicion = 0.0;
    errorDePresicion = 0.0;

    printf("Ingrese un numero: " );
    fflush(stdin);
    scanf( "%lf", &numeroDeDoblePresicion );

    numeroEntero = numeroDeDoblePresicion;
    errorDePresicion = fabs(numeroEntero - numeroDeDoblePresicion);

    if ( errorDePresicion > 0.001 )
    {
        printf( "Error de entrada!!!\n" );
    }
    else
    {
        /** (2^n| n>0) no muestra resultados **/
        numerosConsecutivos = 2;
        resultadoDeLaIncognita = 0;
        while (resultadoDeLaIncognita != -1)
        {
            resultadoDeLaIncognita =
                obtenerConsecutivoInicial(numerosConsecutivos, numeroEntero);

            if (resultadoDeLaIncognita > 0)
                mostrarOperacion(resultadoDeLaIncognita, numerosConsecutivos);

            numerosConsecutivos += 1;
        }
    }

    system("PAUSE");
    return (0);
}

int obtenerConsecutivoInicial(int numerosConsecutivos, int numeroACalcular)
{
    int sumaDeConsecutivos, variableTemporal, resultado;
    variableTemporal = 0;
    /*x0+0+x1+1+xn+n=i*/
    /* formula (n(n+1))/2 */
    sumaDeConsecutivos = numerosConsecutivos;
    sumaDeConsecutivos -= 1;
    sumaDeConsecutivos *= numerosConsecutivos;
    sumaDeConsecutivos /= 2;

    /**Desbordamiento**/
    if (sumaDeConsecutivos <= -1)
        return (-1);

    resultado = (numeroACalcular - sumaDeConsecutivos);

    /**Desbordamiento**/
    if (resultado <= 0)
        return (-1);

    variableTemporal = (resultado % numerosConsecutivos);

    /**No divisible**/
    if (variableTemporal != 0)
        return (0);

    variableTemporal = (resultado / numerosConsecutivos);
    return (variableTemporal);
}

void mostrarOperacion(int resultadoDeLaIncognita, int numerosConsecutivos)
{
    int resultadoFinal, contador, nIteracion, temp;
    resultadoFinal = 0;

    printf("%d ", resultadoDeLaIncognita);
    temp = resultadoDeLaIncognita;
    
    nIteracion = (numerosConsecutivos > LIMITE_N_CONSECUTIVOS)? LIMITE_N_ITERACION : numerosConsecutivos;

    for (contador = 1; (contador < nIteracion); contador++)
    {
        temp += 1;
        printf("+ %d ", temp);
    }

    temp = (resultadoDeLaIncognita + (numerosConsecutivos -1));
    resultadoFinal = (((resultadoDeLaIncognita + temp) * ((temp - resultadoDeLaIncognita) + 1)) / 2);

    (numerosConsecutivos > LIMITE_N_CONSECUTIVOS) ? 
        printf("+ ... + %d = %d\n", temp, resultadoFinal) : 
        printf("= %d\n", resultadoFinal);
}

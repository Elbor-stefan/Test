#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LIMITE_N_CONSECUTIVOS 5
#define LIMITE_N_ITERACION 3
#define BASE2 2

int obtenerConsecutivo(int, int);
void mostrarOperacion(int, int);

int main()
{
    int numero, nConsecutivo, incognita;
    double dnumero, error;

    numero  = 0;
    dnumero = 0.0;
    error   = 0.0;

    printf("Ingrese un numero: " );
    fflush(stdin);
    scanf( "%lf", &dnumero );

    numero  = dnumero;
    error   = fabs(numero - dnumero);

    if ( error > 0.001 )
    {
        printf( "Error de entrada!!!\n" );
        system("PAUSE");

        return(0);
    }

    int exp =0;
    exp = (int) roundl((logl(numero) / logl(BASE2)));
    if (numero == (1 << exp))
    {
        /** (2^n | n>0) **/
        printf("2^n\n");
        system("PAUSE");

        return(0);
    };

    nConsecutivo = 2;
    incognita = 0;
    while (incognita != -1)
    {
        incognita = obtenerConsecutivo(nConsecutivo, numero);

        if (incognita > 0)
        {
            mostrarOperacion(incognita, nConsecutivo);
        }

        nConsecutivo += 1;
    }

    system("PAUSE");
    return (0);
}

int obtenerConsecutivo(int nConsecutivo, int numeroACalcular)
{
    int sumConsecutivo, temp, resultado;
    temp = 0;

    sumConsecutivo = nConsecutivo;
    sumConsecutivo -= 1;

    sumConsecutivo *= nConsecutivo;
    sumConsecutivo /= 2;

    /** Desbordamiento **/
    if (sumConsecutivo <= -1)
        return (-1);

    resultado = (numeroACalcular - sumConsecutivo);

    /** Desbordamiento **/
    if (resultado <= 0)
        return (-1);

    temp = (resultado % nConsecutivo);

    /** No divisible (residuo) **/
    if (temp != 0)
        return (0);

    temp = (resultado / nConsecutivo);
    return (temp);
}

void mostrarOperacion(int vIncognita, int nConsecutivo)
{
    int contador, nIteracion;
    long double resultadoFinal, temp;

    resultadoFinal  =0.0;
    temp            =0.0;

    printf("%d ", vIncognita);
    temp = vIncognita;

    nIteracion = (nConsecutivo > LIMITE_N_CONSECUTIVOS)
        ? LIMITE_N_ITERACION
        : nConsecutivo;

    for (contador = 1; (contador < nIteracion); contador++)
    {
        temp += 1;
        printf("+ %.0lf ", temp);
    }

    temp = (vIncognita + (nConsecutivo -1));
    resultadoFinal = ((vIncognita + temp) / 2);
    resultadoFinal = (resultadoFinal * ((temp - vIncognita) + 1));

    (nConsecutivo > LIMITE_N_CONSECUTIVOS) ?
        printf("+ ... + %.0lf = %.0lf\n", temp, resultadoFinal) :
        printf("= %.0lf\n", resultadoFinal);
}

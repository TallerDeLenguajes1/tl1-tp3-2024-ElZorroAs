/**
Una empresa necesita simular la producción de los próximos 5 años para tal fin necesita
generar una matriz (estática) de 5x12 donde cada fila corresponde a un año y cada columna
es un mes. Ud. debe realizar las siguientes tareas:
a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
b. Muestre por pantalla los valores cargados
c. Saque el promedio de ganancia por año y muestrelos por pantalla
d. Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de
cuándo ocurrió.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define fila 5     // año
#define columna 12 // mes

int main()
{
    srand(time(0));
    int matriz[fila][columna];

    // a
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            matriz[i][j] = rand() % 40001 + 10000;
        }
    }
    // b
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }
    // c
    int suma;
    float promedio;
    for (int i = 0; i < fila; i++)
    {
        suma = 0;
        for (int j = 0; j < columna; j++)
        {
            suma += matriz[i][j];
        }

        promedio = (float)suma / columna;
        printf("Anio %d: %.2f\n", i + 1, promedio);
    }
    // d
    int minAnio = 0, maxAnio = 0, minMes = 0, maxMes = 0, min = 50001, max = -1;
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            if (matriz[i][j] > max)
            {
                max = matriz[i][j];
                maxAnio = i;
                maxMes = j;
            }
            if (matriz[i][j] < min)
            {
                min = matriz[i][j];
                minAnio = i;
                minMes = j;
            }
        }
    }
    printf("El valor Maximo es %d del anio %d y mes %d\n", max, maxAnio + 1, maxMes + 1);
    printf("El valor Minimo es %d del anio %d y mes %d\n", min, minAnio + 1, minMes + 1);
    return 0;
}
/*******************************************************************************
* 
* Quicksort implementando seguindo a seguinte aula:  https://www.youtube.com/watch?v=0jDiBM68NGU
*
*
* Créditos à Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include "ControleDeVoo.h"
#include "QuickSort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(dados* x, dados* y)
{
    dados temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(dados* tarefa, int numTarefas)
{
    srand(time(NULL));
    quicksort_recursivo(tarefa, 0, numTarefas - 1);
}

void quicksort_recursivo(dados* tarefa, int inicio, int fim)
{
    if (inicio < fim)
    {
        int indice_pivo = particionar(tarefa, inicio, fim);

        quicksort_recursivo(tarefa, inicio, indice_pivo - 1);

        quicksort_recursivo(tarefa, indice_pivo + 1, fim);
    }
}

int particionar(dados* tarefa, int inicio, int fim)
{
    int indice_pivo = inicio + (rand() % (fim - inicio));

    if (indice_pivo != fim)
        trocar(&tarefa[indice_pivo], &tarefa[fim]);

    int valor_pivo = tarefa[fim].prior;

    int i = inicio;

    for (int j = inicio; j < fim; j++)
    {
        if (tarefa[j].prior >= valor_pivo)
        {
            trocar(&tarefa[i], &tarefa[j]);
            i++;
        }
    }
    trocar(&tarefa[i], &tarefa[fim]);

    return i;
}
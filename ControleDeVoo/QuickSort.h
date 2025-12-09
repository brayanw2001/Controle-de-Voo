#ifndef QUICKSORT_H
#define QUICKSORT_H

/*******************************************************************************
* Quicksort implementando seguindo a seguinte aula:  https://www.youtube.com/watch?v=0jDiBM68NGU
*
* Créditos à Kevin Browne @ https://portfoliocourses.com
*
*******************************************************************************/
#include "ControleDeVoo.h"

void quicksort(dados* tarefa, int numTarefas);
void quicksort_recursivo(dados* tarefa, int inicio, int fim);
int particionar(dados* tarefa, int inicio, int fim);
void trocar(dados* x, dados* y);

#endif // QUICKSORT_H
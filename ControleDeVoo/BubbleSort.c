#include <stdio.h>

#include "ControleDeVoo.h"
#include "BubbleSort.h"

void bubbleSort(dados* tarefa, int numTarefas)
{
	for (int i = 0; i < numTarefas; i++)
	{
		for (int j = i; j < numTarefas; j++)
		{
			if (tarefa[i].prior < tarefa[j].prior)
			{
				trocar(&tarefa[i], &tarefa[j]);
			}
		}
	}
}
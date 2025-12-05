#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "ControleDeVoo.h"
#include "ArvoreBinaria.h"

dados* novaTarefa(int numTarefas)
{
	dados* tarefas = (dados*) malloc (sizeof(dados) * numTarefas);

	if (tarefas == NULL)
	{
		fprintf(stderr, "Erro ao alocar memória.");
		return tarefas;
	}

	int* prioridades = geraPrioridades(numTarefas);

	for (int i = 0; i < numTarefas; i++)
	{
		printf("Insira a tarefa: ");
		fgets(tarefas[i].tarefa, 30, stdin);
		tarefas[i].tarefa[strcspn(tarefas[i].tarefa, "\n")] = '\0';

		tarefas[i].prior = prioridades[i];
	}

	free(prioridades);
	printf("\n");

	return tarefas;
}


int* geraPrioridades(int numTarefas)
{
	int* prioridades = (int*)malloc(sizeof(int) * numTarefas);

	if (prioridades == NULL)
	{
		fprintf(stderr, "Erro ao gerar tarefas.");
		return NULL;
	}

	for (int i = 0; i < numTarefas; i++)
	{
		prioridades[i] = rand() % ((4 * numTarefas) + 1);

		for (int j = 0; j < i; j++)
		{
			if (prioridades[i] == prioridades[j])
			{
				prioridades[i] = rand() % ((4 * numTarefas) + 1);
				j = -1;
			}
		}
	}

	return prioridades;
}

dados* incrementarTarefas(dados* tarefas, int *novoTamanho)
{
	(*novoTamanho)++;
	int i = (*novoTamanho)-1;

	dados* tarefaAtualizadas = (dados*)realloc(tarefas, (sizeof(dados) * (*novoTamanho)) );

	if (tarefas == NULL)
	{
		fprintf(stderr, "Erro ao expandir as tarefas.");
		return tarefas;
	}

	printf("\nInsira a tarefa: ");

	fgets(tarefaAtualizadas[i].tarefa, 30, stdin);
	tarefaAtualizadas[i].tarefa[strcspn(tarefaAtualizadas[i].tarefa, "\n")] = '\0';

	tarefaAtualizadas[i].prior = rand() % (4 * (*novoTamanho) );

	return tarefaAtualizadas;
}

dados* excluiMaiorPrior(dados* tarefas, int* numTarefas)
{
	//dados* aux = &tarefas[0];			//	quero mudar os endereços ou apenas sobreescrever as infos?
	dados guardaMaior = tarefas[0];
	dados guardaUltimo;
	dados* tarefasRaealocado;
	int guardaIndice = 0;
	int tamVetor = (*numTarefas) - 1;

	for (int i = 0; i < *numTarefas; i++)
	{
		if (tarefas[i].prior > guardaMaior.prior)
		{
			guardaMaior = tarefas[i];				// salvei os valores da tarefa maior
			guardaIndice = i;
		}
	}

	guardaUltimo = tarefas[tamVetor];
	tarefas[tamVetor] = guardaMaior;
	tarefas[guardaIndice] = guardaUltimo;

	(*numTarefas)--;
	return tarefasRaealocado = (dados*)realloc(tarefas, (sizeof(dados) * (*numTarefas)) );
}

void alterarPrioridade(dados* tarefas, int numTarefas)
{
	int num, novaPrioridade;

	printf("\n============== EDITAR PRIORIDADE ==============");
	for (int i = 0; i < numTarefas; i++)
	{
		printf("\n[%d] - Tarefa: %s \n      Prioridade: %d", i, tarefas[i].tarefa, tarefas[i].prior);
		printf("\n");
	}
	
	printf("\nInsira qual das tarefas deseja mudar: ");
	scanf("%d", &num);

	printf("\nInsira a nova prioridade: ");
	scanf("%d", &novaPrioridade);

	tarefas[num].prior = novaPrioridade;

	printf("Tarefa atualizada: \n");
	printf("\n\nTarefa: %s \nPrioridade: %d\n", tarefas[num].tarefa, tarefas[num].prior);


	printf("\n===============================================\n\n");

}

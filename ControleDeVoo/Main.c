#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ControleDeVoo.h"
#include "ArvoreBinaria.h"
#include "QuickSort.h"
#include "BubbleSort.h"

void ordenarPrioridade(dados* tarefa, int numTarefas);

int main() 
{
    srand(time(NULL));

    int numTarefas, opc;
    int controleDeSequencia = 0;
    dados* tarefas = NULL;
    no* arvoreBinaria = NULL;

    do 
    {
        printf("[1] - Criar Vetor\n"
               "[2] - Incrementar tarefas\n"
               "[3] - Excluir tarefa com maior prioridade\n"
               "[4] - Alterar prioridade\n"
               "[5] - Arvore Binaria\n"
               "[6] - Ordenar por prioridade\n"
               "[7] - * Mostrar tarefas *\n"
               "[8] - Encerrar\n");

        printf("Insira a opcao: ");
        scanf("%d", &opc);

        while (getchar() != '\n');

        switch (opc) 
        {
            case 1:
                printf("\nQuantas tarefas? ");
                scanf("%d", &numTarefas);

                while (getchar() != '\n'); 

                printf("\n");
                tarefas = novaTarefa(numTarefas);

                controleDeSequencia = 1;

                break;

            case 2:
                tarefas = incrementarTarefas(tarefas, &numTarefas);
                printf("\n\n");
                break;

            case 3:
                if (controleDeSequencia == 0)
                {
                    printf("\nCrie tarefas antes de executar esse comando!\n\n");
                    break;
                }

                tarefas = excluiMaiorPrior(tarefas, &numTarefas);
                printf("\n");
                break;

            case 4:
                if (controleDeSequencia == 0)
                {
                    printf("\nCrie tarefas antes de executar esse comando!\n\n");
                    break;
                }

                alterarPrioridade(tarefas, numTarefas);
                break;

            case 5:
                if (controleDeSequencia == 0)
                {
                    printf("\nCrie tarefas antes de executar esse comando!\n\n");
                    break;
                }

                if (arvoreBinaria == NULL)
                {
                    arvoreBinaria = insereNos(tarefas, numTarefas);
                }
                else
                {
                    liberaArvore(arvoreBinaria);
                    arvoreBinaria = insereNos(tarefas, numTarefas);
                }

                imprime(arvoreBinaria, 0);
                break;

            case 6:
                if (controleDeSequencia == 0)
                {
                    printf("\nCrie tarefas antes de executar esse comando!\n\n");
                    break;
                }

                ordenarPrioridade(tarefas, numTarefas);
                printf("\n");
                break;

            case 7:
                if (controleDeSequencia == 0)
                {
                    printf("\nCrie tarefas antes de executar esse comando!\n\n");
                    break;
                }

                printf("\n============== TAREFAS ==============");

                for (int i = 0; i < numTarefas; i++)
                {
                    printf("\nDescricao: %s", tarefas[i].tarefa);
                    printf("\nPrioridade: %d", tarefas[i].prior);
                    printf("\n");
                }
                printf("=======================================\n\n");

                break;
        }
    } while (opc != 8);

    // não esquecer de limpar memoria
}

void ordenarPrioridade (dados* tarefa, int numTarefas)
{
    int opc = 0;

    printf("\n\n============== ORDENAR PRIORIDADE ==============\n");
 
    printf("[1] - QuickSort\n"
           "[2] - BubbleSort\n"
           "[3] - Voltar\n");

    printf("Insira a opcao: ");
    scanf("%d", &opc);

    switch (opc)
    {
    case 1:
        quicksort(tarefa, numTarefas);
        break;
    case 2:
        bubbleSort(tarefa, numTarefas);
        break;
    }

    printf("================================================\n");
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ControleDeVoo.h"
#include "ArvoreBinaria.h"

int main() 
{
    srand(time(NULL));

    int numTarefas, opc;
    dados* tarefas = NULL;
    no* arvoreBinaria = NULL;

    do 
    {
        printf("[1] - Criar Vetor\n"
               "[2] - Incrementar tarefas\n"
               "[3] - Excluir tarefa com maior prioridade\n"
               "[4] - Alterar prioridade (em construção...)\n"
               "[5] - Arvore Binaria\n");

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

                break;

            case 2:
                tarefas = incrementarTarefas(tarefas, &numTarefas);
                printf("\n\n");
                break;

            case 3:
                tarefas = excluiMaiorPrior(tarefas, &numTarefas);
                break;

            case 5:
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
            // ... outros cases
            case 9:
                printf("\n===== TAREFAS =====");
                for (int i = 0; i < numTarefas; i++)
                {
                    printf("\nDescricao: %s", tarefas[i].tarefa);
                    printf("\nPrioridade: %d", tarefas[i].prior);
                    printf("\n");
                }
                printf("==================\n\n");

                break;
        }
    } while (opc != 8);

    // não esquecer de limpar memoria
}
#include <stdio.h>
#include <stdlib.h>

#include "ArvoreBinaria.h"
#include  "ControleDeVoo.h"


void liberaArvore(no* n)
{
	if (n != NULL)
	{
		liberaArvore(n->dir);
		liberaArvore(n->esq);
		free(n);
	}
}

no* criaNo(dados info)
{
	no* novoNo = (no*)malloc(sizeof(no));
	novoNo->dado = info;
	novoNo->esq = NULL;
	novoNo->dir = NULL;

	return novoNo;
}

no* insereNos(dados* info, int numTarefas)
{
	no* novoNo = criaNo(info[0]);
	no* raiz = novoNo;

		for (int i = 1; i < numTarefas; i++) 
		{
			while (novoNo != NULL)
			{
				if (info[i].prior < novoNo->dado.prior)
				{
					if (novoNo->esq == NULL)
					{
						novoNo->esq = criaNo(info[i]);
						break;
					}
					novoNo = novoNo->esq;
				}
				else if (info[i].prior > novoNo->dado.prior)
				{
					if (novoNo->dir == NULL)
					{
						novoNo->dir = criaNo(info[i]);
						break;
					}
					novoNo = novoNo->dir;
				}
			}
			novoNo = raiz;
		}
	return raiz;
}

void imprime(no* no, int tab)
{
	if (no == NULL)
		return;
	
	for (int i = 0; i < tab; i++)
	{
		printf("-");
	}

	if (no != NULL)
	{
		printf("%d\n", no->dado.prior);
		imprime(no->esq, tab + 1);
		imprime(no->dir, tab + 1);
	}
	else printf("vazio");
}

no* busca(no* no, int id)
{
	if (no == NULL)
		return NULL;

	while (no != NULL)
	{
		if (id < no->dado.prior)
			no = no->esq;
		else if (id > no->dado.prior)
			no = no->dir;
		else                        // se for igual (achou) retorna o no
			return no;
	}
	return NULL;
}


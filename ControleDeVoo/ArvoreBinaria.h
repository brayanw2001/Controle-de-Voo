#include "ControleDeVoo.h"

typedef struct No
{
	dados dado;
	struct No* dir;
	struct No* esq;
} no;

no* criaNo(dados info);
void liberaArvore(no* n);
void imprime(no* raiz, int tab);
no* busca(no* no, int id);
no* insereNos(dados* info, int numTarefas);

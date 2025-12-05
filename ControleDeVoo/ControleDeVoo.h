#ifndef CONTROLE_DE_VOO_H  
#define CONTROLE_DE_VOO_H

typedef struct
{
	char tarefa[30];
	int prior;
} dados;

dados* novaTarefa(int numTarefas);
int* geraPrioridades(int numTarefas);
dados* incrementarTarefas(dados* tarefas, int *novoTamanho);
dados* excluiMaiorPrior(dados* tarefas, int* numTarefas);

#endif
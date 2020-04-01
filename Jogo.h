#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED
#include "Conjunto.h"
#include "Pessoas.h"
typedef struct movimento Jogada, *ljog;
struct movimento{
    char descricao[50];
    int NJogador;
    ljog prox;
};

typedef struct jog Jogo;
struct jog{
	int id;
    cconj VectorConjuntos;
    ppessoa VectorPessoas;
    ljog Jogadas;
	int JogActual;
	float DispTotal;
	int NConj;
	int NPes;

};



Jogo NovoJogo(int NPessoas, int NConjuntos);//cria um novo jogo(recebe por parametro o numero de pessoas e conjuntos
int cria_distribuicao(int n_pessoas, int conj, char *txt);//cria um novo ficheiro de distribuição(recebe por parametro o numero de pessoas e conjuntos e o id do jogo para guardar no txt)
int random_int(int min, int max); //gera um numero inteiro entre o parametro minimo e maximo
void preenche_fixo(int fixo[], int n_pessoas, int conj);
void LerDistribuicao(cconj ListaConjunto, ppessoa ListaPessoas, int Nconjuntos);//lê a distribuição para memoria(recebe por parametro a lista de conjuntos, lista de pessoas do binario e o numero total de conjuntos)
int Valida(cconj c, int id);
float CalculaDispersaoTotal(cconj c);
void GuardarJogo(Jogo *j);
Jogo LerJogo();
void LimparJogo(Jogo *jog);
#endif // JOGO_H_INCLUDED

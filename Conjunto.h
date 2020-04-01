#ifndef CONJUNTO_H_INCLUDED
#define CONJUNTO_H_INCLUDED
#include "Pessoas.h"


typedef struct conj Conjunto, *cconj;
struct conj{
    int IdConj;
    //char *Nome;
    ppessoa VectorPessoas;
    cconj prox;
	float dist;
	int TotPessoas;

};
void CriarNovoConjunto(cconj c,int id);

//funçoes do conjunto
ppessoa AdicionarPessoa(ppessoa l,ppessoa p);//adiciona 1 pessoa ao conjunto(recebe por parametro a pessoa e o conjunto)
ppessoa ElimarPessoaConjunto(cconj c, int id);//elimina pessoa do conjunto(recebe por parametro a pessoa)
ppessoa MoverPessoa(ppessoa l, ppessoa p, ppessoa d);//Move pessoa do conjunto x para o y
float CalcularDistribuicao(cconj c);//recebe a lista por parametro, devolve a distribuição calculada
void GuardarDistribuicao();//guardar no txt a dist(codigo do prof)
void ImprimeConjunto(cconj c);//imprime no ecrã o conjunto passado por parametro.

#endif // CONJUNTO_H_INCLUDED

#include "Conjunto.h"


void CriarNovoConjunto(cconj c,int id)
{


	c->IdConj = id;
	c->VectorPessoas = NULL;
	c->dist = 0;
	c->TotPessoas = 0;
	c->prox = NULL;

}

//funçoes do conjunto
ppessoa AdicionarPessoa(ppessoa l, ppessoa p)//adiciona pessoa ao conjunto(recebe por parametro a pessoa e o conjunto)
{
    ppessoa novo,aux= NULL;
	novo = malloc(sizeof(pessoa));

	if (novo == NULL)
		return;
	novo->id = p->id;
	novo->idade = p->idade;
	strcpy(novo->nome, p->nome);
	novo->prox = NULL;
	//l = novo;
	if (l == NULL || novo->id < l->id)
	{
		novo->prox = l;
		l = novo;
	}
	else
	{
		aux = l;
		while (aux->prox != NULL && novo->id > aux->prox->id)
			aux = aux->prox;
		novo->prox = aux->prox;
		aux->prox = novo;
	}
	return l;


}
ppessoa EliminarPessoaConjunto(ppessoa c, int id)//elimina pessoa do conjunto(recebe por parametro a pessoa)
{
	ppessoa atual, anterior = NULL;
	atual = c;
	while (atual != NULL && atual->id != id)
	{
		anterior = atual;
		atual = atual->prox;
	}
	if (atual == NULL)
		return c;
	if (anterior == NULL)
		c = atual->prox;
	else
		anterior->prox = atual->prox;
	free(atual);

	return c;
}
ppessoa MoverPessoa(ppessoa l, ppessoa p, ppessoa d)//Move pessoa do conjunto x para o y
{
	ppessoa aux = d;
	while (aux != NULL)
	{
		if (aux->id == p->id)
		{
			printf("Esta pessoa já existe neste Conjunto!\n");

			return l;

		}
		else
			aux = aux->prox;
	}
	d = AdicionarPessoa(d, p);
	l = EliminarPessoaConjunto(l, p->id);
	printf("Pessoa transferida com sucesso!\n");
	return l;


}

float CalcularDistribuicao(cconj c)
{
	int count=0,total = 0, dif = 0;
	ppessoa aux, aux2;
	aux = c->VectorPessoas;
	c->TotPessoas = 0;

	while (aux != NULL)
	{
		/*total = total + aux->idade;
		aux = aux->prox;
		count++;*/

			aux2 = aux->prox;
			while (aux2 != NULL)
			{
				dif = (aux->idade - aux2->idade);
				count++;
				if (dif < 0)
					dif = dif * -1;
				total = total + dif;
				aux2 = aux2->prox;
			}
			c->TotPessoas++;
			aux = aux->prox;

	}
	c->dist = total / count;

	return c->dist;
}


void GuardarDistribuicao()//guardar no txt a dist(codigo do prof)
{}

void ImprimeConjunto(cconj c)
{
	ppessoa aux;
	aux = c->VectorPessoas;
	printf("Conjunto ID: %d Distribuição: %4.2f Pessoas no conjunto: %d\n", c->IdConj, c->dist, c->TotPessoas);
	while (aux != NULL)
	{
		printf("%d : %s : %d\n", aux->id, aux->nome, aux->idade);
		aux = aux->prox;
	}
	printf("\n");
}


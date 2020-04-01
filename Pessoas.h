#ifndef PESSOAS_H_INCLUDED
#define PESSOAS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct dados pessoa, *ppessoa;
struct dados{
 char nome[100];
 int idade;
 int id;

 ppessoa prox;
};


pessoa NovaPessoa();//cria uma nova pessoa e guarda directamente no ficheiro


//fun�oes de pessoa
void EscreverPessoa(pessoa *p);//imprime no ecr� uma pessoa


void GuardaPessoa(pessoa *p);//guarda uma pessoa no ficheiro bin�rio

void EditarPessoa(ppessoa l,int id);//edita os dados da pessoa e guarda no ficheiro binario

void EliminarPessoa(char *n);//elimina uma pessoa do ficheiro binario

ppessoa LerPessoas();//l� as pessoas do ficheiro bin�rio para memoria

#endif // PESSOAS_H_INCLUDED

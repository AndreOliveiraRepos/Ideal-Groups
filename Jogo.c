#include "Jogo.h"


Jogo NovoJogo(int NPessoas, int NConjuntos)
{

	Jogo jog;

	cconj aux,c;
	int i;
	jog.id = 0;
	jog.DispTotal = 0;
	jog.JogActual = 1;
	jog.VectorPessoas = NULL;
    jog.NConj = NConjuntos;
    jog.NPes = NPessoas;
    jog.Jogadas = NULL;


	jog.VectorConjuntos = NULL;
	jog.VectorPessoas = LerPessoas();
	for (i = 0; i < NConjuntos; i++)
	{
		c = malloc(sizeof(Conjunto));
		CriarNovoConjunto(c, i + 1);

		if (jog.VectorConjuntos == NULL)
		{


			jog.VectorConjuntos = c;

		}
		else
		{

			aux = jog.VectorConjuntos;
			while (aux->prox !=NULL)

				aux = aux->prox;
			aux->prox = c;



		}


	}


    //cria_distribuicao(NPessoas,NConjuntos,"jogo.txt");

	LerDistribuicao(jog.VectorConjuntos, jog.VectorPessoas, NConjuntos);
	//atribuiar ao conjunto pedir as jogas e condição de victoria.

	return jog;
}

void LerDistribuicao(cconj ListaConjuntos, ppessoa ListaPessoas, int Nconjuntos)//devolver lista de conjuntos, recebe a lista criada no novo jogo e o vector de pessoas para atribuir ids.
{

    FILE *f;
	cconj aux;
	ppessoa paux;

    char str[2];
    int c,i,count,anterior = 0;
	aux = ListaConjuntos;
	paux = ListaPessoas;
    f = fopen("jogo.txt", "r");

	count = 1;
    while(aux != NULL)
        {
			while (fscanf(f, "%d\t", &c) != EOF)
			{
				if (anterior < c){

					//printf("%d\t", c);
					anterior = c;
					while(paux != NULL)
					{
					    if(paux->id==c)
                        {

							ppessoa nova = malloc(sizeof(pessoa));

							nova = AdicionarPessoa(aux->VectorPessoas, paux);
							//nova->prox = aux->VectorPessoas;
							aux->VectorPessoas = nova;


							break;

					    }
						else
						{
							paux = paux->prox;
						}

					}


				}
				else
				{
					//printf("\n");
					cconj novo = malloc(sizeof(Conjunto));

					novo = aux->prox;
					aux->dist = CalcularDistribuicao(aux);
					aux = aux->prox;

					novo = ListaConjuntos;
					paux = ListaPessoas;
					while (paux != NULL)
					{
						if (paux->id == c)
						{

							ppessoa nova = malloc(sizeof(pessoa));
							//printf("%d\t", c);
							nova = AdicionarPessoa(aux->VectorPessoas, paux);
							//nova->prox = aux->VectorPessoas;
							aux->VectorPessoas = nova;


							break;

						}
						else
						{
							paux = paux->prox;
						}

					}
					anterior = 0;

					c = 0;
					count++;


				}
			}
			if (aux->prox == NULL)
			{
				aux->dist = CalcularDistribuicao(aux);
				break;
			}

        }

    fclose(f);


}

int random_int(int min, int max)
{
	return min + rand() % (max-min+1);
}

void preenche_fixo(int fixo[], int n_pessoas, int conj)
{
	int i, x, y, c=0;

	for(i=0; i<n_pessoas; i++,c++)
		fixo[i] = c%conj;

	for(i=0; i<n_pessoas*conj; i++)
	{
		x = random_int(0, n_pessoas-1);
		do{
			y = random_int(0, n_pessoas-1);
		}while(x==y);
		c = fixo[x];
		fixo[x] = fixo[y];
		fixo[y] = c;
	}
}

int Valida(cconj c,int id)
{
	cconj caux;
	ppessoa aux;
	caux = c;

	int count = 0;
	while (caux != NULL)
	{
		aux = caux->VectorPessoas;
		while (aux != NULL)
		{
			if (aux->id == id)
			{
				count++;
				aux = aux->prox;
			}

			else
				aux = aux->prox;
		}
		caux = caux->prox;
	}

	if (count == 3)
	{
		/*free(caux);
		free(aux);*/
		return 1;
	}
	else if (count == 1)
	{
		return 2;
	}

	else
	{
		/*free(caux);
		free(aux);*/
		return 0;
	}


}

float CalculaDispersaoTotal(cconj c)
{
	cconj caux;
	caux = c;
	//ppessoa aux;
	float disp = 0;
	while (caux != NULL)
	{
		//aux = caux->VectorPessoas;
		disp += caux->dist;

		caux = caux->prox;

	}


	return disp;
}

void GuardarJogo(Jogo *j)
{
	FILE *f;
	cconj aux = j->VectorConjuntos;
	ppessoa auxp;
	//int i;
	f = fopen("jogo.dat", "wb");
	if (f == NULL)
	{
		printf("Erro no acesso ao ficheiro\n");
		return;
	}


	fwrite(j, sizeof(Jogo), 1, f);

	while(aux!= NULL)
    {

            fwrite(aux, sizeof(Conjunto), 1, f);
            auxp = aux->VectorPessoas;
            while(auxp!= NULL)
            {
                    printf("A guardar:%s\n", auxp->nome);
                     fwrite(auxp, sizeof(pessoa), 1, f);
                     auxp = auxp->prox;
            }

            aux = aux->prox;
	}
	fclose(f);
	printf("jogo guardado com sucesso!\n");
}

Jogo LerJogo()
{
	Jogo novo;
	cconj novoc,aux;
	ppessoa novap;
	FILE *f;
	int i,j;
	f = fopen("jogo.dat", "rb");
	if (!f)
		return;

	//novo = malloc(sizeof( Jogo));
	/*if (novo == NULL)
		printf("Erro de memória!\n");*/
	fread(&novo, sizeof(Jogo), 1, f);
	printf("%d\n",novo.NConj);
	novo.VectorConjuntos = NULL;
	novo.VectorPessoas = LerPessoas();
	for(i = 0; i < novo.NConj; i++)
    {
        novoc = malloc(sizeof(Conjunto));
        fread(novoc,sizeof(Conjunto),1,f);
        //novoc->prox = NULL;
        printf("%d\n",novoc->IdConj);
        novoc->VectorPessoas = NULL;
        novoc->prox = NULL;
        novap = malloc(sizeof(pessoa));
        for(j = 0;j < novoc->TotPessoas;j++)
        //while(fread(novap,sizeof(pessoa),1,f)==1)
        {
            fread(novap,sizeof(pessoa),1,f);
            printf("%s\n",novap->nome);
            //system("pause");
            novoc->VectorPessoas = AdicionarPessoa(novoc->VectorPessoas,novap);
            //novoc->VectorPessoas = novap;
        }
        if(novo.VectorConjuntos == NULL)
            novo.VectorConjuntos = novoc;
        else
        {
            aux = novo.VectorConjuntos;
            while(aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novoc;
        }
        //novoc->prox = novo.VectorConjuntos;

        //novo.VectorConjuntos = novoc;

    }
    printf("leu\n");
    //EscreverPessoa()
    aux = novo.VectorConjuntos;
    while(aux != NULL)
    {
      ImprimeConjunto(aux);
        aux = aux->prox;
    }



    system("pause");
	fclose(f);
	return novo;
}

/*int cria_distribuicao(int n_pessoas, int conj, char *txt)
{
	int conta[n_pessoas];
	int pertence[n_pessoas];
	int fixo[n_pessoas];
	int i, j, pos, x;
	FILE *f;


	if(n_pessoas < 6 || conj < 3 || conj > n_pessoas/2)
	{
		printf("Configuracao errada\n");
		return 0;
	}

	memset(conta, 0, sizeof(conta));
	srand((unsigned)time(NULL));

	preenche_fixo(fixo, n_pessoas, conj);

	f = fopen(txt, "w");
	if(f == NULL)
		return 0;

	for(i=0; i<conj; i++)
	{
		memset(pertence, 0, sizeof(pertence));
		x = random_int(2, 3*n_pessoas/conj);

		for(j=0; j<n_pessoas; j++)
			if(fixo[j] == i)
			{
				pertence[j] = 1;
				x--;
			}

		for(j=0; j<x; j++)
		{
			do{
				pos = random_int(0, n_pessoas-1);
			}while(pertence[pos]==1 || conta[pos]==2);
			pertence[pos] = 1;
			conta[pos]++;
		}

		for(j=0; j<n_pessoas; j++)
        {
            if(pertence[j] == 1)
				fprintf(f, "%d\t", j+1);



        }
        fprintf(f,"\n");
	}

	fclose(f);
	return 1;
}*/

void LimparJogo(Jogo *jog)
{
    free(jog->VectorPessoas);
    free(jog->VectorConjuntos);
    free(jog);
    //free(jog->VectorConjuntos);
}

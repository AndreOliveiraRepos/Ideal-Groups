#include "Menu.h"
#include "Pessoas.h"
#include "Conjunto.h"
#include "Jogo.h"

void MenuInicial()
{
    int escolha = 0;
	printf("--- Escolha uma das seguintes opcoes:\n");
	printf("--- 1 - Novo jogo.\n");
	printf("--- 2 - Menu Pessoas.\n");
	//printf("--- 3 - Menu Conjuntos.\n");
	printf("--- 4 - Sair.\n");
	scanf("%d",&escolha);
	switch (escolha)
	{
		case 1:
		    {
		        MenuNovoJogo();
                break;
		    }


		case 2:
		    {
		        MenuPessoas();
		        break;
		    }


		/*case 3:
		    {
		        MenuConjuntos();
		        break;
		    }*/


		case 4:

		    return;
        break;

		default:
		printf("--- Erro! Opcao Invalida! ---\n");
		break;
	}
}
void MenuNovoJogo()
{
    int escolha = 0;
	printf("--- Escolha uma das seguintes opcoes:\n");
	//ler de um ficheiro já existente
	//criar novo ficheiro
	printf("--- 1 - Ler de um ficheiro já existente.\n");
    printf("--- 2 - Criar novo ficheiro.\n");

	printf("--- 3 - Regressar ao menu anterior.\n");
	scanf("%d",&escolha);
	switch (escolha)
	{
		case 1:
		{
				  Jogo *jog;
				  jog = malloc(sizeof(Jogo));
				  *jog = LerJogo();
                    MenuJogo(jog);
				  break;
		}


		case 2:
		    {
		        //validar numero de pessoas existentes no ficheiro.
		        int NPessoas = 0, Nconjuntos = 0;
		        Jogo *jog;
		        /*NPessoas = 8;
		        Nconjuntos = 4;*/
		        jog = malloc(sizeof(Jogo));
		        printf("--- 1 - Introduzir pessoas.\n");//perguntar se quer introduzir novas pessoas ou ler, ler n_linhas do .dat para ver o nr de pessoas
		        scanf("%d",&NPessoas);

                printf("--- 2 - Introduzir conjuntos.\n");
                scanf("%d",&Nconjuntos);

                *jog = NovoJogo(NPessoas,Nconjuntos);
                printf("Jogo criado com sucesso!\n");
				//iniciar jogo aqui: imprimir conjuntos e mostrar opções de jogo.
                system("pause");
				system("cls");

				MenuJogo(jog);
				free(jog);
		        break;
		    }



		case 3:

		break;

		default:
		printf("--- Erro! Opcao Invalida! ---\n");
		break;
	}
}

void MenuPessoas()
{
    int escolha = 0;
    ppessoa lista;
	printf("--- Escolha uma das seguintes opcoes:\n");
	printf("--- 1 - Inserir Pessoa.\n");//implementado
	printf("--- 2 - Editar Pessoa.\n");//implementado
	printf("--- 3 - Eliminar Pessoa.\n");//implementado
	printf("--- 4 - Listar todas.\n");//implementado
	printf("--- 5 - Regressar ao menu anterior.\n");
	scanf("%d",&escolha);
	switch (escolha)
	{
		case 1:
		    {//ler todas as pessoas do ficheiro para validações pela lista
		        pessoa d;
		        d=NovaPessoa();
                MenuPessoas();
		        break;
		    }


		case 2://ler todas as pessoas do ficheiro para a lista, listar, procurar por id e mostrar opções de edição
		{
                ppessoa aux = NULL;
                int id;
                lista = LerPessoas();
                aux = lista;
                while(aux != NULL)
                {
                    EscreverPessoa(aux);
                    aux = aux->prox;
                }
                printf("Escolha o ID da pessoa a editar.\n");
                scanf("%d",&id);
                //aux = lista;
                EditarPessoa(lista,id);

                free(lista);
                free(aux);
                MenuPessoas();
                break;
		}

		case 3://ler todas as pessoas do ficheiro para a lista, listar, procurar por id e eliminar do ficheiro
		    {
		        ppessoa aux = NULL;
                int id;
                lista = LerPessoas();
                aux = lista;
                while(aux != NULL)
                {
                    EscreverPessoa(aux);
                    aux = aux->prox;
                }
                printf("Escolha o ID da pessoa a eliminar.\n");
                scanf("%d",&id);
                aux = lista;
                while(aux != NULL)
                {
                    if(aux->id == id)
                    {
                        EliminarPessoa(aux->nome);
                        aux = aux->prox;
                    }
                    else
                        aux = aux->prox;

                }
                MenuPessoas();
                break;
		    }


        case 4://lista completa de todos as pessoas contidas no ficheiro binario.
            {
                lista = LerPessoas();
                while(lista != NULL)
                {
                    EscreverPessoa(lista);
                    lista = lista->prox;
                }
                free(lista);
                MenuPessoas();
                break;
            }

		case 5:
		    {
		        MenuInicial();
		        break;
            }


		default:
		printf("--- Erro! Opcao Invalida! ---\n");
		break;
	}
}

void MenuConjuntos()
{
    int escolha = 0;
	printf("--- Escolha uma das seguintes opcoes:\n");
	printf("--- 1 - Criar conjuntos.\n");
	printf("--- 2 - Eliminar conjunto.\n");
	printf("--- 3 - Editar conjunto.\n");
	printf("--- x - Regressar ao menu anterior.\n");
	scanf("%d",&escolha);
	switch (escolha)
	{
		case 1:
		    {
		        int NConj,i,NPessoas,j;
		        cconj ListaConj = NULL;

		        Conjunto c;

		        printf("--- Quantos conjuntos pretende inserir?:\n");
		        scanf("%d",&NConj);
		        //c = malloc(sizeof(Conjunto));
                ListaConj = malloc(sizeof(Conjunto)*NConj);
                if(ListaConj==NULL)
					//*ListaConj = c = CriarNovoConjunto(1);

		        for(i=0;i < NConj;i++)
                {
                    //c = CriarNovoConjunto(i+1);
                    //ListaConj[i] = c;
                    ppessoa aux,Lista = NULL;
                    Lista = LerPessoas();



                    printf("Conjunto com o ID %d criado com sucesso!\n");

                    printf("Quantas pessoas pretende adicionar neste conjunto?\n");
                    scanf("%d",&NPessoas);
                    ListaConj[i].VectorPessoas = malloc(sizeof(pessoa)*NPessoas);
                    ListaConj[i].VectorPessoas = NULL;
                    for(j = 0; j < NPessoas; j++)
                        {
                            aux = Lista;
                            while(aux->prox!= NULL)
                            {
                                EscreverPessoa(aux);
                                aux = aux->prox;
                            }
                            aux = Lista;
                            //printf("Escolha um ID para adicionar ao conjunto %d!\n", c.IdConj);
                            printf("Escreva 0 para parar de inserir!\n");
                            scanf("%d",&escolha);
                            while(aux->prox != NULL)
                            {
                                if(aux->id == escolha)
                                {
									//ListaConj[i].VectorPessoas = AdicionarPessoa(ListaConj[i].VectorPessoas, aux);
                                    break;

                                }
                                else
                                    aux = aux->prox;
                            }

                        }

                }
		        break;//break case
		    }


		case 2:
		break;

		case 3:
		break;

		case 4:
		    {

                /*MenuInicial();
		        break;*/
            }
		default:
		    {
		       printf("--- Erro! Opcao Invalida! ---\n");
                break;
		    }

	}
}

void MenuJogo(Jogo *jog)
{
	int opcao = 0;
	cconj aux;
	float anterior;
	aux = jog->VectorConjuntos;
	while (aux != NULL)
	{
		ImprimeConjunto(aux);
		aux = aux->prox;
	}

	jog->DispTotal = CalculaDispersaoTotal(jog->VectorConjuntos);
	printf("Dispersão total: %4.2f\n", jog->DispTotal);
	printf("Jogador %d a jogar!\n", jog->JogActual);
	printf("Escolha uma das opções:\n");
	printf("1 - Eliminar pessoa do conjunto.\n");
	printf("2 - Transferir pessoa de um conjunto para outro.\n");
	printf("3 - Inserir pessoa do conjunto.\n");
	printf("4 - Guardar jogo.\n");
	printf("5 - Ultimas jogadas.\n");
	printf("6 - Sair do jogo.\n");
	scanf("%d", &opcao);
	switch (opcao)
	{
	case 1:
	{
			  cconj aux;
			  aux = jog->VectorConjuntos;
			  opcao = 0;
			  printf("Qual o ID do Conjunto onde eliminar?\n");
			  scanf("%d", &opcao);
			  while (aux != NULL)
			  {
				  if (aux->IdConj == opcao)
				  {

					  if (aux->TotPessoas - 1 < 2)
					  {
						  printf("Não pode eliminar pessoas deste Conjunto!\n");
						  system("pause");
						  MenuJogo(jog);
						  //reencaminhar para menu de jogo e imprimir os conjuntos de novo.
					  }
					  else
					  {
						  ppessoa lista;
						  lista = aux->VectorPessoas;

						  while (lista != NULL)
						  {
							  EscreverPessoa(lista);
							  lista = lista->prox;
						  }
						  lista = aux->VectorPessoas;
						  opcao = 0;
						  printf("Qual o ID da pessoa a eliminar?\n");
						  scanf("%d", &opcao);
						  if (Valida(jog->VectorConjuntos, opcao)==2)
						  {
							  printf("Cada pessoa precisa existir em um dos conjuntos!\n");
							  system("pause");
							  MenuJogo(jog);
						  }
						  while (lista != NULL)
						  {
							  if (lista->id == opcao)
							  {
								  aux->VectorPessoas = EliminarPessoaConjunto(aux->VectorPessoas, opcao);

								  aux->dist = CalcularDistribuicao(aux);
								  printf("Pessoa eliminada com sucesso!");
								  system("pause");
								  anterior = jog->DispTotal;
								  jog->DispTotal = CalculaDispersaoTotal(jog->VectorConjuntos);
								  if (anterior > jog->DispTotal)
								  {
									  if (jog->JogActual == 1){
                                            ljog novaj;
                                            novaj = malloc(sizeof(Jogada));
                                            novaj->NJogador = jog->JogActual;
                                            strcpy(novaj->descricao," eliminou uma pessoa");
                                            novaj->prox = jog->Jogadas;
                                            jog->Jogadas = novaj;

                                            jog->JogActual = 2;
									  }
									  else
                                      {
                                            ljog novaj;
                                            novaj = malloc(sizeof(Jogada));
                                            novaj->NJogador = jog->JogActual;
                                            strcpy(novaj->descricao," eliminou uma pessoa");
                                            novaj->prox = jog->Jogadas;
                                            jog->Jogadas = novaj;
                                            jog->JogActual = 1;
                                      }

									  MenuJogo(jog);
								  }
								  else
								  {
									  printf("Jogador %d Perdeu!\n", jog->JogActual);
									  system("pause");
									  MenuInicial();
								  }
							  }
							  else
								  lista = lista->prox;
						  }

						  //chamar função eliminar conjunto
					  }
				  }
				  else
				  {
					  aux = aux->prox;
				  }

			  }

			  break;
	}

	case 2:
	{
		cconj aux, destino;
		int opcao2 = 0;
		aux = jog->VectorConjuntos;
		destino = jog->VectorConjuntos;
		opcao = 0;
		printf("Qual o ID do Conjunto origem?\n");
		scanf("%d", &opcao);
		printf("Qual o ID do Conjunto destino?\n");
		scanf("%d", &opcao2);
		while (aux != NULL)
		{
			if (aux->IdConj == opcao)
			{

				if (aux->TotPessoas - 1 < 2)
				{
					printf("Não pode transferir pessoas deste Conjunto!");
					//reencaminhar para menu de jogo e imprimir os conjuntos de novo.
				}
				else
				{

					//chamar função transferir conjunto
					ppessoa lista;
					lista = aux->VectorPessoas;

					while (lista != NULL)
					{
						EscreverPessoa(lista);
						lista = lista->prox;
					}
					lista = aux->VectorPessoas;
					opcao = 0;
					printf("Qual o ID da pessoa a transferir?\n");
					scanf("%d", &opcao);
					while (destino != NULL)
					{
						if (destino->IdConj== opcao2)
						{
							while (lista != NULL)
							{
								if (lista->id == opcao)
								{
									aux->VectorPessoas = MoverPessoa(aux->VectorPessoas,lista, destino->VectorPessoas);
									aux->dist = CalcularDistribuicao(aux);

									destino->dist = CalcularDistribuicao(destino);
									anterior = jog->DispTotal;
									jog->DispTotal = CalculaDispersaoTotal(jog->VectorConjuntos);
									if (anterior > jog->DispTotal)
									{
										if (jog->JogActual == 1)
                                        {
                                            ljog novaj;
                                            novaj = malloc(sizeof(Jogada));
                                            novaj->NJogador = jog->JogActual;
                                            strcpy(novaj->descricao," transferiu uma pessoa");
                                            novaj->prox = jog->Jogadas;
                                            jog->Jogadas = novaj;
                                            jog->JogActual = 2;
                                        }

										else
                                        {
                                            ljog novaj;
                                            novaj = malloc(sizeof(Jogada));
                                            novaj->NJogador = jog->JogActual;
                                            strcpy(novaj->descricao," transferiu uma pessoa");
                                            novaj->prox = jog->Jogadas;
                                            jog->Jogadas = novaj;
                                            jog->JogActual = 1;
                                        }
										MenuJogo(jog);
									}
									else
									{
										printf("Jogador %d Perdeu!\n", jog->JogActual);
										system("pause");
										MenuInicial();
									}
								}
								else
									lista = lista->prox;
							}
						}
						else
						{
							destino = destino->prox;
						}

					}

				}
			}
			else
			{
				aux = aux->prox;
			}

		}

		break;
	}
	case 3:
	{
			  cconj aux, vaux;
			  aux = jog->VectorConjuntos;
			  vaux = jog->VectorConjuntos;
			  opcao = 0;
			  printf("Qual o ID do Conjunto a inserir?\n");
			  scanf("%d", &opcao);
			  while (aux != NULL)
			  {
				  if (aux->IdConj == opcao)
				  {
					  //listar pessoas e escolher o ID, validar se o ID já existe senão adiciona
					  ppessoa lista;

					  int count = 0;
					  lista = jog->VectorPessoas;

					  while (lista != NULL)
					  {
						  EscreverPessoa(lista);
						  lista = lista->prox;
					  }
					  printf("Qual o ID da Pessoa a inserir?\n");
					  scanf("%d", &opcao);
					  lista = aux->VectorPessoas;
					  if (Valida(jog->VectorConjuntos,opcao)==1)
					  {
						  printf("Não pode inserir esta pessoa pois já existe 3 vezes nos conjuntos!\n");
						  system("pause");
						  MenuJogo(jog);
					  }

					  while (lista != NULL)
					  {
						  if (lista->id == opcao)
						  {
							  printf("Esta pessoa já existe neste grupo!\n");
							  system("pause");
							  MenuJogo(jog);
						  }


						  else
						  {
							  lista = lista->prox;
						  }

					  }




					  lista = jog->VectorPessoas;

					  while (lista != NULL)
					  {
						  if (lista->id == opcao)
						  {
							  aux->VectorPessoas = AdicionarPessoa(aux->VectorPessoas, lista);
							  printf("Pessoa adicionada com sucesso!\n");
							  aux->dist = CalcularDistribuicao(aux);
							  aux->TotPessoas++;
							  system("pause");
							  anterior = jog->DispTotal;
							  jog->DispTotal = CalculaDispersaoTotal(jog->VectorConjuntos);
							  if (anterior > jog->DispTotal)
							  {
								  if (jog->JogActual == 1)
                                  {
                                            ljog novaj;
                                            novaj = malloc(sizeof(Jogada));
                                            novaj->NJogador = jog->JogActual;
                                            strcpy(novaj->descricao," adicionou uma pessoa");
                                            printf("O jogado %d %s \n",novaj->NJogador,novaj->descricao);
                                            novaj->prox = jog->Jogadas;
                                            jog->Jogadas = novaj;
                                            jog->JogActual = 2;
                                  }

								  else
									  {
                                            ljog novaj;
                                            novaj = malloc(sizeof(Jogada));
                                            novaj->NJogador = jog->JogActual;
                                            strcpy(novaj->descricao," adicionou uma pessoa");
                                            printf("O jogado %d %s \n",novaj->NJogador,novaj->descricao);
                                            novaj->prox = jog->Jogadas;
                                            jog->Jogadas = novaj;
                                            jog->JogActual = 1;
                                    }
								  MenuJogo(jog);
							  }
							  else
							  {
								  printf("Jogador %d Perdeu!\n", jog->JogActual);
								  system("pause");
								  MenuInicial();
							  }
						  }
						  else
						  {
							  lista = lista->prox;
						  }

					  }

				  }
				  else
				  {
					  aux = aux->prox;
				  }

			  }

			  break;
	}
	case 4:
	{
			  int op = 0;
			  GuardarJogo(jog);
			  printf("Deseja continuar este jogo ou sair?\n");
			  printf("1 - Sair\n");
			  printf("2 - Continuar\n");
			  scanf("%d", &op);
			  if (op == 1)
				  MenuInicial();
			  else
				  MenuJogo(jog);
	}
	case 5:
        {
            ljog auxjog;
            auxjog = jog->Jogadas;
            printf("A listar as ultimas jogadas\n");

            while(auxjog != NULL)
            {
                printf("O jogado %d %s \n",auxjog->NJogador,auxjog->descricao);
                auxjog = auxjog->prox;
            }
            system("pause");
            MenuJogo(jog);
        }
	case 6:
        {
            printf("A limpar memória!\n");
            LimparJogo(jog);
            printf("Memória limpa!\n");
            system("pause");
            MenuInicial();
            break;
        }
	default:
		break;
	}
}

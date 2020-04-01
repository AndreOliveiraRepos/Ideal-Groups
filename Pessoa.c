#include "Pessoas.h"



pessoa NovaPessoa(){//implementar o ID com o fseek(seek_set)
    pessoa p;
    FILE *f;
    f = fopen("pessoas.dat", "rb");
    fseek(f, 0, SEEK_END);
	if(ftell(f) / sizeof(pessoa)==0)
        p.id=1;
    else
        p.id = ftell(f) / sizeof(pessoa)+1;
    printf("Insira o Nome da Pessoa: ");
    scanf("%s",p.nome);
    printf("Insira a Idade da Pessoa: ");
    scanf("%d", &(p.idade));
    GuardaPessoa(&p);
    fclose(f);
    return p;
}

//funçoes de pessoa
void EscreverPessoa(pessoa *p){

    printf("--------------------------------\n");
    printf("ID: %d \n",p->id);
    printf("NOME: %s \n",p->nome);
    printf("IDADE: %d \n",p->idade);

}

void GuardaPessoa(pessoa *p){
    FILE *f;
    //int i;
    f = fopen("pessoas.dat", "ab");
    if(f==NULL)
    {
        printf("Erro no acesso ao ficheiro\n");
        return;
    }
    /*for(i=0; i<total; i++)*/
        fwrite(p, sizeof(pessoa), 1, f);
    fclose(f);
    printf("Pessoa com o ID %d gravada com sucesso\n",p->id);
}

void EliminarPessoa(char *n){
    FILE *f,*g;
    pessoa c;
    f=fopen("pessoas.dat","rb");
    g=fopen("temporario.dat","wb");
    while(fread(&c,sizeof(pessoa),1,f)==1)
    {
            if(strcmp(c.nome,n)!=0)
            {
                EscreverPessoa(&c);
                fwrite(&c,sizeof(pessoa),1,g);

            }

    }
    fclose(f);
    fclose(g);
    remove("pessoas.dat");
    rename("temporario.dat","pessoas.dat");
}

void EditarPessoa(ppessoa l, int id)
{
    int escolha;
    //screverPessoa(p);
    printf("1 - Editar nome\n");
    printf("2 - Editar Idade\n");
    scanf("%d",&escolha);
    switch (escolha)
	{
		case 1:
            {
                FILE *f,*g;
                char nnome[110];
                f=fopen("pessoas.dat","rb");
                g=fopen("temporario.dat","wb");
                while(l!=NULL)
                {
                    if(l->id != id)
                    {
                        fwrite(l,sizeof(pessoa),1,g);
                        l = l->prox;
                    }
                    else
                    {
                        printf("Escreva um novo nome!\n");
                        scanf("%s",nnome);
                        strcpy(l->nome,nnome);
                        fwrite(l,sizeof(pessoa),1,g);
                        l= l->prox;
                    }

                }
                fclose(f);
                fclose(g);

                remove("pessoas.dat");

                rename("temporario.dat","pessoas.dat");



                break;
            }
        case 2:
            {
                break;
            }
        default:
            break;
	}
}

ppessoa LerPessoas()
{
    ppessoa novo, lista = NULL;
    FILE *f;
    int i, total;
    f = fopen("pessoas.dat", "rb");
    if(!f)
        return NULL;
	fseek(f, 0, SEEK_END);
	total = ftell(f) / sizeof(pessoa);
    fseek(f, 0, SEEK_SET);
    for(i=total-1;i>=0;i--)
    {
        fseek(f, sizeof(pessoa)*i, SEEK_SET);
        novo = malloc(sizeof(pessoa));
        if(novo == NULL)
        {
            fclose(f);
            return lista;
        }
        fread(novo, sizeof(pessoa),1, f);
        novo->prox = lista;
        lista = novo;
		//lista->TotalBin++;
    }
    fclose(f);//free novo
    return lista;
}

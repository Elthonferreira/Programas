#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
typedef struct
{
    char nome[40];
    char email[30];
    char rua[50];
    char bairro[30];
    char cidade[30];
    char cep[15];
    long int cpf;
    int telefone;
}Agenda;
void alterar(Agenda* a,long int cpf,int seq)
{
    system("cls");
    printf("\n\t º%i na ordem da agenda!\n\nCpf: %li",seq+1,cpf);
    printf("\nNome: ");
    gets((*a).nome);
    printf("E-mail: ");
    gets((*a).email);
    printf("Telefone: ");
    scanf("%i",&(*a).telefone);
    getchar();
    printf("\nEndereço\n\nRua: ");
    gets((*a).rua);
    printf("\nBairro: ");
    gets((*a).bairro);
    printf("\nCidade: ");
    gets((*a).cidade);
    printf("\nCep: ");
    gets((*a).cep);
}
Agenda cadastrar(int num_sequencia)
{
    Agenda a;
    system("cls");
    printf("\tCADASTRAMENTO\n\nArmazenado no º%i espaço\n\nNome: ",num_sequencia);
    gets(a.nome);
    printf("E-mail: ");
    gets(a.email);
    printf("Cpf: ");
    scanf("%li",&a.cpf);
    printf("Telefone: ");
    scanf("%i",&a.telefone);
    getchar();
    printf("\nEndereço\n\nRua: ");
    gets(a.rua);
    printf("Bairro: ");
    gets(a.bairro);
    printf("Cidade: ");
    gets(a.cidade);
    printf("Cep: ");
    gets(a.cep);
    return a;
}
void mostrar(Agenda* contato,int seq)
{
    system("cls");
    printf("\n------------------------------------------\n\t º%i na ordem da agenda!\n\n",seq+1);
    printf("\n\nNome: %s\n",(*contato).nome);
    printf("E-mail: %s\n",(*contato).email);
    printf("Cpf: %li\n",(*contato).cpf);
    printf("Telefone: %i\n",(*contato).telefone);
    printf("\nEndereço\n\nRua: %s",(*contato).rua);
    printf("\nBairro: %s",(*contato).bairro);
    printf("\nCidade: %s",(*contato).cidade);
    printf("\nCep: %s\n\n",(*contato).cep);
    system("pause");
} 
void procurar(Agenda* buscando,int seq)
{
    system("cls");
    printf("\t º%i na ordem da agenda\n\nNome: %s",seq,(*buscando).nome);
    printf("\nE-mail: %s",(*buscando).email);
    printf("\nCpf: %li",(*buscando).cpf);
    printf("\nTelefone: %i",(*buscando).telefone);
    printf("\n\nEndereço\n\nRua: %s",(*buscando).rua);
    printf("\nBairro: %s",(*buscando).bairro);
    printf("\nCidade: %s",(*buscando).cidade);
    printf("\nCep: %s\n\n",(*buscando).cep);
    system("pause");
}
main()
{
    setlocale(LC_ALL,"Portuguese");
    FILE* arq1;
    FILE* arq2;
    long int menu;
    int add=0;
    int aux;
    int count;
    int salvar=0;
    Agenda contato[100];
    Agenda troca;
    arq1 = fopen("num_add.bin","rb");
    arq2 = fopen("info_contatos.bin","rb");
    fread(&add,sizeof(add),1,arq1);
    fread(&contato,sizeof(contato),1,arq2);
    fclose(arq1);
    fclose(arq2);
    while(salvar!=1)
    {
        system("cls");
        printf("\t%iAGENDA\n\n1 - Cadastrar\n2 - Deletar\n3 - Procurar\n4 - Alterar\n5 - Todos os contatos\n6 - Fechar a agenda\n--> ",add);
        scanf("%li",&menu);
        fflush(stdin);
        switch(menu)
        {
            case 1:
                {
                    for(add;add<100;)
                    {
                        contato[add] = cadastrar(add+1);
                    break;
                    }
                    for(aux=0;aux<add;aux++)
                    {
                        if(contato[add].cpf==contato[aux].cpf)
                        {
                            while(contato[add].cpf==contato[aux].cpf)
                            {
                                system("cls");
                                printf("\n\n\nCPF inválido. digite novamente: ");
                                scanf("%li",&contato[add].cpf);
                            }
                        }
                    }
                    if(add==99)
                    {
                        system("cls");
                        printf("\n\n\tNão se pode cadastrar mais contatos\nNúmero maximo de 100 contatos atingidos!\nPara cadastrar mais delete algum outro contato\n\n");
                    }
                    ++add;
                    arq1 = fopen("num_add.bin","wb");
                    arq2 = fopen("info_contatos.bin","wb");
                    fread(&add,sizeof(add),1,arq1);
                    fread(&contato,sizeof(contato),1,arq2);
                    fclose(arq1);
                    fclose(arq2);
                break;
                }
            case 2:
                {
                    system("cls");
                    printf("\n\tDELETAR\n\nDigite o CPF do contato que deseja deletar: ");
                    scanf("%li",&menu);
                    if(add==0)
                    {
                        system("cls");
                        printf("\n\n\tNão existe nenhum contato cadastrado!\n\n");
                        system("pause");
                    }
                    else
                    {
                        for(aux=0;aux<add;++aux)
                        {
                            printf("%li",menu);
                            if(menu==contato[aux].cpf)
                            {
                                for(count=aux;count<add;count++)
                                {
                                    troca = contato[aux+1];
                                    contato[aux+1] = contato[aux];
                                    contato[aux] = troca;
                                }
                                --add;
                                system("cls");
                                printf("\n\n\n\tContato deletado com sucesso !\n\n\n");
                                system("pause");
                            }
                            else
                            {
                                system("cls");
                                printf("\n\n\n\tO contato não foi encontrado !\n\n\n");
                                system("pause");
                            }
                        }
                    }
                break;
                }
            case 3:
                {
                    if(add==0)
                    {
                        system("cls");
                        printf("\n\n\tNão existe nenhum contato cadastrado!\n\n");
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        printf("\n\n\tPROCURAR\n\nInsira o CPF do contato: ");
                        scanf("%li",&menu);
                        getchar();
                        for(aux=0;aux<add;aux++)
                        {
                            if(contato[aux].cpf==menu)
                            {
                                procurar(&contato[aux],aux+1);
                                break;
                            }
                            else if(aux==add-1)
                            {
                                system("cls");
                                printf("\n\n\tContato não encontrado!\n\n");
                                system("pause");
                            }
                        }
                    }
                break;
                }
            case 4:
                {
                    if(add==0)
                    {
                        system("cls");
                        printf("\n\n\tNão existe nenhum contato cadastrado!\n\n");
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        printf("\n\n\tALTERAR\n\nInsira o CPF do contato: ");
                        scanf("%li",&menu);
                        fflush(stdin);
                        for(aux=0;aux<add;aux++)
                        {
                            if(contato[aux].cpf==menu)
                            {
                                alterar(&contato[aux],contato[aux].cpf,aux);
                                system("cls");
                                printf("\n\n\tº%i espaço da agenda foi alterado com sucesso\n\n",aux+1);
                                system("pause");
                                break;
                            }
                            else if(aux==add-1)
                            {
                                system("cls");
                                printf("\n\n\tContato não encontrado!\n\n");
                                system("pause");
                                break;
                            }
                        }
                    }
                break;
                }
            case 5:
                {
                    if(add==0)
                    {
                        system("cls");
                        printf("\n\n\tNão existe nenhum contato cadastrado!\n\n");
                        system("pause");
                    }
                    else
                    {
                        for(aux=0;aux<add;++aux)
                        {
                            mostrar(&contato[aux],aux);
                        }
                    }
                break;
                }
            case 6:
                {
                    system("cls");
                    printf("\n\n\n\tfechando a agenda!\n\n\n");
                    system("pause");
                    salvar=1;
                break;
                }
            default:
                {
                    system("cls");
                    printf("\n\n\tOpção inválida!\n\n");
                    system("pause");
                }
        }
    }
    arq1 = fopen("num_add.bin","wb");
    arq2 = fopen("info_contatos.bin","wb");
    fwrite(&add,sizeof(add),1,arq1);
    fwrite(&contato,sizeof(contato),1,arq2);
    fclose(arq1);
    fclose(arq2);
return 0;
}

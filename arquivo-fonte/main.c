#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"
#include "Fila.h"
#include "Lista.h"
#include "relatorio.h"
#include <locale.h>
#include <windows.h>


int main()
{

    setlocale(LC_ALL,"Portuguese");
    system("color 5F");
    system("title Instituição de Caridade GameOfThrones");


    int opc,opc1,opc2,opc3;
    char doador[121],pecaDeRoupa[50],livro[100];

    Listaa* listaDoacoes_historico=cria_lista();
    Listaa* listaDoacoes_txt=cria_lista();
    ListaRelatorio* listaResultado_historico = cria_listaRelatorio();
    ListaRelatorio* listaResultado_txt = cria_listaRelatorio();
    Fila* fila= fila_cria();
    PilhaLivro* pilha=cria();


   do{
        printf("\n\t==========================\n");
        puts("\tCAMPANHA DO AGASALHO - GOT\n");
        printf("\t==========================\n\n");
        printf("\n =========== MENU DE OPÇÕES =============\n");
        printf("   [1]           Fila de pessoas\n");
        printf("   [2]           Pilha de Livros\n");
        printf("   [3]           Opção para Realizar Doação\n");
        printf("   [4]           Histórico de Doações\n");
        printf("   [5]           Entregar Documentos\n");
        printf("   [6]           Ganhadores dos livros\n");
        printf("   [7]           Sair\n");
        printf(" =======================================\n");
        printf(" Informe sua opção: ");
        fflush(stdin);
        scanf("%d",&opc);
        switch(opc){
        case 1:
            system("cls");
            do{
                printf("\n  +-----------------+\n");
                printf("  | FILA DE PESSOAS |\n");
                printf("  +-----------------+\n\n");
                printf(" 1- Cadastrar \n");
                printf(" 2- Remover Doadores\n");
                printf(" 3- Exibir fila de Doadores\n");
                printf(" 0- Voltar ao menu principal\n");
                printf("\nInforme sua opção: ");
                fflush(stdin);
                scanf("%d",&opc1);
//int i;
                switch(opc1){
                case 1:
                    system("cls");
                    printf("\n  +-------------------------------+\n");
                    printf("  | TELA DE CADASTRO DOS DOADORES |\n");
                    printf("  +-------------------------------+\n\n");
                    printf(" Informe o nome do doador: ");
                    fflush(stdin);
                    scanf(" %120[^\n]s",doador);
                            if((percore_relatorio(listaResultado_historico,doador)!=0) || (comparaFila(fila,doador)!=0)){
                        printf ("\n\n*O doador informado já está na fila, ou já realizou a doação.\n\n");
                        printf("você está sendo redirecionado para o menu principal, aguarde. \n\n");
                        Sleep(3000);
                        system("cls");
                    }else{
                        printf("\n Informe a peça de roupa: ");
                        fflush(stdin);
                        scanf(" %50[^\n]s",pecaDeRoupa);
                        fila_inserir(fila,doador,pecaDeRoupa);
                        printf("\n *Cadastro relizado com sucesso!\n");
                        system("pause");
                        system("cls");
                    }
                    break;
                case 2:
                    system("cls");
                    printf("\n  +-------------------------------+\n");
                    printf("  | TELA DE REMOÇÃO DOS DOADORES |\n");
                    printf("  +-------------------------------+\n\n");
                    if(fila_vazia(fila)){
                        printf("\n *A Fila de doadores se encontra vazia no momento. Não há o que remover!\n");
                        system("pause");
                        system("cls");
                    }else{
                       fila_remover(fila,doador,pecaDeRoupa);
                        printf("\a\n *Remoção realizada com sucesso!\nSe desejar, verifique a lista de doadores para confirmar.\n\n");
                        system("pause");
                        system("cls");
                    }
                    break;
                case 3:
                    system("cls");
                    printf("\n  +-------------------------------+\n");
                    printf("  | REGISTRO DA FILA DOS DOADORES |\n");
                    printf("  +-------------------------------+\n\n");
                    imprime(fila);
                    system("pause");
                    system("cls");
                    break;
                case 0:
                    system("cls");
                    printf("\a\n Retornando ao menu principal...\n");
                    Sleep(1000);
                    system("cls");
                    break;
                default:
                    system("cls");
                    printf("\n OPÇÃO INVÁLIDA\nVocê será redirecionado para o menu em instantes, aguarde!\n");
                    Sleep(1000);
                    system("cls");
                    break;
                }

            }while(opc1!=0);
            break;
        case 2:
            system("cls");
            do{
                printf("\n  +-----------------+\n");
                printf("  | PILHA DE LIVROS |\n");
                printf("  +-----------------+\n\n");
                printf(" [1] - Cadastrar Livros\n");
                printf(" [2] - Remover Livro\n");
                printf(" [3] - Exibir Livros\n");
                printf(" [0] - Voltar ao menu principal\n");
                printf("\nInforme sua opção: ");
                fflush(stdin);
                scanf("%d",&opc2);

                switch(opc2){
                case 1:
                    system("cls");
                    printf("\n  +----------------------------+\n");
                    printf("  | TELA DE CADASTRO DE LIVROS |\n");
                    printf("  +----------------------------+\n\n");
                    printf(" Insira o nome do livro: ");
                    fflush(stdin);
                    scanf(" %50[^\n]s",livro);
                    pushlivro(pilha,livro);
                    system("cls");
                    break;
                case 2:
                    system("cls");
                    printf("\n  +---------------------------+\n");
                    printf("  | TELA DE REMOÇÃO DE LIVROS |\n");
                    printf("  +---------------------------+\n\n");
                    if(pilha_vazia(pilha)){
                        puts(" *A pilha de livros se encontra vazia no momento, não há o que remover!\n");
                        system("pause");
                    }else{
                        strcpy(livro,poplivro(pilha));
                        printf("\a\n *Remoção realizada com sucesso!\n Se desejar, verifique a pilha de livros para confirmar.\n");
                        system("pause");
                    }
                    system("cls");
                    break;
                case 3:
                    system("cls");
                    printf("\n  +--------------------+\n");
                    printf("  | REGISTRO DE LIVROS |\n");
                    printf("  +--------------------+\n\n");
                    imprime_pilha(pilha);
                    system("pause");
                    system("cls");
                    break;
                case 0:
                    system("cls");
                    printf("\a\n Retornando ao Menu Principal...\n");
                    Sleep(1000);
                    system("cls");
                    break;
                default:
                    system("cls");
                    printf("\a\n OPÇÃO INVÁLIDA\nVocê será redirecionado para o Menu em instantes, aguarde!\n");
                    Sleep(1000);
                    system("cls");
                    break;
                }

            }while(opc2!=0);
            break;
        case 3:
            system("cls");
            if(!fila_vazia(fila) && !pilha_vazia(pilha)){
                printf("\n\n REALIZANDO DOAÇÃO...\n");
                Sleep(2000);
                fila_remover(fila,doador,pecaDeRoupa);
                lista_de_doacao(listaDoacoes_historico,pecaDeRoupa,listaDoacoes_txt);
                strcpy(livro,poplivro(pilha));
                lista_relatorio(listaResultado_historico,doador,livro);
                lista_relatorio(listaResultado_txt,doador,livro);
                printf("\n|=============================|\n");
                printf("\n|Doação Realizada com sucesso!|");
                printf("\n|=============================|\n\n");
                printf("\n %s recebeu o livro %s\n\n",doador,livro);
                system("pause");
                system("cls");
            }
            else {
                printf("\n  +-------------------------------+\n");
                printf("  | TELA DE REALIZAÇÃO DE DOAÇÕES |\n");
                printf("  +-------------------------------+\n\n");
                puts("\a Erro ao realizar doação,verifique o estoque de livros, e/ou a quantidade de pessoas cadastradas.\n");
                Sleep(3000);
                system("cls");
            }
            break;
        case 4:
            system("cls");
            imprime_listaDeDoacoes(listaDoacoes_historico);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            do{
                printf("\n  +------------------+\n");
                printf("  | GERAR DOCUMENTOS |\n");
                printf("  +------------------+\n\n");
                printf (" [1] - Estoque de doações\n");
                printf (" [2] - Relatório final\n");
                printf (" [0] - Voltar ao menu principal\n");
                printf ("\nInforme a opção desejada: ");
                fflush(stdin);
                scanf("%d",&opc3);
                switch(opc3){
                case 1:
                    gera(listaDoacoes_txt);
                    system("pause");
                    system("cls");
                break;
                case 2:
                    geraRelatorio(listaResultado_txt);
                    system("pause");
                    system("cls");
                break;
                case 0:
                    system("cls");
                    printf("\a\n Retornando ao Menu Principal...\n");
                    Sleep(1000);
                    system("cls");
                    break;
                default:
                    system("cls");
                    printf("\a\n OPÇÃO INVÁLIDA\nVocê será redirecionado para o Menu em instantes, aguarde!\n");
                    Sleep(1000);
                    system("cls");
                    break;
                }
            } while(opc3!=0);
            break;
        case 6:
            system("cls");
            imprime_relatorio(listaResultado_historico);
            system("pause");
            system("cls");
            break;
        case 7:
            system("cls");
            printf("\a\n O programa será fechado, confirme se deseja sair \n");
            printf("7 - Sair\t\t\t 0 - Cancelar e continuar\n");
            fflush(stdin);
            scanf("%d",&opc);
            if(opc==7){
                system("cls");
                libera_pilha(pilha);
                libera_fila(fila);
                libera_DoacoesCompleto(listaDoacoes_historico);
                libera_DoacoesCompleto(listaDoacoes_txt);
                libera_RelatorioCompleto(listaResultado_historico);
                libera_RelatorioCompleto(listaResultado_txt);
                printf("\a\nSaindo do programa...\n\n");
                Sleep(2000);
            }
            system("cls");
            break;
        default:
            system("cls");
            printf("\nOPÇÃO INVÁLIDA\nVocê será redirecionado para o menu em instantes, aguarde!\n");
            Sleep(1500);
            system("cls");
            break;
        }
   }while(opc!=7);

    return 0;
}

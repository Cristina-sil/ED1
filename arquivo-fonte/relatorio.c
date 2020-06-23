#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "relatorio.h"

typedef struct no noRelatorio;
struct no{
    char doador[120];
    char livro[50];
    noRelatorio* prox;
};


struct lista{
    noRelatorio* prim;

};

ListaRelatorio* cria_listaRelatorio(void){
    ListaRelatorio* lst = (ListaRelatorio*)malloc(sizeof(ListaRelatorio));
    if (lst == NULL){
        puts("\nMemória Indisponível\n");
        exit(1);
    }

    lst->prim = NULL;
    return lst;
}

void lista_relatorio(ListaRelatorio* lista,char* doador,char* livroGanho){
    noRelatorio* n;
    n = (noRelatorio*)malloc(sizeof(noRelatorio));
    if (n == NULL){
        puts("\nMemória indisponível\n");
        exit(1);
    }

    strcpy(n->doador,doador);
    strcpy(n->livro,livroGanho);

    n->prox=lista->prim;
    lista->prim = n;
}

void geraRelatorio(ListaRelatorio* lst){
    FILE* arquivo;
    if(lst->prim!=NULL){
        arquivo = fopen("relatorio.txt","a");
        if (arquivo == NULL){
            printf ("\nFalha ao abrir arquivo\n");
            exit (1);
        }
        noRelatorio* aux;
        for (aux=lst->prim;aux!=NULL;aux=aux->prox){
            fprintf(arquivo,"Doador:%s\t\tLivro:%s\n",aux->doador,aux->livro);
        }
        printf("\n");

        fclose(arquivo);

        printf("\n\nRELATÓRIO COM A REALÇÃO DOS DOADORES COM OS RESPECTIVOS LIVROS GANHOS FOI GERADO COM SUCESSO!\n\n");
        libera_relatorio_nos(lst);
    }
    else{
        printf ("\n *ATENÇÃO\n A lista com os dados dos doadores e o prêmio se encontra vazia, ou já foi gerado, mas você pode tentar novamente.\n\n");
    }
}


void imprime_relatorio(ListaRelatorio *lst){
    puts("\n RELAÇÃO DOS DOADORES E RESPECTIVOS LIVROS GANHOS\n");
    if(lst->prim!=NULL){
        noRelatorio* aux;
        for(aux=lst->prim;aux!=NULL;aux=aux->prox){
            printf("DOADOR: %s     LIVRO: %s\n",aux->doador,aux->livro);
        }
        printf("\n");
    }else{
        puts("ATENÇÃO: Ainda não há doacões, tente novamente.\n");
    }
}


int percore_relatorio(ListaRelatorio* listaResultado_historico,char *nome){
    noRelatorio* no;
    if(listaResultado_historico->prim!=NULL){
        for(no=listaResultado_historico->prim;no!=NULL;no=no->prox){
            if(strcmp(nome,no->doador)==0){
                return 1;
            }
        }
    }
    return 0;
}

void libera_relatorio_nos(ListaRelatorio* lst){
    noRelatorio* aux=lst->prim;
    while(aux!=NULL){
        noRelatorio* temp=aux->prox;
        free(aux);
        aux=temp;
    }
    lst->prim=NULL;
}

void libera_RelatorioCompleto(ListaRelatorio* lst){
    noRelatorio* aux=lst->prim;
    while(aux!=NULL){
        noRelatorio* temp=aux->prox;
        free(aux);
        aux=temp;
    }
    free(lst);
    lst=NULL;
}

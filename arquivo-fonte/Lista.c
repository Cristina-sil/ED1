#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"
#include "Fila.h"
#include "Pilha.h"

struct noo{
    char roupa[51];
    ListaNoo* prox;
};

struct listaa{
    ListaNoo* prim;
};

Listaa* cria_lista(void){
    Listaa* lst=(Listaa*)malloc(sizeof(Listaa));
    if(lst==NULL){
        puts("Memória insuficiente!\n");
        exit(1);
    }
    lst->prim=NULL;
    return lst;
}

void lista_de_doacao(Listaa* lst,char* roupa,Listaa* lst2){

    ListaNoo* novoLst1=(ListaNoo*)malloc(sizeof(ListaNoo));
    if(novoLst1==NULL){
        puts("Memória insuficiente!\n");
        exit(1);
    }

    ListaNoo* novoLst2=(ListaNoo*)malloc(sizeof(ListaNoo));
    if(novoLst2==NULL){
        puts("Memória insuficiente!\n");
        exit(1);
    }

    strcpy(novoLst1->roupa,roupa);
    strcpy(novoLst2->roupa,roupa);

    novoLst1->prox=lst->prim;
    novoLst2->prox=lst2->prim;

    lst->prim=novoLst1;
    lst2->prim=novoLst2;

}

void imprime_listaDeDoacoes(Listaa* lst){
    ListaNoo* aux;
    int qtdR=0;
    printf("\n REGISTROS DE DOAÇÕES\n\n");
    if(lst->prim!=NULL){
        for(aux=lst->prim;aux!=NULL;aux=aux->prox){
            printf(" - %s\n",aux->roupa);
            qtdR++;
        }
        printf("\nTotal de peças de roupa = %d\n",qtdR);
    }else{
        printf(" Nenhuma doação feita até o momento.");
    }
    puts("\n");
}

void gera(Listaa* lst){
    FILE *arquivo;
    int qtdTotal=0;
    if(lst->prim!=NULL){
        arquivo = fopen("doacao.txt","a");
        if (arquivo == NULL){
            printf ("Arquivo não pôde ser criado\n");
            exit(1);
        }

        ListaNoo *aux;
        for (aux = lst->prim;aux!=NULL;aux=aux->prox){
            fprintf(arquivo," - %s\n",aux->roupa);
            qtdTotal++;
        }

        fclose(arquivo);

        printf("\n RELATÓRIO COM A LISTA DE DOAÇÕES FOI GERADO COM SUCESSO!\n\n");
        liberaDoacoes_nos(lst);
        }else{
            printf("\n *ATENÇÃO!\n\n O Relatório com a Lista de Doações já foi gerado e salvo ou o Registro de Doações se encontra vazio!\n\n");
        }
}

void liberaDoacoes_nos(Listaa *lst){
    ListaNoo* p=lst->prim;
    while(p!=NULL){
        ListaNoo* t=p->prox;
        free(p);
        p=t;
    }
   lst->prim=NULL;
}

void libera_DoacoesCompleto(Listaa *lst){
    ListaNoo* p=lst->prim;
    while(p!=NULL){
        ListaNoo* t=p->prox;
        free(p);
        p=t;
    }
    free(lst);
    lst=NULL;
}





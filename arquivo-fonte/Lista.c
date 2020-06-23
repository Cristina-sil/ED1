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
        puts("Mem�ria insuficiente!\n");
        exit(1);
    }
    lst->prim=NULL;
    return lst;
}

void lista_de_doacao(Listaa* lst,char* roupa,Listaa* lst2){

    ListaNoo* novoLst1=(ListaNoo*)malloc(sizeof(ListaNoo));
    if(novoLst1==NULL){
        puts("Mem�ria insuficiente!\n");
        exit(1);
    }

    ListaNoo* novoLst2=(ListaNoo*)malloc(sizeof(ListaNoo));
    if(novoLst2==NULL){
        puts("Mem�ria insuficiente!\n");
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
    printf("\n REGISTROS DE DOA��ES\n\n");
    if(lst->prim!=NULL){
        for(aux=lst->prim;aux!=NULL;aux=aux->prox){
            printf(" - %s\n",aux->roupa);
            qtdR++;
        }
        printf("\nTotal de pe�as de roupa = %d\n",qtdR);
    }else{
        printf(" Nenhuma doa��o feita at� o momento.");
    }
    puts("\n");
}

void gera(Listaa* lst){
    FILE *arquivo;
    int qtdTotal=0;
    if(lst->prim!=NULL){
        arquivo = fopen("doacao.txt","a");
        if (arquivo == NULL){
            printf ("Arquivo n�o p�de ser criado\n");
            exit(1);
        }

        ListaNoo *aux;
        for (aux = lst->prim;aux!=NULL;aux=aux->prox){
            fprintf(arquivo," - %s\n",aux->roupa);
            qtdTotal++;
        }

        fclose(arquivo);

        printf("\n RELAT�RIO COM A LISTA DE DOA��ES FOI GERADO COM SUCESSO!\n\n");
        liberaDoacoes_nos(lst);
        }else{
            printf("\n *ATEN��O!\n\n O Relat�rio com a Lista de Doa��es j� foi gerado e salvo ou o Registro de Doa��es se encontra vazio!\n\n");
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





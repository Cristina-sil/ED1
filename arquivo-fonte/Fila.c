#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila.h"
#include "Lista.h"
#include "Pilha.h"

struct no{
    ListaNo* prox;
    char nome[121];
    char roupa[51];
};
struct fila{
    ListaNo* inicio;
    ListaNo* fim;
};

Fila* fila_cria(void){
    Fila* f=(Fila*)malloc(sizeof(Fila));
    if(f==NULL){
        puts("Memória insuficiente!\n");
        exit(1);
    }

    f->fim =NULL;
    f->inicio=NULL;

    return f;
}

void fila_inserir(Fila* f,char* nome,char* roupa){
    ListaNo* novo=(ListaNo*)malloc(sizeof(ListaNo));
    if(novo==NULL){
        puts("Memória insuficiente!\n");
        exit(1);
    }
    strcpy(novo->nome,nome);
    strcpy(novo->roupa,roupa);
    novo->prox=NULL;

    if(f->fim==NULL){
        f->inicio=novo;
    }else{
        f->fim->prox=novo;
    }
    f->fim=novo;
}


void fila_remover(Fila* f,char* nome,char* roupa){
    ListaNo* aux;
    aux=f->inicio;

    strcpy(roupa,aux->roupa);
    strcpy(nome,aux->nome);

    f->inicio=aux->prox;

    if(f->inicio==NULL){
        f->fim=NULL;
    }

    free(aux);
}

void imprime(Fila* f){
    ListaNo* aux;
    if(!fila_vazia(f)){
        for(aux=f->inicio;aux!=NULL;aux=aux->prox){
            printf(" 1 - %s \t deseja doar: %s\n",aux->nome,aux->roupa);
        }
        printf("\n");
    }else{
        printf("\nFila vazia, não há nada para ser impresso.\n");
    }
}

int  comparaFila(Fila *f, char*nome){
    ListaNo* no;
    for (no=f->inicio; no!=NULL; no=no->prox){
        if (strcmp(no->nome,nome)==0){
            return 1;
        }
    }
    return 0;
}

int fila_vazia(Fila* f){
    return (f->inicio==NULL);
}

void libera_fila(Fila* f){
    ListaNo* no=f->inicio;
    while(no!=NULL){
        ListaNo* temp=no->prox;
        free(no);
        no=temp;
    }
    free(f);
}

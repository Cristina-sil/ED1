#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pilha.h"
#include "Fila.h"
#include "Lista.h"

typedef struct nolivro NoLivro;
struct nolivro{
    char livro[100];
    NoLivro *prox;
};

struct pilhalivro{
   NoLivro *prim;
};

PilhaLivro* cria(void){
    PilhaLivro* p = (PilhaLivro*) malloc(sizeof(PilhaLivro));
    if (p== NULL){
        printf("\nMemória insuficiente\n");
        exit(1);
    }
    p->prim = NULL;
    return p;
}


void pushlivro(PilhaLivro *p, char* nome_livro){
    NoLivro* lista = (NoLivro*)malloc(sizeof(NoLivro));
    if(lista==NULL){
        printf("\nMemória insuficiente!\n");
        exit(1);
    }
    strcpy(lista->livro,nome_livro);
    lista->prox= p->prim;
    p->prim = lista;
    printf ("\a\nLivro cadastrado com sucesso!\n");
    system("pause");

}

char* poplivro(PilhaLivro *p){
    NoLivro* no;
    char* livro;
    livro = (char*)malloc(100*sizeof(char));
    if(livro == NULL){
        printf ("Memória insuficiente!\n");
        return NULL;
    }

    no = p->prim;
    strcpy(livro,no->livro);
    p->prim = no->prox;
    free(no);

    return livro;
}

void imprime_pilha(PilhaLivro* p){
    NoLivro* no;
    int qtdL=0;
    puts("(Estoque de livros disponíveis para troca.)");
    if(!pilha_vazia(p)){
        for (no = p->prim; no!=NULL; no=no->prox){
            printf("\n [%d]: %s\n",qtdL+1,no->livro);
            qtdL++;
        }
    }else{
        printf("\nNão há livros disponíveis.\n");
    }
    puts("\n");
}

int pilha_vazia(PilhaLivro *p){
    return(p->prim == NULL);
}

void libera_pilha(PilhaLivro* p){
    NoLivro* no=p->prim;
    while(no!=NULL){
        NoLivro *temp= no->prox;
        free(no);
        no=temp;
    }
    free(p);

}

#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED


typedef struct no ListaNo;
typedef struct fila Fila;

Fila* fila_cria(void);
/* A função fila_cria vai criar a fila, alocando o espaço necessário na memória, e retorna o endereço pra fila.
* Não possui parâmetros. */


void fila_inserir(Fila* f,char* nome,char* roupa);
/* A função fila_inserir tem por objetivo inserir pessoas na fila,
* tendo esta como parâmentro uma string roupa e outra string nome( informações pertencentes à pessoa), e o endereço pra fila. */


void fila_remover(Fila* f,char* nome,char* roupa); //remove uma pessoa da fila
/* A função fila_remover tem a seguinte finalidade: remover elementos da fila, que são o nome e a roupa do doador.
 Os parâmetros são o endereço pra fila, uma string roupa e outra string nome. */

void imprime(Fila* f);
/* Essa função exibe todos os elementos da fila, mostrando, portanto, os nomes das pessoas presentes na fila.
* Recebe como parâmetro o endereço para essa fila. Caso a fila esteja vazia, mostrará uma mensagem correspodente.*/


int fila_vazia(Fila* f);
/* A função fila_vazia recebe como parâmetro o endereço pra fila e visa
* verificar se há ou não elementos na fila. Retorna 1 caso esteja vazia, e 0 caso contrário.*/


int comparaFila(Fila *f, char* nome);
/* Essa função recebe o endereço de uma fila e uma string nome que representa um nome de pessoa
* que se deseja inserir na fila. A função percorre a fila para verificar a existência ou não
* do mesmo nome. Retornará 0 caso não encontre, e 1 caso contrário.
* para  */

void libera_fila(Fila *f);
/* Recebe como parâmetro o endereço pra uma fila e esta será liberada. */


#endif // FILA_H_INCLUDED

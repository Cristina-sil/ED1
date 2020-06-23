#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED


typedef struct no ListaNo;
typedef struct fila Fila;

Fila* fila_cria(void);
/* A fun��o fila_cria vai criar a fila, alocando o espa�o necess�rio na mem�ria, e retorna o endere�o pra fila.
* N�o possui par�metros. */


void fila_inserir(Fila* f,char* nome,char* roupa);
/* A fun��o fila_inserir tem por objetivo inserir pessoas na fila,
* tendo esta como par�mentro uma string roupa e outra string nome( informa��es pertencentes � pessoa), e o endere�o pra fila. */


void fila_remover(Fila* f,char* nome,char* roupa); //remove uma pessoa da fila
/* A fun��o fila_remover tem a seguinte finalidade: remover elementos da fila, que s�o o nome e a roupa do doador.
 Os par�metros s�o o endere�o pra fila, uma string roupa e outra string nome. */

void imprime(Fila* f);
/* Essa fun��o exibe todos os elementos da fila, mostrando, portanto, os nomes das pessoas presentes na fila.
* Recebe como par�metro o endere�o para essa fila. Caso a fila esteja vazia, mostrar� uma mensagem correspodente.*/


int fila_vazia(Fila* f);
/* A fun��o fila_vazia recebe como par�metro o endere�o pra fila e visa
* verificar se h� ou n�o elementos na fila. Retorna 1 caso esteja vazia, e 0 caso contr�rio.*/


int comparaFila(Fila *f, char* nome);
/* Essa fun��o recebe o endere�o de uma fila e uma string nome que representa um nome de pessoa
* que se deseja inserir na fila. A fun��o percorre a fila para verificar a exist�ncia ou n�o
* do mesmo nome. Retornar� 0 caso n�o encontre, e 1 caso contr�rio.
* para  */

void libera_fila(Fila *f);
/* Recebe como par�metro o endere�o pra uma fila e esta ser� liberada. */


#endif // FILA_H_INCLUDED

#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct listaa Listaa;
typedef struct noo ListaNoo;


Listaa* cria_lista(void);
/* A fun��o cria_lista tem por finalidade criar uma lista
* e em seguida retornar o endere�o dessa lista. N�o possui par�metros. */

void lista_de_doacao(Listaa* lst,char* roupa,Listaa* lst2);
/* A fun��o lista_de_doacao recebe como par�metro o endere�o de duas listas e uma string
* roupa. A fun��o ir� inserir essa string roupa em ambas as listas, no seu in�cio. */


void imprime_listaDeDoacoes(Listaa* lst);
/* A fun��o imprime_listaDeDoacoes recebe como par�metro o endere�o de uma lista, que cont�m
* todas as roupas doadas at� o momento, e imprime todas as roupas existentes na lista e a quantidade total. Caso a lista
* esteja vazia, a fun��o ir� exibir uma informa��o de que ainda n�o foram efetuadas doa��es.
*/

void gera(Listaa* lst);
/* A fun��o gera tem como objetivo inserir todas as roupas ganhas pela institui��o em um arquivo .txt, recebendo
* como param�tro o endere�o da lista que cont�m o hist�rico de doa��es, e assim que essas roupas s�o iseridas no arquivo, essa lista
* ser� esvaziada.
*/

void liberaDoacoes_nos(Listaa *lst);
/* A fun��o liberaDoacoes_nos tem por objetivo apagar as informa��es dos n�s de uma lista, ela recebe como
* par�metro o endere�o dessa lista, possibilitando que a lista seja utilizada novamente.
*/

void libera_DoacoesCompleto(Listaa *lst);
/* A fun��o libera_DoacoesCompleto recebe o endere�o de uma lista na qual se deseja liberar,
*e essa ser� apagada por completo. */


#endif // LISTA_H_INCLUDED

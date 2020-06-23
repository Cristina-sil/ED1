#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct listaa Listaa;
typedef struct noo ListaNoo;


Listaa* cria_lista(void);
/* A função cria_lista tem por finalidade criar uma lista
* e em seguida retornar o endereço dessa lista. Não possui parâmetros. */

void lista_de_doacao(Listaa* lst,char* roupa,Listaa* lst2);
/* A função lista_de_doacao recebe como parâmetro o endereço de duas listas e uma string
* roupa. A função irá inserir essa string roupa em ambas as listas, no seu início. */


void imprime_listaDeDoacoes(Listaa* lst);
/* A função imprime_listaDeDoacoes recebe como parâmetro o endereço de uma lista, que contém
* todas as roupas doadas até o momento, e imprime todas as roupas existentes na lista e a quantidade total. Caso a lista
* esteja vazia, a função irá exibir uma informação de que ainda não foram efetuadas doações.
*/

void gera(Listaa* lst);
/* A função gera tem como objetivo inserir todas as roupas ganhas pela instituição em um arquivo .txt, recebendo
* como paramêtro o endereço da lista que contém o histórico de doações, e assim que essas roupas são iseridas no arquivo, essa lista
* será esvaziada.
*/

void liberaDoacoes_nos(Listaa *lst);
/* A função liberaDoacoes_nos tem por objetivo apagar as informações dos nós de uma lista, ela recebe como
* parâmetro o endereço dessa lista, possibilitando que a lista seja utilizada novamente.
*/

void libera_DoacoesCompleto(Listaa *lst);
/* A função libera_DoacoesCompleto recebe o endereço de uma lista na qual se deseja liberar,
*e essa será apagada por completo. */


#endif // LISTA_H_INCLUDED

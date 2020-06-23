#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilhalivro PilhaLivro;
typedef struct nolivro NoLivro;

PilhaLivro* cria(void);
/* A fun��o cria tem por objetivo criar uma pilha que ir� representar uma pilha de livros,
* e em seguida retorna o endere�o dessa pilha.
*/

void pushlivro(PilhaLivro *p, char* nome_livro);
/* A fun��o pushlivro tem por objetivo inserir livros em uma pilha, tendo esta
* como paramentro o endere�o pra pilha e uma string nome que representa o nome do livro.
*/

char* poplivro(PilhaLivro*p);
/* A fun��o poplivro tem por objetivo desempilhar a pilha de livros. Recebe
* o endere�o da pilha. Essa fun��o retorna o nome do livro desempilhado.
*/

void imprime_pilha (PilhaLivro* p);
/* A fun��o imprime_pilha tem  como param�tro o endere�o da pilha e tem por finalidade imprimir todos
* os livros existentes na pilha. Caso a pilha de livros esteja vazia ser�
* exibida uma mensagem correspondente.
*/

int pilha_vazia(PilhaLivro* p);
/* A fun��o pilha_vazia tem como par�metro o endere�o da pilha e desempenha a fun��o de verificar se h� algum livro
* na pilha de livros, ou se a mesma se encontra vazia. Retorna 1 caso esteja vazia e 0 caso contr�rio.
*/

void libera_pilha(PilhaLivro* p);
/* Recebe o endere�o de uma pilha e esta ser� liberada, apagada. */

#endif // PILHA_H_INCLUDED

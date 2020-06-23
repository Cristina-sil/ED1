#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct pilhalivro PilhaLivro;
typedef struct nolivro NoLivro;

PilhaLivro* cria(void);
/* A função cria tem por objetivo criar uma pilha que irá representar uma pilha de livros,
* e em seguida retorna o endereço dessa pilha.
*/

void pushlivro(PilhaLivro *p, char* nome_livro);
/* A função pushlivro tem por objetivo inserir livros em uma pilha, tendo esta
* como paramentro o endereço pra pilha e uma string nome que representa o nome do livro.
*/

char* poplivro(PilhaLivro*p);
/* A função poplivro tem por objetivo desempilhar a pilha de livros. Recebe
* o endereço da pilha. Essa função retorna o nome do livro desempilhado.
*/

void imprime_pilha (PilhaLivro* p);
/* A função imprime_pilha tem  como paramêtro o endereço da pilha e tem por finalidade imprimir todos
* os livros existentes na pilha. Caso a pilha de livros esteja vazia será
* exibida uma mensagem correspondente.
*/

int pilha_vazia(PilhaLivro* p);
/* A função pilha_vazia tem como parâmetro o endereço da pilha e desempenha a função de verificar se há algum livro
* na pilha de livros, ou se a mesma se encontra vazia. Retorna 1 caso esteja vazia e 0 caso contrário.
*/

void libera_pilha(PilhaLivro* p);
/* Recebe o endereço de uma pilha e esta será liberada, apagada. */

#endif // PILHA_H_INCLUDED

#ifndef RELATORIO_H_INCLUDED
#define RELATORIO_H_INCLUDED

typedef struct no noRelatorio;
typedef struct lista ListaRelatorio;

ListaRelatorio* cria_listaRelatorio(void);
/* A função cria_listaRelatorio não tem nenhum parâmetro e tem por finalidade criar uma lista
* que  irá representar todas as doacoes feitas, e em seguida  retorná o endereço dessa lista
*  para o arquivo cliente. */

void lista_relatorio(ListaRelatorio* lista,char* doador,char* livroGanho);
/* A função lista_relatorio recebe como parâmetro o endereço de uma lista, e
* duas strings, sendo uma representando o nome do doador e outra o nome do livro.
* Tem por objetivo inserir na lista essas informações, no início.
*/

void geraRelatorio(ListaRelatorio* lst);
/* A função geraRelatorio recebe como parâmetro o endereço de uma lista, e a partir
* dos dados contidos nela insere todos eles em um arquivo .txt, e em seguida essas informações da lista são
* deletadas. Caso a lista já tenha sido gerada ou estiver vazia aparecerá uma mensagem informativa.
*/

void imprime_relatorio(ListaRelatorio *lst);
/* A função imprime_relatorio recebe como parâmetro o endereço de uma lista e tem
*  como finalidade imprimir todos os dados contidos nessa lista. Caso não exista
* nenhuma informação, será exibido uma informação de que ainda não há doações realizadas.
*/

int percore_relatorio(ListaRelatorio* listaResultado_historico,char*nome);
/* Ela recebe como paramêtro o endereço de uma lista em que está contida o registro de todos os doadores
* até o momento, e o nome de uma nova pessoa que se deseja cadastrar.
* Caso já exista registro dessa pessoa na lista das pessoas que já doaram
* a função retorna 1, caso contrário retornará 0.
*/

void libera_relatorio_nos(ListaRelatorio* lst);
/* A função libera_relatorio não possui retorno e recebe como parâmetro o endereço de uma lista
 *  e tem como objetivo apagar apenas os nós dessa lista.
*/

void libera_RelatorioCompleto(ListaRelatorio* lst);
/* Recebe como parâmetro o endereço para a lista e sua função é liberar toda a lista,
 * apagá-la por completo.
*/

#endif // RELATORIO_H_INCLUDED

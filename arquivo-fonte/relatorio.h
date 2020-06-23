#ifndef RELATORIO_H_INCLUDED
#define RELATORIO_H_INCLUDED

typedef struct no noRelatorio;
typedef struct lista ListaRelatorio;

ListaRelatorio* cria_listaRelatorio(void);
/* A fun��o cria_listaRelatorio n�o tem nenhum par�metro e tem por finalidade criar uma lista
* que  ir� representar todas as doacoes feitas, e em seguida  retorn� o endere�o dessa lista
*  para o arquivo cliente. */

void lista_relatorio(ListaRelatorio* lista,char* doador,char* livroGanho);
/* A fun��o lista_relatorio recebe como par�metro o endere�o de uma lista, e
* duas strings, sendo uma representando o nome do doador e outra o nome do livro.
* Tem por objetivo inserir na lista essas informa��es, no in�cio.
*/

void geraRelatorio(ListaRelatorio* lst);
/* A fun��o geraRelatorio recebe como par�metro o endere�o de uma lista, e a partir
* dos dados contidos nela insere todos eles em um arquivo .txt, e em seguida essas informa��es da lista s�o
* deletadas. Caso a lista j� tenha sido gerada ou estiver vazia aparecer� uma mensagem informativa.
*/

void imprime_relatorio(ListaRelatorio *lst);
/* A fun��o imprime_relatorio recebe como par�metro o endere�o de uma lista e tem
*  como finalidade imprimir todos os dados contidos nessa lista. Caso n�o exista
* nenhuma informa��o, ser� exibido uma informa��o de que ainda n�o h� doa��es realizadas.
*/

int percore_relatorio(ListaRelatorio* listaResultado_historico,char*nome);
/* Ela recebe como param�tro o endere�o de uma lista em que est� contida o registro de todos os doadores
* at� o momento, e o nome de uma nova pessoa que se deseja cadastrar.
* Caso j� exista registro dessa pessoa na lista das pessoas que j� doaram
* a fun��o retorna 1, caso contr�rio retornar� 0.
*/

void libera_relatorio_nos(ListaRelatorio* lst);
/* A fun��o libera_relatorio n�o possui retorno e recebe como par�metro o endere�o de uma lista
 *  e tem como objetivo apagar apenas os n�s dessa lista.
*/

void libera_RelatorioCompleto(ListaRelatorio* lst);
/* Recebe como par�metro o endere�o para a lista e sua fun��o � liberar toda a lista,
 * apag�-la por completo.
*/

#endif // RELATORIO_H_INCLUDED

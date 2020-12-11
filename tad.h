//Biblioteca que cont�m as defini��es necess�rias para o TAD desenvolvido.
#include "tad.c"

//Fun��o que inicializa o mundo.
City* createWorld(int);

//Fun��o que adiciona uma aresta no grafo.
int add_edge(City*, int, int, float);

//Fun��o que altera a quantidade de her�is em determinada cidade.
void upd_heroes(City*, int);

//Fun��o que modifica a dist�ncia entre duas cidades.
int upd_dist(City*, int, int);

//Fun��o que apaga aresta do grafo.
int del_road(City*, int, int);

//Fun��o que determina a cidade mais vulner�vel, i.e. a com menor I.R.
void vuln(City*, int, int*, float*);

//Fun��o que avalia se existem cidades isoladas no mundo.
int chc_alone(City*, int);

//Fun��o que determina a cidade determinada como sede,
//  definida como aquela com maior I.R.
void find_host(City*, int, int*, float*);

//Fun��o que imprime as informa��es do grafo.
void print_info(City*, int);

//Fun��o auxiliar para liberar as arestas.
void free_edge(Route*);

//Fun��o que libera todas as estruturas do mundo.
void destroyWorld(City*, int);

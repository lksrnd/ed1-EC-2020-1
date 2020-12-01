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

//Fun��o que imprime as informa��es do grafo.
void print_info(City*, int);

//Fun��o auxiliar para liberar as arestas.
void free_edge(struct route*);

//Fun��o que libera todas as estruturas do mundo.
void destroyWorld(City*, int);

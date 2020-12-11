//Biblioteca que contém as definições necessárias para o TAD desenvolvido.
#include "tad.c"

//Função que inicializa o mundo.
City* createWorld(int);

//Função que adiciona uma aresta no grafo.
int add_edge(City*, int, int, float);

//Função que altera a quantidade de heróis em determinada cidade.
void upd_heroes(City*, int);

//Função que modifica a distância entre duas cidades.
int upd_dist(City*, int, int);

//Função que apaga aresta do grafo.
int del_road(City*, int, int);

//Função que determina a cidade mais vulnerável, i.e. a com menor I.R.
void vuln(City*, int, int*, float*);

//Função que avalia se existem cidades isoladas no mundo.
int chc_alone(City*, int);

//Função que determina a cidade determinada como sede,
//  definida como aquela com maior I.R.
void find_host(City*, int, int*, float*);

//Função que imprime as informações do grafo.
void print_info(City*, int);

//Função auxiliar para liberar as arestas.
void free_edge(Route*);

//Função que libera todas as estruturas do mundo.
void destroyWorld(City*, int);

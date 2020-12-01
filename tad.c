#include <stdio.h>
#include <stdlib.h>

//Estrutura que define as arestas entre os n�s do grafo.
typedef struct route{

    int to_index;               // Pr�xima cidade
    float length;               // Dist�ncia entre as cidades
    struct route* next_city;    // Ponteiro para a pr�xima aresta

}Route;

//Estrutura que define os v�rtices do grafo
typedef struct city{

	int index;                  // �ndice da cidade
	int heroes;                 // N�mero de her�is nessa cidade
	struct route* next;         // Ponteiro para as arestas que saem dessa cidade

}City;

// Fun��o que inicializa o mundo.

//  Par�metros:
//      int n - N�mero de cidades no mundo.

//  Retorno:
//      Estrutura inicial com n v�rtices do tipo City alocados.
City* createWorld(int n){

    int i;

    City* world = (City*)malloc(n*sizeof(City));

    printf("Defina o numero de herois para cada cidade!\n");

    for(i=0; i<n; i++){
        world[i].index = i;

        do{
            printf("Numero de herois para a cidade %d: ", world[i].index);
            scanf("%d", &world[i].heroes);
        }while(world[i].heroes <= 0);

        world[i].next = NULL;
    }

    return world;

}

// Fun��o que insere uma aresta no grafo, i.e. uma estrada entre as cidades.

//  Par�metros:
//      City* world - Mundo no qual essa aresta ser� inserida;
//      int start - Cidade de origem da estrada;
//      int finish - Cidade de destino da cidade;
//      float dist - Dist�ncia entre as cidades.

//  Retorno:
//      Valor de controle para identificar se a aresta foi inserida.
//      Se 0 - Cidade inserida com sucesso;
//      Se -1 - Falha na aloca��o;
//      Se 1 - Aresta j� existente.
int add_edge(City* world, int start, int finish, float dist){

    Route* aux;

    Route* new_road = (Route*)malloc(sizeof(Route));

    if(new_road == NULL){
        return -1;
    }

    new_road->to_index = finish;
    new_road->length = dist;
    new_road->next_city = NULL;

    if (world[start].next == NULL){
        world[start].next = new_road;
        return 0;
    }

    else{
        aux = world[start].next;

        while(aux->next_city != NULL){
            if(aux->to_index == finish)
                return 1;

            else{
                aux = aux->next_city;
            }
        }

        aux->next_city = new_road;
    }

    return 0;
}

// Fun��o que altera a quantidade de her�is por cidade.

//  Par�metros:
//      City* world - Mundo;
//      int n - �ndice da cidade cujo valor de her�is ser� modificado.

//  Retorno:
//      void.
void upd_heroes(City* world, int start){

    int aux;

    printf("Atualmente a cidade %d possui %d herois.\n\n", start, world[start].heroes);

    do{
        printf("Digite o novo numero de herois para essa cidade: ");
        scanf("%d", &aux);
    }while(aux<0);

    world[start].heroes = aux;

    return;

}

// Fun��o que altera a dist�ncia entre as cidades.

//  Par�metros:
//      City* world - Mundo;
//      int start - Cidade de origem da estrada;
//      int finish - Cidade de destino da cidade;

//  Retorno:
//      Valor de controle para identificar se a dist�ncia foi alterada.
//      Se 0 - Valor alterado com sucesso;
//      Se -1 - Aresta n�o existe.
int upd_dist(City* world, int start, int finish){

    float new_dist;

    Route* aux;

    if(world[start].next == NULL){
        return -1;
    }

    else{
        aux = world[start].next;
        while(aux->to_index != finish && aux != NULL){
            aux = aux->next_city;
        }

        if(aux == NULL){
            return -1;
        }

        else{
            printf("Atualmente a distancia entre as cidades %d e %d eh %.2f.\n\n",
                   start, finish, aux->length);

            do{
                printf("Digite a nova distancia entre as cidades: ");
                scanf("%f", &new_dist);

            }while(new_dist<=0);

            aux->length = new_dist;

            return 0;
        }
    }

}

// Fun��o que deleta uma aresta.

//  Par�metros:
//      City* world - Mundo;
//      int start - Cidade de origem da estrada;
//      int finish - Cidade de destino da cidade;

//  Retorno:
//      Valor de controle para identificar se a aresta foi inserida.
//      Se 0 - Aresta exclu�da com sucesso;
//      Se -1 - Aresta n�o existe.
int del_road(City* world, int start, int finish){

    Route *first, *sec;

    if(world[start].next == NULL){
        return -1;
    }

    else{
        first = world[start].next;
        sec = first->next_city;

        if(first->to_index == finish){
            world[start].next = sec;
            free(first);
            return 0;
        }

        while(sec != NULL && sec->to_index != finish){
            first = sec;
            sec = sec->next_city;
        }

        if(sec == NULL){
            return -1;
        }

        else{
            first->next_city = sec->next_city;
            free(sec);

            return 0;
        }

    }
}

// Fun��o que imprime todas as informa��es de determinada cidade.
// Imprime o n�mero de her�is por cidade e as estradas partindo
// de cada cidade para cada uma de destino, e suas dist�ncias.

//  Par�metros:
//      City* world - Mundo;
//      int n - N�mero total de cidades.

//  Retorno:
//      void.
void print_info(City* world, int n){

    int i;
    Route* aux;

    printf("Informacoes sobre o mundo!");

    for(i=0; i<n; i++){
        printf("\nA cidade %d possui %d super herois;\n", i, world[i].heroes);

        if(world[i].next == NULL){
            printf("\tEsta cidade nao possui rotas para nenhuma outra!\n");
        }

        else{
            aux = world[i].next;

            while(aux != NULL){
                printf("\tEsta cidade esta conectada com a cidade %d, distantes %.2f unidades.\n",
                       aux->to_index, aux->length);
               aux = aux->next_city;
            }
        }
    }

    return;

}

// Fun��o recursiva para liberar as arestas do grafo.

//  Par�metros:
//      struct route* next - Aresta a ser desalocada.

//  Retorno:
//      void.
void free_edge(struct route* next){

    while(next->next_city != NULL){
        free_edge(next->next_city);
    }

    free(next);

    return;

}

// Fun��o que libera a mem�ria alocada para o mundo.

//  Par�metros:
//      City* world - Mundo a ser desalocado;
//      int n - N�mero de v�rtices no grafo.

//  Retorno:
//      void.
void destroyWorld(City* world, int n){

    int i;

    for(i=0; i<n; i++){
        if(world[i].next != NULL){
            free_edge(world[i].next);
        }
    }

    free(world);

    return;

}

//Arquivo que contém as funções utilizadas no
//trabalho da disciplina "Estruturas de Dados".

//Aluno: Augusto Stival de Paula Bizinoto Ferreira


#include <stdio.h>
#include <stdlib.h>

typedef struct route{

    int to_index;
    float length;
    struct route* next_city;

}Route;

typedef struct city{

	int index;
	int heroes;
	struct route* next;

}City;

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

void add_edge(City* world, int start, int finish, float dist){

    Route* aux;

    Route* new_road = (Route*)malloc(sizeof(Route));

    new_road->to_index = finish;
    new_road->length = dist;
    new_road->next_city = NULL;

    if (world[start].next == NULL){
        world[start].next = new_road;
    }

    else{
        aux = world[start].next;

        while(aux->next_city != NULL){
            aux = aux->next_city;
        }

        aux->next_city = new_road;
    }

    return;

}

void destroyWorld(City* world){

    free(world);

}

//Projeto desenvolvido para a disciplina "Estruturas de Dados".

//Aluno: Augusto Stival de Paula Bizinoto Ferreira

#include "tad.h"

int main(int argc, char* argv[]){

    int opt, n = -1;
    int i, start, finish;

    float dist;

    City* world = NULL;

    do{
        printf("\nBem-vindo ao programa de apoio ao Conselho de Vraskovia!\n\n");

        printf("Escolha a opcao do menu:\n");
        printf("1-) Criar novo mundo;\n");
        printf("2-) Criar estrada;\n");
        printf("3-) Alterar informacoes;\n");
        printf("4-) Apagar estrada;\n");
        printf("5-) Identificar sede;\n");
        printf("6-) Identificar cidade vulneravel;\n");
        printf("7-) Melhores rotas;\n");
        printf("8-) Identificar cidades isoladas;\n");
        printf("9-) Destruir estruturas e sair.\n");

        printf("\n Opcao desejada: ");
        scanf("%d", &opt);

        switch(opt){
        case 1:
            if(n == -1){
                do{
                    printf("Defina o numero de cidades: ");
                    scanf("%d", &n);
                }while(n<=0);

                world = createWorld(n);
            }

            else{
                printf("Mundo ja existe!\n");
            }

            opt = -1;

            break;

        case 2:
            if(world != NULL){
                do{
                    printf("Escolha a cidade de origem: ");
                    scanf("%d", &start);

                    printf("Escolha a cidade de destino: ");
                    scanf("%d", &finish);
                }while(start == finish);

                printf("Determine a distancia entre as cidades: ");
                scanf("%f", &dist);

                add_edge(world, start, finish, dist);

                printf("Adicionada rodovia da cidade %d ate a cidade %d, com distancia %.2f!\n",
                            start, finish, dist);
            }

            else
                printf("Mundo vazio!\n");

            break;

        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
            printf("A ser implementado!!\n");

            break;

        case 9:
            if(world != NULL)
                destroyWorld(world);

            else
                printf("Mundo nao existe!\n");

            break;
        }

    }while(opt < 1 || opt > 9);


	return 0;

}

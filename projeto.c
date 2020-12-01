
#include "tad.h"

int main(int argc, char* argv[]){

    int opt, n = -1, check;
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
        printf("9-) Imprimir informacoes sobre o mundo.\n\n");

        printf("0-) Destruir as estruturas e sair.\n");

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

                check = add_edge(world, start, finish, dist);

                if(!check){
                    printf("Adicionada rodovia da cidade %d ate a cidade %d, com distancia %.2f!\n",
                            start, finish, dist);
                }

                else if(check == 1){
                    printf("Cidade já presente no grafo!\n");
                }

                else{
                    printf("Não foi possivel alocar memória!\n");
                }

            }

            else
                printf("Mundo vazio!\n");

            opt = -1;

            break;

        case 3:

            printf("Digite o indice da cidade a ser alterada: ");
            scanf("%d", &start);

            printf("Digite o mesmo indice para alterar o numero de herois\n");
            printf("\tou um indice diferente para alterar informacao de distancia\n");
            scanf("%d", &finish);

            if(start == finish){
                upd_heroes(world, start);

                printf("A cidade %d agora contem %d herois!\n", start, world[start].heroes);
            }

            else{
                check = upd_dist(world, start, finish);

                if(!check){
                    printf("Distancia alterada com sucesso!\n");
                }

                else{
                    printf("Nao existe aresta entre as cidades %d e %d!\n", start, finish);
                }
            }

            opt = -1;

            break;

        case 4:

            printf("Digite a cidade de origem da estrada a ser apagada: ");
            scanf("%d", &start);

            printf("Digite a cidade de destino da estrada a ser apagada: ");
            scanf("%d", &finish);

            check = del_road(world, start, finish);

            if(!check){
                printf("Estrada removida com sucesso!\n");
            }

            else{
                printf("Nao existe estrada entre as cidades %d e %d!\n", start, finish);
            }

            opt = -1;

            break;

        case 5:
        case 6:
        case 7:
        case 8:
            printf("A ser implementado!!\n");

            break;

        case 9:
            if(world != NULL)
                print_info(world, n);

            else
                printf("Mundo nao existe!\n");

            opt = -1;

            break;


        case 0:
            if(world != NULL)
                destroyWorld(world, n);

            else
                printf("Mundo nao existe!\n");

            break;
        }

    }while(opt < 0 || opt > 9);


	return 0;

}

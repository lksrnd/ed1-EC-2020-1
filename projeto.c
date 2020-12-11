#include "tad.h"

int main(int argc, char* argv[]){

    int opt, n = -1, check;
    int i, start, finish;

    float dist, v_i;

    City* world = NULL;

    do{
        printf("\nBem-vindo ao Projeto Athenas!\n\n");

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
                    printf("Rodovia ja presente no grafo!\n");
                }

                else{
                    printf("N�o foi possivel alocar mem�ria!\n");
                }

            }

            else
                printf("Mundo vazio!\n");

            opt = -1;

            break;

        case 3:
            if(world != NULL){
                printf("Digite o indice da cidade a ser alterada: ");
                scanf("%d", &start);

                printf("Digite o mesmo indice para alterar o numero de herois\n");
                printf("\tou um indice diferente para alterar informacao de distancia\n");

                printf("\n Opcao desejada: ");
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
            }

            else
                printf("Mundo vazio!\n");

            opt = -1;

            break;

        case 4:

            if(world != NULL){
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
            }

            else
                printf("Mundo vazio!\n");


            opt = -1;

            break;

        case 5:
            if(world != NULL){
                find_host(world, n, &check, &v_i);

                if(check == -1){
                    printf("Existe(m) cidade(s) isolada(s). Consulte a opcao 9!\n");
                }

                else{
                    printf("A sede deve ser implementada na cidade %d!\n", check);
                }
            }

            else{
                printf("Mundo vazio!\n");
            }

            opt = -1;

            break;


        case 6:
            if(world != NULL){
                vuln(world, n, &check, &v_i);

                printf("A cidade mais vulneravel e a cidade %d, com indice de %.2f!\n",
                       check, v_i);
            }

            else{
                printf("Mundo vazio!\n");
            }

            opt = -1;

            break;

        case 8:
            if(world != NULL){
                check = chc_alone(world, n);

                check ?
                printf("Existe(m) cidade(s) isolada(s), favor consultar a opcao 9!\n") :
                printf("Nao existe cidade isolada!\n");
            }

            else{
                printf("Mundo vazio!\n");
            }

            opt = -1;

            break;

        case 7:

            printf("Algoritmo de Prim (ou Kruskal).\n");

            break;

        case 9:
            if(world != NULL)
                print_info(world, n);

            else
                printf("Mundo nao existe!\n");

            opt = -1;

            break;


        case 0:
            if(world != NULL){
                destroyWorld(world, n);
                printf("O mundo foi nukado!\n");
            }
            else
                printf("Mundo nao existe!\n");

            break;
        }

    }while(opt < 0 || opt > 9);


	return 0;

}

#include <stdio.h>
#include <stdlib.h>
#include "noh.h"
#include "nopatricio.h"


void menu(NO *arv){
    int escolha, n, validez;
    char chave[20];
    NO *novo;

    printf("menu adentrado");
    while(1){
        printf("\n-------------Menu-------------\n 1 - Inserção \n 2 - Deletar \n 3 - Busca \n 4- Sair \n -----------------------------");
        printf("\nDigite uma das opcoes acima:");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case (1) :
            printf("Digite o número da chave do cliente que você deseja inserir: \n");
            scanf("%s", chave);
            n = strlen(chave);
            printf("tamanho da chave %d \n", n);
            arv = inserirpat(arv, chave, n);
            //printf("fechando arquivos e ponteiros");
            break;
        case (2):
            printf("Digite a chave do cliente que você quer deletar:\n");
            scanf("%s", chave);
            n = strlen(chave);
            //deletarpav(arv, chave, n);
            free(novo);
            break;
        case (3):
            printf("Digite a chave do cliente que você quer buscar:\n");
            scanf("%s", chave);
            n = strlen(chave);
            novo = buscapat(arv, chave, n);
            validez= comparaChave(novo->chave, chave, n);
            if(validez == -1){
                printf("Noh não encontrado, busca se encerrou num nó folha incorreto ou num nó interno");
            }
            else{
                printf("> Chave do nó: %s \n", novo->chave);
            }
            break;

        case(4):
            printf("Nó raiz %s \n", arv->chave);
            printf("Primeiro filho a esquerda %s \n", arv->esq->chave);
            printf("Primeiro filho a direita %s \n", arv->dir->chave);
            break;
        case (5):
            free(novo);
            exit(1);
            break;
        default:
            printf("Escolha um dos números do menu\n");
            break;
        }
    }

}


int main(){
    NO *arv;
    arv = criarNOh("null", 0, -1);
    menu(arv);
    return 0;
}

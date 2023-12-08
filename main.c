#include <stdio.h>
#include <stdlib.h>
#include "Noh.h"
#include "nopatricio.h"
void menu(FILE *meta, FILE *clientes, int modo){
    int escolha, n, 
    char chave[20];
    Cliente *novo;

    while(1){
        printf("\n-------------Menu-------------\n 1 - Inserção \n 2 - Deletar \n 3 - Busca \n 4- Sair \n -----------------------------");
        printf("\nDigite uma das opcoes acima:");
        scanf("%d", &escolha);
        switch (escolha)
        {
        case (1) :
            printf("Digite o número da chave do cliente que você deseja inserir: \n");
            scanf("%s", &chave);
            n = strlen(chave);
            inserirpat(arv, chave, n);
          
            //printf("fechando arquivos e ponteiros");
            break;
        case (2):
            printf("Digite a chave do cliente que você quer deletar:\n");
            scanf("%s", &chave);
            n = strlen(chave);
            deletarpav(arv, chave, n);
            free(novo);
            break;
        case (3):
            printf("Digite a chave do cliente que você quer buscar:\n");
            scanf("%s", &chave);
            novo = buscarnog(arv, chave, n);

            if(novo->chave != chave){
                printf("Noh não encontrado, busca se encerrou num nó folha incorreto ou num nó interno");
            }
            else{
                printf("> Chave do nó: %s \n", novo->chave);
            }
            break;
        case (5):
            free(cliente)
            exit(1);
            break;
        default:
            printf("Escolha um dos números do menu\n");
            break;
        }
    }
    
}
int main(){
  No *arv = (No *)malloc(sizeof(No));
    arv = criarNoH(NULL, 1, NULL, NULL, NULL, 0);
  menu(arv);
  return 0;
}

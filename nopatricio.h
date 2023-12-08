#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Noh.h"


No *criarNoh(char * chave, char *reg, No*pai, No*esquerdo, No*direito, int val){
    No *novo = (No *)malloc(sizeof(No));
    if (novo) {
        strcpy(novo->chave, chave)
        novo->reg = reg;
        novo->pai = pai;
        novo->esq = esquerdo;
        novo->dir = direito;
        novo->folha = val;
        printf("\n> Novo cliente criado\n");
    }
    return novo;
}

int maiorprefixo(char* nomeA, char* nomeB){
    int i =0;
    while(nomeA[i] == nomeB[i]){
        i++;
    }
    return 0;
}

No *buscapat(No* arv, char* x, int n){
    No *novo = arv;
    int chave, i, a = 0;
    

    while(a == 0){
      if(novo->folha == 1){
        chave = atoi(novo.chave);
        if(chave == x){
          a = 1;
        }
        else{
        a = 2;
      }
    }
      i = novo->reg;
      if (i<=n){
        if(novo->chave[i] == 0){
          novo = novo->esq;
      }
        else if(novo->chave[i] == 1){
          novo = novo->dir;   
    }
  }
      else{
        a = 2;
    }
}
  if(a==1){
    printf("Nó com chave", %s, "encontrado\n");
  }
  else{
    printf("chave não encontrada, retorno do ultimo nó do caminho feito pela busca");
  }
  return novo;
} 

void inserirpat(No* arv, char* x, int n){
  int T, l, c, reg_w;
  No* z;
  No* w;
  No* v;
  No* ptf;
  No* pr;
  pr = buscapat(arv, x, n);
  if(pr.chave == x){
    printf("Inserção invalida, chave já existente");
    return -1;
  }
  if(pr->folha == 0){
     ptf= pr;
    while(T != 1){
      ptf = ptf->esq;
      if(ptf->folha == 1){
        T = 1;
      }
    }
  }else if(pr->folha == 1){
    ptf = pr;
  }
    if(pr->folha >= 0){
    c = strlen(prf.chave);
    l = maiorprefixo(prf.chave, x);
    if(l == strlen(x) || l == c){
      printf("Inserção inválida. Uma chave é prefixa de outra");
      return -1;
    }
    z = ptf.pai;
    if(z.reg> l+1){
      while(z.pai.reg > l+1){
        z = z.pai;
      }
    }else{
      z = ptf;
    }
    }else if(pr->folha == - 1){
        z = arv
        z->reg = 2;
    }
    reg_w = atoi(x);
    w = criarNoh(x, reg_w, NULL,NULL,NULL, 1);
    if(x[l+1] == 0){
      v = criarNOH(NULL, l+1, z.pai, w, z, 0);
    }else{
      v = criarNOH(NULL, l+1, z.pai, z, w, 0);
    }
    z.pai = v;
    w.pai = v;
  }


void deletar(FILE *hash, FILE *meta, FILE *clientes, int chave){
    int validade = 0, proximo;
    int posicao = chave % TAMANHO_HASH;
    Cliente *atual = (Cliente *)malloc(sizeof(Cliente));
    rewind(hash);

    fseek(hash, sizeof(int) * (posicao), SEEK_SET);

    fread(&posicao, sizeof(int), 1, hash);
    //printf("%d", posicao);
    printf("\n> Procurando cliente...\n");
    if (posicao != -1) {
        while (validade == 0) {
            rewind(clientes);
            fseek(clientes, sizeof(Cliente) * posicao, SEEK_SET);
            fread(&atual->chave, sizeof(int), 1, clientes);
            fread(atual->nome, sizeof(char), sizeof(atual->nome), clientes);
            fread(&atual->estado, sizeof(int), 1, clientes);
            fread(&atual->prox, sizeof(int), 1, clientes);
            //printf("\nteste");
            if (atual->chave == chave) {
                validade = 1;
                atual->chave = -1;
                strcpy(atual->nome, "----");
                atual->estado = 0;
                proximo = atual->prox;
                rewind(clientes);
                fseek(clientes, sizeof(Cliente) * posicao, SEEK_SET);

                fwrite(&atual->chave, sizeof(int), 1, clientes);
                fwrite(atual->nome, sizeof(char), sizeof(atual->nome), clientes);
                fwrite(&atual->estado, sizeof(int), 1, clientes);

                printf("\nCliente deletado com sucesso!\n");
                return;
            } else if (atual->prox == -1) {
                validade = -1;
                printf("Cliente não encontrado, por favor insira ele na Hash primeiro.\n");
                break;
            } else {
                posicao = atual->prox;
            }
        }
    } else {
        printf("Cliente não existe, por favor insira ele na Hash primeiro\n");
    }
    free(atual);
}

void lerarqs(FILE *tabhash, FILE *meta){
    int contador;
    int b;
    rewind(tabhash);
    printf("\n");
    for (int i = 0; i < TAMANHO_HASH; i++) {
        fread(&b, sizeof(int), 1, tabhash);
        printf("hash %d: %d \n", i, b);
    }
    rewind(meta);
    fread(&contador, sizeof(int), 1, meta);
    printf("Contador: %d", contador);
}

void zerar(FILE *tabhash, FILE *meta, FILE *clientes){
    FILE *nhash;
    FILE *nmeta;
    FILE *nclientes;
    int contador = 0;
    int novo;
    int a = -1;
    int b;

    fclose(tabhash);
    fclose(meta);

    if ((nhash = fopen(TABELA_HASH, "wb")) == NULL) {
        printf("Erro ao abrir o arquivo da tabela hash\n");
        exit(1);
    }

    if ((nmeta = fopen(METADADOS, "wb")) == NULL) {
        printf("Erro ao abrir o arquivo da tabela meta\n");
        exit(1);
    }


    for (int i = 0; i < TAMANHO_HASH; i++) {
        fwrite(&a, sizeof(int), 1, nhash);
    }
    fclose(nhash);

    if ((nhash = fopen(TABELA_HASH, "a+ b")) == NULL) {
        printf("Erro ao abrir o arquivo da tabela clientes\n");
        exit(1);
    }

    rewind(nhash);

    /*for (int i = 0; i < TAMANHO_HASH; i++) {
        fread(&b, sizeof(int), 1, nhash);
        printf("hash: %d \n", b);
    }*/

    printf("\n> Arquivo hash zerado\n");

    rewind(nmeta);
    fwrite(&contador, sizeof(int), 1, nmeta);

    fclose(nmeta);

    if ((nmeta = fopen(METADADOS, "a+b")) == NULL) {
        printf("Erro ao abrir o arquivo da tabela meta\n");
        exit(1);
    }

    rewind(nmeta);

    fread(&novo, sizeof(int), 1 ,nmeta);
    printf("> Contador: %d\n", novo);
    printf("> Tabela Clientes zerada\n");
    printf("Arquivos zerados com sucesso!");
    fclose(clientes);

    if ((nclientes = fopen(REGISTRO_CLIENTE, "w+b")) == NULL) {
        printf("Erro ao abrir o arquivo da tabela clientes\n");
        exit(1);
    }
    fclose(nclientes);
    fclose(nhash);
    fclose(nmeta);

}

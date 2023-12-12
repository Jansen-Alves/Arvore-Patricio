#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "noh.h"


NO *criarNOh(char * chave, int reg, int val){
    NO *novo = (NO *)malloc(sizeof(NO));
    printf("Memoria alocada\n");
    strcpy(novo->chave, chave);
    novo->reg = reg;
    novo->pai = NULL;
    novo->esq = NULL;
    novo->dir = NULL;

    novo->folha = val;
    printf("\n> Novo cliente criado\n");


  return novo;
}

void ajeitarArv(NO* folha){
    int k, val, lvl, lado;
    NO* z;
    NO* v1;
    NO* sweep;

    val = 0;
    k = 1;
    lvl = 1;
    z = folha->pai;
    printf("ajeitando arvore \n");
    printf("Folha do pai %d \n", z->folha);
    if(z->folha != -1){
        if(z->esq == NULL || z->dir == NULL){
            folha->pai = z->pai;
            free(z);
        }
        else{
            while(val == 0){
                z = z->pai; // começa pelo avo da folha
                printf("Folha do antepassado %d\n", z->folha );
                if(z->esq == NULL || z->dir == NULL){ //verifica se tem ziguezague
                    printf("Um dos filhos esta vazio \n");

                    if(z->pai->esq == NULL || z->pai->dir == NULL){
                        k++;
                    }
                    else{
                        v1 = z;
                        while(v1->folha != -1){
                            lvl++;
                            v1= v1->pai;
                        }
                        z = folha->pai;
                        z->reg = k+lvl;
                        val = 1;
                    }
                }else{
                    val = 2;
                }
            }
            //Processo de liberar da memória os nós descartados do ziguezague
            if(val == 1){
                sweep = folha->pai;
                v1 = sweep->pai;
                while(k>0){
                    sweep= v1;
                    v1 = sweep->pai;
                    if(k == 1){

                        /*if(v1->dir == sweep){
                            lado = 1;
                        }
                        else if(v1->esq == sweep){
                            lado = -1;
                        }*/
                    }
                    free(sweep);
                    k--;
                    }

               z->pai = v1;
               lado = v1->reg;
                if(z->chave[lado]>0){
                    v1->dir = z;
                }else{
                    v1->esq = z;
                }
        }
    }
    }

}

int maiorprefixo(char* nomeA, char* nomeB){
    int k =-1;
    int i = 0;
    while(nomeA[i] == nomeB[i]){
        k++;
        i++;
    }
    return k;
}

int comparaChave(char* nomeA, char* nomeB, int n){
    int i, k, m;
    i = 0;
    k = 1;
    m = strlen(nomeA);

    if(n != m){
        return -1;
    }
    while(k==1 && i < n){
        if(nomeA[i] == nomeB[i]){
            i++;
        }
        else{
            k = -1;
        }
    }
    return k;
}

NO *buscapat(NO* arv, char* x, int n){
    NO *novo = arv;
    int i, a = 0, k;
    char chave[20];

    printf("busca iniciada\n");
    while(a == 0){
        printf("chave pai %s tipo %d \n", novo->chave, novo->folha);
        printf("chave esquerda %s \n", novo->esq->chave);
        printf("chave direita %s \n", novo->dir->chave);
      if(novo->folha == 1){
        strcpy(chave, novo->chave);
        printf("chave: %s\n", chave);
        k = comparaChave(chave, x, n);
        if(k == 1){
          a = 1;
        }
        else{
        a = 2;
      }
    }
      i = novo->reg;
      printf("reg %d e tamanho igual a  %d\n", i, n);
      //i = i-1;
      if (arv->esq == NULL && arv->dir == NULL){
        a = 2;
      } else if (i<=n){
        //printf("entrou no if com i igual a %d \n", i);
        //printf("chave na posicao i eh igual a %c \n", x[i]);
        //c = (char)x[i];
        //k = atoi(c);
        //printf("k = %d", k);
        if(x[i] == '0' && novo->esq != NULL){
          novo = novo->esq;
          printf("Foi para esquerda\n");
      } else if(x[i]  == '1' && novo->dir != NULL){
          novo = novo->dir;
          printf("Foi para direita\n");
      } else{
        a = 2;
      }
    }
}
  if(a==1){
    printf("Nó com chave %s encontrado\n", novo->chave);
  }
  else{
    printf("chave não encontrada, retorno do ultimo nó do caminho feito pela busca\n");
  }
  return novo;
}



NO* inserirpat(NO* arv, char* x, int n){
  int T, l, c, reg_w, validez, tam_x;
  NO* z;
  NO* zl;
  NO* w;
  NO* v;
  NO* yf;
  NO* pr;
  pr = buscapat(arv, x, n);

  l = 0;
  c = 0;

  validez = comparaChave(pr->chave, x, n);
  if(validez == 1){
    printf("Inserção invalida, chave já existente\n");
    return arv;
  }
  else{
    printf("chave não existente na arvore\n");
  }


  if(pr->folha == 0){
    printf("busca acabou em nó interno\n");
    yf = pr;
    while(T > 0){
      yf = yf->esq;
      if(yf->folha == 1){
        T = 1;
      }
    }
  }
  else if(pr->folha == 1){
      printf("busca acabou em folha\n");
      yf = pr;
  }else if(pr->folha == -1){
      printf("só há raiz nessa arvore\n");
      yf = pr;
  }

    if(yf->folha == 1){
        c = strlen(yf->chave);
        c--;
        l = maiorprefixo(yf->chave, x);
        printf("Maior prefixo eh l %d \n", l);
        tam_x = strlen(x);
        tam_x--;
        if(l == tam_x || l == c){
            printf("Inserção inválida. Uma chave é prefixa de outra");
            return arv;
        }
        z = yf->pai;
        if(z->reg > l){
            printf("reg de z(%d) é maior que l(%d) \n", z->reg, l);
            while(z->pai->reg > l){
            z = z->pai;
            }
        }else{
            printf("reg de z(%d) nao é maior que l(%d) \n", z->reg, l);
            printf("folha de z %d \n", z->folha);
            z = yf;
        }

    }else if(yf->folha == - 1){
        printf("só há raiz da arvore \n");
        z = yf;
        }

    reg_w = atoi(x);
    w = criarNOh(x, reg_w, 1);
    printf("criando noh w\n");
    if(z->folha >= 0){
        zl = z->pai;
        printf("pai de z :%d \n", zl->folha);
        v = criarNOh("interno", l+1, 0);
        v->pai = zl;
        printf(" folha zl %d", zl->folha);
        printf("folha do pai e %d, e a chave e %s \n", v->pai->folha, v->pai->chave);

        if(x[l+1] == 0){
          printf("no: %s \n", v->chave);
          v->esq = w;
          v->dir = z;
          printf("filho esquerdo %s\n", w->chave);
          printf("filho direito %s\n", z->chave);
        }else{
          printf("no v: %s\n", v->chave);
          printf("pai eh:  %d\n", v->pai->folha);
          v->esq = z;
          v->dir = w;
          printf("filho esquerdo %s\n", z->chave);
          printf("filho direito %s\n", w->chave);
        }
        z->pai = v;
        w->pai = v;
    }else{
        printf("criando filhos da raiz\n");
        if(x[l] == '0'){
          v = criarNOh("nll", 0, -1);
          v->esq = w;
          if(z->dir!= NULL){
            v->dir = z->dir;
          }
        }else{
          v = criarNOh("nill", 0, -1);
          v->dir = w;

          if(z->esq!= NULL){
            v->esq = z->esq;
          }
    }
        w->pai = v;
        printf("Noh v criado %s\n", v->chave);
        arv = v;
        free(z);
        return v;
    }
    printf("terminei a alocação\n");
    ajeitarArv(w);
    printf("chave criada");
    return arv;
}


void deletarpat(NO* arv, char* x, int n){
    int lado;
    NO* pr;
    NO* pai;
    pr = buscapat(arv, x, n);
    if(pr->chave == x){
        pai = pr->pai;
        if(pai->dir == pr){
            lado = 1;
        }else if(pai->esq == pr){
            lado = -1;
        }
        free(pr);

        if(lado == 1){
            pr = pai->dir;
        }else{
            pr = pai->esq;
        }
        ajeitarArv(pr);
  }
}

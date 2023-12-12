#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "noh.h"


NO *criarNOh(char * chave, int reg, NO*pai, NO*esquerdo, NO*direito, int val){
    NO *novo = (NO *)malloc(sizeof(NO));
    printf("Memoria alocada");
    strcpy(novo->chave, chave);
        printf("nome alocado");
        novo->reg = reg;
        if(val == -1){
            novo->pai = NULL;
            novo->esq = NULL;
            novo->dir = NULL;
        }
        else{
            novo->pai = pai;
            novo->esq = esquerdo;
            novo->dir = direito;
        }

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

    if(z->folha != -1){
        if(z->esq == NULL || z->dir == NULL){
            folha->pai = z->pai;
            free(z);
        }
        else{
            while(val == 0){
                z = z->pai; // começa pelo avo da folha
                if(z->esq == NULL || z->dir == NULL){ //verifica se tem ziguezague

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
                    val = 1;
                }
            }
            //Processo de liberar da memória os nós descartados do ziguezague
            sweep = folha->pai;
            v1 = sweep->pai;
            while(k>0){
                sweep= v1;
                v1 = sweep->pai;
                if(k == 1){
                    if(v1->dir == sweep){
                        lado = 1;
                    }
                    else if(v1->esq == sweep){
                        lado = -1;
                    }
                }
                free(sweep);
                k--;
                }

           z->pai = v1;
            if(lado >0){
                v1->dir = z;
            }else{
                v1->esq = z;
            }
        }
    }

}

int maiorprefixo(char* NOmeA, char* NOmeB){
    int i =0;
    while(NOmeA[i] == NOmeB[i]){
        i++;
    }
    return i;
}

NO *buscapat(NO* arv, char* x, int n){
    NO *NOvo = arv;
    int chave, i, a = 0;


    while(a == 0){
      if(NOvo->folha == 1){
        chave = atoi(NOvo->chave);
        if(chave == x){
          a = 1;
        }
        else{
        a = 2;
      }
    }
      i = NOvo->reg;
      if (i<=n){
        if(NOvo->chave[i] == 0){
          NOvo = NOvo->esq;
      }
        else if(NOvo->chave[i] == 1){
          NOvo = NOvo->dir;
    }else{
        a = 2;
          }
  }
      else{
        a = 2;
    }
}
  if(a==1){
    printf("Nó com chave %s encontrado\n", NOvo->chave);
  }
  else{
    printf("chave não encontrada, retorno do ultimo nó do caminho feito pela busca\n");
  }
  return NOvo;
}

int inserirpat(NO* arv, char* x, int n){
  int T, l, c, reg_w;
  NO* z;
  NO* w;
  NO* v;
  NO* yf;
  NO* pr;
  pr = buscapat(arv, x, n);
  if(pr->chave == x){
    printf("Inserção invalida, chave já existente\n");
    return -1;
  }
  else{
    printf("chave não existente na arvore\n");
  }
  printf("A chave tem folha igual ah %d \n", pr->folha);
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
      printf("busca acabou em folha");
      yf = pr;
  }
  else if(pr->folha == -1){
      printf("só há raiz nessa arvore");
      yf = pr;
  }

    if(yf->folha == 1){
        c = strlen(yf->chave);
        l = maiorprefixo(yf->chave, x);
    if(l == strlen(x) || l == c){
        printf("Inserção inválida. Uma chave é prefixa de outra");
        return -1;
    }
    z = yf->pai;
    if(z->reg> l+1){
        while(z->pai->reg > l+1){
            z = z->pai;
          }
    }else{
        z = yf;
    }
    }else if(pr->folha == - 1){
        printf("só há raiz da arvore");
        z = yf;
    }
    reg_w = atoi(x);
    w = criarNOh(x, reg_w, NULL,NULL,NULL, 1);
    if(z->folha > 0){
        if(x[l+1] == 0){
          v = criarNOh(NULL, l+1, z->pai, w, z, 0);
        }else{
          v = criarNOh(NULL, l+1, z->pai, z, w, 0);
        }
        z->pai = v;
        w->pai = v;
    }else{
        if(x[l+1] == 0){
          v = criarNOh(NULL, l+1, z->pai, w, NULL, -1);
        }else{
          v = criarNOh(NULL, l+1, z->pai, NULL, w, -1);
    }
        arv = v;
        free(z);
    }
    ajeitarArv(w);
    printf("chave criada");
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



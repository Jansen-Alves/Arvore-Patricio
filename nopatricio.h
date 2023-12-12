#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "noh.h"


NO *criarNOh(char * chave, int reg, NO*pai, NO*esquerdo, NO*direito, int val){
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
    printf("Folha do pai %d", z->folha);
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
                    val = 2;
                }
            }
            //Processo de liberar da memória os nós descartados do ziguezague
            sweep = folha->pai;
            v1 = sweep->pai;
            while(k>0 && val == 1){
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

int maiorprefixo(char* nomeA, char* noomeB){
    int i =0;
    while(nomeA[i] == nomeB[i]){
        i++;
    }
    return i;
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
            i++
        }
        else{
            k = -1;
        }
    }
    return k;
}

NO *buscapat(NO* arv, char* x, int n){
    NO *novo = arv;
    int chave, i, a = 0, k;
    
    printf("chave raiz %s \n", novo->chave);
    
    printf("busca iniciada\n");
    while(a == 0){
      if(novo->folha == 1){
        strcpy(chave, novo->chave)
        printf("chave: %s\n", chave);
        k =(novo->chave, chave, n);
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
        printf("entrou no if com i igual a %d \n", i);
        printf("chave na posicao i eh igual a %c", x[i]);
        //c = (char)x[i];
        //k = atoi(c);
        //printf("k = %d", k);
        if(x[i] == '0'){
          novo = novo->esq;
          printf("Foi para esquerda\n");
      } else if(x[i]  == '1'){
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
  int T, l, c, reg_w, validez;
  NO* z;
  NO* w;
  NO* v;
  NO* yf;
  NO* pr;
  pr = buscapat(arv, x, n);

  l = 0;
  c = 0;
  validez = maiorprefixo(pr->chave, x);
  if(valizez == n){
    printf("Inserção invalida, chave já existente\n");
    return arv;
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
            return arv;
        }
        z = yf->pai;
        if(z->reg > l){
            while(z->pai->reg > l){
            z = z->pai;
          }
        }else{
            z = yf;
        }
        }else if(pr->folha == - 1){
            printf("só há raiz da arvore \n");
            z = yf;
        }
    reg_w = atoi(x);
    w = criarNOh(x, reg_w, NULL,NULL,NULL, 1);
    printf("criando noh w");
    if(z->folha >= 0){
        if(x[l+1] == 0){
          v = criarNOh(NULL, l, z->pai, w, z, 0);
          v->pai = z->pai;
          v->esq = w;
          v->dir = z;
        }else{
          v = criarNOh(NULL, l, z->pai, z, w, 0);
          v->pai = z->pai;
          v->esq = z;
          v->dir = w;
        }
        z->pai = v;
        w->pai = v;
    }else{
        printf("criando filhos da raiz\n");
        if(x[l] == 0){
          v = criarNOh("nll", l, NULL, w, NULL, -1);
          v->esq = w;
        }else{
          v = criarNOh("nill", l, NULL, NULL, w, -1);
          v->dir = w;
    }
        w->pai = v;
        printf("Noh v criado %s\n", v->chave);
        arv = v;
        printf("No raiz assimilado %s\n", arv->chave);
        free(z);
        printf("No raiz assimilado 2 %s\n", arv->chave);
        return v;
    }
    printf("terminei a alocação");
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


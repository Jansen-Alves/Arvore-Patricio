#ifndef NOH_H
#define NOH_H

typedef struct NO{
    char * chave;
    int reg;
    struct NO* pai;
    struct NO* esq;
    struct NO* dir;
    int folha;
}NO;

#endif

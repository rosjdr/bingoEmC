#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_CARTELA 10
#define QTDE_BOLAS 90

void imprime_cartela(int c[TAMANHO_CARTELA]);

/*
Implementação de um jogo de bingo em C
*/
int main(){
    int cartela[TAMANHO_CARTELA];
    int bolas[QTDE_BOLAS] = {0};

    srand((unsigned)time(NULL));

    //coloca as bolas no saco
    for(int i=0;i<QTDE_BOLAS;i++){
        bolas[i] = i+1;
    }

    //gera uma cartela de bingo
    for(int i=0;i<TAMANHO_CARTELA;i++){
        cartela[i] = rand()%QTDE_BOLAS + 1;
    }
    //imprime a cartela de bingo
    imprime_cartela(cartela);
}

void imprime_cartela(int c[TAMANHO_CARTELA]){
    for(int i=0;i<TAMANHO_CARTELA;i++){
        printf("%d ", c[i]);
        if (i == 4) printf("\n");
    }
}
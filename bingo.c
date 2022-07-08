#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_CARTELA 10

/*
Implementação de um jogo de bingo em C
*/
int main(){
    int cartela[TAMANHO_CARTELA];
    int bolas[90] = {0};

    srand((unsigned)time(NULL));

    //coloca as bolas no saco
    for(int i=0;i<90;i++){
        bolas[i] = i+1;
    }

    //gera uma cartela de bingo
    for(int i=0;i<TAMANHO_CARTELA;i++){
        cartela[i] = rand()%90 + 1;
    }
    //imprime a cartela de bingo
    for(int i=0;i<TAMANHO_CARTELA;i++){
        printf("%d ", cartela[i]);
        if (i == 4) printf("\n");
    }




}
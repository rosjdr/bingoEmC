#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXIMO_CARTELAS 10
#define TAMANHO_CARTELA 10
#define QTDE_BOLAS 90

void imprime_cartelas(int c[MAXIMO_CARTELAS][TAMANHO_CARTELA], int qtde);
void gera_cartela(int c[MAXIMO_CARTELAS][TAMANHO_CARTELA], int qtde);

/*
Implementação de um jogo de bingo em C
*/
int main(){
    int cartelas[MAXIMO_CARTELAS][TAMANHO_CARTELA] = {0};
    int bolas[QTDE_BOLAS] = {0};
    int tem_vencedor = 0;
    int qtde_cartelas = 5;

    srand((unsigned)time(NULL));

    //coloca as bolas no saco
    for(int i=0;i<QTDE_BOLAS;i++){
        bolas[i] = i+1;
    }

    //gera uma cartela de bingo
    gera_cartela(cartelas,qtde_cartelas);
    //imprime a cartela de bingo
    imprime_cartelas(cartelas, qtde_cartelas);

    //começar sorteio

    
}

void imprime_cartelas(int c[MAXIMO_CARTELAS][TAMANHO_CARTELA], int qtde){
    for(int cont=0;cont<qtde;cont++){
        printf("Cartela %d: ", cont+1);
        for(int i=0;i<TAMANHO_CARTELA;i++){
            printf("| %d ", c[cont][i]);
        }
        printf("|\n");
    }
}

void gera_cartela(int c[MAXIMO_CARTELAS][TAMANHO_CARTELA], int qtde){
    for(int cont=0;cont<qtde;cont++){
        int cont_sorteados = 0;
        while (cont_sorteados < TAMANHO_CARTELA){
            int bolinha = rand()%QTDE_BOLAS+1;
            int repetido = 0;
            //verificar se repetiu
            for(int i=0;i<cont_sorteados;i++){
                if(c[cont][i] == bolinha) {
                    repetido = 1;
                    break;
                }
            }
            if(repetido) continue;
            c[cont][cont_sorteados] = bolinha;
            cont_sorteados++;
        }
    }
}
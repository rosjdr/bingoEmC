#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
    #include <Windows.h> //função sleep
#else
    #include <unistd.h>
#endif

#define MAXIMO_CARTELAS 10
#define TAMANHO_CARTELA 10
#define QTDE_BOLAS 90
#define TEMPO_ESPERA 250

void imprime_cartelas(int c[MAXIMO_CARTELAS][TAMANHO_CARTELA], int qtde, int bolas[QTDE_BOLAS], int qtde_sorteados);
void gera_cartela(int c[MAXIMO_CARTELAS][TAMANHO_CARTELA], int qtde);
int confere_bola(int numero, int bola);
int verifica_vencedores(int c[MAXIMO_CARTELAS][TAMANHO_CARTELA], int qtde, int bolas[QTDE_BOLAS], int qtde_sorteados);
void imprime_sorteados(int bolas[QTDE_BOLAS], int qtde_sorteados);
void espera();
void limpa_tela();

/*
Implementação de um jogo de bingo em C
*/
int main(){
    int cartelas[MAXIMO_CARTELAS][TAMANHO_CARTELA] = {0};
    int bolas[QTDE_BOLAS] = {0};
    int qtde_vencedores = 0;
    int qtde_cartelas = 10;
    int cont_sorteados = 0;

    srand((unsigned)time(NULL));

    //coloca as bolas no saco
    for(int i=0;i<QTDE_BOLAS;i++){
        bolas[i] = i+1;
    }

    //gera uma cartela de bingo
    gera_cartela(cartelas,qtde_cartelas);
    //imprime a cartela de bingo
    imprime_cartelas(cartelas, qtde_cartelas, bolas, cont_sorteados);

    //começar sorteio
    while(!qtde_vencedores){        
        int bola = rand()%QTDE_BOLAS+1;
        int repetido = 0;
        for(int i=0;i<cont_sorteados;i++){
            if(bola == bolas[i]){
                repetido = 1;
                break;
            }
        }
        if (repetido) continue;
        bolas[cont_sorteados++] = bola;

        espera();
        limpa_tela();
        printf("\n---- RODADA %d ---- SORTEADO: %d ----\n", cont_sorteados, bola);
        imprime_sorteados(bolas,cont_sorteados);
        imprime_cartelas(cartelas,qtde_cartelas, bolas, cont_sorteados);
        qtde_vencedores = verifica_vencedores(cartelas,qtde_cartelas,bolas,cont_sorteados);
    }
    
}

void limpa_tela(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void espera(){
    #ifdef _WIN32
        Sleep(TEMPO_ESPERA);
    #else
        sleep(TEMPO_ESPERA);
    #endif
}

void imprime_sorteados(int bolas[QTDE_BOLAS], int qtde_sorteados){
    printf("SORTEADOS: ");
    for(int i=0; i<qtde_sorteados;i++){
        printf("| %d ", bolas[i]);
    }
    printf("|\n\n");
}

int verifica_vencedores(int c[MAXIMO_CARTELAS][TAMANHO_CARTELA], int qtde, int bolas[QTDE_BOLAS], int qtde_sorteados){
    int cont_vencedores = 0;
    for(int cont=0;cont<qtde;cont++){
        int cont_acertos = 0;
        for(int i=0;i<TAMANHO_CARTELA;i++){
            for(int j=0;j<qtde_sorteados;j++){
                if(confere_bola(c[cont][i],bolas[j])) cont_acertos++;
            }
        }
        if(cont_acertos==TAMANHO_CARTELA) {
            cont_vencedores++;
            printf("Vencedor: Cartela %d\n", cont+1);
        }
    }
    return cont_vencedores;
}

int confere_bola(int numero, int bola){
    return numero == bola;
}

void imprime_cartelas(int c[MAXIMO_CARTELAS][TAMANHO_CARTELA], int qtde, int bolas[QTDE_BOLAS], int qtde_sorteados){
    for(int cont=0;cont<qtde;cont++){
        printf("Cartela %d: ", cont+1);
        for(int i=0;i<TAMANHO_CARTELA;i++){
            int marcar = 0;
            for(int j=0;j<qtde_sorteados;j++){
                if(confere_bola(c[cont][i],bolas[j])){
                    marcar = 1;
                    break;
                }
            }
            if(marcar){
                printf("| * ");
            } else {
                printf("| %d ", c[cont][i]);
            }
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
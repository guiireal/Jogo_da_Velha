#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

#define POS_X 3
#define POS_Y 3
#define MAX_CHAR 20

/*****************************************
            VARIÁVEIS GLOBAIS
******************************************/
char nomeDoJogador[2][MAX_CHAR];
int pontuacao[] = {0, 0};
char tabuleiro[POS_X][POS_Y] = {{'a', 'b', 'c'},
                      {'d', 'e', 'f'},
                      {'g', 'h', 'i'}};
int jogadas = 8;
int quemVenceu = 2;
/*****************************************/

/*********************************************************************************
                            PROTÓTIPOS DE FUNÇÕES
**********************************************************************************/
void exibeDisplay(); // EXIBE O DISPLAY DO JOGO
void exibeTabuleiro(); // INICIA O TABULEIRO
void jogada(int jogador); // VEZ DO JOGADOR 1 OU 2
int validaJogada(char posicao); // VALIDAÇÃO DE JOGADA
void verificaLinha(int jogador); // VERIFICA SE O JOGADOR CONSEGUIU FAZER UMA LINHA
void verificaColuna(int jogador); // VERIFICA SE O JOGADOR CONSEGUIU FAZER UMA COLUNA
void verificaDiagonal(int jogador); // VERIFICA SE O JOGADOR CONSEGUIU FAZER UMA DIAGONAL
/*********************************************************************************/

/**
 * FUNÇÃO PRINCIPAL (INICIA O JOGO)
 */
int main() {

    // ENTRADA DE DADOS
    setlocale(LC_CTYPE, "Portuguese"); // DEFININDO A COMPATIBILIDADE DE CARACTERES
    exibeDisplay();
    printf("\n\t\t\t  Nome do jogador 1: ");
    fflush(stdin);
    gets(nomeDoJogador[0]);
    system("CLS");
    exibeDisplay();
    printf("\n\t\t\t  Nome do jogador 2: ");
    fflush(stdin);
    gets(nomeDoJogador[1]);
    system("CLS");

    // COMEÇA O JOGO !!
    do {
        exibeTabuleiro();
        jogada(0);
        verificaLinha(0);
        verificaColuna(0);
        verificaDiagonal(0);
        system("CLS");
        if (jogadas == 0)
            break;
        exibeTabuleiro();
        jogada(1);
        verificaLinha(1);
        verificaColuna(1);
        verificaDiagonal(1);
        system("CLS");
    } while (jogadas != 0);

    system("CLS");
    exibeTabuleiro();
    if (quemVenceu == 0) {
        printf("\nParabéns %s ! Você venceu o jogo !\n\n", nomeDoJogador[0]);
    } else if (quemVenceu == 1) {
        printf("\nParabéns %s ! Você venceu o jogo !\n\n", nomeDoJogador[1]);
    } else {
        printf("\nEmpate TÉCNICO !\n\n");
    }
    getch();

    return 0;

} // FIM DA FUNÇÃO "MAIN"

void exibeDisplay() {
    printf("\n\t\t\t\tJOGO DA VELHA\n\t\t\t(Feito por: Guilherme França)\n\n");
}

void exibeTabuleiro() {
    int i, j;
    printf("\n\n");
    for(i = 0; i < POS_X; i++) {
            printf("\t\t\t| ");
        for (j = 0; j < POS_Y; j++) {
            printf("%c | ", tabuleiro[i][j]);
        }
        printf("\n\n");
    }
}

void jogada(int jogador) {
    char simbolo, letra;
    int player;
    int validador;
    if (jogador == 0) {
        simbolo = 'X';
        player = 0;
    }
    else {
        simbolo = 'O';
        player = 1;
    }
    printf("%s, vai jogar o %c em qual letra ? : ", nomeDoJogador[player], simbolo);
    fflush(stdin);
    scanf("%c", &letra);
    do {
        if (toupper(letra) == 'A') {
            if (validaJogada(tabuleiro[0][0]) == 0) {
                tabuleiro[0][0] = simbolo;
                validador = 0;
            } else {
                validador = 1;
                printf("Jogada inválida ! Digite outra letra: ");
                fflush(stdin);
                scanf("%c", &letra);
            }
        } else if (toupper(letra) == 'B') {
            if (validaJogada(tabuleiro[0][1]) == 0) {
                tabuleiro[0][1] = simbolo;
                validador = 0;
            } else {
                validador = 1;
                printf("Jogada inválida ! Digite outra letra: ");
                fflush(stdin);
                scanf("%c", &letra);
            }
        } else if (toupper(letra) == 'C') {
            if (validaJogada(tabuleiro[0][2]) == 0) {
                tabuleiro[0][2] = simbolo;
                validador = 0;
            }
            else {
                validador = 1;
                printf("Jogada inválida ! Digite outra letra: ");
                fflush(stdin);
                scanf("%c", &letra);
            }
        } else if (toupper(letra) == 'D') {
            if (validaJogada(tabuleiro[1][0]) == 0) {
                tabuleiro[1][0] = simbolo;
                validador = 0;
            } else {
                validador = 1;
                printf("Jogada inválida ! Digite outra letra: ");
                fflush(stdin);
                scanf("%c", &letra);
            }
        } else if (toupper(letra) == 'E') {
            if (validaJogada(tabuleiro[1][1]) == 0) {
                tabuleiro[1][1] = simbolo;
                validador = 0;
            } else {
                validador = 1;
                printf("Jogada inválida ! Digite outra letra: ");
                fflush(stdin);
                scanf("%c", &letra);
            }
        } else if (toupper(letra) == 'F') {
            if (validaJogada(tabuleiro[1][2]) == 0) {
                tabuleiro[1][2] = simbolo;
                validador = 0;
            } else {
                validador = 1;
                printf("Jogada inválida ! Digite outra letra: ");
                fflush(stdin);
                scanf("%c", &letra);
            }
        } else if (toupper(letra) == 'G') {
            if (validaJogada(tabuleiro[2][0]) == 0) {
                tabuleiro[2][0] = simbolo;
                validador = 0;
            } else {
                validador = 1;
                printf("Jogada inválida ! Digite outra letra: ");
                fflush(stdin);
                scanf("%c", &letra);
            }
        } else if (toupper(letra) == 'H') {
            if (validaJogada(tabuleiro[2][1]) == 0) {
                tabuleiro[2][1] = simbolo;
                validador = 0;
            } else {
                validador = 1;
                printf("Jogada inválida ! Digite outra letra: ");
                fflush(stdin);
                scanf("%c", &letra);
            }
        } else if (toupper(letra) == 'I') {
            if (validaJogada(tabuleiro[2][2]) == 0) {
                tabuleiro[2][2] = simbolo;
                validador = 0;
            } else {
                validador = 1;
                printf("Jogada inválida ! Digite outra letra: ");
                fflush(stdin);
                scanf("%c", &letra);
            }
        }
    } while (validador == 1);
    jogadas--;
} // FIM DA FUNÇÃO

int validaJogada(char posicao) {
    int flag;
    if ((posicao == 'X') || (posicao == 'O'))
        flag = 1;
    else
        flag = 0;

    return flag;
}

void verificaLinha(int jogador) {
    char simbolo;
    if (jogador == 0)
        simbolo = 'X';
    else
        simbolo = 'O';

    if ((tabuleiro[0][0] == simbolo) && (tabuleiro[0][1] == simbolo) && (tabuleiro[0][2] == simbolo)) {
        jogadas = 0;
        quemVenceu = (simbolo == 'X') ? 0 : 1;
    } else if ((tabuleiro[1][0] == simbolo) && (tabuleiro[1][1] == simbolo) && (tabuleiro[1][2] == simbolo)) {
        jogadas = 0;
        quemVenceu = (simbolo == 'X') ? 0 : 1;
    } else if ((tabuleiro[2][0] == simbolo) && (tabuleiro[2][1] == simbolo) && (tabuleiro[2][2] == simbolo)) {
        jogadas = 0;
        quemVenceu = (simbolo == 'X') ? 0 : 1;
    }
}

void verificaColuna(int jogador) {
    char simbolo;
    if (jogador == 0)
        simbolo = 'X';
    else
        simbolo = 'O';

    if ((tabuleiro[0][0] == simbolo) && (tabuleiro[1][0] == simbolo) && (tabuleiro[2][0] == simbolo)) {
        jogadas = 0;
        quemVenceu = (simbolo == 'X') ? 0 : 1;
    } else if ((tabuleiro[0][1] == simbolo) && (tabuleiro[1][1] == simbolo) && (tabuleiro[2][1] == simbolo)) {
        jogadas = 0;
        quemVenceu = (simbolo == 'X') ? 0 : 1;
    } else if ((tabuleiro[0][2] == simbolo) && (tabuleiro[1][2] == simbolo) && (tabuleiro[2][2] == simbolo)) {
        jogadas = 0;
        quemVenceu = (simbolo == 'X') ? 0 : 1;
    }
}

void verificaDiagonal(int jogador) {
    char simbolo;
    if (jogador == 0)
        simbolo = 'X';
    else
        simbolo = 'O';

    if ((tabuleiro[0][0] == simbolo) && (tabuleiro[1][1] == simbolo) && (tabuleiro[2][2] == simbolo)) {
        jogadas = 0;
        quemVenceu = (simbolo == 'X') ? 0 : 1;
    } else if ((tabuleiro[0][2] == simbolo) && (tabuleiro[1][1] == simbolo) && (tabuleiro[2][0] == simbolo)) {
        jogadas = 0;
        quemVenceu = (simbolo == 'X') ? 0 : 1;
    }
}

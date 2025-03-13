#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int escolhaJogador, escolhaComputador;
    srand(time(0));

    printf("Jogo de Jokenpo\n");
    printf("Escolha uma opção:\n");
    printf("1. Pedra\n");
    printf("2. Papel\n");
    printf("3. Tesoura\n");
    printf("Escolha: ");
    scanf("%d", &escolhaJogador);

    escolhaComputador = rand() % 3 + 1;

    switch (escolhaJogador) {
        case 1:
            printf("Você escolheu Pedra\n");
            break;
        case 2:
            printf("Você escolheu Papel\n");
            break;
        case 3:
            printf("Você escolheu Tesoura\n");
            break;
        default:
            printf("Opção inválida!\n");
            return 1; 
    }

    switch (escolhaComputador) {
        case 1:
            printf("Computador escolheu Pedra\n");
            break;
        case 2:
            printf("Computador escolheu Papel\n");
            break;
        case 3:
            printf("Computador escolheu Tesoura\n");
            break;
    }

    if (escolhaComputador == escolhaJogador) {
        printf("Empate!\n");
    } else if ((escolhaComputador == 1 && escolhaJogador == 3) || 
               (escolhaComputador == 2 && escolhaJogador == 1) || 
               (escolhaComputador == 3 && escolhaJogador == 2)) {
        printf("Computador venceu!\n");
    } else {
        printf("Jogador venceu!\n");
    }

    return 0; 
}

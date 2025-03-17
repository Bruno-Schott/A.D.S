#include <stdio.h>

int main() {
    int escolha;

    // Menu interativo daa seleção de peças
    printf("Bem-vindo ao simulador de movimentos de xadrez!\n");
    printf("Escolha a peça para simular o movimento:\n");
    printf("1 - Torre \u2656\n");
    printf("2 - Bispo \u2657\n");
    printf("3 - Rainha \u2655\n");
    printf("0 - Sair \u25A7\n");
    printf("Digite o número da opção desejada: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: // Movimento da Torre
            printf("\nVocê escolheu a Torre.\n");
            printf("Movimento da Torre: 5 casas para a direita.\n");
            for (int i = 0; i < 5; i++) {
                printf("Direita\n"); // imprimie o movimento da peça escolhida (torre)
            }
            break;

        case 2: // Movimento do Bispo
            printf("\nVocê escolheu o Bispo.\n");
            printf("Movimento do Bispo: 5 casas na diagonal para cima e à direita.\n");
            int casa_bispo = 0;
            while (casa_bispo < 5) {
                printf("Cima, Direita\n"); // imprimie o movimento da peça escolhida (bispo)
                casa_bispo++;
            }
            break;

        case 3: // Movimento da Rainha
            printf("\nVocê escolheu a Rainha.\n");
            printf("Movimento da Rainha: 8 casas para a esquerda.\n");
            int casa_rainha = 0;
            do {
                printf("Esquerda\n"); // imprimie o movimento da peça escolhida (rainha)
                casa_rainha++;
            } while (casa_rainha < 8);
            break;

        case 0: // Sair do programa
            printf("\nSaindo do programa...\n");
            break;

        default: // Opção inválida
            printf("\nOpção inválida! Por favor, escolha uma opção válida.\n");
            break;
    }

    return 0;
}

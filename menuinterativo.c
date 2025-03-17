#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){

    int opcao, regras;
    int numeroSecreto, palpite;

    printf("Menu principal:\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Regras do Jogo\n"); 
    printf("3. Sair do jogo\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);


    switch (opcao)
    {
    case 1:
    srand(time(0));
    numeroSecreto = rand() % 10;
    printf("Digite um número entre 0 e 9: ");
    scanf("%d", &palpite);
    if (palpite == numeroSecreto){
        printf("Parabéns, você acertou!\n");
        printf("numero secreto: %d\n", numeroSecreto);
    } else {
        printf("Que pena, você errou!\n");
        printf("numero secreto: %d\n", numeroSecreto);
    }
    
    break;
    case 2:
    printf("Regras do jogo...\n");
    break;
    case 3:
    printf("Saindo do jogo...\n");
    break;
    default:
    printf("Opção inválida!\n");
        break;
    }




}

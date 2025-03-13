#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int numeroJogador, numeroComputador, resultado;
    char tipoComparacao;

    // gerar numero aleatorio para o computador
    srand(time(0));
    numeroComputador = rand() % 100 + 1; //numero entre 1 e 100

    // inicio do jogo
    printf("Bem-vindo ao Jogo maior, Menor ou Igual!\n");
    printf("Você deve escolher um número e o tipo de comparação.\n");
    printf("M. Maior\n");
    printf("N. Menor\n");
    printf("I. Igual\n");

    printf("Escolha a comparação: ");
    scanf(" %c", &tipoComparacao);

    printf("Digite seu número (entre 1 e 100): ");
    scanf("%d", &numeroJogador);

    //eixbir o numero do computador
    printf("O número do computador é: %d\n", numeroComputador);


    switch (tipoComparacao)
    {
    case 'M':
    case 'm':
        printf("Você escolheu Maior\n");
    resultado = numeroJogador > numeroComputador ? 1 : 0;
        break;

    case 'N':
    case 'n':
        printf("Você escolheu Menor\n");
        resultado = numeroJogador < numeroComputador ? 1 : 0;
        break;
        
    case 'I':
    case 'i':
        printf("Você escolheu Igual\n");
       resultado = numeroJogador == numeroComputador ? 1 : 0;
        break;
        printf("O numero do computador é %d e o do jogador é: %d\n", numeroComputador, numeroJogador);
    }
if (resultado == 1)
{
    printf("Parabéns, você venceu!\n");
} else {
    printf("Que pena, você perdeu!\n");
}

    return 0;
}

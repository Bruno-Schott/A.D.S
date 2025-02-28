#include <stdio.h>

int main(){


/*
soma (+)
subtração (-)
multiplicação (*)
divisão (/)

*/

int numero1, numero2;
int soma, subtracao, multiplicacao, divisao;

printf("Entre com o numero 1: \n");
scanf("%d", &numero1);
printf("Entre com o numero 2: \n");
scanf("%d", &numero2);

//operação soma
soma = numero1 + numero2;
//operação subtração
subtracao = numero1 - numero2;  
//operação multiplicação
multiplicacao = numero1 * numero2;
//operação divisão
divisao = numero1 / numero2;

printf("A some é: %d\n", soma);
printf("A subtração é: %d\n", subtracao);
printf("A multiplicação é: %d\n", multiplicacao);
printf("A divisão é: %d\n", divisao);


}

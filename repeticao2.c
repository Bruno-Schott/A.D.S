#include <stdio.h>

int main(){


    int numero;

    do {

        printf("Digite um numero par para sair do programa: \n");
        scanf("%d", &numero);

        if(numero % 2 == 0){
            printf("O numero %d é par!\n", numero);
        } else {
            printf("O numero %d é impar!\n", numero);
        }


    } while (numero % 2 !=0);

    printf("Você digitou um numero par, saindo do programa...\n");





    return 0;
}

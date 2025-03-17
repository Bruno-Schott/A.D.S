#include <stdio.h>

int main() {
    int opcao;
    float nota1, nota2, media;

    printf("Menu de Gerenciamento de Estudantes\n");
    printf("1. Calcular média\n");
    printf("2. Determinar Status\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Calcular a Média\n");
            printf("Digite a primeira nota: ");
            scanf("%f", &nota1);
            printf("Digite a segunda nota: ");
            scanf("%f", &nota2);

       
            if (nota1 < 0 || nota1 > 10 || nota2 < 0 || nota2 > 10) {
                printf("Nota inválida!\n");
            } else {
             
                media = (nota1 + nota2) / 2;
                printf("Média: %.2f\n", media);
            }
            break;

        case 2:
            printf("Determinar Status\n");
            printf("Entrar com a média do aluno: ");
            scanf("%f", &media);
            //media >= 5 ? printf("Aprovado!\n") : printf("Reprovado!\n");
            if (media >= 7)
            {
                printf("Aprovado!\n");
            }
            else if (media >= 5)
            {
                printf("Recuperação!\n");
            }
            else
            {
                printf("Reprovado!\n");
            }
            break;

        case 3:
            printf("Saindo do programa...\n");
            break;

        default:
            printf("Opção inválida!\n");
            break;
    }

    return 0;
}

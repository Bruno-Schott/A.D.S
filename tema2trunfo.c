#include <stdio.h>
#include <string.h> // Para usar strcspn

// Função para limpar o buffer de entrada
void limparBuffer() {
    while (getchar() != '\n');
}

// Função para comparar um atributo escolhido e exibir o resultado
void compararAtributo(const char* atributo, float valor1, float valor2, const char* cidade1, const char* cidade2, const char* estado1, const char* estado2) {
    printf("\nComparação de cartas (Atributo: %s):\n", atributo);
    printf("Carta 1 - %s (%s): %.2f\n", cidade1, estado1, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", cidade2, estado2, valor2);

    if (strcmp(atributo, "Densidade Populacional") == 0) {
        // Para densidade, o menor valor vence
        if (valor1 < valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else if (valor1 > valor2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    } else {
        // Para outros atributos, o maior valor vence
        if (valor1 > valor2) {
            printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
        } else if (valor1 < valor2) {
            printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
}

int main() {
    // Variáveis para as cartas
    char codigo1[10], codigo2[10];
    char estado1[30], estado2[30];
    char cidade1[80], cidade2[80];
    unsigned long int populacao1, populacao2; // População como unsigned long int
    float pib1, pib2;
    float area1, area2;
    int pontos_turisticos1, pontos_turisticos2;
    float densidade1, densidade2;
    float pib_per_capita1, pib_per_capita2;

    // Informações para a primeira carta
    printf("Cadastro da Carta 1\n");
    printf("Digite uma letra de 'A' a 'H' (representando um dos oito estados): \n");
    printf("Estado: ");
    scanf("%s", estado1);
    limparBuffer();

    printf("O código contém o estado mais o número da cidade\n");
    printf("Exemplos: A01, B01, C02, D02, assim por diante. \n");
    printf("Código: ");
    scanf("%s", codigo1);
    limparBuffer();

    printf("Escreva o nome da cidade (pode usar espaços):\n");
    printf("Nome da cidade: ");
    fgets(cidade1, sizeof(cidade1), stdin); // Captura a linha inteira, incluindo espaços
    cidade1[strcspn(cidade1, "\n")] = '\0'; // Remove a nova linha (\n) do final

    printf("População: ");
    scanf("%lu", &populacao1);
    limparBuffer();

    printf("Área (em km²): ");
    scanf("%f", &area1);
    limparBuffer();

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    limparBuffer();

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos1);
    limparBuffer();

    printf(" \n");
    printf("Carta 1 cadastrada com sucesso!\n");
    printf(" \n");

    // Informações para a segunda carta
    printf("Cadastro da Carta 2\n");
    printf("Digite uma letra de 'A' a 'H' (representando um dos oito estados): \n");
    printf("Estado: ");
    scanf("%s", estado2);
    limparBuffer();

    printf("O código contém o estado mais o número da cidade\n");
    printf("Exemplos: A01, B01, C02, D02, assim por diante. \n");
    printf("Código: ");
    scanf("%s", codigo2);
    limparBuffer();

    printf("Escreva o nome da cidade (pode usar espaços):\n");
    printf("Nome da cidade: ");
    fgets(cidade2, sizeof(cidade2), stdin); // Captura a linha inteira, incluindo espaços
    cidade2[strcspn(cidade2, "\n")] = '\0'; // Remove a nova linha (\n) do final

    printf("População: ");
    scanf("%lu", &populacao2);
    limparBuffer();

    printf("Área (em km²): ");
    scanf("%f", &area2);
    limparBuffer();

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    limparBuffer();

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);
    limparBuffer();

    printf(" \n");
    printf("Carta 2 cadastrada com sucesso!\n");
    printf(" \n");

    // Cálculos para a primeira carta
    densidade1 = (float)populacao1 / area1;
    pib_per_capita1 = (float)pib1 / populacao1;

    // Cálculos para a segunda carta
    densidade2 = (float)populacao2 / area2;
    pib_per_capita2 = (float)pib2 / populacao2;

    // Exibição dos dados da primeira carta
    printf("\nCarta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %.0lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per capita: %.2f reais/habitante\n", pib_per_capita1);

    // Exibição dos dados da segunda carta
    printf("\nCarta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %.0lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per capita: %.2f reais/habitante\n", pib_per_capita2);

    // Menu de escolha de atributo para comparação
    int escolha;
    printf("\nEscolha o atributo para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Densidade Populacional\n");
    printf("5. PIB per capita\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    // Variáveis para armazenar os valores dos atributos escolhidos
    const char* atributoEscolhido;
    float valor1, valor2;

    switch (escolha) {
        case 1:
            atributoEscolhido = "População";
            valor1 = (float)populacao1;
            valor2 = (float)populacao2;
            break;
        case 2:
            atributoEscolhido = "Área";
            valor1 = area1;
            valor2 = area2;
            break;
        case 3:
            atributoEscolhido = "PIB";
            valor1 = pib1;
            valor2 = pib2;
            break;
        case 4:
            atributoEscolhido = "Densidade Populacional";
            valor1 = densidade1;
            valor2 = densidade2;
            break;
        case 5:
            atributoEscolhido = "PIB per capita";
            valor1 = pib_per_capita1;
            valor2 = pib_per_capita2;
            break;
        default:
            printf("Escolha inválida!\n");
            return 1; // Encerra o programa se a escolha for inválida
    }

    // Chamada da função para comparar o atributo escolhido
    compararAtributo(atributoEscolhido, valor1, valor2, cidade1, cidade2, estado1, estado2);

    return 0;
}

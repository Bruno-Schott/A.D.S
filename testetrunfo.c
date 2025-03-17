#include <stdio.h>
#include <string.h> // Para usar strcspn

// Função para limpar o buffer de entrada
void limparBuffer() {
    while (getchar() != '\n');
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
    float super_poder1, super_poder2;

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
    super_poder1 = populacao1 + area1 + pib1 + pontos_turisticos1 + pib_per_capita1 + (1 / densidade1);

    // Cálculos para a segunda carta
    densidade2 = (float)populacao2 / area2;
    pib_per_capita2 = (float)pib2 / populacao2;
    super_poder2 = populacao2 + area2 + pib2 + pontos_turisticos2 + pib_per_capita2 + (1 / densidade2);

    // Exibição dos dados da primeira carta
    printf("\nCarta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %.0lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", populacao1 / area1);
    printf("PIB per capita: %.2f reais/habitante\n", pib1 / populacao1);

    // Exibição dos dados da segunda carta
    printf("\nCarta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %.0lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", populacao2 / area2);
    printf("PIB per capita: %.2f reais/habitante\n", pib2 / populacao2);

    // Comparação das cartas
    printf("\nComparação de Cartas:\n");
    printf("População: Carta %d venceu (%d)\n", (populacao1 > populacao2) ? 1 : 2, (populacao1 > populacao2) ? 0 : 1);
    printf("Área: Carta %d venceu (%d)\n", (area1 > area2) ? 1 : 2, (area1 > area2) ? 0 : 1);
    printf("PIB: Carta %d venceu (%d)\n", (pib1 > pib2) ? 1 : 2, (pib1 > pib2) ? 0 : 1);
    printf("Pontos Turísticos: Carta %d venceu (%d)\n", (pontos_turisticos1 > pontos_turisticos2) ? 1 : 2, (pontos_turisticos1 > pontos_turisticos2) ? 0 : 1);
    printf("Densidade Populacional: Carta %d venceu (%d)\n", (densidade1 < densidade2) ? 1 : 2, (densidade1 < densidade2) ? 0 : 1);
    printf("PIB per Capita: Carta %d venceu (%d)\n", (pib_per_capita1 > pib_per_capita2) ? 1 : 2, (pib_per_capita1 > pib_per_capita2) ? 0 : 1);
    printf("Super Poder: Carta %d venceu (%d)\n", (super_poder1 > super_poder2) ? 1 : 2, (super_poder1 > super_poder2) ? 0 : 1);

    return 0;
}

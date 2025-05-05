#include <stdio.h>
#include <string.h>

// Códigos ANSI para cores no terminal
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RED "\x1b[31m"

// Função para calcular a densidade populacional
float calcular_densidade(unsigned long int populacao, float area) {
    return (float)populacao / area;
}

// Função para calcular o PIB per capita
float calcular_pib_per_capita(float pib, unsigned long int populacao) {
    return (pib * 1000) / populacao; // Convertendo PIB de bilhões para milhões
}

// Função para calcular o Super Poder
float calcular_super_poder(unsigned long int populacao, float area, float pib, int pontos_turisticos, float pib_per_capita, float densidade) {
    return (float)populacao + area + pib + (float)pontos_turisticos + pib_per_capita + (1.0 / densidade);
}

// Função para exibir uma linha separadora
void linha_separadora() {
    printf(ANSI_COLOR_CYAN "--------------------------------------------------\n" ANSI_COLOR_RESET);
}

int main() {
    // Variáveis para armazenar os dados das duas cartas
    char estado1, estado2;
    char codigo1[4], codigo2[4];
    char nome_cidade1[50], nome_cidade2[50];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos_turisticos1, pontos_turisticos2;

    // Entrada de dados para a Carta 1
    printf(ANSI_COLOR_BLUE "\n📋 Cadastro da Carta 1\n" ANSI_COLOR_RESET);
    linha_separadora();
    printf("📍 Digite uma letra de 'A' a 'H' (representando um dos oito estados): \n");
    printf("Estado: ");
    scanf(" %c", &estado1);
    printf("📌 O código contém o estado mais o número da cidade\n");
    printf(" Exemplos: A01, B01, C02, D02, assim por diante. \n");
    printf("Código: ");
    scanf("%s", codigo1);
    printf("🏙️   Nome da Cidade: ");
    scanf(" %[^\n]", nome_cidade1);
    printf("👥 População: ");
    scanf("%lu", &populacao1);
    printf("📏 Área (em km²): ");
    scanf("%f", &area1);
    printf("💰 PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    printf("🏞️   Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos1);
    linha_separadora();

    // Entrada de dados para a Carta 2
    printf(ANSI_COLOR_BLUE "\n📋 Cadastro da Carta 2\n" ANSI_COLOR_RESET);
    linha_separadora();
    printf("📍 Digite uma letra de 'A' a 'H' (representando um dos oito estados): \n");
    printf("Estado: ");
    scanf(" %c", &estado2);
    printf("📌 O código contém o estado mais o número da cidade\n");
    printf(" Exemplos: A01, B01, C02, D02, assim por diante. \n");
    printf("Código: ");
    scanf("%s", codigo2);
    printf("🏙️   Nome da Cidade: ");
    scanf(" %[^\n]", nome_cidade2);
    printf("👥 População: ");
    scanf("%lu", &populacao2);
    printf("📏 Área (em km²): ");
    scanf("%f", &area2);
    printf("💰 PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    printf("🏞️   Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);
    linha_separadora();

    // Cálculo das propriedades derivadas para a Carta 1
    float densidade1 = calcular_densidade(populacao1, area1);
    float pib_per_capita1 = calcular_pib_per_capita(pib1, populacao1);
    float super_poder1 = calcular_super_poder(populacao1, area1, pib1, pontos_turisticos1, pib_per_capita1, densidade1);

    // Cálculo das propriedades derivadas para a Carta 2
    float densidade2 = calcular_densidade(populacao2, area2);
    float pib_per_capita2 = calcular_pib_per_capita(pib2, populacao2);
    float super_poder2 = calcular_super_poder(populacao2, area2, pib2, pontos_turisticos2, pib_per_capita2, densidade2);

    // Exibição dos dados da Carta 1
    printf(ANSI_COLOR_GREEN "\n📊 Dados da Carta 1:\n" ANSI_COLOR_RESET);
    linha_separadora();
    printf("📍 Estado: %c\n", estado1);
    printf("📌 Código: %s\n", codigo1);
    printf("🏙️ Nome da Cidade: %s\n", nome_cidade1);
    printf("👥 População: %lu\n", populacao1);
    printf("📏 Área: %.2f km²\n", area1);
    printf("💰 PIB: %.2f bilhões de reais\n", pib1);
    printf("🏞️ Número de Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("📈 Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("💵 PIB per Capita: %.2f reais\n", pib_per_capita1);
    printf("⚡ Super Poder: %.2f\n", super_poder1); // Ícone alterado para ⚡
    linha_separadora();

    // Exibição dos dados da Carta 2
    printf(ANSI_COLOR_GREEN "\n📊 Dados da Carta 2:\n" ANSI_COLOR_RESET);
    linha_separadora();
    printf("📍 Estado: %c\n", estado2);
    printf("📌 Código: %s\n", codigo2);
    printf("🏙️ Nome da Cidade: %s\n", nome_cidade2);
    printf("👥 População: %lu\n", populacao2);
    printf("📏 Área: %.2f km²\n", area2);
    printf("💰 PIB: %.2f bilhões de reais\n", pib2);
    printf("🏞️ Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("📈 Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("💵 PIB per Capita: %.2f reais\n", pib_per_capita2);
    printf("⚡ Super Poder: %.2f\n", super_poder2); // Ícone alterado para ⚡
    linha_separadora();

    // Comparação das cartas
    printf(ANSI_COLOR_YELLOW "\n🏆 Comparação de Cartas:\n" ANSI_COLOR_RESET);
    linha_separadora();
    printf("👥 População: Carta %d venceu (%d)\n", (populacao1 > populacao2) ? 1 : 2, (populacao1 > populacao2) ? 1 : 0);
    printf("📏 Área: Carta %d venceu (%d)\n", (area1 > area2) ? 1 : 2, (area1 > area2) ? 1 : 0);
    printf("💰 PIB: Carta %d venceu (%d)\n", (pib1 > pib2) ? 1 : 2, (pib1 > pib2) ? 1 : 0);
    printf("🏞️ Pontos Turísticos: Carta %d venceu (%d)\n", (pontos_turisticos1 > pontos_turisticos2) ? 1 : 2, (pontos_turisticos1 > pontos_turisticos2) ? 1 : 0);
    printf("📈 Densidade Populacional: Carta %d venceu (%d)\n", (densidade1 < densidade2) ? 1 : 2, (densidade1 < densidade2) ? 1 : 0);
    printf("💵 PIB per Capita: Carta %d venceu (%d)\n", (pib_per_capita1 > pib_per_capita2) ? 1 : 2, (pib_per_capita1 > pib_per_capita2) ? 1 : 0);
    printf("⚡ Super Poder: Carta %d venceu (%d)\n", (super_poder1 > super_poder2) ? 1 : 2, (super_poder1 > super_poder2) ? 1 : 0); // Ícone alterado para ⚡
    linha_separadora();

    return 0;
}

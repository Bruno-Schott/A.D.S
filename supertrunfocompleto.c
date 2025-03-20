#include <stdio.h>
#include <string.h>
#include <locale.h> // Para formatação de números

// Códigos ANSI para cores e estilos no terminal
#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_BOLD "\x1b[1m"

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

// Função para formatar a população com separadores de milhares
void formatar_populacao(unsigned long int populacao, char *buffer) {
    char temp[20];
    snprintf(temp, 20, "%lu", populacao); // Converte a população para string
    int len = strlen(temp);
    int pos = 0;

    // Adiciona separadores de milhares
    for (int i = 0; i < len; i++) {
        if ((len - i) % 3 == 0 && i != 0) {
            buffer[pos++] = '.';
        }
        buffer[pos++] = temp[i];
    }
    buffer[pos] = '\0'; // Finaliza a string
}

// Função para exibir os dados de uma carta
void exibir_carta(char estado, char codigo[], char nome_cidade[], unsigned long int populacao, float area, float pib, int pontos_turisticos, float densidade, float pib_per_capita, float super_poder) {
    char populacao_formatada[20];
    formatar_populacao(populacao, populacao_formatada); // Formata a população

    printf(ANSI_COLOR_GREEN "\n📊 Dados da Carta:\n" ANSI_COLOR_RESET);
    linha_separadora();
    printf("📍 Estado: %c\n", estado);
    printf("📌 Código: %s\n", codigo);
    printf("🏙️ Nome da Cidade: %s\n", nome_cidade);
    printf("👥 População: %s\n", populacao_formatada); // Exibe a população formatada
    printf("📏 Área: %.2f km²\n", area);
    printf("💰 PIB: %.2f bilhões de reais\n", pib);
    printf("🏞️ Número de Pontos Turísticos: %d\n", pontos_turisticos);
    printf("📈 Densidade Populacional: %.2f hab/km²\n", densidade);
    printf("💵 PIB per Capita: %.2f reais\n", pib_per_capita);
    printf("⚡ Super Poder: %.2f\n", super_poder);
    linha_separadora();
}

// Função para comparar as cartas
void comparar_cartas(float atributo1, float atributo2, char *descricao) {
    if (atributo1 > atributo2) {
        printf("%s: " ANSI_COLOR_GREEN "Carta 1 venceu (1)\n" ANSI_COLOR_RESET, descricao);
    } else if (atributo1 < atributo2) {
        printf("%s: " ANSI_COLOR_RED "Carta 2 venceu (0)\n" ANSI_COLOR_RESET, descricao);
    } else {
        printf("%s: " ANSI_COLOR_YELLOW "Empate!\n" ANSI_COLOR_RESET, descricao);
    }
}

// Função para cadastrar uma carta
void cadastrar_carta(char *estado, char codigo[], char nome_cidade[], unsigned long int *populacao, float *area, float *pib, int *pontos_turisticos) {
    printf("📍 Digite uma letra de 'A' a 'H' (representando um dos oito estados): \n");
    printf("Estado: ");
    scanf(" %c", estado);
    printf("📌 O código contém o estado mais o número da cidade\n");
    printf(" Exemplos: A01, B01, C02, D02, assim por diante. \n");
    printf("Código: ");
    scanf("%s", codigo);
    printf("🏙️  Nome da Cidade: ");
    scanf(" %[^\n]", nome_cidade);
    printf("👥 População: ");
    scanf("%lu", populacao);
    printf("📏 Área (em km²): ");
    scanf("%f", area);
    printf("💰 PIB (em bilhões de reais): ");
    scanf("%f", pib);
    printf("🏞️  Número de Pontos Turísticos: ");
    scanf("%d", pontos_turisticos);
}

int main() {
    setlocale(LC_NUMERIC, ""); // Habilita formatação de números com separadores de milhares

    // Variáveis para armazenar os dados das duas cartas
    char estado1 = ' ', estado2 = ' ';
    char codigo1[4] = "", codigo2[4] = "";
    char nome_cidade1[50] = "", nome_cidade2[50] = "";
    unsigned long int populacao1 = 0, populacao2 = 0;
    float area1 = 0, area2 = 0;
    float pib1 = 0, pib2 = 0;
    int pontos_turisticos1 = 0, pontos_turisticos2 = 0;

    int opcao;
    do {
        // Menu interativo
        printf(ANSI_BOLD ANSI_COLOR_BLUE "\n🎮 Menu Principal:\n" ANSI_COLOR_RESET);
        linha_separadora();
        printf("1. Cadastrar Carta 1\n");
        printf("2. Cadastrar Carta 2\n");
        printf("3. Exibir Dados das Cartas\n");
        printf("4. Comparar Cartas\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf(ANSI_BOLD ANSI_COLOR_BLUE "\n🎮 Cadastro da Carta 1\n" ANSI_COLOR_RESET);
                linha_separadora();
                cadastrar_carta(&estado1, codigo1, nome_cidade1, &populacao1, &area1, &pib1, &pontos_turisticos1);
                linha_separadora();
                break;

            case 2:
                printf(ANSI_BOLD ANSI_COLOR_BLUE "\n🎮 Cadastro da Carta 2\n" ANSI_COLOR_RESET);
                linha_separadora();
                cadastrar_carta(&estado2, codigo2, nome_cidade2, &populacao2, &area2, &pib2, &pontos_turisticos2);
                linha_separadora();
                break;

            case 3:
                if (estado1 == ' ') {
                    printf(ANSI_COLOR_RED "\nErro: Carta 1 não cadastrada.\n" ANSI_COLOR_RESET);
                } else {
                    float densidade1 = calcular_densidade(populacao1, area1);
                    float pib_per_capita1 = calcular_pib_per_capita(pib1, populacao1);
                    float super_poder1 = calcular_super_poder(populacao1, area1, pib1, pontos_turisticos1, pib_per_capita1, densidade1);
                    exibir_carta(estado1, codigo1, nome_cidade1, populacao1, area1, pib1, pontos_turisticos1, densidade1, pib_per_capita1, super_poder1);
                }

                if (estado2 == ' ') {
                    printf(ANSI_COLOR_RED "\nErro: Carta 2 não cadastrada.\n" ANSI_COLOR_RESET);
                } else {
                    float densidade2 = calcular_densidade(populacao2, area2);
                    float pib_per_capita2 = calcular_pib_per_capita(pib2, populacao2);
                    float super_poder2 = calcular_super_poder(populacao2, area2, pib2, pontos_turisticos2, pib_per_capita2, densidade2);
                    exibir_carta(estado2, codigo2, nome_cidade2, populacao2, area2, pib2, pontos_turisticos2, densidade2, pib_per_capita2, super_poder2);
                }
                break;

            case 4:
                if (estado1 == ' ' || estado2 == ' ') {
                    printf(ANSI_COLOR_RED "\nErro: Ambas as cartas devem ser cadastradas antes de comparar.\n" ANSI_COLOR_RESET);
                } else {
                    float densidade1 = calcular_densidade(populacao1, area1);
                    float pib_per_capita1 = calcular_pib_per_capita(pib1, populacao1);
                    float super_poder1 = calcular_super_poder(populacao1, area1, pib1, pontos_turisticos1, pib_per_capita1, densidade1);

                    float densidade2 = calcular_densidade(populacao2, area2);
                    float pib_per_capita2 = calcular_pib_per_capita(pib2, populacao2);
                    float super_poder2 = calcular_super_poder(populacao2, area2, pib2, pontos_turisticos2, pib_per_capita2, densidade2);

                    printf(ANSI_BOLD ANSI_COLOR_YELLOW "\n⚔️   Comparação de Cartas ⚔️\n" ANSI_COLOR_RESET);
                    linha_separadora();
                    comparar_cartas(populacao1, populacao2, "👥 População");
                    comparar_cartas(area1, area2, "📏 Área");
                    comparar_cartas(pib1, pib2, "💰 PIB");
                    comparar_cartas(pontos_turisticos1, pontos_turisticos2, "🏞️ Pontos Turísticos");
                    comparar_cartas(-densidade1, -densidade2, "📈 Densidade Populacional"); // Invertido para menor densidade vencer
                    comparar_cartas(pib_per_capita1, pib_per_capita2, "💵 PIB per Capita");
                    comparar_cartas(super_poder1, super_poder2, "⚡ Super Poder");
                    linha_separadora();
                }
                break;

            case 5:
                printf(ANSI_COLOR_GREEN "\nSaindo...\n" ANSI_COLOR_RESET);
                break;

            default:
                printf(ANSI_COLOR_RED "\nOpção inválida! Tente novamente.\n" ANSI_COLOR_RESET);
        }
    } while (opcao != 5);

    return 0;
}

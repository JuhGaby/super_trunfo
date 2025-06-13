#include <stdio.h>

int main() {
    // Variáveis do Cartão 1
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    int populacao1;
    float area1;
    float pib1; // em bilhões
    int atracoesTuristicas1;
    float densidade1; // densidade populacional
    float pibPerCapita1; // em reais

    // Variáveis do Cartão 2
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    int populacao2;
    float area2;
    float pib2; // em bilhões
    int atracoesTuristicas2;
    float densidade2; // densidade populacional
    float pibPerCapita2; // em reais

    // Entrada para o Cartão 1
    printf("Digite os dados para o Cartão 1:\n");
    
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    
    printf("Código (ex., A01): ");
    scanf("%3s", codigo1);
    
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade1);
    
    printf("População: ");
    scanf("%d", &populacao1);
    
    printf("Área (km²): ");
    scanf("%f", &area1);
    
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    
    printf("Número de Atrações Turísticas: ");
    scanf("%d", &atracoesTuristicas1);

    // Calcular métricas do Cartão 1
    densidade1 = populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1; // Converter PIB para reais

    // Entrada para o Cartão 2
    printf("\nDigite os dados para o Cartão 2:\n");
    
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    
    printf("Código (ex., B02): ");
    scanf("%3s", codigo2);
    
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade2);
    
    printf("População: ");
    scanf("%d", &populacao2);
    
    printf("Área (km²): ");
    scanf("%f", &area2);
    
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    
    printf("Número de Atrações Turísticas: ");
    scanf("%d", &atracoesTuristicas2);

    // Calcular métricas do Cartão 2
    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2; // Converter PIB para reais

    // Exibir informações do Cartão 1
    printf("\nCartão 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Atrações Turísticas: %d\n", atracoesTuristicas1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    // Exibir informações do Cartão 2
    printf("\nCartão 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Atrações Turísticas: %d\n", atracoesTuristicas2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    return 0;
}

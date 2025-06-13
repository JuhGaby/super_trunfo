#include <stdio.h>

int main() {
    // Variáveis do Cartão 1
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    unsigned long int populacao1;  // Alterado para unsigned long int
    float area1;
    float pib1; // em bilhões
    int atracoesTuristicas1;
    float densidade1;
    float pibPerCapita1;
    float superPoder1;

    // Variáveis do Cartão 2
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;  // Alterado para unsigned long int
    float area2;
    float pib2; // em bilhões
    int atracoesTuristicas2;
    float densidade2;
    float pibPerCapita2;
    float superPoder2;

    // Entrada para o Cartão 1
    printf("Digite os dados para o Cartão 1:\n");
    
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    
    printf("Código (ex., A01): ");
    scanf("%3s", codigo1);
    
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade1);
    
    printf("População: ");
    scanf("%lu", &populacao1);  // %lu para unsigned long int
    
    printf("Área (km²): ");
    scanf("%f", &area1);
    
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);
    
    printf("Número de Atrações Turísticas: ");
    scanf("%d", &atracoesTuristicas1);

    // Calcular métricas do Cartão 1
    densidade1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000) / populacao1;
    superPoder1 = populacao1 + area1 + pib1 + atracoesTuristicas1 + pibPerCapita1 + (1/densidade1);

    // Entrada para o Cartão 2
    printf("\nDigite os dados para o Cartão 2:\n");
    
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    
    printf("Código (ex., B02): ");
    scanf("%3s", codigo2);
    
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", nomeCidade2);
    
    printf("População: ");
    scanf("%lu", &populacao2);  // %lu para unsigned long int
    
    printf("Área (km²): ");
    scanf("%f", &area2);
    
    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);
    
    printf("Número de Atrações Turísticas: ");
    scanf("%d", &atracoesTuristicas2);

    // Calcular métricas do Cartão 2
    densidade2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000) / populacao2;
    superPoder2 = populacao2 + area2 + pib2 + atracoesTuristicas2 + pibPerCapita2 + (1/densidade2);

    // Exibir informações do Cartão 1
    printf("\nCartão 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Atrações Turísticas: %d\n", atracoesTuristicas1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);
    printf("Super Poder: %.2f\n", superPoder1);

    // Exibir informações do Cartão 2
    printf("\nCartão 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Atrações Turísticas: %d\n", atracoesTuristicas2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
    printf("Super Poder: %.2f\n", superPoder2);

    // Comparação entre Cartões
    printf("\nComparação entre Cartões:\n");
    printf("População: Cartão %d venceu (%d)\n", (populacao1 > populacao2) ? 1 : 2, populacao1 > populacao2);
    printf("Área: Cartão %d venceu (%d)\n", (area1 > area2) ? 1 : 2, area1 > area2);
    printf("PIB: Cartão %d venceu (%d)\n", (pib1 > pib2) ? 1 : 2, pib1 > pib2);
    printf("Atrações Turísticas: Cartão %d venceu (%d)\n", (atracoesTuristicas1 > atracoesTuristicas2) ? 1 : 2, atracoesTuristicas1 > atracoesTuristicas2);
    printf("Densidade Populacional: Cartão %d venceu (%d)\n", (densidade1 < densidade2) ? 1 : 2, densidade1 < densidade2);
    printf("PIB per Capita: Cartão %d venceu (%d)\n", (pibPerCapita1 > pibPerCapita2) ? 1 : 2, pibPerCapita1 > pibPerCapita2);
    printf("Super Poder: Cartão %d venceu (%d)\n", (superPoder1 > superPoder2) ? 1 : 2, superPoder1 > superPoder2);

    return 0;
}

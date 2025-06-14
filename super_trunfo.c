#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
} CartaCidade;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibirMenu() {
    printf("\nMENU DE ATRIBUTOS\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Demográfica\n");
    printf("0. Sair\n");
    printf("Escolha o atributo para comparação: ");
}

void compararCartas(CartaCidade a, CartaCidade b) {
    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1: // População
                printf("\nComparação por População:\n");
                printf("%s: %lu habitantes\n", a.nomeCidade, a.populacao);
                printf("%s: %lu habitantes\n", b.nomeCidade, b.populacao);
                
                if(a.populacao > b.populacao) {
                    printf("Resultado: %s venceu!\n", a.nomeCidade);
                } else if(b.populacao > a.populacao) {
                    printf("Resultado: %s venceu!\n", b.nomeCidade);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;
                
            case 2: // Área
                printf("\nComparação por Área:\n");
                printf("%s: %.2f km²\n", a.nomeCidade, a.area);
                printf("%s: %.2f km²\n", b.nomeCidade, b.area);
                
                if(a.area > b.area) {
                    printf("Resultado: %s venceu!\n", a.nomeCidade);
                } else if(b.area > a.area) {
                    printf("Resultado: %s venceu!\n", b.nomeCidade);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;
                
            case 3: // PIB
                printf("\nComparação por PIB:\n");
                printf("%s: %.2f bilhões\n", a.nomeCidade, a.pib);
                printf("%s: %.2f bilhões\n", b.nomeCidade, b.pib);
                
                if(a.pib > b.pib) {
                    printf("Resultado: %s venceu!\n", a.nomeCidade);
                } else if(b.pib > a.pib) {
                    printf("Resultado: %s venceu!\n", b.nomeCidade);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;
                
            case 4: // Pontos Turísticos
                printf("\nComparação por Pontos Turísticos:\n");
                printf("%s: %d pontos\n", a.nomeCidade, a.pontosTuristicos);
                printf("%s: %d pontos\n", b.nomeCidade, b.pontosTuristicos);
                
                if(a.pontosTuristicos > b.pontosTuristicos) {
                    printf("Resultado: %s venceu!\n", a.nomeCidade);
                } else if(b.pontosTuristicos > a.pontosTuristicos) {
                    printf("Resultado: %s venceu!\n", b.nomeCidade);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;
                
            case 5: // Densidade Demográfica
                printf("\nComparação por Densidade Demográfica:\n");
                printf("%s: %.2f hab/km²\n", a.nomeCidade, a.densidade);
                printf("%s: %.2f hab/km²\n", b.nomeCidade, b.densidade);
                
                // Regra invertida para densidade (menor valor vence)
                if(a.densidade < b.densidade) {
                    printf("Resultado: %s venceu! (menos denso)\n", a.nomeCidade);
                } else if(b.densidade < a.densidade) {
                    printf("Resultado: %s venceu! (menos denso)\n", b.nomeCidade);
                } else {
                    printf("Resultado: Empate!\n");
                }
                break;
                
            case 0:
                printf("Saindo do programa...\n");
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 0);
}

int main() {
    CartaCidade carta1 = {'A', "A01", "São Paulo", 12300000, 1521.11, 699.28, 50};
    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao;

    CartaCidade carta2 = {'B', "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30};
    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao;

    printf("Cartas cadastradas:\n");
    printf("1. %s (%c)\n", carta1.nomeCidade, carta1.estado);
    printf("2. %s (%c)\n", carta2.nomeCidade, carta2.estado);

    compararCartas(carta1, carta2);

    return 0;
}

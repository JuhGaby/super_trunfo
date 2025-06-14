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

void exibirMenuAtributos(int atributoExcluido) {
    printf("\nMENU DE ATRIBUTOS\n");
    if (atributoExcluido != 1) printf("1. População\n");
    if (atributoExcluido != 2) printf("2. Área\n");
    if (atributoExcluido != 3) printf("3. PIB\n");
    if (atributoExcluido != 4) printf("4. Pontos Turísticos\n");
    if (atributoExcluido != 5) printf("5. Densidade Demográfica\n");
    printf("0. Voltar\n");
    printf("Escolha o atributo: ");
}

int escolherAtributo(int atributoExcluido) {
    int opcao;
    do {
        exibirMenuAtributos(atributoExcluido);
        scanf("%d", &opcao);
        limparBuffer();

        if (opcao == 0) return -1; // Opção para voltar
        
        // Verifica se o atributo é válido e não foi excluído
        if (opcao < 1 || opcao > 5 || opcao == atributoExcluido) {
            printf("Opção inválida ou atributo já selecionado. Tente novamente.\n");
            opcao = -1;
        }
    } while (opcao == -1);
    
    return opcao;
}

int compararAtributo(CartaCidade a, CartaCidade b, int atributo) {
    switch(atributo) {
        case 1: // População
            return a.populacao > b.populacao ? 1 : (a.populacao < b.populacao ? -1 : 0);
        case 2: // Área
            return a.area > b.area ? 1 : (a.area < b.area ? -1 : 0);
        case 3: // PIB
            return a.pib > b.pib ? 1 : (a.pib < b.pib ? -1 : 0);
        case 4: // Pontos Turísticos
            return a.pontosTuristicos > b.pontosTuristicos ? 1 : 
                   (a.pontosTuristicos < b.pontosTuristicos ? -1 : 0);
        case 5: // Densidade Demográfica (menor valor vence)
            return a.densidade < b.densidade ? 1 : (a.densidade > b.densidade ? -1 : 0);
        default:
            return 0;
    }
}

const char* nomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

void exibirValorAtributo(CartaCidade cidade, int atributo) {
    switch(atributo) {
        case 1: printf("%lu habitantes", cidade.populacao); break;
        case 2: printf("%.2f km²", cidade.area); break;
        case 3: printf("%.2f bilhões", cidade.pib); break;
        case 4: printf("%d pontos", cidade.pontosTuristicos); break;
        case 5: printf("%.2f hab/km²", cidade.densidade); break;
    }
}

void compararCartasAvancado(CartaCidade a, CartaCidade b) {
    int atributo1 = -1, atributo2 = -1;
    
    printf("\n=== COMPARAÇÃO AVANÇADA ===\n");
    
    // Escolha do primeiro atributo
    printf("\nEscolha o PRIMEIRO atributo:\n");
    atributo1 = escolherAtributo(-1);
    if (atributo1 == -1) return;
    
    // Escolha do segundo atributo (excluindo o primeiro)
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    atributo2 = escolherAtributo(atributo1);
    if (atributo2 == -1) return;
    
    // Comparação dos atributos
    printf("\n=== RESULTADOS DA COMPARAÇÃO ===\n");
    printf("Cidades: %s vs %s\n", a.nomeCidade, b.nomeCidade);
    
    // Comparação do primeiro atributo
    printf("\n[Atributo 1] %s:\n", nomeAtributo(atributo1));
    printf("%s: ", a.nomeCidade); exibirValorAtributo(a, atributo1); printf("\n");
    printf("%s: ", b.nomeCidade); exibirValorAtributo(b, atributo1); printf("\n");
    
    int resultado1 = compararAtributo(a, b, atributo1);
    printf("Resultado: %s\n", 
           resultado1 == 1 ? a.nomeCidade : 
           (resultado1 == -1 ? b.nomeCidade : "Empate"));
    
    // Comparação do segundo atributo
    printf("\n[Atributo 2] %s:\n", nomeAtributo(atributo2));
    printf("%s: ", a.nomeCidade); exibirValorAtributo(a, atributo2); printf("\n");
    printf("%s: ", b.nomeCidade); exibirValorAtributo(b, atributo2); printf("\n");
    
    int resultado2 = compararAtributo(a, b, atributo2);
    printf("Resultado: %s\n", 
           resultado2 == 1 ? a.nomeCidade : 
           (resultado2 == -1 ? b.nomeCidade : "Empate"));
    
    // Cálculo da soma dos atributos
    float somaA = 0, somaB = 0;
    
    // Normalização dos valores para soma (todos na mesma escala)
    somaA += (atributo1 == 1 ? a.populacao / 1000000.0 : 
             (atributo1 == 2 ? a.area : 
             (atributo1 == 3 ? a.pib : 
             (atributo1 == 4 ? a.pontosTuristicos * 10.0 : 
             (1000.0 - a.densidade)))));
    
    somaA += (atributo2 == 1 ? a.populacao / 1000000.0 : 
             (atributo2 == 2 ? a.area : 
             (atributo2 == 3 ? a.pib : 
             (atributo2 == 4 ? a.pontosTuristicos * 10.0 : 
             (1000.0 - a.densidade)))));
    
    somaB += (atributo1 == 1 ? b.populacao / 1000000.0 : 
             (atributo1 == 2 ? b.area : 
             (atributo1 == 3 ? b.pib : 
             (atributo1 == 4 ? b.pontosTuristicos * 10.0 : 
             (1000.0 - b.densidade)))));
    
    somaB += (atributo2 == 1 ? b.populacao / 1000000.0 : 
             (atributo2 == 2 ? b.area : 
             (atributo2 == 3 ? b.pib : 
             (atributo2 == 4 ? b.pontosTuristicos * 10.0 : 
             (1000.0 - b.densidade)))));
    
    printf("\nSoma ponderada dos atributos:\n");
    printf("%s: %.2f pontos\n", a.nomeCidade, somaA);
    printf("%s: %.2f pontos\n", b.nomeCidade, somaB);
    
    if (somaA > somaB) {
        printf("\nRESULTADO FINAL: %s venceu!\n", a.nomeCidade);
    } else if (somaB > somaA) {
        printf("\nRESULTADO FINAL: %s venceu!\n", b.nomeCidade);
    } else {
        printf("\nRESULTADO FINAL: Empate!\n");
    }
}

void menuPrincipal(CartaCidade a, CartaCidade b) {
    int opcao;
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Comparação simples (1 atributo)\n");
        printf("2. Comparação avançada (2 atributos)\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1:
                compararCartas(a, b);
                break;
            case 2:
                compararCartasAvancado(a, b);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);
}

int main() {
    CartaCidade carta1 = {'A', "A01", "São Paulo", 12300000, 1521.11, 699.28, 50};
    carta1.densidade = carta1.populacao / carta1.area;
    carta1.pibPerCapita = (carta1.pib * 1000000000) / carta1.populacao;

    CartaCidade carta2 = {'B', "B02", "Rio de Janeiro", 6748000, 1200.25, 300.50, 30};
    carta2.densidade = carta2.populacao / carta2.area;
    carta2.pibPerCapita = (carta2.pib * 1000000000) / carta2.populacao;

    printf("=== SUPER TRUNFO DE CIDADES ===\n");
    printf("Cartas cadastradas:\n");
    printf("1. %s (%c) - Código: %s\n", carta1.nomeCidade, carta1.estado, carta1.codigo);
    printf("2. %s (%c) - Código: %s\n", carta2.nomeCidade, carta2.estado, carta2.codigo);

    menuPrincipal(carta1, carta2);

    return 0;
}

#include <stdio.h>

typedef struct {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    unsigned long populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
} CartaCidade;

void lerCarta(CartaCidade *carta) {
    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);
    
    printf("Código (ex: A01): ");
    scanf("%3s", carta->codigo);
    
    printf("Nome da Cidade: ");
    scanf(" %49[^\n]", carta->nomeCidade);
    
    printf("População: ");
    scanf("%lu", &carta->populacao);
    
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    
    printf("PIB (em bilhões): ");
    scanf("%f", &carta->pib);
    
    printf("Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculos automáticos
    carta->densidade = (float)carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000) / carta->populacao;
}

void mostrarCarta(CartaCidade carta, int numero) {
    printf("\nCarta %d - %s (%c):\n", numero, carta.nomeCidade, carta.estado);
    printf("População: %lu\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade: %.2f hab/km²\n", carta.densidade);
    printf("PIB per capita: %.2f\n", carta.pibPerCapita);
}

void compararCartas(CartaCidade a, CartaCidade b) {
    // Escolha do atributo para comparação (definido no código)
    // Altere esta variável para comparar por diferentes atributos
    char atributoEscolhido = 'P'; // P=População, A=Área, I=PIB, D=Densidade, C=PIB per capita
    
    printf("\nComparação de cartas (");
    
    if(atributoEscolhido == 'P') {
        printf("Atributo: População)\n");
        mostrarCarta(a, 1);
        mostrarCarta(b, 2);
        
        if(a.populacao > b.populacao) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", a.nomeCidade);
        } else if(b.populacao > a.populacao) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", b.nomeCidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    }
    else if(atributoEscolhido == 'A') {
        printf("Atributo: Área)\n");
        mostrarCarta(a, 1);
        mostrarCarta(b, 2);
        
        if(a.area > b.area) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", a.nomeCidade);
        } else if(b.area > a.area) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", b.nomeCidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    }
    else if(atributoEscolhido == 'I') {
        printf("Atributo: PIB)\n");
        mostrarCarta(a, 1);
        mostrarCarta(b, 2);
        
        if(a.pib > b.pib) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", a.nomeCidade);
        } else if(b.pib > a.pib) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", b.nomeCidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    }
    else if(atributoEscolhido == 'D') {
        printf("Atributo: Densidade Populacional)\n");
        mostrarCarta(a, 1);
        mostrarCarta(b, 2);
        
        // Para densidade, o menor valor vence
        if(a.densidade < b.densidade) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", a.nomeCidade);
        } else if(b.densidade < a.densidade) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", b.nomeCidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    }
    else if(atributoEscolhido == 'C') {
        printf("Atributo: PIB per capita)\n");
        mostrarCarta(a, 1);
        mostrarCarta(b, 2);
        
        if(a.pibPerCapita > b.pibPerCapita) {
            printf("\nResultado: Carta 1 (%s) venceu!\n", a.nomeCidade);
        } else if(b.pibPerCapita > a.pibPerCapita) {
            printf("\nResultado: Carta 2 (%s) venceu!\n", b.nomeCidade);
        } else {
            printf("\nResultado: Empate!\n");
        }
    }
}

int main() {
    CartaCidade carta1, carta2;
    
    printf("Cadastro da Carta 1:\n");
    lerCarta(&carta1);
    
    printf("\nCadastro da Carta 2:\n");
    lerCarta(&carta2);
    
    compararCartas(carta1, carta2);

    return 0;
}

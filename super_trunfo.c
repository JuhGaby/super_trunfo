// Variáveis do Cartão 2
char estado2;
char codigo2[4];
char nomeCidade2[50];
int populacao2;
float area2;
float pib2;
int atracoesTuristicas2;

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

// Exibir informações do Cartão 1
printf("\nCartão 1:\n");
printf("Estado: %c\n", estado1);
printf("Código: %s\n", codigo1);
printf("Nome da Cidade: %s\n", nomeCidade1);
printf("População: %d\n", populacao1);
printf("Área: %.2f km²\n", area1);
printf("PIB: %.2f bilhões de reais\n", pib1);
printf("Número de Atrações Turísticas: %d\n", atracoesTuristicas1);

// Exibir informações do Cartão 2
printf("\nCartão 2:\n");
printf("Estado: %c\n", estado2);
printf("Código: %s\n", codigo2);
printf("Nome da Cidade: %s\n", nomeCidade2);
printf("População: %d\n", populacao2);
printf("Área: %.2f km²\n", area2);
printf("PIB: %.2f bilhões de reais\n", pib2);
printf("Número de Atrações Turísticas: %d\n", atracoesTuristicas2);

return 0;

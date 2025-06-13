#include <stdio.h>

int main() {
    // Card 1 variables
    char state1;
    char code1[4];
    char cityName1[50];
    int population1;
    float area1;
    float gdp1;
    int touristAttractions1;

    // Card 2 variables
    char state2;
    char code2[4];
    char cityName2[50];
    int population2;
    float area2;
    float gdp2;
    int touristAttractions2;

    // Input for Card 1
    printf("Enter data for Card 1:\n");
    
    printf("State (A-H): ");
    scanf(" %c", &state1);
    
    printf("Code (e.g., A01): ");
    scanf("%3s", code1);
    
    printf("City Name: ");
    scanf(" %49[^\n]", cityName1);
    
    printf("Population: ");
    scanf("%d", &population1);
    
    printf("Area (km²): ");
    scanf("%f", &area1);
    
    printf("GDP (in billions of reais): ");
    scanf("%f", &gdp1);
    
    printf("Number of Tourist Attractions: ");
    scanf("%d", &touristAttractions1);

    // Input for Card 2
    printf("\nEnter data for Card 2:\n");
    
    printf("State (A-H): ");
    scanf(" %c", &state2);
    
    printf("Code (e.g., B02): ");
    scanf("%3s", code2);
    
    printf("City Name: ");
    scanf(" %49[^\n]", cityName2);
    
    printf("Population: ");
    scanf("%d", &population2);
    
    printf("Area (km²): ");
    scanf("%f", &area2);
    
    printf("GDP (in billions of reais): ");
    scanf("%f", &gdp2);
    
    printf("Number of Tourist Attractions: ");
    scanf("%d", &touristAttractions2);

    // Display Card 1 information
    printf("\nCard 1:\n");
    printf("State: %c\n", state1);
    printf("Code: %s\n", code1);
    printf("City Name: %s\n", cityName1);
    printf("Population: %d\n", population1);
    printf("Area: %.2f km²\n", area1);
    printf("GDP: %.2f billion reais\n", gdp1);
    printf("Number of Tourist Attractions: %d\n", touristAttractions1);

    // Display Card 2 information
    printf("\nCard 2:\n");
    printf("State: %c\n", state2);
    printf("Code: %s\n", code2);
    printf("City Name: %s\n", cityName2);
    printf("Population: %d\n", population2);
    printf("Area: %.2f km²\n", area2);
    printf("GDP: %.2f billion reais\n", gdp2);
    printf("Number of Tourist Attractions: %d\n", touristAttractions2);

    return 0;
}
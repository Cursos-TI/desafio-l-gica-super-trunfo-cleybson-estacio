#include <stdio.h>
#include <string.h>

// Função de comparação entre as cartas
// Quando o atributo for densidade, será passado 1/densidade, entao quanto maior o numero, menor o resultado da divisao
void compararCartas(
    char cidade1[], char estado1[], float valor1,
    char cidade2[], char estado2[], float valor2,
    char atributo[])
{
  printf("\nComparação de cartas (Atributo: %s):\n\n", atributo);
  printf("Carta 1 - %s (%s): %.2f\n", cidade1, estado1, valor1);
  printf("Carta 2 - %s (%s): %.2f\n", cidade2, estado2, valor2);

  if (valor1 > valor2)
  {
    printf("\nResultado: Carta 1 (%s) venceu!\n", cidade1);
  }
  else if (valor2 > valor1)
  {
    printf("\nResultado: Carta 2 (%s) venceu!\n", cidade2);
  }
  else
  {
    printf("\nResultado: Empate!\n");
  }
}

float calcSuperPoder(unsigned long int populacao, float area, float pib, int qtdTurismo, float pibPerCapita, float densidadeP) {
  return (float) populacao + area + pib + qtdTurismo + pibPerCapita + densidadeP;
}

int main()
{
  // Carta 1
  char estado1[50], codigo1[10], cidade1[50];
  unsigned long int populacao1;
  int pontosTuristicos1;
  float area1, pib1;
  float densidade1, pibPerCapita1, superPoder1;

  // Carta 2
  char estado2[50], codigo2[10], cidade2[50];
  unsigned long int populacao2;
  int pontosTuristicos2;
  float area2, pib2;
  float densidade2, pibPerCapita2, superPoder2;

  // Entrada dos dados da carta 1
  printf("Digite os dados da Carta 1:\n");

  printf("Estado: ");
  scanf(" %[^\n]", estado1);

  printf("Código da carta: ");
  scanf(" %[^\n]", codigo1);

  printf("Nome da cidade: ");
  scanf(" %[^\n]", cidade1);

  printf("População: ");
  scanf("%lu", &populacao1);

  printf("Área (km²): ");
  scanf("%f", &area1);

  printf("PIB: ");
  scanf("%f", &pib1);

  printf("Número de pontos turísticos: ");
  scanf("%d", &pontosTuristicos1);

  // Cálculos carta 1
  densidade1 = populacao1 / area1;
  pibPerCapita1 = pib1 / populacao1;
  superPoder1 = calcSuperPoder(populacao1, area1, pib1, pontosTuristicos1, pibPerCapita1, 1/densidade1);

  // Entrada dos dados da carta 2
  printf("\nDigite os dados da Carta 2:\n");

  printf("Estado: ");
  scanf(" %[^\n]", estado2);

  printf("Código da carta: ");
  scanf(" %[^\n]", codigo2);

  printf("Nome da cidade: ");
  scanf(" %[^\n]", cidade2);

  printf("População: ");
  scanf("%lu", &populacao2);

  printf("Área (km²): ");
  scanf("%f", &area2);

  printf("PIB: ");
  scanf("%f", &pib2);

  printf("Número de pontos turísticos: ");
  scanf("%d", &pontosTuristicos2);

  // Cálculos carta 2
  densidade2 = populacao2 / area2;
  pibPerCapita2 = pib2 / populacao2;
  superPoder2 = calcSuperPoder(populacao2, area2, pib2, pontosTuristicos2, pibPerCapita2, 1/densidade2);

  // Atributo escolhido para comparação
  char atributoEscolhido[] = "populacao2";

  // Chamada da função para comparar
  compararCartas(cidade1, estado1, populacao1,
                 cidade2, estado2, populacao2,
                 atributoEscolhido);

  return 0;
}

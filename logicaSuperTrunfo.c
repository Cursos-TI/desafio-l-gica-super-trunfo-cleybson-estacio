#include <stdio.h>
#include <string.h>

// Função para exibir o menu e retornar a escolha
int exibirMenu()
{
  int opcao;
  printf("\n=== MENU DE COMPARAÇÃO DE CARTAS ===\n");
  printf("1 - População\n");
  printf("2 - Área\n");
  printf("3 - PIB\n");
  printf("4 - Pontos Turísticos\n");
  printf("5 - PIB per capita\n");
  printf("6 - Densidade Populacional (menor vence)\n");
  printf("7 - Super Poder (soma dos atributos)\n");
  printf("Escolha o atributo para comparar (1 a 7): ");
  scanf("%d", &opcao);
  return opcao;
}

// Função de comparação entre as cartas
// Quando o atributo for densidade, será passado 1/densidade, então quanto maior o número, menor a densidade original
void compararCartas(
    char cidade1[], char estado1[], float valor1,
    char cidade2[], char estado2[], float valor2,
    char atributo[], short int inverso)
{
  printf("\nComparação de cartas (Atributo: %s):\n\n", atributo);
  printf("Carta 1 - %s (%s): %.2f\n", cidade1, estado1, valor1);
  printf("Carta 2 - %s (%s): %.2f\n", cidade2, estado2, valor2);

  if (inverso)
  {
    if (valor1 < valor2)
    {
      printf("\nResultado: Carta 1 (%s) venceu!\n", cidade1);
    }
    else if (valor2 < valor1)
    {
      printf("\nResultado: Carta 2 (%s) venceu!\n", cidade2);
    }
    else
    {
      printf("\nResultado: Empate!\n");
    }
  }
  else
  {
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
}

// Função que calcula o "super poder" da carta
float calcSuperPoder(unsigned long int populacao, float area, float pib, int qtdTurismo, float pibPerCapita, float inversoDensidade)
{
  return (float)populacao + area + pib + qtdTurismo + pibPerCapita - inversoDensidade;
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
  superPoder1 = calcSuperPoder(populacao1, area1, pib1, pontosTuristicos1, pibPerCapita1, densidade1);

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
  superPoder2 = calcSuperPoder(populacao2, area2, pib2, pontosTuristicos2, pibPerCapita2, densidade2);

  // Obtenção da escolha do usuário
  int opcao = exibirMenu();

  // Processamento conforme opção
  switch (opcao)
  {
  case 1:
    compararCartas(cidade1, estado1, (float)populacao1,
                   cidade2, estado2, (float)populacao2,
                   "População", 0);
    break;
  case 2:
    compararCartas(cidade1, estado1, area1,
                   cidade2, estado2, area2,
                   "Área", 0);
    break;
  case 3:
    compararCartas(cidade1, estado1, pib1,
                   cidade2, estado2, pib2,
                   "PIB", 0);
    break;
  case 4:
    compararCartas(cidade1, estado1, (float)pontosTuristicos1,
                   cidade2, estado2, (float)pontosTuristicos2,
                   "Pontos Turísticos", 0);
    break;
  case 5:
    compararCartas(cidade1, estado1, pibPerCapita1,
                   cidade2, estado2, pibPerCapita2,
                   "PIB per capita", 0);
    break;
  case 6:
    compararCartas(cidade1, estado1, densidade1,
                   cidade2, estado2, densidade2,
                   "Densidade Populacional", 1);
    break;
  case 7:
    compararCartas(cidade1, estado1, superPoder1,
                   cidade2, estado2, superPoder2,
                   "Super Poder", 0);
    break;
  default:
    printf("\nOpção inválida! Encerrando o programa.\n");
    break;
  }

  return 0;
}

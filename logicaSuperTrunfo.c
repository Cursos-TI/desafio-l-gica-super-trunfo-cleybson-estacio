#include <stdio.h>
#include <string.h>

// Função para exibir o menu e retornar a escolha
// Exibe o menu principal e retorna a opção escolhida
int exibirMenu(char titulo[], int atributoBloqueado)
{
  int opcao;
  printf("\n%s\n", titulo);
  for (int i = 1; i <= 6; i++)
  {
    if (i == atributoBloqueado)
      continue;

    switch (i)
    {
    case 1:
      printf("1 - População\n");
      break;
    case 2:
      printf("2 - Área\n");
      break;
    case 3:
      printf("3 - PIB\n");
      break;
    case 4:
      printf("4 - Pontos Turísticos\n");
      break;
    case 5:
      printf("5 - PIB per capita\n");
      break;
    case 6:
      printf("6 - Densidade Populacional\n");
      break;
    }
  }
  printf("Escolha uma opção: ");
  scanf("%d", &opcao);
  return opcao;
}

int escolherSegundoAtributo(int atributo1)
{
  int opcao = exibirMenu("Escolha o segundo atributo (diferente do primeiro):", atributo1);
  if (opcao == atributo1)
  {
    printf("Você já escolheu esse atributo. Escolha outro.\n");
    return escolherSegundoAtributo(atributo1); // chamada recursiva
  }
  return opcao;
}

// Retorna o nome do atributo
char *nomeAtributo(int opcao)
{
  switch (opcao)
  {
  case 1: return "População";
  case 2: return "Área";
  case 3: return "PIB";
  case 4: return "Pontos Turísticos";
  case 5: return "PIB per capita";
  case 6: return "Densidade Populacional";
  default: return "Atributo inválido";
  }
}

// Função de comparação entre as cartas
void compararCartas(
    char cidade1[], char estado1[], float valor1A, float valor1B,
    char cidade2[], char estado2[], float valor2A, float valor2B,
    int atributo1, int atributo2)
{
  if (atributo1 == 6)
  {
    valor1A = valor1A * -1; // Inverte a densidade para comparação
    valor2A = valor2A * -1; // Inverte a densidade para comparação
  }

  if (atributo2 == 6)
  {
    valor1B = valor1B * -1; // Inverte a densidade para comparação
    valor2B = valor2B * -1; // Inverte a densidade para comparação
  }

  float soma1 = valor1A + valor1B;
  float soma2 = valor2A + valor2B;

  // Exibição dos resultados
  printf("\n===== Comparação das Cartas =====\n\n");

  printf("Carta 1 - %s (%s):\n", cidade1, estado1);
  printf("- %s: %.2f\n", nomeAtributo(atributo1), valor1A);
  printf("- %s: %.2f\n", nomeAtributo(atributo2), valor1B);
  printf("- Soma ponderada: %.2f\n\n", soma1);

  printf("Carta 2 - %s (%s):\n", cidade2, estado2);
  printf("- %s: %.2f\n", nomeAtributo(atributo1), valor2A);
  printf("- %s: %.2f\n", nomeAtributo(atributo2), valor2B);
  printf("- Soma ponderada: %.2f\n\n", soma2);

  // Resultado final
  printf("Resultado: %s\n",
         soma1 > soma2 ? cidade1 : soma2 > soma1 ? cidade2
                                                 : "Empate!");
}

// Função que calcula o "super poder" da carta
float calcSuperPoder(unsigned long int populacao, float area, float pib, int qtdTurismo, float pibPerCapita, float inversoDensidade)
{
  return (float)populacao + area + pib + qtdTurismo + pibPerCapita - inversoDensidade;
}

// Obtém o valor numérico de um atributo
float obterValorAtributo(int opcao, unsigned long int pop, float area, float pib, int turismo, float pibPerCapita, float densidade)
{
  switch (opcao)
  {
  case 1:
    return (float)pop;
  case 2:
    return area;
  case 3:
    return pib;
  case 4:
    return (float)turismo;
  case 5:
    return pibPerCapita;
  case 6:
    return densidade;
  default:
    return 0;
  }
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

  // Escolha dos dois atributos
  int atributo1 = exibirMenu("Escolha o primeiro atributo para comparação:", 0);
  int atributo2 = escolherSegundoAtributo(atributo1);

  // Obtenção dos valores dos atributos
  float valor1A = obterValorAtributo(atributo1, populacao1, area1, pib1, pontosTuristicos1, pibPerCapita1, densidade1);
  float valor2A = obterValorAtributo(atributo1, populacao2, area2, pib2, pontosTuristicos2, pibPerCapita2, densidade2);

  float valor1B = obterValorAtributo(atributo2, populacao1, area1, pib1, pontosTuristicos1, pibPerCapita1, densidade1);
  float valor2B = obterValorAtributo(atributo2, populacao2, area2, pib2, pontosTuristicos2, pibPerCapita2, densidade2);

  compararCartas(cidade1, estado1, valor1A, valor1B,
                 cidade2, estado2, valor2A, valor2B,
                 atributo1, atributo2);
  return 0;
}

#include <stdio.h>
#include <string.h>

    // Definição da Estrutura da Carta
    typedef struct {
    char nome[50];
    char codigo[10];
    char estado[50];

    // Atributos de entrada
    unsigned long int populacao;
    float area;
    float pib_bilhoes;
    int pontos_turisticos;
     // Atributos calculados

    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

// --- FUNÇÕES DE LÓGICA ---

// Função para calcular atributos derivados (Densidade, PIB Per Capita e Super Poder).
void calcular_atributos(Carta *c) {

    // Calcular Densidade Populacional: População / Área
    if (c->area > 0)
    // Casting para float para o cálculo
        c->densidade_populacional = (float)c->populacao / c->area;
    else
        c->densidade_populacional = 0;

    // Calcular PIB per Capita: (PIB Total) / População
    // Primeiro, converte o PIB de Bilhões para o valor total  

    float pib_total = c->pib_bilhoes * 1000000000.0;
    if (c->populacao > 0)
        c->pib_per_capita = pib_total / (float)c->populacao;
    else
        c->pib_per_capita = 0;

    // Calcular Super Poder 
    // Para simplificar e evitar somar um número grande (PIB total), soma o PIB em bilhões

    float inverso_densidade = (c->densidade_populacional > 0) ? (1.0 / c->densidade_populacional) : 0.0;

    c->super_poder = (float)c->populacao + c->area + c->pib_bilhoes +
                     (float)c->pontos_turisticos + c->pib_per_capita + inverso_densidade;
}

// Função para exibir atributo escolhido
float obter_valor(Carta c, int opcao) {
    switch (opcao) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib_bilhoes;
        case 4: return (float)c.pontos_turisticos;
        case 5: return c.densidade_populacional;
        case 6: return c.pib_per_capita;
        case 7: return c.super_poder;
        default: return 0;
    }
}

// Função para mostrar o nome do atributo
const char* nome_atributo(int opcao) {
    switch (opcao) {
        case 1: return "Populacao";
        case 2: return "Area";
        case 3: return "PIB (bilhoes)";
        case 4: return "Pontos Turisticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per Capita";
        case 7: return "Super Poder";
        default: return "Invalido";
    }
}

// --- PROGRAMA PRINCIPAL ---
int main() {
// Declaração das estruturas    
    Carta carta1, carta2;

    // Carta 1 - (Natal) RN
    strcpy(carta1.estado, "RN");
    strcpy(carta1.codigo, "A01");
    strcpy(carta1.nome, "Natal");
    carta1.populacao = 3455236;
    carta1.area = 52809.601;
    carta1.pib_bilhoes = 9.76;
    carta1.pontos_turisticos = 18;

    // Carta 2 - (Fortaleza) CEARA
    strcpy(carta2.estado, "CE");
    strcpy(carta2.codigo, "B02");
    strcpy(carta2.nome, "Fortaleza");
    carta2.populacao = 9268836;
    carta2.area = 1488944.0;
    carta2.pib_bilhoes = 2055.0;
    carta2.pontos_turisticos = 20;

    // Cálculo de todos os atributos.
    calcular_atributos(&carta1);
    calcular_atributos(&carta2);

    // Exibição dos Dados Finais
    printf("\n=== SUPER TRUNFO FINAL ===\n");
    printf("Cartas em batalha:\n1. %s (%s)\n2. %s (%s)\n\n", carta1.nome, carta1.estado, carta2.nome, carta2.estado);

    //Menu
    int atributo1, atributo2;

    printf("Escolha o primeiro atributo para comparar:\n");
    printf("1. Populacao\n2. Area\n3. PIB (bilhoes)\n4. Pontos Turisticos\n5. Densidade Populacional\n6. PIB per Capita\n7. Super Poder\n> ");
    scanf("%d", &atributo1);

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 7; i++) {
        if (i != atributo1)
            printf("%d. %s\n", i, nome_atributo(i));
    }
    printf("> ");
    scanf("%d", &atributo2);

    if (atributo1 == atributo2 || atributo1 < 1 || atributo1 > 7 || atributo2 < 1 || atributo2 > 7) {
        printf("\n Opções inválidas. Tente novamente.\n");
        return 0;
    }

    // Comparações
    float valor1a = obter_valor(carta1, atributo1);
    float valor2a = obter_valor(carta2, atributo1);
    float valor1b = obter_valor(carta1, atributo2);
    float valor2b = obter_valor(carta2, atributo2);

    // Exceção: Densidade Populacional (menor vence)
    int carta1_v1 = (atributo1 == 5) ? (valor1a < valor2a) : (valor1a > valor2a);
    int carta1_v2 = (atributo2 == 5) ? (valor1b < valor2b) : (valor1b > valor2b);

    float soma1 = valor1a + valor1b;
    float soma2 = valor2a + valor2b;

    printf("\n=== RESULTADO DA BATALHA ===\n");
    printf("Atributos escolhidos: %s e %s\n\n", nome_atributo(atributo1), nome_atributo(atributo2));

    printf("%s -> %.2f | %.2f | Soma: %.2f\n", carta1.nome, valor1a, valor1b, soma1);
    printf("%s -> %.2f | %.2f | Soma: %.2f\n\n", carta2.nome, valor2a, valor2b, soma2);

    if (soma1 == soma2)
        printf("Empate!\n");
    else
        printf("%s venceu a rodada! %s\n",
               (soma1 > soma2) ? carta1.nome : carta2.nome,
               (soma1 > soma2) ? "🏆" : "😢");

    return 0;
}


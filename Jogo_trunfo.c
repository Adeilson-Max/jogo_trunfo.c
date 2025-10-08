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

// Função para calcular os atributos derivados (Densidade, PIB Per Capita e Super Poder)
void calcular_atributos(Carta *c) {
    
    // Calcular Densidade Populacional: População / Área
    if (c->area > 0) {
        // Casting para float para o cálculo
        c->densidade_populacional = (float)c->populacao / c->area;
    } else {
        c->densidade_populacional = 0;
    }

    // Calcular PIB per Capita: (PIB Total) / População
    // Primeiro, converte o PIB de Bilhões para o valor total
    float pib_total = c->pib_bilhoes * 1000000000.0; 
    
    if (c->populacao > 0) {
        c->pib_per_capita = pib_total / (float)c->populacao;
    } else {
        c->pib_per_capita = 0;
    }

    // Calcular Super Poder
     
    // Para simplificar e evitar somar um número grande (PIB total), soma o PIB em bilhões
    float inverso_densidade = (c->densidade_populacional > 0) ? (1.0 / c->densidade_populacional) : 0.0;
    
    c->super_poder = 
        (float)c->populacao + 
        c->area + 
        c->pib_bilhoes + 
        (float)c->pontos_turisticos + 
        c->pib_per_capita + 
        inverso_densidade;
}

// Função para exibir o resultado da comparação no formato exigido
void exibir_resultado_comparacao(const char *atributo, int carta1_venceu) {
    printf("%s: ", atributo);
    if (carta1_venceu) {
        printf("Carta 1 venceu (1)\n");
    } else {
        printf("Carta 2 venceu (0)\n");
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
    strcpy(carta2.estado, "Ceara");
    strcpy(carta2.codigo, "B02");
    strcpy(carta2.nome, "Fortaleza");
    carta2.populacao = 9268836;
    carta2.area = 1488944.0;
    carta2.pib_bilhoes = 2055.0; 
    carta2.pontos_turisticos = 20;

    // Cálculo de todos os atributos derivados
    calcular_atributos(&carta1);
    calcular_atributos(&carta2);

    // Exibição dos Dados Finais
    printf("\n--- Dados Finais da Carta 1 (%s) ---\n", carta1.nome);
    printf("Populacao: %lu , Area: %.2f , PIB: %.2f (bilhoes) , Pontos: %d\n", 
           carta1.populacao, carta1.area, carta1.pib_bilhoes, carta1.pontos_turisticos);
    printf("Densidade: %.2f hab/km² , PIB/Capita: %.2f R$ , Super Poder: %.2f\n", 
           carta1.densidade_populacional, carta1.pib_per_capita, carta1.super_poder);
           
    printf("\n--- Dados Finais da Carta 2 (%s) ---\n", carta2.nome);
    printf("Populacao: %lu , Area: %.2f , PIB: %.2f (bilhoes) , Pontos: %d\n", 
           carta2.populacao, carta2.area, carta2.pib_bilhoes, carta2.pontos_turisticos);
    printf("Densidade: %.2f hab/km² , PIB/Capita: %.2f R$ , Super Poder: %.2f\n", 
           carta2.densidade_populacional, carta2.pib_per_capita, carta2.super_poder);

    // Comparação Atributo por Atributo
    printf("\n\n--- Resultado da Batalha (Comparacao de Cartas) ---\n");

    // 1. População (MAIOR valor vence)
    exibir_resultado_comparacao("Populacao", carta1.populacao > carta2.populacao);

    // 2. Area (MAIOR valor vence)
    exibir_resultado_comparacao("Area", carta1.area > carta2.area);

    // 3. PIB (MAIOR valor vence)
    exibir_resultado_comparacao("PIB (bilhoes)", carta1.pib_bilhoes > carta2.pib_bilhoes);

    // 4. Pontos Turísticos (MAIOR valor vence)
    exibir_resultado_comparacao("Pontos Turisticos", carta1.pontos_turisticos > carta2.pontos_turisticos);
    
    // 5. Densidade Populacional (ATENÇÃO: MENOR valor vence)
    exibir_resultado_comparacao("Densidade Populacional", carta1.densidade_populacional < carta2.densidade_populacional);
    
    // 6. PIB per Capita (MAIOR valor vence)
    exibir_resultado_comparacao("PIB per Capita", carta1.pib_per_capita > carta2.pib_per_capita);

    // 7. Super Poder (MAIOR valor vence)
    exibir_resultado_comparacao("Super Poder", carta1.super_poder > carta2.super_poder);

    return 0;
}

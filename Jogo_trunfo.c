#include <stdio.h>

int main() {
    //Carta 01
    char estado1[]= "RN";
    char codigo_da_carta1[]= "A01";
    char nome_da_cidade1[]= "Natal";
    int populacao1= 3455236;
    float area_em_km1= 52809.601;
    float pib_valor_bilhoes1= 9.76;
    int numero_de_pontos_turistico1= 18;

    // cálculos
    float densidade_populacional1 = (float) populacao1 / area_em_km1;
    float pib_per_capita1 = (pib_valor_bilhoes1 * 1000000000) / populacao1;

    printf("Densidade populacional: %.2f hab/km²\n", densidade_populacional1);
    printf("PIB per capita: %.2f R$\n", pib_per_capita1);


    //leitura carta 01
    printf("cadastro carta A01:\n");
    printf("estado: %s\n", estado1);
    scanf("%s", estado1);

    printf("codigo_da_carta: %s\n", codigo_da_carta1);
    scanf("%s", codigo_da_carta1);

    printf("nome_da_cidade: %s\n", nome_da_cidade1);
    scanf("%s", nome_da_cidade1);

    printf("populacao: %d\n", populacao1);
    scanf("%d", &populacao1);

    printf("area_em_km: %2f km²\n", area_em_km1);
    scanf("%f", &area_em_km1);

    printf("PIB: %.1f bilhoes\n", pib_valor_bilhoes1);
    scanf("%f", &pib_valor_bilhoes1);

    printf("numero_de_pontos_turisticos: %d\n", numero_de_pontos_turistico1);
    scanf("%d", &numero_de_pontos_turistico1);

     //carta 02 
    char estado2[]= "Ceara";
    char codigo_da_carta2[]= "B02";
    char nome_da_cidade2[]= "Fortaleza";
    int  populacao2= 9268836;
    float area_em_km2= 1488944;
    float pib_valor_bilhoes2= 2055;
    int  numero_de_pontos_turistico2= 20;
   
     // cálculos
    float densidade_populacional2 = (float) populacao2 / area_em_km2;
    float pib_per_capita2 = (pib_valor_bilhoes2 * 1000000000) / populacao2;

    printf("Densidade populaciona2: %.2f hab/km²\n", densidade_populacional2);
    printf("PIB per capita2cod: %.2f R$\n", pib_per_capita2);

    //leitura carta 02
    printf("cadastro carta B02:\n");
    printf("estado: %s\n", estado2);
    scanf("%s", estado2);

    printf("codigo_da_carta: %s\n", codigo_da_carta2);
    scanf("%s", codigo_da_carta2);

    printf("nome_da_cidade: %s\n", nome_da_cidade2);
    scanf("%s", nome_da_cidade2);

    printf("populacao: %d\n", populacao2);
    scanf("%d", &populacao2);

    printf("area_em_km: %2f km²\n", area_em_km2);
    scanf("%f", &area_em_km2);

    printf("PIB: %.1f bilhoes\n", pib_valor_bilhoes2);
    scanf("%f", &pib_valor_bilhoes2);

    printf("numero_de_pontos_turisticos: %d\n", numero_de_pontos_turistico2);
    scanf("%d", &numero_de_pontos_turistico2);

     

    return 0;

}
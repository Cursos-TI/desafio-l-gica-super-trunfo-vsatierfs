#include <stdio.h>
#include <stdlib.h>

//variaveis globais para uso das funções auxiliares
int carta1 = 0, carta2 = 0;
char nomeCidade1[100], nomeCidade2[100];

//funções de comparação
int ComparaFloat (float x, float y) {
    if (x > y) {
       return 1;
        carta1++;
    } else if (y > x) {
        return 2;
        carta2++;
    } else {
        return 0;
    }
    return 0;
}

int ComparaINT(int x, int y) {
    if (x > y) {
        return 1;
        carta1++;
    } else if (y > x) {
        return 2;
        carta2++;
    } else {
        return 0;
    }
     return 0;
}
//compração densidade populacional separada pois tem lógica inversa as outras
int ComparaDensidadePopulacional(float x, float y) {
    if (x < y) {
        return 1;
    } else if (y < x) {
        return 2;
    } else {
        return 0;
    }
    return 0;
}

//função para calculo do resultado das comparações para rodada
int Resultado(int x, int y) {
    if (x == 1 && y == 1) {
        printf("A carta 1 %s ganhou em ambos os atributos\n", nomeCidade1);
        carta1++;
    } else if (x == 2 && y == 2) {
        printf("A carta 2 %s ganhou em ambos os atributos\n", nomeCidade2);
        carta2++;
    } else {
        printf("Empate!\n");
    }

}
//calculo resultado final
int ResFinal(void) {
    if (carta1 > carta2) {
        printf("Carta 1 %s venceu!\n", nomeCidade1);
    } else if (carta2 > carta1) {
        printf("Carta 2 %s venceu!\n", nomeCidade2);
    } else {
        printf("Empate!\n");
    }
}

int main() {
    char estado1, estado2;
    char codigoEstado1[5], codigoEstado2[5];
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    float PIBperCapita1, PIBperCapita2;
    float  densidadePopulacional1, densidadePopulacional2;
    int pontoTuristico1, pontoTuristico2;
    int atributo1, atributo2;
    int resultado1, resultado2;


    //cadastramento primeira carta
    printf("Insira as informacoes da primeira carta:\n"); 
    printf("Nome do estado (letra de 'A' a 'H'): \n");
    scanf(" %c", &estado1);
    printf("Codigo da carta (letra do estado e um numero de 01 a 04): \n");
    scanf("%4s", codigoEstado1);
    printf("Nome da cidade: \n");
    scanf(" %[^\n]", nomeCidade1);
    printf("Populacao: \n");
    scanf("%lu", &populacao1);
    printf("Area:  \n");
    scanf("%f", &area1);
    printf("PIB:  \n ");
    scanf("%f", &pib1);
    printf("Numero de pontos turisticos: \n ");
    scanf("%d", &pontoTuristico1);

    //calculo densidade populacional carta 1
    if (area1 == 0.0f) {
        printf("Area igual a zero, densidade definida como 0.00\n");
    } else {
        densidadePopulacional1 = (float)populacao1 / area1;
    }
    //calculo PIB per capita carta 1
    if (pib1 == 0.0f) {
        printf("PIB igual a zero, PIB per capita definido como 0.00\n");
    } else {
        PIBperCapita1 = (pib1 * 1000000000.0) / (float)populacao1;
    }
    //superpoder carta 1
    float superPoder1 = populacao1 + area1 + pontoTuristico1 + pib1 + PIBperCapita1 + (1.0/densidadePopulacional1);

    //cadastramento segunda carta
    printf("Insira as informacoes da segunda carta:\n"); 
    printf("Nome do estado (letra de 'A' a 'H'):\n");
    scanf(" %c", &estado2);
    printf("Codigo da carta (letra do estado e um numero de 01 a 04): \n");
    scanf("%4s", codigoEstado2);
    printf("Nome da cidade: \n");
    scanf(" %[^\n]", nomeCidade2);
    printf("Populacao: \n");
    scanf("%lu", &populacao2);
    printf("Area:  \n");
    scanf("%f", &area2);
    printf("PIB:  \n ");
    scanf("%f", &pib2);
    printf("Numero de pontos turisticos: \n ");
    scanf("%d", &pontoTuristico2);

    //calculo densidade populacional carta 2
    if (area2 == 0.0f) {
        printf("Area igual a zero, densidade definida como 0.00\n");
    } else {
        densidadePopulacional2 = (float)populacao2 / area2;
    }
    //calculo PIB per capita carta 2
    if (pib2 == 0.0f) {
        printf("PIB igual a zero, PIB per capita definido como 0.00\n");
    } else {
        PIBperCapita2 = (pib2 * 1000000000.0) / (float)populacao2;
    }
    //superpoder carta 2
    float superPoder2 = populacao2 + area2 + pontoTuristico2 + pib2 + PIBperCapita2 + (1.0/densidadePopulacional2);

    //dados primeira carta
    printf("Carta 1\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo do estado: %s\n", codigoEstado1);
    printf("Nome da cidade: %s\n", nomeCidade1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f\ km²\n", area1);
    printf("PIB: R$%.2f\n", pib1);
    printf("Numero de pontos turisticos: %d\n", pontoTuristico1);
    printf("Densidade populacional: %.2f habitantes por km^2\n", densidadePopulacional1);
    printf("PIB per capita: R$%.2f\n", PIBperCapita1);
    printf("\n--------------\n");
 
    //dados segunda carta
    printf("Carta 2\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo do estado: %s\n", codigoEstado2);
    printf("Nome da cidade: %s\n", nomeCidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: R$%.2f\n", pib2);
    printf("Numero de pontos turisticos: %d\n", pontoTuristico2);
    printf("Densidade populacional: %.2f\ habitantes por km^2\n", densidadePopulacional2);
    printf("PIB per capita: R$%.2f\n", PIBperCapita2);
    printf("\n");

    //escolha de atributos para comparação
    printf("Comparacao entre cartas:\n");
    printf("Escolha dois atributos para realizar a comparacao\nPrimeiro atributo: \n");

    printf("1. Comparar populacao\n");
    printf("2. Comparar area\n");
    printf("3. Comparar PIB\n");
    printf("4. Comparar pontos turisticos\n");
    printf("5. Comparar densidade populacional\n");
    printf("6. Comparar PIB per capita\n");
    printf("7. Comparar superpoder\n");
    scanf("%d", &atributo1);
    

    //menu interativo para comparaçao de cartas e mostrar resultado final
    switch(atributo1) {
        case 1: 
            printf("Escolha o segundo atributo para comparacao: \n");
            printf("2. Comparar area\n");
            printf("3. Comparar PIB\n");
            printf("4. Comparar pontos turisticos\n");
            printf("5. Comparar densidade populacional\n");
            printf("6. Comparar PIB per capita\n");
            printf("7. Comparar superpoder\n");
            scanf("%d", &atributo2);
            switch(atributo2) {
                case 2:
                    printf("Populacao: \n");
                    resultado1 = ComparaINT(populacao1, populacao2);
                    printf("Area: \n");
                    resultado2 = ComparaFloat(area1, area2);
                    Resultado(resultado1, resultado2);
                    break;
                case 3:
                    printf("Populacao: \n");
                    resultado1 = ComparaINT(populacao1, populacao2);
                    printf("PIB: \n");
                    resultado2 = ComparaFloat(pib1, pib2);
                    Resultado(resultado1, resultado2);
                    break;
                case 4:
                    printf("Populacao: \n");
                    resultado1 = ComparaINT(populacao1, populacao2);
                    printf("Ponto turistico: \n");
                    resultado2 = ComparaINT(pontoTuristico1, pontoTuristico2);
                    Resultado(resultado1, resultado2);
                    break;
                case 5:
                    printf("Populacao: \n");
                    resultado1 = ComparaINT(populacao1, populacao2);
                    printf("Densidade populacional: \n");
                    resultado2 = ComparaDensidadePopulacional(densidadePopulacional1, densidadePopulacional2);
                    Resultado(resultado1, resultado2);
                    break;
                case 6:
                    printf("Populacao: \n");
                    resultado1 = ComparaINT(populacao1, populacao2);
                    printf("PIB per capita: \n");
                    resultado2 = ComparaFloat(PIBperCapita1, PIBperCapita2);
                    Resultado(resultado1, resultado2);
                    break;
                case 7:
                    printf("Populacao: \n");
                    resultado1 = ComparaINT(populacao1, populacao2);
                    printf("Superpoder: \n");
                    resultado2 = ComparaFloat(superPoder1, superPoder2);
                    Resultado(resultado1, resultado2);
                    break;
                default:
                    printf("Opcao invalida\n");
            }
            break;
        case 2: 
            printf("Escolha o segundo atributo para comparacao: \n");
            printf("1. Comparar populacao\n");
            printf("3. Comparar PIB\n");
            printf("4. Comparar pontos turisticos\n");
            printf("5. Comparar densidade populacional\n");
            printf("6. Comparar PIB per capita\n");
            printf("7. Comparar superpoder\n");
            scanf("%d", &atributo2);
            switch(atributo2) {
                case 1:
                    printf("Area: \n");
                    resultado1 = ComparaFloat(area1, area2);
                    printf("Populacao: \n"); 
                    resultado2 = ComparaINT(populacao1, populacao2);
                    Resultado(resultado1, resultado2);
                    break;
                case 3:
                    printf("Area: \n");
                    resultado1 = ComparaFloat(area1, area2); 
                    printf("PIB: \n");   
                    resultado2 = ComparaFloat(pib1, pib2);
                    Resultado(resultado1, resultado2);
                    break;
                case 4:
                    printf("Area: \n");
                    resultado1 = ComparaFloat(area1, area2); 
                    printf("Ponto turistico: \n");   
                    resultado2 = ComparaINT(pontoTuristico1, pontoTuristico2);
                    Resultado(resultado1, resultado2);
                    break;
                case 5:
                    printf("Area: \n");
                    resultado1 = ComparaFloat(area1, area2);   
                    printf("Densidade populacional: \n");
                    resultado2 = ComparaDensidadePopulacional(densidadePopulacional1, densidadePopulacional2);
                    Resultado(resultado1, resultado2);
                    break;
                case 6:
                    printf("Area: \n");
                    resultado1 = ComparaFloat(area1, area2);   
                    printf("PIB per capita: \n");
                    resultado2 = ComparaFloat(PIBperCapita1, PIBperCapita2);
                    Resultado(resultado1, resultado2);
                    break;
                case 7:
                    printf("Area: \n");
                    resultado1 = ComparaFloat(area1, area2);  
                    printf("Superpoder: \n");
                    resultado2 = ComparaFloat(superPoder1, superPoder2);
                    Resultado(resultado1, resultado2);
                    break;
                default:
                    printf("Opcao invalida\n");
            }
            break;
        case 3:
            printf("Escolha o segundo atributo para comparacao: \n");
            printf("1. Comparar populacao\n");
            printf("2. Comparar area\n");
            printf("4. Comparar pontos turisticos\n");
            printf("5. Comparar densidade populacional\n");
            printf("6. Comparar PIB per capita\n");
            printf("7. Comparar superpoder\n");
            scanf("%d", &atributo2);
            switch(atributo2) {
                case 1:   
                    printf("PIB: \n");
                    resultado1 = ComparaFloat(pib1, pib2);
                    printf("Populacao: \n");
                    resultado2 = ComparaINT(populacao1, populacao2);
                    Resultado(resultado1, resultado2);
                    break;
                case 2:
                    printf("PIB: \n");
                    resultado1 = ComparaFloat(pib1, pib2);
                    printf("Area: \n");
                    resultado2 =  ComparaFloat(area1, area2);  
                    Resultado(resultado1, resultado2);
                    break;
                case 4:
                    printf("PIB: \n");
                    resultado1 = ComparaFloat(pib1, pib2); 
                    printf("Ponto turistico: \n");
                    resultado2 = ComparaINT(pontoTuristico1, pontoTuristico2);
                    Resultado(resultado1, resultado2);
                    break;
                case 5:
                    printf("PIB: \n");
                    resultado1 = ComparaFloat(pib1, pib2); 
                    printf("Densidade populacional: \n");
                    resultado2 = ComparaDensidadePopulacional(densidadePopulacional1, densidadePopulacional2);
                    Resultado(resultado1, resultado2);
                    break;
                case 6:
                    printf("PIB: \n");
                    resultado1 = ComparaFloat(pib1, pib2);
                    printf("PIB per capita: \n");
                    resultado2 = ComparaFloat(PIBperCapita1, PIBperCapita2);
                    Resultado(resultado1, resultado2);
                    break;
                case 7:
                    printf("PIB: \n");
                    resultado1 = ComparaFloat(pib1, pib2);
                    printf("Superpoder: \n");
                    resultado2 = ComparaFloat(superPoder1, superPoder2);
                    Resultado(resultado1, resultado2);
                    break;
                default:
                    printf("Opcao invalida\n");
            }
            break;
        case 4:
            printf("Escolha o segundo atributo para comparacao: \n");
            printf("1. Comparar populacao\n");
            printf("2. Comparar area\n");
            printf("3. Comparar PIB\n");
            printf("5. Comparar densidade populacional\n");
            printf("6. Comparar PIB per capita\n");
            printf("7. Comparar superpoder\n");
            scanf("%d", &atributo2);
            switch(atributo2) {
                case 1:   
                    printf("Ponto turistico: \n");
                    resultado1 = ComparaINT(pontoTuristico1, pontoTuristico2);
                    printf("Populacao: \n");
                    resultado2 = ComparaINT(populacao1, populacao2);
                    Resultado(resultado1, resultado2);
                    break;
                case 2:
                    printf("Ponto turistico: \n");
                    resultado1 = ComparaINT(pontoTuristico1, pontoTuristico2);
                    printf("Area: \n");
                    resultado2 = ComparaFloat(area1, area2);     
                    Resultado(resultado1, resultado2);
                    break;
                case 3:
                    printf("Ponto turistico: \n");
                    resultado1 = ComparaINT(pontoTuristico1, pontoTuristico2);
                    printf("PIB: \n");
                    resultado2 = ComparaFloat(pib1, pib2);
                    Resultado(resultado1, resultado2);
                    break;
                case 5:
                    printf("Ponto turistico: \n");
                    resultado1 = ComparaINT(pontoTuristico1, pontoTuristico2);
                    printf("Densidade populacional: \n");
                    resultado2 = ComparaDensidadePopulacional(densidadePopulacional1, densidadePopulacional2);
                    Resultado(resultado1, resultado2);
                    break;
                case 6:
                    printf("Ponto turistico: \n");
                    resultado1 = ComparaINT(pontoTuristico1, pontoTuristico2);
                    printf("PIB per capita: \n");
                    resultado2 = ComparaFloat(PIBperCapita1, PIBperCapita2);
                    Resultado(resultado1, resultado2);
                    break;
                case 7:
                    printf("Ponto turistico: \n");
                    resultado1 = ComparaINT(pontoTuristico1, pontoTuristico2);
                    printf("Superpoder: \n");
                    resultado2 = ComparaFloat(superPoder1, superPoder2);
                    Resultado(resultado1, resultado2);
                    break;
                default:
                    printf("Opcao invalida\n");
                
            }
            break;
        case 5:
            printf("Escolha o segundo atributo para comparacao: \n");
            printf("1. Comparar populacao\n");
            printf("2. Comparar area\n");
            printf("3. Comparar PIB\n");
            printf("4. Comparar pontos turisticos\n");
            printf("6. Comparar PIB per capita\n");
            printf("7. Comparar superpoder\n");
            scanf("%d", &atributo2);
            switch(atributo2) {
                case 1:   
                    printf("Densidade populacional: \n");
                    resultado1 = ComparaDensidadePopulacional(densidadePopulacional1, densidadePopulacional2);
                    printf("Populacao: \n");
                    resultado2 = ComparaINT(populacao1, populacao2);
                    Resultado(resultado1, resultado2);
                    break;
                case 2:
                    printf("Densidade populacional: \n");
                    resultado1 = ComparaDensidadePopulacional(densidadePopulacional1, densidadePopulacional2);
                    printf("Area: \n");
                    resultado2 = ComparaFloat(area1, area2);     
                    Resultado(resultado1, resultado2);
                    break;
                case 3:
                    printf("Densidade populacional: \n");
                    resultado1 = ComparaDensidadePopulacional(densidadePopulacional1, densidadePopulacional2);
                    printf("PIB: \n");
                    resultado2 = ComparaFloat(pib1, pib2);
                    Resultado(resultado1, resultado2);
                    break;
                case 4:
                    printf("Densidade populacional: \n");
                    resultado1 = ComparaDensidadePopulacional(densidadePopulacional1, densidadePopulacional2);
                    printf("Ponto turistico: \n");
                    resultado2 = ComparaINT(pontoTuristico1, pontoTuristico2);
                    Resultado(resultado1, resultado2);
                    break;
                case 6:
                    printf("Densidade populacional: \n");
                    resultado1 = ComparaDensidadePopulacional(densidadePopulacional1, densidadePopulacional2);
                    printf("PIB per capita: \n");
                    resultado2 = ComparaFloat(PIBperCapita1, PIBperCapita2);
                    Resultado(resultado1, resultado2);
                    break;
                case 7:
                    printf("Densidade populacional: \n");
                    resultado1 = ComparaDensidadePopulacional(densidadePopulacional1, densidadePopulacional2);
                    printf("Superpoder: \n");
                    resultado2 = ComparaFloat(superPoder1, superPoder2);
                    Resultado(resultado1, resultado2);
                    break;
                default:
                    printf("Opcao invalida\n");
            }
            break;
        case 6:
        printf("Escolha o segundo atributo para comparacao: \n");
            printf("1. Comparar populacao\n");
            printf("2. Comparar area\n");
            printf("3. Comparar PIB\n");
            printf("4. Comparar pontos turisticos\n");
            printf("5. Comparar densidade populacional\n");
            printf("7. Comparar superpoder\n");
            scanf("%d", &atributo2);
            switch(atributo2) {
                case 1:  
                    printf("PIB per capita: \n");
                    resultado1 = ComparaFloat(PIBperCapita1, PIBperCapita2);
                    printf("Populacao: \n");
                    resultado2 = ComparaINT(populacao1, populacao2);
                    Resultado(resultado1, resultado2);
                    break;
                case 2:
                    printf("PIB per capita: \n");
                    resultado1 = ComparaFloat(PIBperCapita1, PIBperCapita2);
                    printf("Area: \n");
                    resultado2 = ComparaFloat(area1, area2);   
                    Resultado(resultado1, resultado2);
                    break;
                case 3:
                    printf("PIB per capita: \n");
                    resultado1 = ComparaFloat(PIBperCapita1, PIBperCapita2);
                    printf("PIB: \n");
                    resultado2 = ComparaFloat(pib1, pib2);
                    Resultado(resultado1, resultado2);
                    break;
                case 4:
                    printf("PIB per capita: \n");
                    resultado1 = ComparaFloat(PIBperCapita1, PIBperCapita2);
                    printf("Ponto turistico: \n");
                    resultado2 = ComparaINT(pontoTuristico1, pontoTuristico2);
                    Resultado(resultado1, resultado2);
                    break;
                case 5:
                    printf("PIB per capita: \n");
                    resultado1 = ComparaFloat(PIBperCapita1, PIBperCapita2);
                    printf("Densidade populacional: \n");
                    resultado2 = ComparaDensidadePopulacional(densidadePopulacional1, densidadePopulacional2);
                    Resultado(resultado1, resultado2);
                    break;
                case 7:
                    printf("PIB per capita: \n");
                    resultado1 = ComparaFloat(PIBperCapita1, PIBperCapita2);
                    printf("Superpoder: \n");
                    resultado2 = ComparaFloat(superPoder1, superPoder2); 
                    Resultado(resultado1, resultado2);
                    break;
                default:
                    printf("Opcao invalida\n");
            }
            break;
        case 7: 
            printf("Escolha o segundo atributo para comparacao: \n");
            printf("1. Comparar populacao\n");
            printf("2. Comparar area\n");
            printf("3. Comparar PIB\n");
            printf("4. Comparar pontos turisticos\n");
            printf("5. Comparar densidade populacional\n");
            printf("6. Comparar PIB per capita\n");
            scanf("%d", &atributo2);
            switch(atributo2) {
                case 1:   
                    printf("Superpoder: \n");
                    resultado1 = ComparaFloat(superPoder1, superPoder2);
                    printf("Populacao: \n");
                    resultado2 = ComparaINT(populacao1, populacao2);
                    Resultado(resultado1, resultado2);
                    break;
                case 2:
                    printf("Superpoder: \n");
                    resultado1 = ComparaFloat(superPoder1, superPoder2);
                    printf("Area: \n");
                    resultado2 = ComparaFloat(area1, area2);    
                    Resultado(resultado1, resultado2);
                    break;
                case 3:
                    printf("Superpoder: \n");
                    resultado1 = ComparaFloat(superPoder1, superPoder2);
                    printf("PIB: \n");
                    resultado2 = ComparaFloat(pib1, pib2);
                    Resultado(resultado1, resultado2);
                    break;
                case 4:
                    printf("Superpoder: \n");
                    resultado1 = ComparaFloat(superPoder1, superPoder2);
                    printf("Ponto turistico: \n");
                    resultado2 = ComparaINT(pontoTuristico1, pontoTuristico2);
                    Resultado(resultado1, resultado2);
                    break;
                case 5:
                    printf("Superpoder: \n");
                    resultado1 = ComparaFloat(superPoder1, superPoder2);
                    printf("Densidade populacional: \n");
                    resultado2 = ComparaDensidadePopulacional(densidadePopulacional1, densidadePopulacional2);
                    Resultado(resultado1, resultado2);
                    break;
                case 6:
                    printf("Superpoder: \n");
                    resultado1 = ComparaFloat(superPoder1, superPoder2);
                    printf("PIB per capita: \n");
                    resultado2 = ComparaFloat(PIBperCapita1, PIBperCapita2);
                    Resultado(resultado1, resultado2);
                    break;
                default:
                    printf("Opcao invalida\n");

            }
            break;
        default:
            printf("Opcao invalida\n");
    }
    //mostrar resultado final
    ResFinal();
    return 0;
}
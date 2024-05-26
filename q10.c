#include <stdio.h>
#include <string.h>

#define MAX_ELETRODOMESTICOS 5
#define MAX_LENGTH_NOME 16

typedef struct {
    char nome[MAX_LENGTH_NOME];
    float potencia;
    float tempoAtivoPorDia;
} Eletrodomestico;

void calcularConsumoTotal(Eletrodomestico eletrodomesticos[], int numEletrodomesticos, int tempoDias) {
    float consumoTotal = 0;

    for (int i = 0; i < numEletrodomesticos; i++) {
        consumoTotal += eletrodomesticos[i].potencia * eletrodomesticos[i].tempoAtivoPorDia * tempoDias;
    }

    printf("Consumo total da casa durante %d dias: %.2f kWh\n", tempoDias, consumoTotal);

    printf("Consumo relativo de cada eletrodoméstico durante %d dias:\n", tempoDias);
    for (int i = 0; i < numEletrodomesticos; i++) {
        float consumoRelativo = (eletrodomesticos[i].potencia * eletrodomesticos[i].tempoAtivoPorDia * tempoDias) / consumoTotal * 100;
        printf("%s: %.2f%%\n", eletrodomesticos[i].nome, consumoRelativo);
    }
}

int main() {
    Eletrodomestico eletrodomesticos[MAX_ELETRODOMESTICOS];
    int tempoDias;

    printf("Entre com os dados de 5 eletrodomésticos:\n");
    for (int i = 0; i < MAX_ELETRODOMESTICOS; i++) {
        printf("\nEletrodoméstico %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", eletrodomesticos[i].nome);
        printf("Potência (em kW): ");
        scanf("%f", &eletrodomesticos[i].potencia);
        printf("Tempo ativo por dia (em horas): ");
        scanf("%f", &eletrodomesticos[i].tempoAtivoPorDia);
    }

    printf("\nEntre com o tempo em dias: ");
    scanf("%d", &tempoDias);

    calcularConsumoTotal(eletrodomesticos, MAX_ELETRODOMESTICOS, tempoDias);

    return 0;
}

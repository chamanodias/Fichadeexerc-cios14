#include <stdio.h>
#include <string.h>

#define MAX_CARROS 5
#define MAX_LENGTH_MARCA 16 
#define MAX_LENGTH_PRECO 10 

typedef struct {
    char marca[MAX_LENGTH_MARCA];
    int ano;
    float preco;
} Carro;

void mostrarCarrosComPrecoMenorQueP(Carro carros[], int tamanho, float p) {
    printf("Carros com preço menor que %.2f:\n", p);
    for (int i = 0; i < tamanho; i++) {
        if (carros[i].preco < p) {
            printf("Marca: %s\n", carros[i].marca);
            printf("Ano: %d\n", carros[i].ano);
            printf("Preço: %.2f\n", carros[i].preco);
            printf("\n");
        }
    }
}

int main() {
    Carro carros[MAX_CARROS];
    float p;

    printf("Entre com os dados de 5 carros:\n");
    for (int i = 0; i < MAX_CARROS; i++) {
        printf("\nCarro %d:\n", i + 1);
        printf("Marca: ");
        scanf("%s", carros[i].marca);
        printf("Ano: ");
        scanf("%d", &carros[i].ano);
        printf("Preço: ");
        scanf("%f", &carros[i].preco);
    }

    do {
        printf("\nEntre com um valor de p para mostrar carros com preço menor que p (ou 0 para sair): ");
        scanf("%f", &p);

        if (p != 0) {
            mostrarCarrosComPrecoMenorQueP(carros, MAX_CARROS, p);
        }
    } while (p != 0);

    return 0;
}

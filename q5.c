#include <stdio.h>

typedef struct {
    float x;
    float y;
    float z;
} Vetor;

Vetor somaVetores(Vetor v1, Vetor v2) {
    Vetor soma;
    soma.x = v1.x + v2.x;
    soma.y = v1.y + v2.y;
    soma.z = v1.z + v2.z;
    return soma;
}

int main() {
    Vetor vetor1, vetor2, resultado;

    printf("Digite as coordenadas do primeiro vetor (x, y, z): ");
    scanf("%f %f %f", &vetor1.x, &vetor1.y, &vetor1.z);

    printf("Digite as coordenadas do segundo vetor (x, y, z): ");
    scanf("%f %f %f", &vetor2.x, &vetor2.y, &vetor2.z);

    resultado = somaVetores(vetor1, vetor2);

    printf("A soma dos vetores é: (%.2f, %.2f, %.2f)\n", resultado.x, resultado.y, resultado.z);

    return 0;
}

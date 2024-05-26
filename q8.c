#include <stdio.h>
#include <string.h>

#define MAX_PESSOAS 5
#define MAX_LENGTH_NOME 100
#define MAX_LENGTH_ENDERECO 200
#define MAX_LENGTH_TELEFONE 15

typedef struct {
    char nome[MAX_LENGTH_NOME];
    char endereco[MAX_LENGTH_ENDERECO];
    char telefone[MAX_LENGTH_TELEFONE];
} Pessoa;

void ordenarPorNome(Pessoa pessoas[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (strcmp(pessoas[j].nome, pessoas[j + 1].nome) > 0) {
                Pessoa temp = pessoas[j];
                pessoas[j] = pessoas[j + 1];
                pessoas[j + 1] = temp;
            }
        }
    }
}

int main() {
    Pessoa pessoas[MAX_PESSOAS];

    printf("Entre com os dados das 5 pessoas:\n");
    for (int i = 0; i < MAX_PESSOAS; i++) {
        printf("\nPessoa %d:\n", i + 1);
        printf("Nome: ");
        fgets(pessoas[i].nome, MAX_LENGTH_NOME, stdin);
        printf("Endereço: ");
        fgets(pessoas[i].endereco, MAX_LENGTH_ENDERECO, stdin);
        printf("Telefone: ");
        fgets(pessoas[i].telefone, MAX_LENGTH_TELEFONE, stdin);
    }

    ordenarPorNome(pessoas, MAX_PESSOAS);

    printf("\nPessoas em ordem alfabética:\n");
    for (int i = 0; i < MAX_PESSOAS; i++) {
        printf("\nPessoa %d:\n", i + 1);
        printf("Nome: %s", pessoas[i].nome);
        printf("Endereço: %s", pessoas[i].endereco);
        printf("Telefone: %s", pessoas[i].telefone);
    }

    return 0;
}

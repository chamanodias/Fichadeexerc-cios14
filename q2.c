#include <stdio.h>

typedef struct {
    char nome[100];
    int idade;
    char endereco[200];
} Pessoa;

int main() {
    Pessoa pessoa;

    printf("Digite o nome: ");
    fgets(pessoa.nome, sizeof(pessoa.nome), stdin);

    printf("Digite a idade: ");
    scanf("%d", &pessoa.idade);
    getchar();

    printf("Digite o endereço: ");
    fgets(pessoa.endereco, sizeof(pessoa.endereco), stdin);

    printf("\nDados da pessoa:\n");
    printf("Nome: %s", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
    printf("Endereço: %s", pessoa.endereco);

    return 0;
}

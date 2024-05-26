#include <stdio.h>
#include <string.h>

#define MAX_DIRETORES 5
#define MAX_LENGTH_NOME_DIRETOR 21 // 20 letras + 1 para o caractere nulo
#define MAX_FILMES 10
#define MAX_LENGTH_NOME_FILME 51 // 50 letras + 1 para o caractere nulo

typedef struct {
    char nome[MAX_LENGTH_NOME_DIRETOR];
    int quantidadeFilmes;
    struct {
        char nome[MAX_LENGTH_NOME_FILME];
        int ano;
        int duracao;
    } filmes[MAX_FILMES];
} Diretor;

void mostrarFilmesDoDiretor(Diretor diretores[], int numDiretores, char nomeDiretor[]) {
    int encontrado = 0;

    for (int i = 0; i < numDiretores; i++) {
        if (strcmp(diretores[i].nome, nomeDiretor) == 0) {
            encontrado = 1;
            printf("Filmes do diretor %s:\n", diretores[i].nome);
            for (int j = 0; j < diretores[i].quantidadeFilmes; j++) {
                printf("Nome: %s\n", diretores[i].filmes[j].nome);
                printf("Ano: %d\n", diretores[i].filmes[j].ano);
                printf("Duração: %d minutos\n\n", diretores[i].filmes[j].duracao);
            }
            break;
        }
    }

    if (!encontrado) {
        printf("Diretor não encontrado.\n");
    }
}

int main() {
    Diretor diretores[MAX_DIRETORES];
    char nomeDiretor[MAX_LENGTH_NOME_DIRETOR];
    int numDiretores;

    printf("Entre com os dados de 5 diretores:\n");
    for (int i = 0; i < MAX_DIRETORES; i++) {
        printf("\nDiretor %d:\n", i + 1);
        printf("Nome: ");
        scanf("%s", diretores[i].nome);
        printf("Quantidade de filmes: ");
        scanf("%d", &diretores[i].quantidadeFilmes);
        for (int j = 0; j < diretores[i].quantidadeFilmes; j++) {
            printf("Filme %d:\n", j + 1);
            printf("Nome: ");
            scanf("%s", diretores[i].filmes[j].nome);
            printf("Ano: ");
            scanf("%d", &diretores[i].filmes[j].ano);
            printf("Duração (em minutos): ");
            scanf("%d", &diretores[i].filmes[j].duracao);
        }
    }

    printf("\nProcurar filmes de diretores (digite uma string vazia para sair):\n");
    while (1) {
        printf("Nome do diretor: ");
        scanf("%s", nomeDiretor);
        if (strcmp(nomeDiretor, "") == 0) {
            break;
        }
        mostrarFilmesDoDiretor(diretores, MAX_DIRETORES, nomeDiretor);
    }

    return 0;
}

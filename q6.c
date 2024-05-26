#include <stdio.h>

#define NUM_ALUNOS 10

typedef struct {
    int matricula;
    char nome[100];
    int codigoDisciplina;
    float nota1;
    float nota2;
} Aluno;

int main() {
    Aluno alunos[NUM_ALUNOS];
    int numAlunos;

    printf("Digite o número de alunos (até %d): ", NUM_ALUNOS);
    scanf("%d", &numAlunos);
    getchar();  

    for (int i = 0; i < numAlunos; i++) {
        printf("Digite a matrícula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);
        getchar();  

        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);

        printf("Digite o código da disciplina do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].codigoDisciplina);

        printf("Digite a nota 1 do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota1);

        printf("Digite a nota 2 do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota2);

        getchar();  
        printf("\n");
    }

    printf("Listagem final dos alunos com suas respectivas médias finais:\n");
    for (int i = 0; i < numAlunos; i++) {
        float mediaFinal = (alunos[i].nota1 * 1.0 + alunos[i].nota2 * 2.0) / 3.0;
        printf("Aluno %d:\n", i + 1);
        printf("Matrícula: %d\n", alunos[i].matricula);
        printf("Nome: %s", alunos[i].nome);
        printf("Código da Disciplina: %d\n", alunos[i].codigoDisciplina);
        printf("Média Final: %.2f\n\n", mediaFinal);
    }

    return 0;
}

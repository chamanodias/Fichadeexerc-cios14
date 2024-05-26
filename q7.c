#include <stdio.h>

typedef struct {
    char nome[100];
    int idade;
    char sexo;
    char cpf[12];
    char dataNascimento[11];
    int codigoSetor;
    char cargo[31];
    float salario;
} Funcionario;

int main() {
    Funcionario funcionario;

    printf("Digite o nome do funcionário: ");
    fgets(funcionario.nome, sizeof(funcionario.nome), stdin);

    printf("Digite a idade do funcionário: ");
    scanf("%d", &funcionario.idade);
    getchar();

    printf("Digite o sexo do funcionário (M/F): ");
    scanf("%c", &funcionario.sexo);
    getchar();

    printf("Digite o CPF do funcionário (somente números): ");
    scanf("%s", funcionario.cpf);

    printf("Digite a data de nascimento do funcionário (DD/MM/AAAA): ");
    scanf("%s", funcionario.dataNascimento);

    printf("Digite o código do setor onde o funcionário trabalha (0-99): ");
    scanf("%d", &funcionario.codigoSetor);

    printf("Digite o cargo que o funcionário ocupa (até 30 caracteres): ");
    getchar();
    fgets(funcionario.cargo, sizeof(funcionario.cargo), stdin);

    printf("Digite o salário do funcionário: ");
    scanf("%f", &funcionario.salario);

    printf("\nDados do funcionário:\n");
    printf("Nome: %s", funcionario.nome);
    printf("Idade: %d\n", funcionario.idade);
    printf("Sexo: %c\n", funcionario.sexo);
    printf("CPF: %s\n", funcionario.cpf);
    printf("Data de Nascimento: %s\n", funcionario.dataNascimento);
    printf("Código do Setor: %d\n", funcionario.codigoSetor);
    printf("Cargo: %s", funcionario.cargo);
    printf("Salário: %.2f\n", funcionario.salario);

    return 0;
}

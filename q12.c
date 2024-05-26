#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 100
#define MAX_LENGTH_NOME 50
#define MAX_LENGTH_EMAIL 50
#define MAX_LENGTH_OBSERVACOES 100
#define MAX_LENGTH_RUA 50
#define MAX_LENGTH_CIDADE 50
#define MAX_LENGTH_ESTADO 3
#define MAX_LENGTH_PAIS 20
#define MAX_LENGTH_TELEFONE 15

typedef struct {
    char nome[MAX_LENGTH_NOME];
    char email[MAX_LENGTH_EMAIL];
    struct {
        char rua[MAX_LENGTH_RUA];
        int numero;
        char complemento[MAX_LENGTH_RUA];
        char bairro[MAX_LENGTH_RUA];
        char cep[9];
        char cidade[MAX_LENGTH_CIDADE];
        char estado[MAX_LENGTH_ESTADO];
        char pais[MAX_LENGTH_PAIS];
    } endereco;
    char telefone[MAX_LENGTH_TELEFONE];
    struct {
        int dia;
        int mes;
        int ano;
    } aniversario;
    char observacoes[MAX_LENGTH_OBSERVACOES];
} Contato;

Contato agenda[MAX_CONTATOS];
int numContatos = 0;

void buscaPorNome(char nome[]) {
    int encontrado = 0;

    for (int i = 0; i < numContatos; i++) {
        if (strcmp(agenda[i].nome, nome) == 0) {
            encontrado = 1;
            printf("Nome: %s\n", agenda[i].nome);
            printf("E-mail: %s\n", agenda[i].email);
            printf("Endereço: %s, %d, %s, %s, %s, %s, %s, %s\n", agenda[i].endereco.rua, agenda[i].endereco.numero, agenda[i].endereco.complemento, agenda[i].endereco.bairro, agenda[i].endereco.cep, agenda[i].endereco.cidade, agenda[i].endereco.estado, agenda[i].endereco.pais);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Aniversário: %d/%d/%d\n", agenda[i].aniversario.dia, agenda[i].aniversario.mes, agenda[i].aniversario.ano);
            printf("Observações: %s\n\n", agenda[i].observacoes);
        }
    }

    if (!encontrado) {
        printf("Contato não encontrado.\n");
    }
}

void buscaPorMesAniversario(int mes) {
    printf("Aniversariantes do mês %d:\n", mes);
    for (int i = 0; i < numContatos; i++) {
        if (agenda[i].aniversario.mes == mes) {
            printf("%s\n", agenda[i].nome);
        }
    }
}

void buscaPorDiaMesAniversario(int dia, int mes) {
    printf("Aniversariantes do dia %d/%d:\n", dia, mes);
    for (int i = 0; i < numContatos; i++) {
        if (agenda[i].aniversario.dia == dia && agenda[i].aniversario.mes == mes) {
            printf("%s\n", agenda[i].nome);
        }
    }
}

void insereContato(Contato novoContato) {
    int i, j;
    for (i = 0; i < numContatos; i++) {
        if (strcmp(novoContato.nome, agenda[i].nome) < 0) {
            break;
        }
    }
    for (j = numContatos - 1; j >= i; j--) {
        agenda[j + 1] = agenda[j];
    }
    agenda[i] = novoContato;
    numContatos++;
}

void removeContato(char nome[]) {
    int i, j;
    for (i = 0; i < numContatos; i++) {
        if (strcmp(nome, agenda[i].nome) == 0) {
            for (j = i; j < numContatos - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            numContatos--;
            printf("Contato removido.\n");
            return;
        }
    }
    printf("Contato não encontrado.\n");
}

void imprimeAgenda() {
    printf("Agenda de contatos:\n");
    for (int i = 0; i < numContatos; i++) {
        printf("%s - %s - %s\n", agenda[i].nome, agenda[i].telefone, agenda[i].email);
    }
}

int main() {
    int opcao, mes, dia;
    Contato novoContato;

    do {
        printf("\nMenu Principal\n");
        printf("1. Buscar por nome\n");
        printf("2. Buscar por mês de aniversário\n");
        printf("3. Buscar por dia e mês de aniversário\n");
        printf("4. Inserir novo contato\n");
        printf("5. Remover contato\n");
        printf("6. Imprimir agenda\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome a ser buscado: ");
                scanf("%s", novoContato.nome);
                buscaPorNome(novoContato.nome);
                break;
            case 2:
                printf("Digite o mês de aniversário a ser buscado: ");
                scanf("%d", &mes);
                buscaPorMesAniversario(mes);
                break;
            case 3:
                printf("Digite o dia de aniversário a ser buscado: ");
                scanf("%d", &dia);
                printf("Digite o mês de aniversário a ser buscado: ");
                scanf("%d", &mes);
                buscaPorDiaMesAniversario(dia, mes);
                break;
            case 4:
                printf("Digite o nome do novo contato: ");
                scanf("%s", novoContato.nome);
                printf("Digite o e-mail do novo contato: ");
                scanf("%s", novoContato.email);
                printf("Digite a rua do endereço: ");
                scanf("%s", novoContato.endereco.rua);
                printf("Digite o número do endereço: ");
                scanf("%d", &novoContato.endereco.numero);
printf("Digite o complemento do endereço: ");
scanf("%s", novoContato.endereco.complemento);
printf("Digite o bairro do endereço: ");
scanf("%s", novoContato.endereco.bairro);
printf("Digite o CEP do endereço: ");
scanf("%s", novoContato.endereco.cep);
printf("Digite a cidade do endereço: ");
scanf("%s", novoContato.endereco.cidade);
printf("Digite o estado do endereço: ");
scanf("%s", novoContato.endereco.estado);
printf("Digite o país do endereço: ");
scanf("%s", novoContato.endereco.pais);
printf("Digite o telefone do novo contato: ");
scanf("%s", novoContato.telefone);
printf("Digite o dia do aniversário: ");
scanf("%d", &novoContato.aniversario.dia);
printf("Digite o mês do aniversário: ");
scanf("%d", &novoContato.aniversario.mes);
printf("Digite o ano do aniversário: ");
scanf("%d", &novoContato.aniversario.ano);
printf("Digite observações especiais: ");
scanf("%s", novoContato.observacoes);
insereContato(novoContato);
printf("Contato inserido com sucesso.\n");
break;
case 5:
printf("Digite o nome do contato a ser removido: ");
scanf("%s", novoContato.nome);
removeContato(novoContato.nome);
break;
case 6:
imprimeAgenda();
break;
case 0:
printf("Encerrando o programa...\n");
break;
default:
printf("Opção inválida.\n");
}
} while (opcao != 0);
return 0;
}

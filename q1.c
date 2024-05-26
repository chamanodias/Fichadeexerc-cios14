#include <stdio.h>

typedef struct {
    int hora;
    int minutos;
    int segundos;
} Horario;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    Data data;
    Horario horario;
    char descricao[100];
} Compromisso;

int main() {
    Horario horario1 = {14, 30, 0};
    Data data1 = {26, 5, 2024};
    Compromisso compromisso1 = {data1, horario1, "Reunião com o time de desenvolvimento"};

    printf("Compromisso: %s\n", compromisso1.descricao);
    printf("Data: %02d/%02d/%04d\n", compromisso1.data.dia, compromisso1.data.mes, compromisso1.data.ano);
    printf("Horário: %02d:%02d:%02d\n", compromisso1.horario.hora, compromisso1.horario.minutos, compromisso1.horario.segundos);

    return 0;
}

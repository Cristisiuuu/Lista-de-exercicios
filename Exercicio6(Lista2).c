#include <stdio.h>

struct dma {
    int dia;
    int mes;
    int ano;
};

// Função para verificar se um ano é bissexto
int eBissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}
// Função para calcular a diferença em dias entre duas datas
int diferencaDias(struct dma data1, struct dma data2) {
    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDias1 = data1.ano * 365 + data1.dia;

    for (int i = 1; i < data1.mes; i++) {
        totalDias1 += diasNoMes[i];
    }

    if (data1.mes > 2 && eBissexto(data1.ano)) {
        totalDias1 += 1;
    }

    int totalDias2 = data2.ano * 365 + data2.dia;

    for (int i = 1; i < data2.mes; i++) {
        totalDias2 += diasNoMes[i];
    }

    if (data2.mes > 2 && eBissexto(data2.ano)) {
        totalDias2 += 1;
    }

    return totalDias1 - totalDias2;
}

int main() {
    struct dma primeiro, segundo;
    int difDias;

    printf("Digite a primeira data (dia mes ano): ");
    scanf("%d %d %d", &primeiro.dia, &primeiro.mes, &primeiro.ano);
    
    printf("Digite a segunda data (dia mes ano): ");
    scanf("%d %d %d", &segundo.dia, &segundo.mes, &segundo.ano);

    difDias = diferencaDias(primeiro, segundo);

    printf("A diferença de dias eh de: %d\n", difDias);

    return 0;
}

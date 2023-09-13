#include <stdio.h>
#include <stdlib.h>

struct registro {
    int numero_maquina;
    int numero_pecas;
};

int main() {
    FILE *arq_entrada;
    FILE *arq_maquina1;
    FILE *arq_maquina2;
    FILE *arq_maquina3;

    if ((arq_entrada = fopen("registros_producao.txt", "r")) == NULL) {
        printf("Erro na abertura do arquivo de entrada.\n");
        exit(1);
    }

    if ((arq_maquina1 = fopen("maquina1.txt", "w")) == NULL) {
        printf("Erro na abertura do arquivo da máquina 1.\n");
        fclose(arq_entrada);
        exit(1);
    }

    if ((arq_maquina2 = fopen("maquina2.txt", "w")) == NULL) {
        printf("Erro na abertura do arquivo da máquina 2.\n");
        fclose(arq_entrada);
        fclose(arq_maquina1);
        exit(1);
    }

    if ((arq_maquina3 = fopen("maquina3.txt", "w")) == NULL) {
        printf("Erro na abertura do arquivo da máquina 3.\n");
        fclose(arq_entrada);
        fclose(arq_maquina1);
        fclose(arq_maquina2);
        exit(1);
    }

    struct registro producao;

    while (fscanf(arq_entrada, "%d %d", &producao.numero_maquina, &producao.numero_pecas) == 2) {
        if (producao.numero_maquina == 1) {
            fprintf(arq_maquina1, "%d %d\n", producao.numero_maquina, producao.numero_pecas);
        } else if (producao.numero_maquina == 2) {
            fprintf(arq_maquina2, "%d %d\n", producao.numero_maquina, producao.numero_pecas);
        } else if (producao.numero_maquina == 3) {
            fprintf(arq_maquina3, "%d %d\n", producao.numero_maquina, producao.numero_pecas);
        } else {
            printf("Número de máquina inválido: %d\n", producao.numero_maquina);
        }
    }

    fclose(arq_entrada);
    fclose(arq_maquina1);
    fclose(arq_maquina2);
    fclose(arq_maquina3);

    printf("Arquivos separados com sucesso.\n");

    return 0;
}


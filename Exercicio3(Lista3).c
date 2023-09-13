#include <stdio.h>
#include <stdlib.h>

struct registro {
    char nome[50];
    float salario;
};

int main() {
    struct registro cliente;
    FILE *arq1;
    FILE *arq2;

    if ((arq1 = fopen("arquivo1.bat", "rb")) == NULL) {
        printf("Erro para abrir o Arquivo!!\n");
        exit(1);
    }

    if ((arq2 = fopen("arquivo2.bat", "wb")) == NULL) {
        printf("Erro para abrir o Arquivo!!\n");
        fclose(arq1); // Fecha o arquivo 1 se o arquivo 2 não puder ser aberto
        exit(1);
    }

    while (fread(&cliente, sizeof(struct registro), 1, arq1) == 1) {
        fwrite(&cliente, sizeof(struct registro), 1, arq2);
        fprintf(arq2, "Nome: %s\n", cliente.nome);
        fprintf(arq2, "Salário: %.2f\n", cliente.salario);
    }

    fclose(arq1);
    fclose(arq2);
    return 0;
}


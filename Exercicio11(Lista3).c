#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char NOME[50];
    char ENDERECO[100];
    char CEP[10];
    char TELEFONE[15];
} Registro;

int main() {
    FILE *arquivoDados;
    Registro registro;

    arquivoDados = fopen("DADOS", "rb");
    if (arquivoDados == NULL) {
        printf("Não foi possível abrir o arquivo DADOS.\n");
        return 1;
    }

    printf("Listagem dos registros do arquivo DADOS:\n");
    while (fread(&registro, sizeof(Registro), 1, arquivoDados) == 1) {
        printf("Nome: %s\n", registro.NOME);
        printf("Endereço: %s\n", registro.ENDERECO);
        printf("CEP: %s\n", registro.CEP);
        printf("Telefone: %s\n", registro.TELEFONE);
        printf("\n");
    }

    fclose(arquivoDados);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

// Estrutura de dados para representar um registro
typedef struct {
    int CHAVE;
    char INFORMACAO[50];
    char DATA[11];
} Registro;

int main() {
    FILE *arquivoFonte, *arquivoFonteNova;
    Registro registro;

    // Abre o arquivo de origem (FONTE) para leitura sequencial
    arquivoFonte = fopen("FONTE", "rb");
    if (arquivoFonte == NULL) {
        printf("N�o foi poss�vel abrir o arquivo de origem (FONTE).\n");
        return 1;
    }

    // Abre o arquivo de destino (FONTENOVA) para escrita sequencial
    arquivoFonteNova = fopen("FONTENOVA", "wb");
    if (arquivoFonteNova == NULL) {
        printf("N�o foi poss�vel criar o arquivo de destino (FONTENOVA).\n");
        fclose(arquivoFonte);
        return 1;
    }

    // L� cada registro do arquivo de origem e escreve no arquivo de destino
    while (fread(&registro, sizeof(Registro), 1, arquivoFonte) == 1) {
        fwrite(&registro, sizeof(Registro), 1, arquivoFonteNova);
    }

    // Fecha os arquivos
    fclose(arquivoFonte);
    fclose(arquivoFonteNova);

    printf("Arquivo FONTE copiado para FONTENOVA.\n");

    return 0;
}


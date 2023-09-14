#include <stdio.h>

int main() {
    FILE *arquivoEntrada, *arquivoSaida;
    int numero;

    arquivoEntrada = fopen("numeros.bin", "rb");
    if (arquivoEntrada == NULL) {
        printf("Não foi possível abrir o arquivo de entrada.\n");
        return 1;
    }

    arquivoSaida = fopen("pares.bin", "wb");
    if (arquivoSaida == NULL) {
        printf("Não foi possível abrir o arquivo de saída.\n");
        fclose(arquivoEntrada);
        return 1;
    }

    while (fread(&numero, sizeof(int), 1, arquivoEntrada) == 1) {
        if (numero % 2 == 0) {
            fwrite(&numero, sizeof(int), 1, arquivoSaida);
        }
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    printf("Números pares copiados para o arquivo 'pares.bin'.\n");

    return 0;
}


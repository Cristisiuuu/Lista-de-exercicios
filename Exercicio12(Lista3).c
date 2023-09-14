#include <stdio.h>
#include <stdlib.h>

// Estrutura de dados para representar um registro de cadastro
typedef struct {
    char NOME[50];
    int SEXO;
    char COR_OLHOS[20];
    float ALTURA;
    float PESO;
    char DATA_NASCIMENTO[11];
} RegistroCadastro;

int main() {
    FILE *arquivoCadastro, *arquivoHomens, *arquivoMulheres;
    RegistroCadastro registro;

    // Abre o arquivo "cadastro.dat" para leitura binária
    arquivoCadastro = fopen("cadastro.dat", "rb");
    if (arquivoCadastro == NULL) {
        printf("Não foi possível abrir o arquivo cadastro.dat.\n");
        return 1;
    }

    // Abre os arquivos "homens.dat" e "mulheres.dat" para escrita binária
    arquivoHomens = fopen("homens.dat", "wb");
    if (arquivoHomens == NULL) {
        printf("Não foi possível criar o arquivo homens.dat.\n");
        fclose(arquivoCadastro);
        return 1;
    }

    arquivoMulheres = fopen("mulheres.dat", "wb");
    if (arquivoMulheres == NULL) {
        printf("Não foi possível criar o arquivo mulheres.dat.\n");
        fclose(arquivoCadastro);
        fclose(arquivoHomens);
        return 1;
    }

    // Lê cada registro do arquivo "cadastro.dat" e escreve nos arquivos "homens.dat" ou "mulheres.dat"
    while (fread(&registro, sizeof(RegistroCadastro), 1, arquivoCadastro) == 1) {
        if (registro.SEXO == 1) {
            // Se o sexo for masculino (1), escreve no arquivo "homens.dat"
            fwrite(&registro, sizeof(RegistroCadastro), 1, arquivoHomens);
        } else if (registro.SEXO == 2) {
            // Se o sexo for feminino (2), escreve no arquivo "mulheres.dat"
            fwrite(&registro, sizeof(RegistroCadastro), 1, arquivoMulheres);
        }
    }

    // Fecha os arquivos
    fclose(arquivoCadastro);
    fclose(arquivoHomens);
    fclose(arquivoMulheres);

    // Remove o arquivo "cadastro.dat"
    remove("cadastro.dat");

    printf("Registros separados em homens.dat e mulheres.dat.\n");

    return 0;
}


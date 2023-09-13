#include <stdio.h>
#include <stdlib.h>

struct registro {
    char sexo;
    int idade;
    float salario;
    char estado_civil;
    int num_dependentes;
    float patrimonio;
    int calorias;
    int grau_instrucao;
};

int main() {
    FILE *arq_regiao1, *arq_regiao2, *arq_regiao3, *arq_saida;

    arq_regiao1 = fopen("regiao1.txt", "r");
    arq_regiao2 = fopen("regiao2.txt", "r");
    arq_regiao3 = fopen("regiao3.txt", "r");

    if (arq_regiao1 == NULL || arq_regiao2 == NULL || arq_regiao3 == NULL) {
        printf("Erro na abertura dos arquivos de entrada.\n");
        exit(1);
    }

    arq_saida = fopen("arquivo_saida.txt", "w");

    if (arq_saida == NULL) {
        printf("Erro na abertura do arquivo de saída.\n");
        fclose(arq_regiao1);
        fclose(arq_regiao2);
        fclose(arq_regiao3);
        exit(1);
    }

    struct registro regiao1, regiao2, regiao3;
    int regiao1_eof = 0, regiao2_eof = 0, regiao3_eof = 0;

    if (fread(&regiao1, sizeof(struct registro), 1, arq_regiao1) != 1) {
        regiao1_eof = 1;
    }

    if (fread(&regiao2, sizeof(struct registro), 1, arq_regiao2) != 1) {
        regiao2_eof = 1;
    }

    if (fread(&regiao3, sizeof(struct registro), 1, arq_regiao3) != 1) {
        regiao3_eof = 1;
    }

    while (!(regiao1_eof && regiao2_eof && regiao3_eof)) {

        int menor_idade = INT_MAX;
        int regiao = 0;

        if (!regiao1_eof && regiao1.idade < menor_idade) {
            menor_idade = regiao1.idade;
            regiao = 1;
        }

        if (!regiao2_eof && regiao2.idade < menor_idade) {
            menor_idade = regiao2.idade;
            regiao = 2;
        }

        if (!regiao3_eof && regiao3.idade < menor_idade) {
            menor_idade = regiao3.idade;
            regiao = 3;
        }

        if (regiao == 1) {
            fwrite(&regiao1, sizeof(struct registro), 1, arq_saida);
            if (fread(&regiao1, sizeof(struct registro), 1, arq_regiao1) != 1) {
                regiao1_eof = 1;
            }
        } else if (regiao == 2) {
            fwrite(&regiao2, sizeof(struct registro), 1, arq_saida);
            if (fread(&regiao2, sizeof(struct registro), 1, arq_regiao2) != 1) {
                regiao2_eof = 1;
            }
        } else if (regiao == 3) {
            fwrite(&regiao3, sizeof(struct registro), 1, arq_saida);
            if (fread(&regiao3, sizeof(struct registro), 1, arq_regiao3) != 1) {
                regiao3_eof = 1;
            }
        }
    }

    fclose(arq_regiao1);
    fclose(arq_regiao2);
    fclose(arq_regiao3);
    fclose(arq_saida);

    printf("Arquivos intercalados com sucesso.\n");

    return 0;
}


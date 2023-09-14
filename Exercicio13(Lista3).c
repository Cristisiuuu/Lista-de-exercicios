#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int NUMERO_CLIENTE;
    char CODIGO_OPERACAO;
    char DESCRICAO[50];
    int QUANTIDADE;
    float VALOR_UNITARIO;
} RegistroOperacao;

int main() {
    FILE *arquivoBolsa, *arquivoResultado;
    RegistroOperacao operacao;
    int numeroClienteAtual;
    float saldoCredor = 0.0, saldoDevedor = 0.0;

    arquivoBolsa = fopen("bolsa.dat", "rb");
    if (arquivoBolsa == NULL) {
        printf("Não foi possível abrir o arquivo bolsa.dat.\n");
        return 1;
    }

    arquivoResultado = fopen("RESULTADO", "w");
    if (arquivoResultado == NULL) {
        printf("Não foi possível criar o arquivo RESULTADO.\n");
        fclose(arquivoBolsa);
        return 1;
    }

    numeroClienteAtual = -1;

    while (fread(&operacao, sizeof(RegistroOperacao), 1, arquivoBolsa) == 1) {
        if (operacao.NUMERO_CLIENTE != numeroClienteAtual) {
            if (saldoCredor > saldoDevedor) {
                fprintf(arquivoResultado, "%d %.2f C\n", numeroClienteAtual, saldoCredor);
            } else {
                fprintf(arquivoResultado, "%d %.2f D\n", numeroClienteAtual, saldoDevedor);
            }

            saldoCredor = 0.0;
            saldoDevedor = 0.0;
            numeroClienteAtual = operacao.NUMERO_CLIENTE;
        }

        float valorOperacao = operacao.QUANTIDADE * operacao.VALOR_UNITARIO;
        if (operacao.CODIGO_OPERACAO == 'C') {
            saldoDevedor += valorOperacao;
        } else if (operacao.CODIGO_OPERACAO == 'V') {
            saldoCredor += valorOperacao;
        }
    }

    if (saldoCredor > saldoDevedor) {
        fprintf(arquivoResultado, "%d %.2f C\n", numeroClienteAtual, saldoCredor);
    } else {
        fprintf(arquivoResultado, "%d %.2f D\n", numeroClienteAtual, saldoDevedor);
    }

    fclose(arquivoBolsa);
    fclose(arquivoResultado);

    printf("Arquivo RESULTADO gerado com sucesso.\n");

    return 0;
}


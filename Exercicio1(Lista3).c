#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data {
    int dia;
    int mes;
    int ano;
};

struct registro {
    int numero_conta;
    char nome_cliente[50];
    float saldo;
    struct data data_ultima_operacao;
};

int main() {
    FILE *arquivo;
    struct registro cliente;

    int opcao;
    char consulta_nome[50];

    if ((arquivo = fopen("registros.bat", "ab+")) == NULL) {
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Cadastrar novo registro\n");
        printf("2 - Consultar registro por nome\n");
        printf("3 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o numero da conta: ");
                scanf("%d", &cliente.numero_conta);
                printf("Digite o nome do cliente: ");
                scanf(" %[^\n]", cliente.nome_cliente);
                printf("Digite o saldo: ");
                scanf("%f", &cliente.saldo);
                printf("Digite a data da ultima operacao (dia mes ano): ");
                scanf("%d/%d/%d", &cliente.data_ultima_operacao.dia,
                      &cliente.data_ultima_operacao.mes,
                      &cliente.data_ultima_operacao.ano);

                fwrite(&cliente, sizeof(struct registro), 1, arquivo);
                printf("Registro cadastrado com sucesso.\n");
                break;

            case 2:
                printf("Digite o nome do cliente para consultar: ");
                scanf(" %[^\n]", consulta_nome);

                rewind(arquivo); // Voltar para o início do arquivo

                while (fread(&cliente, sizeof(struct registro), 1, arquivo) == 1) {
                    if (strcmp(cliente.nome_cliente, consulta_nome) == 0) {
                        printf("Numero da conta: %d\n", cliente.numero_conta);
                        printf("Nome do cliente: %s\n", cliente.nome_cliente);
                        printf("Saldo: %.2f\n", cliente.saldo);
                        printf("Data da ultima operacao: %d/%d/%d\n",
                               cliente.data_ultima_operacao.dia,
                               cliente.data_ultima_operacao.mes,
                               cliente.data_ultima_operacao.ano);
                        break; // Encontrou o registro, sai do loop
                    }
                }
                break;

            case 3:
                fclose(arquivo);
                exit(0);

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }
    
	return 0;
}

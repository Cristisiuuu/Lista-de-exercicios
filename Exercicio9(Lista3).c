#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numero_conta;
    char nome[50];
    float saldo;
} RegistroCliente;

int main() {
    int numero_conta_desejado;
    FILE *arquivo;

    arquivo = fopen("clientes.dat", "rb");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        return 1;
    }

    printf("Informe o número da conta do cliente: ");
    scanf("%d", &numero_conta_desejado);

    long deslocamento = (long)(numero_conta_desejado - 1) * sizeof(RegistroCliente);

    fseek(arquivo, deslocamento, SEEK_SET);

    RegistroCliente cliente;
    fread(&cliente, sizeof(RegistroCliente), 1, arquivo);

    if (cliente.numero_conta == numero_conta_desejado) {
        printf("Número da Conta: %d\n", cliente.numero_conta);
        printf("Nome: %s\n", cliente.nome);
        printf("Saldo: %.2f\n", cliente.saldo);
    } else {
        printf("Cliente não encontrado.\n");
    }

    fclose(arquivo);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int identificador;
    char nome[50];
    int quantidade;
    float custo_unitario;
} Produto;

Produto criarProduto() {
    Produto novoProduto;
    printf("Informe o identificador do produto: ");
    scanf("%d", &novoProduto.identificador);
    printf("Informe o nome do produto: ");
    scanf(" %[^\n]", novoProduto.nome);
    printf("Informe a quantidade em estoque: ");
    scanf("%d", &novoProduto.quantidade);
    printf("Informe o custo unitário do produto: ");
    scanf("%f", &novoProduto.custo_unitario);
    return novoProduto;
}

void incluirProduto(Produto estoque[], int *numProdutos, Produto novoProduto) {
    estoque[*numProdutos] = novoProduto;
    (*numProdutos)++;
    printf("Produto adicionado com sucesso!\n");
}

void removerProduto(Produto estoque[], int *numProdutos, int identificador) {
    int i, j;
	for ( i = 0; i < *numProdutos; i++) {
        if (estoque[i].identificador == identificador) {
            for ( j = i; j < (*numProdutos - 1); j++) {
                estoque[j] = estoque[j + 1];
            }
            (*numProdutos)--;
            printf("Produto removido com sucesso!\n");
            return;
        }
    }
    printf("Produto não encontrado!\n");
}

void consultarProdutoPorNome(Produto estoque[], int numProdutos, char nome[]) {
    int i;
	for ( i = 0; i < numProdutos; i++) {
        if (strcmp(estoque[i].nome, nome) == 0) {
            printf("Identificador: %d\n", estoque[i].identificador);
            printf("Nome: %s\n", estoque[i].nome);
            printf("Quantidade em estoque: %d\n", estoque[i].quantidade);
            printf("Custo unitário: %.2f\n", estoque[i].custo_unitario);
            return;
        }
    }
    printf("Produto não encontrado!\n");
}

void relatorioEstoqueBaixo(Produto estoque[], int numProdutos, int limite) {
    int i;
	printf("Produtos com estoque abaixo de %d unidades:\n", limite);
    for ( i = 0; i < numProdutos; i++) {
        if (estoque[i].quantidade < limite) {
            printf("Identificador: %d\n", estoque[i].identificador);
            printf("Nome: %s\n", estoque[i].nome);
            printf("Quantidade em estoque: %d\n", estoque[i].quantidade);
            printf("Custo unitário: %.2f\n", estoque[i].custo_unitario);
        }
    }
}

// Função principal
int main() {
    Produto estoque[100];
    int numProdutos = 0;

    while (1) {
        printf("\nMenu de Opcoes:\n");
        printf("1 - Incluir Produto\n");
        printf("2 - Remover Produto\n");
        printf("3 - Consultar Produto por Nome\n");
        printf("4 - Relatorio de Estoque Baixo\n");
        printf("5 - Sair\n");

        int opcao;
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Produto novoProduto = criarProduto();
                incluirProduto(estoque, &numProdutos, novoProduto);
                break;
            }
            case 2: {
                int identificador;
                printf("Informe o identificador do produto a ser removido: ");
                scanf("%d", &identificador);
                removerProduto(estoque, &numProdutos, identificador);
                break;
            }
            case 3: {
                char nome[50];
                printf("Informe o nome do produto a ser consultado: ");
                scanf(" %[^\n]", nome);
                consultarProdutoPorNome(estoque, numProdutos, nome);
                break;
            }
            case 4: {
                int limite;
                printf("Informe o limite de estoque baixo: ");
                scanf("%d", &limite);
                relatorioEstoqueBaixo(estoque, numProdutos, limite);
                break;
            }
            case 5: {
                printf("Saindo do programa.\n");
                return 0;
            }
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}


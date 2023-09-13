#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro {
    int telefone;
    char cidade[50];
    float tempo;
};

int main() {
    FILE *arq1;
    FILE *arq2;
    
    struct registro cliente;
    
    if ((arq1 = fopen("registro1.bat", "a+b")) == NULL) {
        printf("Erro na abertura do arquivo 1.\n");
        exit(1);
    }
    
    if ((arq2 = fopen("registro2.bat", "a+b")) == NULL) {
        printf("Erro na abertura do arquivo 2.\n");
        fclose(arq1); // Fecha o primeiro arquivo se o segundo não pôde ser aberto
        exit(1);
    }
    
    int op;
    
    while (1) {
        printf("\n\t MENU\n");
        printf(" 1 - Cadastrar registro no Arquivo 1\n");
        printf(" 2 - Cadastrar registro no Arquivo 2\n");
        printf(" 3 - Listar telefones das cidades em comum\n");
        printf(" 0 - Sair\n");
        
        scanf("%d", &op);
        
        switch (op) {
            case 1:
                printf("Digite o telefone: ");
                scanf("%d", &cliente.telefone);
                printf("Digite a cidade: ");
                scanf(" %[^\n]", cliente.cidade);
                printf("Digite o tempo de ligacao: ");
                scanf("%f", &cliente.tempo);
                
                fwrite(&cliente, sizeof(struct registro), 1, arq1);
                printf("Registro cadastrado com sucesso no Arquivo 1.\n");
                break;
                
            case 2:
                printf("Digite o telefone: ");
                scanf("%d", &cliente.telefone);
                printf("Digite a cidade: ");
                scanf(" %[^\n]", cliente.cidade);
                printf("Digite o tempo de ligacao: ");
                scanf("%f", &cliente.tempo);
                
                fwrite(&cliente, sizeof(struct registro), 1, arq2);
                printf("Registro cadastrado com sucesso no Arquivo 2.\n");
                break;
                
            case 3:
                rewind(arq1);
                rewind(arq2);
                
                printf("Cidades em comum:\n");
                
                while (fread(&cliente, sizeof(struct registro), 1, arq1) == 1) {
                    rewind(arq2);
                    while (fread(&cliente, sizeof(struct registro), 1, arq2) == 1) {
                        if (strcmp(cliente.cidade, cliente.cidade) == 0) {
                            printf("Telefone: %d, Cidade: %s\n", cliente.telefone, cliente.cidade);
                        }
                    }
                }
                break;
                
            case 0:
                fclose(arq1);
                fclose(arq2);
                exit(0);
                
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }
    return 0;
}

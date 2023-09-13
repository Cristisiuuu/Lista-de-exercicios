#include<stdio.h>
#include<stdlib.h>

struct registro{
	int telefone;
	char cidade[50];
	float tempo;
};

int main(){
	FILE *arq1;
	FILE *arq2;
	
	int op = 5;
	
	if((arq1 = fopen("registro1.bat","a+b"))== NULL){
		printf("Erro na abertura do arquivo.");
		exit(1);
	}
	if((arq2 = fopen("registro2.bat","a+b"))== NULL){
		printf("Erro na abertura do arquivo.");
		exit(1);
	}
	
	while(op != 0){
		printf("\t MENU\n");
		printf(" 1 - Cadastrar Arquivo 1\n");
		printf(" 2 - Cadastrar Arquivo 2\n");
		printf(" 3 - Consultar Arquivo 1\n");
		printf(" 4 - Consultar Arquivo 2\n");
		printf(" 0 - Sair\n");
  
		scanf("%d", &op);

		switch (op) {
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
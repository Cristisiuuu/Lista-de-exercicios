#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct registro{
	char nome[50];
	char rua[50];
	int numero;
	int telefone;
	char cidade[50];
	char estado[50];
};

void CriarRegistro(FILE *arq){
	struct registro cliente;
	
	printf("Digite o nome: ");
    scanf(" %[^\n]", cliente.nome);
    printf("Digite a rua: ");
    scanf(" %[^\n]", cliente.rua);
    printf("Digite o número: ");
    scanf("%d", &cliente.numero);
    printf("Digite o telefone: ");
    scanf("%d", &cliente.telefone);
    printf("Digite a cidade: ");
    scanf(" %[^\n]", cliente.cidade);
    printf("Digite o estado: ");
    scanf(" %[^\n]", cliente.estado);
    
    fwrite(&cliente, sizeof(struct registro), 1, arq);
    printf("registro criado com sucesso.\n");
}

void ListarRegistro(FILE *arq){
	struct registro cliente;
	
	rewind(arq); // essa função retorna a posição corretamente do arquivo para o inicio
	while (fread(&cliente, sizeof(struct registro), 1, arq) == 1) {
        printf("Nome: %s\n", cliente.nome);
        printf("Rua: %s\n", cliente.rua);
        printf("Número: %d\n", cliente.numero);
        printf("Telefone: %d\n", cliente.telefone);
        printf("Cidade: %s\n", cliente.cidade);
        printf("Estado: %s\n", cliente.estado);
        printf("----------------------\n");
    }
}

void RemoverRegistro(FILE *arq){
	struct registro cliente;
	char nome[50];
	
	printf("Digite o nome do registro a ser removido: ");
	scanf(" %[^\n]", nome);
	
	FILE *temp = fopen("temp.bat", "w+b");
	
	rewind(arq);
	
	while ( fread(&cliente, sizeof(struct registro), 1, arq) == 1){
		if(strcmp(cliente.nome , nome) != 0){
			fwrite(&cliente, sizeof(struct registro), 1, temp);
		}
	}
	fclose(arq);
	fclose(temp);
	
	remove("arquivo.bat");
	rename("temp.bat", "arquivo.bat");
}

void Menu(FILE *arq) {
    int op;

    while (1) {
        printf("\t MENU\n");
        printf(" 1 - Criar Registro\n");
        printf(" 2 - Listar Registros\n");
        printf(" 3 - Remover Registro\n");
        printf(" 0 - Sair\n");

        scanf("%d", &op);

        switch (op) {
            case 1:
                CriarRegistro(arq);
                break;

            case 2:
                ListarRegistro(arq);
                break;

            case 3:
                RemoverRegistro(arq);
                break;

            case 0:
                fclose(arq);
                exit(0);

            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

int main(){
	struct registro cliente;
	
	FILE *arq;
	
	if((arq = fopen("arquivo.bat", "a+b"))== NULL){
		printf("Erro na hora de abrir o arquivo.");
		exit(1);
	}
	
	Menu(arq);
	
	return 0;
}

#include <stdio.h>
#include <string.h>

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Endereco {
    char rua[50];
    char cidade[50];
    char Estado[50];
    int cep;
};

struct Aluno {
    char nome[50];
    struct Data dataNascimento;
    int RG;
    char sexo[10];
    struct Endereco endereco;
    int RA;
    double CR;
};

// Função para inserir um novo aluno no cadastro
int inserirAluno(struct Aluno aluno[], int *numAlunos) {
    if (*numAlunos < 100) {
        struct Aluno novoAluno;
        printf("Digite o nome do aluno: ");
        scanf(" %[^\n]s", novoAluno.nome);
        printf("Digite a data de nascimento (dia mes ano): ");
        scanf("%d %d %d", &novoAluno.dataNascimento.dia, &novoAluno.dataNascimento.mes, &novoAluno.dataNascimento.ano);
        printf("Digite o RG do aluno: ");
        scanf("%d", &novoAluno.RG);
        printf("Digite o sexo do aluno: ");
        scanf(" %[^\n]s", novoAluno.sexo);
        printf("Digite o endereço do aluno (rua cidade estado cep): ");
        scanf(" %[^\n]s %s %s %d", novoAluno.endereco.rua, novoAluno.endereco.cidade, novoAluno.endereco.Estado, &novoAluno.endereco.cep);
        printf("Digite o RA do aluno: ");
        scanf("%d", &novoAluno.RA);
        printf("Digite o CR do aluno: ");
        scanf("%lf", &novoAluno.CR);

        aluno[*numAlunos] = novoAluno;
        (*numAlunos)++;
        return 1;
    } else {
        printf("Limite de alunos atingido (100 alunos).\n");
        return 0;
    }
}

// Função para ordenar o cadastro por nome em ordem alfabética
void ordenarPorNome(struct Aluno aluno[], int numAlunos) {
	int i,j;
    for (i = 0; i < numAlunos - 1; i++) {
        for (j = 0; j < numAlunos - i - 1; j++) {
            if (strcmp(aluno[j].nome, aluno[j + 1].nome) > 0) {
                struct Aluno temp = aluno[j];
                aluno[j] = aluno[j + 1];
                aluno[j + 1] = temp;
            }
        }
    }
}

void ordenarPorCR(struct Aluno aluno[], int numAlunos) {
    int j, i;
	for (i = 0; i < numAlunos - 1; i++) {
        for (j = 0; j < numAlunos - i - 1; j++) {
            if (aluno[j].CR < aluno[j + 1].CR) {
                struct Aluno temp = aluno[j];
                aluno[j] = aluno[j + 1];
                aluno[j + 1] = temp;
            }
        }
    }
}

// Função para encontrar e imprimir os dados de um aluno por RA
void buscarPorRA(struct Aluno aluno[], int numAlunos, int RA) {
    int i;
	for (i = 0; i < numAlunos; i++) {
        if (aluno[i].RA == RA) {
            printf("Nome: %s\n", aluno[i].nome);
            printf("Data de Nascimento: %d/%d/%d\n", aluno[i].dataNascimento.dia, aluno[i].dataNascimento.mes, aluno[i].dataNascimento.ano);
            printf("RG: %d\n", aluno[i].RG);
            printf("Sexo: %s\n", aluno[i].sexo);
            printf("Endereço: %s, %s, %s, CEP: %d\n", aluno[i].endereco.rua, aluno[i].endereco.cidade, aluno[i].endereco.Estado, aluno[i].endereco.cep);
            printf("RA: %d\n", aluno[i].RA);
            printf("CR: %.2lf\n", aluno[i].CR);
            return;
        }
    }
    printf("Aluno com RA %d não encontrado.\n", RA);
}

// Função para imprimir o cadastro na ordem atual
void imprimirCadastro(struct Aluno aluno[], int numAlunos) {
    int i;
	printf("Cadastro de Alunos:\n");
    for (i = 0; i < numAlunos; i++) {
        printf("Nome: %s\n", aluno[i].nome);
        printf("Data de Nascimento: %d/%d/%d\n", aluno[i].dataNascimento.dia, aluno[i].dataNascimento.mes, aluno[i].dataNascimento.ano);
        printf("RG: %d\n", aluno[i].RG);
        printf("Sexo: %s\n", aluno[i].sexo);
        printf("Endereço: %s, %s, %s, CEP: %d\n", aluno[i].endereco.rua, aluno[i].endereco.cidade, aluno[i].endereco.Estado, aluno[i].endereco.cep);
        printf("RA: %d\n", aluno[i].RA);
        printf("CR: %.2lf\n", aluno[i].CR);
        printf("\n");
    }
}

int main() {
    struct Aluno alunos[100];
    int numAlunos = 0;
    int opcao;
    int RA;

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1) Inserir um novo aluno no cadastro.\n");
        printf("2) Ordenar o cadastro por nome em ordem alfabetica.\n");
        printf("3) Ordenar o cadastro por CR, maiores primeiro.\n");
        printf("4) Ler o valor de um RA e imprimir os dados do aluno no cadastro com o mesmo RA.\n");
        printf("5) Imprimir o cadastro na ordem atual.\n");
        printf("0) Sair.\n");
        printf("*------------------------------------------*");
        printf("\n\t\tOpcao:\t\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (inserirAluno(alunos, &numAlunos)) {
                    printf("Aluno inserido com sucesso.\n");
                }
                break;
            case 2:
                ordenarPorNome(alunos, numAlunos);
                printf("Cadastro ordenado por nome.\n");
                break;
            case 3:
                ordenarPorCR(alunos, numAlunos);
                printf("Cadastro ordenado por CR, maiores primeiro.\n");
                break;
            case 4:
                printf("Digite o RA do aluno a ser buscado: ");
                scanf("%d", &RA);
                buscarPorRA(alunos, numAlunos, RA);
                break;
            case 5:
                imprimirCadastro(alunos, numAlunos);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}


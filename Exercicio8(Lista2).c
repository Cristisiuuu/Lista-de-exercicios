#include <stdio.h>

// Definição das estruturas
struct DataNascimento {
    int dia;
    int mes;
    int ano;
};

struct TipoReg {
    char nome[50];
    int RG;
    double salario;
    int idade;
    char sexo; // M => maiusculo e F => feminino;
    struct DataNascimento dataNascimento;
};

struct TipoCadastro {
    struct TipoReg funcionario[100];
    int Quant;
};

int main() {
    struct TipoCadastro cadastro; // Cria uma instância da estrutura TipoCadastro
    cadastro.Quant = 0; // Inicializa a quantidade de funcionários

    // Exemplo de adição de um funcionário
    struct TipoReg funcionario1;
    strcpy(funcionario1.nome, "Joao da Silva");
    funcionario1.RG = 123456789;
    funcionario1.salario = 2500.0;
    funcionario1.idade = 30;
    funcionario1.sexo = 'M';
    funcionario1.dataNascimento.dia = 10;
    funcionario1.dataNascimento.mes = 5;
    funcionario1.dataNascimento.ano = 1990;

    // Adiciona o funcionário ao cadastro
    cadastro.funcionario[cadastro.Quant] = funcionario1;
    cadastro.Quant++;

    // Exemplo de adição de outro funcionário
    struct TipoReg funcionario2;
    strcpy(funcionario2.nome, "Maria da Silva");
    funcionario2.RG = 987654321;
    funcionario2.salario = 2800.0;
    funcionario2.idade = 28;
    funcionario2.sexo = 'F';
    funcionario2.dataNascimento.dia = 15;
    funcionario2.dataNascimento.mes = 8;
    funcionario2.dataNascimento.ano = 1995;

    // Adiciona o segundo funcionário ao cadastro
    cadastro.funcionario[cadastro.Quant] = funcionario2;
    cadastro.Quant++;

    // Exemplo de exibição dos funcionários cadastrados
    printf("Funcionarios cadastrados:\n");
    for (int i = 0; i < cadastro.Quant; i++) {
        printf("Nome: %s\n", cadastro.funcionario[i].nome);
        printf("RG: %d\n", cadastro.funcionario[i].RG);
        printf("Salario: %.2lf\n", cadastro.funcionario[i].salario);
        printf("Idade: %d\n", cadastro.funcionario[i].idade);
        printf("Sexo: %c\n", cadastro.funcionario[i].sexo);
        printf("Data de Nascimento: %02d/%02d/%d\n", cadastro.funcionario[i].dataNascimento.dia, cadastro.funcionario[i].dataNascimento.mes, cadastro.funcionario[i].dataNascimento.ano);
        printf("\n");
    }

    return 0;
}

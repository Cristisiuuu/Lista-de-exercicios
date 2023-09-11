#include <stdio.h>
#include <string.h>

struct Funcionario {
    char nome[100];
    float salario;
    char RG[20];
    char sexo;
    int dia_nascimento;
    int mes_nascimento;
    int ano_nascimento;
};

struct TipoCadastro {
    struct Funcionario funcionarios[100];
    int quantidade;
};

// Função para calcular o imposto retido na fonte com base no salário
float ImpostoRetido(float salario) {
    if (salario <= 1000.00) {
        return 0.00;
    } else if (salario <= 2000.00) {
        return salario * 0.10;
    } else if (salario <= 3500.00) {
        return salario * 0.15;
    } else {
        return salario * 0.25;
    }
}

// Função para imprimir o nome do funcionário e o imposto retido na fonte
void ImprimeImposto(struct Funcionario funcionario) {
    float imposto = ImpostoRetido(funcionario.salario);
    printf("Nome: %s, Imposto Retido na Fonte: %.2f\n", funcionario.nome, imposto);
}

// Função para buscar um funcionário pelo nome e retornar uma estrutura TipoReg
struct Funcionario BuscaNome(struct TipoCadastro cadastro, char nome[]) {
    struct Funcionario resultado;
    strcpy(resultado.nome, "");
    
    for (int i = 0; i < cadastro.quantidade; i++) {
        if (strcmp(cadastro.funcionarios[i].nome, nome) == 0) {
            resultado = cadastro.funcionarios[i];
            break;
        }
    }
    
    return resultado;
}

// Função para atualizar o salário de um funcionário com base no RG
void AtualizaSalario(struct TipoCadastro *cadastro, char RG[], float novoSalario) {
    for (int i = 0; i < cadastro->quantidade; i++) {
        if (strcmp(cadastro->funcionarios[i].RG, RG) == 0) {
            cadastro->funcionarios[i].salario = novoSalario;
            break;
        }
    }
}

// Função para encontrar o funcionário com o maior salário
struct Funcionario ListaMaraja(struct TipoCadastro cadastro) {
    struct Funcionario maraja = cadastro.funcionarios[0];
    
    for (int i = 1; i < cadastro.quantidade; i++) {
        if (cadastro.funcionarios[i].salario > maraja.salario) {
            maraja = cadastro.funcionarios[i];
        }
    }
    
    return maraja;
}

// Função para remover um funcionário com base no RG
void RemoveFuncionario(struct TipoCadastro *cadastro, char RG[]) {
    int posicao = -1;
    
    for (int i = 0; i < cadastro->quantidade; i++) {
        if (strcmp(cadastro->funcionarios[i].RG, RG) == 0) {
            posicao = i;
            break;
        }
    }
    
    if (posicao != -1) {
        for (int i = posicao; i < cadastro->quantidade - 1; i++) {
            cadastro->funcionarios[i] = cadastro->funcionarios[i + 1];
        }
        cadastro->quantidade--;
    }
}

// Função para listar funcionários que nasceram em um determinado mês
void ListaAniversarioMes(struct TipoCadastro cadastro, int mes) {
    for (int i = 0; i < cadastro.quantidade; i++) {
        if (cadastro.funcionarios[i].mes_nascimento == mes) {
            printf("Nome: %s, Dia de Nascimento: %d\n", cadastro.funcionarios[i].nome, cadastro.funcionarios[i].dia_nascimento);
        }
    }
}

// Função para listar funcionários que nasceram em uma data específica e têm um determinado sexo
void ListaAniversarioSexo(struct TipoCadastro cadastro, int dia, int mes, int ano, char sexo) {
    for (int i = 0; i < cadastro.quantidade; i++) {
        if (cadastro.funcionarios[i].dia_nascimento == dia &&
            cadastro.funcionarios[i].mes_nascimento == mes &&
            cadastro.funcionarios[i].ano_nascimento == ano &&
            cadastro.funcionarios[i].sexo == sexo) {
            printf("Nome: %s\n", cadastro.funcionarios[i].nome);
        }
    }
}

int main() {
    struct TipoCadastro cadastro;
    cadastro.quantidade = 0;
    // Você pode adicionar funcionários aqui ou ler de um arquivo, por exemplo

    // Exemplo de adição de funcionários manualmente:
    strcpy(cadastro.funcionarios[0].nome, "Alice");
    cadastro.funcionarios[0].salario = 1500.00;
    strcpy(cadastro.funcionarios[0].RG, "123456");
    cadastro.funcionarios[0].sexo = 'F';
    cadastro.funcionarios[0].dia_nascimento = 15;
    cadastro.funcionarios[0].mes_nascimento = 5;
    cadastro.funcionarios[0].ano_nascimento = 1990;
    cadastro.quantidade++;

    strcpy(cadastro.funcionarios[1].nome, "Bob");
    cadastro.funcionarios[1].salario = 2500.00;
    strcpy(cadastro.funcionarios[1].RG, "789012");
    cadastro.funcionarios[1].sexo = 'M';
    cadastro.funcionarios[1].dia_nascimento = 10;
    cadastro.funcionarios[1].mes_nascimento = 3;
    cadastro.funcionarios[1].ano_nascimento = 1985;
    cadastro.quantidade++;

    // Exemplo de uso das funções:

    printf("Funcionarios e Imposto Retido:\n");
    for (int i = 0; i < cadastro.quantidade; i++) {
        ImprimeImposto(cadastro.funcionarios[i]);
    }

    printf("\nBusca por nome:\n");
    struct Funcionario resultado = BuscaNome(cadastro, "Alice");
    if (strcmp(resultado.nome, "") != 0) {
        printf("Nome encontrado: %s\n", resultado.nome);
        printf("Salario: %.2f\n", resultado.salario);
        printf("RG: %s\n", resultado.RG);
    } else {
        printf("Nome nao encontrado.\n");
    }

    printf("\nAtualizacao de salario:\n");
    char RG_atualizar[20];
    printf("Digite o RG do funcionario a ser atualizado: ");
    scanf("%s", RG_atualizar);
    float novo_salario;
    printf("Digite o novo salario: ");
    scanf("%f", &novo_salario);
    AtualizaSalario(&cadastro, RG_atualizar, novo_salario);

    printf("\nLista do 'maraja' (funcionario com maior salario):\n");
    struct Funcionario maraja = ListaMaraja(cadastro);
    printf("Nome: %s, Salario: %.2f\n", maraja.nome, maraja.salario);

    printf("\nRemocao de funcionario por RG:\n");
    char RG_remover[20];
    printf("Digite o RG do funcionario a ser removido: ");
    scanf("%s", RG_remover);
    RemoveFuncionario(&cadastro, RG_remover);

    printf("\nLista de Aniversario por Mes (mes 5 no exemplo):\n");
    ListaAniversarioMes(cadastro, 5);

    printf("\nLista de Aniversario por Data e Sexo (10/03/1985, sexo M no exemplo):\n");
    ListaAniversarioSexo(cadastro, 10, 3, 1985, 'M');

    return 0;
}

#include <stdio.h>
#include <string.h>

void removerPontos(char *string) {
    int i, j;
    int tamanho = strlen(string);

    for (i = 0, j = 0; i < tamanho; i++) {
        if (string[i] != '.') {
            string[j] = string[i];
            j++;
        }
    }
    string[j] = '\0'; // Adicionar o caractere nulo para finalizar a string resultante
}

int main() {
    char string[100];

    printf("Digite uma string com pontos: ");
    fgets(string, sizeof(string), stdin);

    removerPontos(string);

    printf("String sem pontos: %s\n", string);

    return 0;
}


#include <stdio.h>
#include <string.h>

void cifraDeCesar(char *string, int chave) {
    int i;
    int tamanho = strlen(string);

    for (i = 0; i < tamanho; i++) {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = (string[i] - 'A' + chave) % 26 + 'A';
        } else if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] = (string[i] - 'a' + chave) % 26 + 'a';
        }
    }
}

int main() {
    char string[100];
    int chave;

    printf("Digite a string a ser codificada: ");
    fgets(string, sizeof(string), stdin);

    printf("Digite a chave de codificação (um numero inteiro): ");
    scanf("%d", &chave);

    cifraDeCesar(string, chave);

    printf("String codificada: %s\n", string);

    return 0;
}



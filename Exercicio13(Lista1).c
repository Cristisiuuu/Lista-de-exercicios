#include <stdio.h>
#include <string.h>

int contarPalavras(const char *string) {
    int numeroPalavras = 0;

    char copiaString[20];
    strcpy(copiaString, string);

    char *token = strtok(copiaString, " \t\n");

    while (token != NULL) {
        numeroPalavras++;
        token = strtok(NULL, " \t\n");
    }

    return numeroPalavras;
}

int main() {
    char string[20];

    while (1) {
        printf("Digite uma string (ou 'sair' para encerrar): ");
        fgets(string, sizeof(string), stdin);
        string[strcspn(string, "\n")] = '\0';

        if (strcmp(string, "sair") == 0) {
            printf("Programa encerrado.\n");
            break;
        }

        int numeroDePalavras = contarPalavras(string);
        printf("O numero de palavras na string eh: %d\n", numeroDePalavras);
    }

    return 0;
}


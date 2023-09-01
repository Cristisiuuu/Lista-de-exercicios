#include <stdio.h>
#include <string.h>
#include <ctype.h>

int ehPalindromo(char *string) {
    int i, j;
    int tamanho = strlen(string);

    // Remover espa�os e transformar letras mai�sculas em min�sculas
    char processada[tamanho + 1];
    int tamanhoProcessada = 0;

    for (i = 0; i < tamanho; i++) {
        if (isalpha(string[i])) {
            processada[tamanhoProcessada] = tolower(string[i]);
            tamanhoProcessada++;
        }
    }
    processada[tamanhoProcessada] = '\0';

    // Verificar se a string processada � um pal�ndromo
    tamanhoProcessada = strlen(processada);
    for (i = 0, j = tamanhoProcessada - 1; i < j; i++, j--) {
        if (processada[i] != processada[j]) {
            return 0; // N�o � um pal�ndromo
        }
    }
    return 1; // � um pal�ndromo
}

int main() {
    char string[100];

    printf("Digite uma string: ");
    fgets(string, sizeof(string), stdin);

    if (ehPalindromo(string)) {
        printf("A string eh um palindromo.\n");
    } 
	else {
        printf("A string nao eh um palindromo.\n");
    }

    return 0;
}


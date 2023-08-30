#include <stdio.h>

int main() {
    char string[100];
    printf("Digite uma string contendo 0's e 1's: ");
    scanf("%s", string);

    int contagem = 0;
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == '1') {
            contagemt++;
        }
    }

    printf("O numero de ocorrencias de '1' na string eh: %d\n", contagem);

    return 0;
}

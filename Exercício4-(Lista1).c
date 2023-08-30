#include <stdio.h>

int main() {
    char inputString[100];
    printf("Digite uma string contendo 0's e 1's: ");
    scanf("%s", inputString);

    int count = 0;
    for (int i = 0; inputString[i] != '\0'; i++) {
        if (inputString[i] == '1') {
            count++;
        }
    }

    printf("O numero de ocorrencias de '1' na string eh: %d\n", count);

    return 0;
}

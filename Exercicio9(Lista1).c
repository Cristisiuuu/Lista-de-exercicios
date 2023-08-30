#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char string[20], caractere;
    int i;

    puts("Digite um caractere para substituir todas as vogais:");
    scanf(" %c", &caractere); 

	// Captura o caractere de nova linha após a leitura do caractere
    getchar(); 

    puts("Digite algo:");
    fgets(string, sizeof(string), stdin);

    for (i = 0; string[i] != '\0'; i++) {
        char vogal = tolower(string[i]);
        if (vogal == 'a' || vogal == 'e' || vogal == 'i' || vogal == 'o' || vogal == 'u') {
            string[i] = caractere;
        }
    }

    printf("Ficou assim:\n%s", string);

    return 0;
}


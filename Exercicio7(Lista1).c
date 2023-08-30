#include <stdio.h>
#include <string.h>
#include <ctype.h>//precisa incluir essa biblioteca

int main() {
    char string[20];
    int i;

    printf("Digite algo e vou remover as vogais: ");
    fgets(string, sizeof(string), stdin);

    for (i = 0; string[i] != '\0'; i++) {
        // Converte o caractere para minúsculo
		char caractere = tolower(string[i]);
		 
        if (caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u') {
            string[i] = ' ';
        }
    }

    printf("O resultado eh:\n%s", string);
    return 0;
}


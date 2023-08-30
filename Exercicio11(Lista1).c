#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char string1[20], string2[20];
    int i;

    puts("Digite algo:");
    fgets(string1, sizeof(string1), stdin);
    puts("Digite algo:");
    fgets(string2, sizeof(string2), stdin);

    //Usei strlen para determinar o comprimento da string
    for (i = 0; i < strlen(string1); i++) {
        char caractere1 = tolower(string1[i]); 
        char caractere2 = tolower(string2[i]);
        if (caractere1 == 'a' || caractere1 == 'e' || caractere1 == 'i' || caractere1 == 'o' || caractere1 == 'u') {
            string1[i] = '*';
        }
        if (caractere2 == 'a' || caractere2 == 'e' || caractere2 == 'i' || caractere2 == 'o' || caractere2 == 'u') {
            string2[i] = '*';
        }
    }
    printf("O resultado eh (string1):\n%s\nO resultado eh (string2):\n%s",strrev(string1), strrev(string2));

    return 0;
}


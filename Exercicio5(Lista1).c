#include <stdio.h>

int main() {
    char string[20];
    int i;

    puts("Digite os caracteres que contenham 0 e vou substituir por 1:\n");
    gets(string);

    for ( i = 0; string[i] != '\0'; i++) {
        if (string[i] == '0') {
            string[i] = '1'; 
        }
    }

    printf("A sequencia de caracteres eh:\n%s\n", string);

    return 0;
}


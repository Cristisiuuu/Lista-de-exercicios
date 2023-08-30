#include <stdio.h>

void paraMaiusculas(char *str) {
    while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - ('a' - 'A');
        }
        str++;
    }
}

int main() {
    char entrada[100];
    
    printf("Digite uma sequencia de caracteres: ");
    fgets(entrada, sizeof(entrada), stdin);
    
    paraMaiusculas(entrada);
    
    printf("Sequencia convertida: %s", entrada);
    
    return 0;
}


#include <stdio.h>

void paraMinusculas(char *str) {//recebe um ponteiro para a o vetor
    while (*str) {
        if (*str >= 'A' && *str <= 'Z') {
            *str = *str + ('a' - 'A');
        }
        str++;
    }
}

int main() {
    char entrada[100];
    
    printf("Digite uma sequencia de caracteres: ");
    fgets(entrada, sizeof(entrada), stdin);//garante que não excede o tamanho do vetor
    
    paraMinusculas(entrada);
    
    printf("Sequencia convertida: %s", entrada);
    
    return 0;
}


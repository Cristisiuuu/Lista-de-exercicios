#include <stdio.h>

//recebe um ponteiro para a o vetor
void paraMinusculas(char *str) {
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
    //garante que não excede o tamanho do vetor
    //o fgets: usada para ler a linha de texto, ela recebe tres argumentos:
    //entrada: é o ponteiro onde os caracteres lidos serao armazenados
    //ja o sizeof(entrada): vê o tamanho do buffer "entrada", garante que o fgets não leia coisa que não precisa
    //stdin: indica que a leitura sera padrão (teclado), ou poderia ser um arquivo
    fgets(entrada, sizeof(entrada), stdin);
    
    paraMinusculas(entrada);
    
    printf("Sequencia convertida: %s", entrada);
    
    return 0;
}


#include <stdio.h>
#include <string.h>

// Função para ordenar um vetor alfanumérico
void ordenarVetor(char vetor[][100], int tamanho) {
    int i, j;
    char temp[100];

    for (i = 0; i < tamanho - 1; i++) {
        for (j = i + 1; j < tamanho; j++) {
            if (strcmp(vetor[i], vetor[j]) > 0) {
                strcpy(temp, vetor[i]);
                strcpy(vetor[i], vetor[j]);
                strcpy(vetor[j], temp);
            }
        }
    }
}

int main() {
    int numElementos;
    char vetor[45][100];
    int i;

    printf("Digite o numero de elementos: ");
    scanf("%d", &numElementos);

    if (numElementos <= 0 || numElementos > 45) {
        printf("Numero de elementos inválido.\n");
        return 1;
    }

    printf("Digite os elementos:\n");
    for (i = 0; i < numElementos; i++) {
        scanf("%s", vetor[i]);
    }

    ordenarVetor(vetor, numElementos);

    printf("Vetor ordenado:\n");
    for (i = 0; i < numElementos; i++) {
        printf("%s\n", vetor[i]);
    }

    return 0;
}


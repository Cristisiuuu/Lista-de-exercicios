#include <stdio.h>
#include <string.h>

// Função para encontrar a maior palavra em uma frase
void encontrarMaiorPalavra() {
    char frase[100];
    char maiorPalavra[100];
    int comprimentoMaior = 0;

    while (1) {
        printf("Digite uma frase (ou 'sair' para sair): ");
        fgets(frase, sizeof(frase), stdin);
        
        // Remover o caractere de nova linha
        frase[strcspn(frase, "\n")] = '\0'; 
        
        if (strcmp(frase, "sair") == 0) {
            printf("Saindo...\n");
            break;
        }

        char *token = strtok(frase, " ");
        while (token != NULL) {
            int comprimentoPalavra = strlen(token);
            if (comprimentoPalavra > comprimentoMaior) {
                comprimentoMaior = comprimentoPalavra;
                strcpy(maiorPalavra, token);
            }
            token = strtok(NULL, " ");
        }

        if (comprimentoMaior > 0) {
            printf("A maior palavra na frase eh: %s\n", maiorPalavra);
        } else {
            printf("Nenhuma palavra encontrada.\n");
        }
    }
}

int main() {
    encontrarMaiorPalavra();
    return 0;
}


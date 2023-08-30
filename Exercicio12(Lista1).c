#include <stdio.h>
#include <string.h>

int Ocorrencias(const char *frase, const char *palavra) {
    int contador = 0;
    int tamanhoFrase = strlen(frase);
    int tamanhoPalavra = strlen(palavra);
	int i;
	
    for (i = 0; i <= tamanhoFrase - tamanhoPalavra; i++) {
        if (strncmp(&frase[i], palavra, tamanhoPalavra) == 0) {
            contador++;
        }
    }
    return contador;
}

int main() {
    char frase[100];
    char palavra[20];
    int totalOcorrencias;

    while (1) {
        printf("Digite uma frase (ou 'sair' para encerrar): ");
        fgets(frase, sizeof(frase), stdin);
        // Remove a quebra de linha
        frase[strcspn(frase, "\n")] = '\0'; 

        if (strcmp(frase, "sair") == 0) {
            break;
        }

        printf("Digite a palavra que deseja contar: ");
        fgets(palavra, sizeof(palavra), stdin);
        palavra[strcspn(palavra, "\n")] = '\0';

        totalOcorrencias = Ocorrencias(frase, palavra);
        printf("A palavra '%s' ocorre %d vezes na frase.\n", palavra, totalOcorrencias);
    }

    printf("Programa encerrado.\n");

    return 0;
}


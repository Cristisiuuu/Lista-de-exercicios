#include <stdio.h>
#include <string.h>

void mostrarPalavras(char *string) {
	// Divide a string em palavras usando o espaço como delimitador
    char *token = strtok(string, " "); 
    while (token != NULL) {
        printf("%s\n", token);
        // Passa para a próxima palavra
        token = strtok(NULL, " "); 
    }
}

int main() {
    char string[100];
    int continuar = 1;

    while (continuar) {
        printf("Digite uma frase (ou 'sair' para sair): ");
        fgets(string, sizeof(string), stdin);

        // Remove a quebra de linha do final da string, se houver
        size_t len = strlen(string);
        
        if (len > 0 && string[len - 1] == '\n') {
            string[len - 1] = '\0';
        }

        if (strcmp(string, "sair") == 0) {
            continuar = 0; // Sai do loop se o usuário digitar "sair"
        }
		 // Chama a função para mostrar as palavras
        mostrarPalavras(string);
    }

    return 0;
}


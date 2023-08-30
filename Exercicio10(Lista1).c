#include <stdio.h>
#include <string.h>

int main() {
    char string[20];
    char alvo, substituta;
    int i;

    printf("Digite uma frase: ");
    fgets(string, sizeof(string), stdin);

    printf("Digite a letra que deseja substituir: ");
    scanf(" %c", &alvo);

    printf("Digite a letra substituta: ");
    scanf(" %c", &substituta);

    for (i = 0; string[i] != '\0'; i++) {
        if (string[i] == alvo) {
            string[i] = substituta;
        }
    }

    printf("Ficou assim:\n%s", string);

    return 0;
}


#include <stdio.h>
#include <string.h>

int main() {
    char string1[20], string2[20];

    printf("Digite algo na primeira string:\n");
    gets(string1);

    printf("Digite algo na segunda string:\n");
    gets(string2);

    int i = 0;
    int diferente = 0;
    //esse while faz a comparação de caractere por caractere;
    while (string1[i] != '\0' && string2[i] != '\0') {
        if (string1[i] != string2[i]) {
            diferente = 1;
            break;
        }
        i++;
    }

    if (diferente || string1[i] != string2[i]) {
        puts("Diferentes ==> (0)\n");
    } else {
        puts("Iguais ==> (1)\n");
    }
    
    return 0;
}

#include <stdio.h>

int compareStrings(const char *str1, const char *str2) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i++;
    }

    if (str1[i] == '\0' && str2[i] == '\0') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char palavra[20];
    char palavra1[20];
    
    scanf("%19[^\n]%*c", palavra);
    scanf("%19[^\n]%*c", palavra1);
    
    if (compareStrings(palavra, palavra1)) {
        printf("sao iguais = 0");
    } else {
        printf("nao sao iguais = 1");
    }
    
    return 0;
}


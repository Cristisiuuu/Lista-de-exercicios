#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
	char string[20];
	int contagem = 0, i;
	
	puts("Digite algo que vou ver quantas vogais vc digitou:");
	fgets(string, sizeof(string), stdin);
	
    for (i = 0; string[i] != '\0'; i++) {
        char caractere = tolower(string[i]);
        
		if (caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u') {
            contagem++;
        }
    }

    printf("O numero de ocorrencias de vogais na string eh: %d\n", contagem);
	
	
	return 0;
}

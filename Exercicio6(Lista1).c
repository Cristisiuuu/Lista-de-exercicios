#include <stdio.h>
#include <string.h>

int main(){
	char string[20];
	
	puts("Digite uma frase que vou escrever ela de tras para frente:");
	gets(string);
	
	printf("A gora a string esta assim:\n%s\n", strrev(string));
	
	return 0;
}

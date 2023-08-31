#include<stdio.h>
#include<string.h>

int main(){
	char string[50];
	int i;
	
	puts("Digite uma palavra:\n");
	fgets(string,sizeof(string), stdin);
	for(i=0; i< strlen(string); i++){
		string[i]= string[i] + 1;
	}
	printf("\n%s\n", string);
	return 0;
}

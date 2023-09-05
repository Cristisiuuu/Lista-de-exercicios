#include<stdio.h>

struct dma{
	int dia;
	int mes;
	int ano;
};

int main(){
	struct dma primeiro, segundo;
	int dia_dia, dia_mes, dia_ano;
	
	scanf("%d %d %d", &primeiro.dia, &primeiro.mes, &primeiro.ano);	
	scanf("%d %d %d", &segundo.dia, &segundo.mes, &segundo.ano);
	
	if(primeiro.dia >= segundo.dia){	
		dia_dia = primeiro.dia - segundo.dia;
		if(primeiro.mes >= segundo.mes){
			dia_mes = primeiro.mes - segundo.mes;
			dia_mes = dia_mes * 30;
			if(primeiro.ano >= segundo.ano){
				dia_ano = primeiro.ano - segundo.ano;
				dia_ano = dia_ano * 365;
			}
		}
	}				
	
	printf("A diferenca de dias eh de: %d", dia_dia + dia_mes + dia_ano);
	
	return 0;
}
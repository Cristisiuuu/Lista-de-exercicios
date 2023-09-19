2°Critique a seguinte versão da função:
	
	
int busca (int x, int n, int v[]) {
 int j = 0;
 while (v[j] < x && j < n) ++j;
 return j;
}

//O problema é a ordem das condições no loop, deve ser:

/*
int busca (int x, int n, int v[]){
	int j =0;
	while (j<n && v[j] < x){
		++j;
	}
	return j;
}
*/

// A função abaixo recebe um vetor crescente v[0..n-1]
// com n >= 1 e um número x.
// Ela devolve um índice j em 0..n tal que v[j-1] < x <= v[j].
int buscabinaria (int x, int n, int v[]) {
	 int e, m, d;
	 
	 if (v[n-1] < x) return n;
	 
	 if (x <= v[0]) return 0; // agora v[0] < x <= v[n-1]
	 e = 0; d = n-1;
	 
	while (e < d-1) {
		 m = (e + d)/2;
		 if (v[m] < x) e = m;
		 else d = m;
	}
	 return d;
}

4°Responda as seguintes perguntas sobre a função buscabinaria descrita acima. 

a) Que acontece se "while (e < d-1)" for trocado por "while (e < d)"? ou por "while (e <= d-1)"?

	R .: Ira ocorrer um problema de loop, onde não irra parar em alguns casos ; 

b) Que acontece se "if (v[m] < x)" for trocado por "if (v[m] <= x)"?

	R .: Ele almentara uma chance de parada nesse no if;

c) Que acontece se "e = m" for trocado por "e = m+1" ou por "e = m-1"? E se "d = m" for trocado por "d = m+1" ou por "d = m-1"?

	R .: Os problemas serão parecidos, onde fara uma uma repeticao a menos;
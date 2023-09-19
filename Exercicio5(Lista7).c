#include <stdio.h>

// A função abaixo recebe um vetor crescente v[0..n-1]
// com n >= 1 e um número x.
// Ela devolve um índice j em 0..n tal que v[j-1] < x <= v[j].

int buscabinaria(int x, int n, int v[]) {
    int e, m, d;
    
    if (v[n - 1] < x) return n;
    if (x <= v[0]) return 0;

    e = 0;
    d = n - 1;

    while (e <= d) { 
        m = (e + d) / 2;
        if (v[m] < x) e = m + 1; 
        else d = m - 1; 
    }
    
    return d + 1; 
}

int main() {
    int x = 9, n = 14;
    int v[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27}; // Vetor crescente

    int resultado = buscabinaria(x, n, v);

    printf("Resultado: %d\n", resultado);

    return 0;
}

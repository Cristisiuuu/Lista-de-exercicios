#include <stdio.h>

struct Ponto {
    int x;
    int y;
};

// Funcao para determinar os cantos do retangulo
void determinarCantos(struct Ponto *v1, struct Ponto *v2) {
    struct Ponto temp;
    
// -> serve para acessar membros de uma estrutura quando esta usando ponteiros para estruturas
    if (v1->x > v2->x) {
        temp = *v1;
        *v1 = *v2;
        *v2 = temp;
    }
    
    if (v1->y > v2->y) {
        temp = *v1;
        *v1 = *v2;
        *v2 = temp;
    }
}

int main() {
    struct Ponto P, v1, v2;
    
    puts("Digite os valores dos vertices 1 e 2:");
    scanf("%d %d", &v1.x, &v1.y);
    scanf("%d %d", &v2.x, &v2.y);

    determinarCantos(&v1, &v2);
    
    puts("Digite o valor do ponto:");
    scanf("%d %d", &P.x, &P.y);
    
    if (P.x >= v1.x && P.x <= v2.x) {
        if (P.y >= v1.y && P.y <= v2.y) {
            printf("Esta dentro do retangulo!! ");
        }
    } else {
        printf("Nao esta dentro do retangulo!! ");
    }
    
    return 0;
}


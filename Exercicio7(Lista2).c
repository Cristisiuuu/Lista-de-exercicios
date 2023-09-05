#include<stdio.h>

struct vetor {
    float x;
    float y;
    float z;
};

struct vetor SomaVetor(struct vetor v1, struct vetor v2) {
    struct vetor soma;
    
    soma.x = v1.x + v2.x;
    soma.y = v1.y + v2.y;
    soma.z = v1.z + v2.z;
    
    return soma;
}

int main() {
    struct vetor v1, v2;
    
    puts("Digite a coordenada do vetor (x y z):\n");
    scanf("%f %f %f", &v1.x, &v1.y, &v1.z);
    scanf("%f %f %f", &v2.x, &v2.y, &v2.z);
    
    struct vetor resultado = SomaVetor(v1, v2);
    
    printf("A soma dos vetores eh: (%.2f, %.2f, %.2f)\n", resultado.x, resultado.y, resultado.z);
    
    return 0;
}

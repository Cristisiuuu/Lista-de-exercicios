#include <stdio.h>

struct complexo {
    double a;
    double b;
};

void lerComplexo(struct complexo *c) {
    printf("Digite a parte real: ");
    scanf("%lf", &c->a);
    printf("Digite a parte imaginaria: ");
    scanf("%lf", &c->b);
}

struct complexo somarComplexos(struct complexo c1, struct complexo c2) {
    struct complexo resultado;
    resultado.a = c1.a + c2.a;
    resultado.b = c1.b + c2.b;
    return resultado;
}

struct complexo subtrairComplexos(struct complexo c1, struct complexo c2) {
    struct complexo resultado;
    resultado.a = c1.a - c2.a;
    resultado.b = c1.b - c2.b;
    return resultado;
}

struct complexo multiplicarComplexos(struct complexo c1, struct complexo c2) {
    struct complexo resultado;
    resultado.a = (c1.a * c2.a) - (c1.b * c2.b);
    resultado.b = (c1.a * c2.b) + (c1.b * c2.a);
    return resultado;
}

int main() {
    struct complexo c1, c2, resultado;

    printf("Digite o primeiro numero complexo:\n");
    lerComplexo(&c1);

    printf("Digite o segundo numero complexo:\n");
    lerComplexo(&c2);

    resultado = somarComplexos(c1, c2);
    printf("A soma dos numeros complexos: %.2lf + %.2lfi\n", resultado.a, resultado.b);

    resultado = subtrairComplexos(c1, c2);
    printf("A subtracao dos numeros complexos: %.2lf + %.2lfi\n", resultado.a, resultado.b);

    resultado = multiplicarComplexos(c1, c2);
    printf("A multiplicacao dos numeros complexos: %.2lf + %.2lfi\n", resultado.a, resultado.b);

    return 0;
}


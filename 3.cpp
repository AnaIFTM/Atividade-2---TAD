#include <stdio.h>
#include <locale.h>

struct Conjunto {
    int elementos[20];
    int tamanho;
};

typedef struct Conjunto Conjunto;

void criarConjuntoVazio(Conjunto *conjunto) {
    conjunto->tamanho = 0;
}

void lerConjunto(Conjunto *conjunto) {
    printf("Digite o tamanho do conjunto: ");
    scanf("%d", &conjunto->tamanho);

    printf("Digite os elementos do conjunto:\n");
    for (int i = 0; i < conjunto->tamanho; i++) {
        scanf("%d", &conjunto->elementos[i]);
    }
}

void uniaoConjuntos(const Conjunto *conjuntoA, const Conjunto *conjuntoB, Conjunto *resultado) {
    criarConjuntoVazio(resultado);

    for (int i = 0; i < conjuntoA->tamanho; i++) {
        resultado->elementos[resultado->tamanho++] = conjuntoA->elementos[i];
    }

    for (int i = 0; i < conjuntoB->tamanho; i++) {
        int elemento = conjuntoB->elementos[i];
        int estaNoResultado = 0;

        for (int j = 0; j < resultado->tamanho; j++) {
            if (resultado->elementos[j] == elemento) {
                estaNoResultado = 1;
                break;
            }
        }

        if (!estaNoResultado) {
            resultado->elementos[resultado->tamanho++] = elemento;
        }
    }
}

void intersecaoConjuntos(const Conjunto *conjuntoA, const Conjunto *conjuntoB, Conjunto *resultado) {
    criarConjuntoVazio(resultado);

    for (int i = 0; i < conjuntoA->tamanho; i++) {
        int elemento = conjuntoA->elementos[i];

        for (int j = 0; j < conjuntoB->tamanho; j++) {
            if (conjuntoB->elementos[j] == elemento) {
                resultado->elementos[resultado->tamanho++] = elemento;
                break;
            }
        }
    }
}

int saoIguais(const Conjunto *conjuntoA, const Conjunto *conjuntoB) {
    if (conjuntoA->tamanho != conjuntoB->tamanho) {
        return 0;
    }

    for (int i = 0; i < conjuntoA->tamanho; i++) {
        int elemento = conjuntoA->elementos[i];
        int encontrado = 0;

        for (int j = 0; j < conjuntoB->tamanho; j++) {
            if (conjuntoB->elementos[j] == elemento) {
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            return 0;
        }
    }

    return 1;
}

void imprimirConjunto(const Conjunto *conjunto) {
    printf("{ ");
    for (int i = 0; i < conjunto->tamanho; i++) {
        printf("%d", conjunto->elementos[i]);
        if (i < conjunto->tamanho - 1) {
            printf(", ");
        }
    }
    printf(" }\n");
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    Conjunto conjuntoA, conjuntoB, conjuntoUniao, conjuntoIntersecao;

    criarConjuntoVazio(&conjuntoA);
    criarConjuntoVazio(&conjuntoB);
    criarConjuntoVazio(&conjuntoUniao);
    criarConjuntoVazio(&conjuntoIntersecao);

    printf("Digite o conjunto A:\n");
    lerConjunto(&conjuntoA);

    printf("Digite o conjunto B:\n");
    lerConjunto(&conjuntoB);

    uniaoConjuntos(&conjuntoA, &conjuntoB, &conjuntoUniao);
    intersecaoConjuntos(&conjuntoA, &conjuntoB, &conjuntoIntersecao);

    printf("Conjunto A: ");
    imprimirConjunto(&conjuntoA);

    printf("Conjunto B: ");
    imprimirConjunto(&conjuntoB);

    printf("União de A e B: ");
    imprimirConjunto(&conjuntoUniao);

    printf("Interseção de A e B: ");
    imprimirConjunto(&conjuntoIntersecao);

    if (saoIguais(&conjuntoA, &conjuntoB)) {
        printf("Conjuntos A e B são iguais.\n");
    } else {
        printf("Conjuntos A e B não são iguais.\n");
    }

    return 0;
}


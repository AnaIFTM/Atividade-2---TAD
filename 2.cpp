#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAX_FUNCIONARIOS 10

struct Funcionario {
    char nome[100];
    char cargo[100];
    double salarioBase;
    double beneficios;
    double descontos;
    double salarioLiquido;
};

typedef struct Funcionario Funcionario;

void calcularSalarioLiquido(Funcionario *funcionario) {
    funcionario->salarioLiquido = funcionario->salarioBase + funcionario->beneficios - funcionario->descontos;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
    Funcionario loja[MAX_FUNCIONARIOS];
    int numFuncionarios;

    printf("Digite o n�mero de funcion�rios (at� %d): ", MAX_FUNCIONARIOS);
    scanf("%d", &numFuncionarios);

    if (numFuncionarios > MAX_FUNCIONARIOS) {
        printf("N�mero de funcion�rios excede o limite.\n");
        return 1;
    }

    for (int i = 0; i < numFuncionarios; i++) {
        printf("Funcion�rio %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]s", loja[i].nome);
        printf("Cargo: ");
        scanf(" %[^\n]s", loja[i].cargo);
        printf("Sal�rio base: ");
        scanf("%lf", &loja[i].salarioBase);
        printf("Benef�cios: ");
        scanf("%lf", &loja[i].beneficios);
        printf("Descontos: ");
        scanf("%lf", &loja[i].descontos);

        calcularSalarioLiquido(&loja[i]);
        printf("\n");
    }

    printf("Dados dos funcion�rios:\n");
    for (int i = 0; i < numFuncionarios; i++) {
        printf("Funcion�rio %d:\n", i + 1);
        printf("Nome: %s\n", loja[i].nome);
        printf("Cargo: %s\n", loja[i].cargo);
        printf("Sal�rio l�quido: %.2lf\n", loja[i].salarioLiquido);
        printf("\n");
    }

    double somaSalarios = 0;
    for (int i = 0; i < numFuncionarios; i++) {
        somaSalarios += loja[i].salarioLiquido;
    }
    double mediaSalarial = somaSalarios / numFuncionarios;
    printf("M�dia salarial da loja: %.2lf\n", mediaSalarial);

    int indiceMaiorSalario = 0;
    for (int i = 1; i < numFuncionarios; i++) {
        if (loja[i].salarioLiquido > loja[indiceMaiorSalario].salarioLiquido) {
            indiceMaiorSalario = i;
        }
    }
    printf("Funcion�rio com maior sal�rio: %s\n", loja[indiceMaiorSalario].nome);

    return 0;
}


#include <stdio.h>
#include <string.h>
#include <locale.h>
#define maxclientes 50

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Cliente {
    char nome[100];
    struct Data dataNascimento;
    int idade;
    char sexo;
};

int calcularIdade(struct Data dataNascimento, struct Data atual) {
    int idade = atual.ano - dataNascimento.ano;

    if ((dataNascimento.mes > atual.mes) || (dataNascimento.mes == atual.mes && dataNascimento.dia > atual.dia)) {
        idade--;
    }

    return idade;
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    struct Cliente clientes[maxclientes];
    struct Data dataAtual;

    int quantidadeClientes = 0;

    printf("Digite a data atual (DD MM AAAA): ");
    scanf("%d %d %d", &dataAtual.dia, &dataAtual.mes, &dataAtual.ano);

    int opcao;
    do {
        printf("\n------------ Menu ------------\n");
        printf("1. Cadastrar um cliente\n");
        printf("2. Listar clientes\n");
        printf("3. Sair\n");
        printf("----- Escolha uma opção -----\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                if (quantidadeClientes < maxclientes) {
                    struct Cliente novoCliente;
                    printf("\nDigite o nome do cliente: ");
                    scanf(" %[^\n]s", novoCliente.nome);

                    printf("Digite a data de nascimento do cliente (DD MM AAAA): ");
                    scanf("%d %d %d", &novoCliente.dataNascimento.dia, &novoCliente.dataNascimento.mes, &novoCliente.dataNascimento.ano);

                    printf("Digite o gênero do cliente (M/F): ");
                    scanf("%c", &novoCliente.sexo);

                    novoCliente.idade = calcularIdade(novoCliente.dataNascimento, dataAtual);

                    clientes[quantidadeClientes] = novoCliente;
                    quantidadeClientes++;

                    printf("Cliente cadastrado com sucesso.\n");
                } else {
                    printf("Limite máximo de clientes atingido.\n");
                }
                break;
            
            case 2: 
                printf("\nLista de Clientes:\n");
                for (int i = 0; i < quantidadeClientes; i++) {
                    printf("Cliente %d:\n", i + 1);
                    printf("Nome: %s\n", clientes[i].nome);
                    printf("Data de Nascimento: %02d/%02d/%d\n", clientes[i].dataNascimento.dia, clientes[i].dataNascimento.mes, clientes[i].dataNascimento.ano);
                    printf("Idade: %d\n", clientes[i].idade);
                    printf("Sexo: %c\n", clientes[i].sexo);
                    printf("----------------------\n");
                }
                break;
            
            case 3: 
                printf("Encerrando o programa.\n");
                break;
            
            default:
                printf("Opção inválida. Por favor, escolha novamente.\n");
                break;
        }
    } while (opcao != 3);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAMANHO_PILHA 5

int topo = -1;
int pilha[TAMANHO_PILHA];

void empilhar(int valor) {
    if (topo < TAMANHO_PILHA - 1) {
        topo = topo + 1;
        pilha[topo] = valor;
        printf("O valor %i foi empilhado!\n\n", valor);
    } else {
        printf("A pilha está cheia!\n\n");
    }
}

void desempilhar() {
    if (topo == -1) {
        printf("A pilha está vazia! Nada para desempilhar.\n\n");
    } else {
        printf("O valor %i foi desempilhado!\n\n", pilha[topo]);
        topo = topo - 1;
    }
}

void imprimePilha() {
    if (topo == -1) {
        printf("A pilha está vazia!\n\n");
    } else {
        printf("Estado atual da pilha:\n");
        for (int i = topo; i >= 0; i--) {
            printf("%i\n", pilha[i]);
        }
        printf("\n");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int val, op = 10;

    while (op != 0) {
        system("cls"); // Limpa a tela (no Windows)
        imprimePilha();
        printf("O que deseja fazer? \n\n1 - Empilhar\n2 - Desempilhar\n0 - Sair\nDigite o código da opção: ");
        scanf("%i", &op);

        switch (op) {
            case 1:
                printf("Digite o valor a ser empilhado: ");
                scanf("%i", &val);
                empilhar(val);
                break;
            case 2:
                desempilhar();
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
        system("pause"); // Pausa o programa (no Windows)
    }
    return 0;
}

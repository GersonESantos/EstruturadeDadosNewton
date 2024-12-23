#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Estrutura da pilha
struct pilha {
    int num;                 // Valor armazenado
    struct pilha *proximo;   // Ponteiro para o próximo elemento
};

struct pilha *topo = NULL;   // Ponteiro para o topo da pilha
struct pilha *aux;           // Ponteiro auxiliar

// Função para empilhar um valor
void empilhar(int val) {
    struct pilha *novo = (struct pilha *)malloc(sizeof(struct pilha));
    if (novo == NULL) {
        printf("\nErro ao alocar memória!\n");
        return;
    }
    novo->num = val;
    
    novo->proximo = topo;
    topo = novo;
    printf("\nNumero empilhado!\n");
}

// Função para desempilhar
void desempilhar() {
    if (topo == NULL) {
        printf("\nA pilha está vazia!\n");
    } else {
        aux = topo;
        topo = topo->proximo;
        free(aux);
        printf("\nNumero desempilhado!\n");
    }
}

// Função para imprimir a pilha
void imprimePilha() {
    if (topo == NULL) {
        printf("\nA pilha está vazia!\n");
    } else {
        aux = topo;
        printf("\nElementos na pilha:\n");
        while (aux != NULL) {
            printf(" %d\n", aux->num);
            aux = aux->proximo;
        }
    }
}

// Função principal
int main() {
    setlocale(LC_ALL, "Portuguese");

    int val, op = 10;

    while (op != 0) {
        // Limpa a tela (alternativa mais segura para `system("cls")`)
        printf("\033[H\033[J"); 

        imprimePilha();
        printf("\nO que deseja fazer?\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Imprimir Pilha\n");
        printf("0 - Finalizar Cadastro\n");
        printf("Digite o código da opção: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Digite o valor a ser inserido na pilha: ");
                scanf("%d", &val);
                empilhar(val);
                break;
            case 2:
                desempilhar();
                break;
            case 3:
                imprimePilha();
                break;

            case 0:
                printf("\nEncerrando o programa.\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
                break;
        }
        // Pausa (alternativa mais segura para `system("pause")`)
        printf("\nPressione Enter para continuar...");
        getchar();
        getchar();
    }

    return 0;
}

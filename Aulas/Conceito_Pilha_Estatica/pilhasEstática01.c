#include <stdio.h>
#include <stdlib.h>

// Estrutura da pilha
struct Pilha {
    int topo;      // Índice do topo da pilha
    int capa;      // Capacidade máxima da pilha
    float *pElem;  // Ponteiro para o array de elementos
};

// Função para criar a pilha
void criarpilha(struct Pilha *p, int c) {
    p->topo = -1;  // Inicializa topo como vazio
    p->capa = c;
    p->pElem = (float *)malloc(c * sizeof(float));  // Aloca memória para a pilha
    if (p->pElem == NULL) {
        printf("Erro ao alocar memória para a pilha.\n");
        exit(1);
    }
}

// Verifica se a pilha está vazia
int estavazia(struct Pilha *p) {
    return (p->topo == -1);
}

// Verifica se a pilha está cheia
int estacheia(struct Pilha *p) {
    return (p->topo == p->capa - 1);
}

// Insere um elemento no topo da pilha
void empilhar(struct Pilha *p, float v) {
    if (estacheia(p)) {
        printf("Erro: a pilha está cheia!\n");
        return;
    }
    p->topo++;
    p->pElem[p->topo] = v;
    printf("Valor %.1f empilhado com sucesso!\n", v);
}

// Remove o elemento do topo da pilha
float desempilhar(struct Pilha *p) {
    if (estavazia(p)) {
        printf("Erro: a pilha está vazia!\n");
        return -1;  // Valor de erro
    }
    float aux = p->pElem[p->topo];
    p->topo--;
    return aux;
}

// Retorna o valor do topo da pilha sem removê-lo
float retornatopo(struct Pilha *p) {
    if (estavazia(p)) {
        printf("Erro: a pilha está vazia!\n");
        return -1;  // Valor de erro
    }
    return p->pElem[p->topo];
}

// Imprime os elementos da pilha
void imprimir(struct Pilha *p) {
    if (estavazia(p)) {
        printf("A pilha está vazia!\n");
    } else {
        printf("Elementos na pilha:\n");
        for (int i = p->topo; i >= 0; i--) {
            printf("%.1f\n", p->pElem[i]);
        }
    }
}

// Função principal
int main() {
    struct Pilha minhapilha;
    int capacidade, op = 0;
    float valor;

    printf("Qual a capacidade da pilha? ");
    scanf("%d", &capacidade);

    criarpilha(&minhapilha, capacidade);

    while (op != 99) {
        printf("\n1 - Empilhar (push)\n");
        printf("2 - Desempilhar (pop)\n");
        printf("3 - Mostrar o topo\n");
        printf("4 - Imprimir a pilha\n");
        printf("99 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);

        switch (op) {
            case 1: // Empilhar
                printf("Digite o valor a ser empilhado: ");
                scanf("%f", &valor);
                empilhar(&minhapilha, valor);
                break;

            case 2: // Desempilhar
                if (!estavazia(&minhapilha)) {
                    valor = desempilhar(&minhapilha);
                    printf("Valor %.1f desempilhado!\n", valor);
                }
                break;

            case 3: // Mostrar o topo
                if (!estavazia(&minhapilha)) {
                    valor = retornatopo(&minhapilha);
                    printf("Topo da pilha: %.1f\n", valor);
                }
                break;

            case 4: // Imprimir a pilha
                imprimir(&minhapilha);
                break;

            case 99: // Sair
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    // Libera a memória alocada para a pilha
    free(minhapilha.pElem);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Estrutura para representar a pilha
typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

// Função para inicializar a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// Função para verificar se a pilha está cheia
int cheia(Pilha *p) {
    return p->topo == MAX - 1;
}

// Função para verificar se a pilha está vazia
int vazia(Pilha *p) {
    return p->topo == -1;
}

// Função para empilhar (push)
void empilhar(Pilha *p, int valor) {
    if (cheia(p)) {
        printf("Erro: Pilha cheia!\n");
        return;
    }
    p->itens[++(p->topo)] = valor;
}

// Função para desempilhar (pop)
int desempilhar(Pilha *p) {
    if (vazia(p)) {
        printf("Erro: Pilha vazia!\n");
        return -1; // Indica erro
    }
    return p->itens[(p->topo)--];
}

// Função para inverter uma pilha
void inverterPilha(Pilha *original) {
    Pilha auxiliar;
    inicializar(&auxiliar);

    // Transfere os elementos para a pilha auxiliar
    while (!vazia(original)) {
        empilhar(&auxiliar, desempilhar(original));
    }

    // Transfere os elementos de volta para a pilha original
    while (!vazia(&auxiliar)) {
        empilhar(original, desempilhar(&auxiliar));
    }
}

// Função para imprimir a pilha
void imprimir(Pilha *p) {
    if (vazia(p)) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("TOPO -> ");
    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->itens[i]);
        if (i > 0) printf("-> ");
    }
    printf("-> FUNDO\n");
}

// Programa principal
int main() {
    Pilha minhaPilha;
    inicializar(&minhaPilha);

    // Empilha alguns valores
    empilhar(&minhaPilha, 4);
    empilhar(&minhaPilha, 5);
    empilhar(&minhaPilha, 1);
    empilhar(&minhaPilha, 2);

    printf("Pilha original:\n");
    imprimir(&minhaPilha);

    // Inverte a pilha
    inverterPilha(&minhaPilha);

    printf("Pilha invertida:\n");
    imprimir(&minhaPilha);

    return 0;
}

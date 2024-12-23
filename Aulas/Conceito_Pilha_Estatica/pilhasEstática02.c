#include <stdio.h>
#include <stdlib.h>

/*
Assim como já explicado, a pilha estática é criada tendo como base um vetor. Dessa forma, o código
a seguir traz a declaração da pilha e da variável topo, responsável por definir onde está o último 
valor da pilha, chamado de topo.
*/
struct Pilha {
    int topo;       // Índice do elemento no topo da pilha
    int capa;       // Capacidade máxima da pilha
    float *pElem;   // Vetor para armazenar os elementos da pilha
};

// Função para criar uma pilha com a capacidade fornecida
void criarpilha(struct Pilha *p, int c) {

  /*
  Note que topo foi inicializado com -1, isso porque quando a pilha está vazia, sua posição topo não pode ser 0
(zero), pois este é o índice que aponta para uma posição do vetor, e a posição topo só deverá assumir o primeiro
campo do vetor quando houver um valor inserido.
Veja  código a seguir que a função empilhar insere novos elementos no topo da pilha. Ela recebe o
valor via parâmetro e, após conferir se a pilha não está cheia, atualiza o topo com a próxima posição e insere o
elemento no novo topo.
  */
    p->topo = -1; // Inicializa o topo como -1 (pilha vazia)
    p->capa = c;
    p->pElem = (float *)malloc(c * sizeof(float));
    if (p->pElem == NULL) { // Verifica se a memória foi alocada corretamente
        printf("Erro ao alocar memória para a pilha!\n");
        exit(1);
    }
}

// Função para verificar se a pilha está vazia
int estavazia(struct Pilha *p) {
    return p->topo == -1;
}

// Função para verificar se a pilha está cheia
int estacheia(struct Pilha *p) {
    return p->topo == p->capa - 1;
}
/*Veja  código a seguir que a função empilhar insere novos elementos no topo da pilha. Ela recebe o
valor via parâmetro e, após conferir se a pilha não está cheia, atualiza o topo com a próxima posição e insere o
elemento no novo topo.
*/
// Função para empilhar um elemento
void empilhar(struct Pilha *p, float v) {
    if (estacheia(p)) {
        printf("A pilha está cheia, não é possível empilhar!\n");
        return;
    }
    p->topo++;             // Incrementa o topo
    p->pElem[p->topo] = v; // Insere o elemento no novo topo
}

// Função para desempilhar um elemento
float desempilhar(struct Pilha *p) {
    if (estavazia(p)) {
        printf("A pilha está vazia, não é possível desempilhar!\n");
        return -1; // Retorna um valor inválido para indicar erro
    }
    float aux = p->pElem[p->topo]; // Armazena o valor no topo
    p->topo--;                     // Decrementa o topo
    return aux;                    // Retorna o elemento desempilhado
}

// Função para obter o valor do elemento no topo da pilha
float retornatopo(struct Pilha *p) {
    if (estavazia(p)) {
        printf("A pilha está vazia, sem valor no topo!\n");
        return -1; // Retorna um valor inválido para indicar erro
    }
    return p->pElem[p->topo];
}

// Função para imprimir os elementos da pilha

/*
Mostrar pilha nada mais é do que imprimir os elementos presentes na pilha. Para que eles apareçam da forma que
se demonstra uma pilha, a impressão é feita do fim para o início e com salto de linha para que apareça na vertical.
Caso a lista esteja vazia, será mostrada uma mensagem infor
*/
void imprimir(struct Pilha *p) {
    if (estavazia(p)) {
        printf("A pilha está vazia!\n\n");
    } else {
        printf("Elementos da pilha:\n");
        for (int i = p->topo; i >= 0; i--) {
            printf("%.1f\n", p->pElem[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Pilha minhapilha; // Declaração da pilha
    int capacidade, op = 0; // Variáveis para capacidade da pilha e opção do menu
    float valor;

    printf("Qual a capacidade da pilha?\n");
    scanf("%d", &capacidade);

    criarpilha(&minhapilha, capacidade); // Criação da pilha

    while (op != 99) { // Loop para o menu
        printf("\nMenu de Opções:\n");
        printf("1 - Empilhar (push)\n");
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
                valor = desempilhar(&minhapilha);
                if (valor != -1) {
                    printf("Valor desempilhado: %.1f\n", valor);
                }
                break;

            case 3: // Mostrar o topo
                valor = retornatopo(&minhapilha);
                if (valor != -1) {
                    printf("Topo da pilha: %.1f\n", valor);
                }
                break;

            case 4: // Imprimir a pilha
                imprimir(&minhapilha);
                break;

            case 99: // Sair
                printf("Programa finalizado.\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    // Libera a memória alocada para a pilha
    free(minhapilha.pElem);

    return 0;
}

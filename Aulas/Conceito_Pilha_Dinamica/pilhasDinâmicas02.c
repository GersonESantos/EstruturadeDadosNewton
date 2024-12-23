#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura
struct elemento {
    int valor;
    struct elemento *proximo;
};

int main() {
    // Alocação de memória para um novo elemento
    struct elemento *novo = (struct elemento *)malloc(sizeof(struct elemento));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Atribuição de valores aos campos do novo elemento
    novo->valor = 10;
    novo->proximo = NULL;

    // Exibição dos valores atribuídos
    printf("Valor: %d\n", novo->valor);

    // Liberação da memória alocada
    free(novo);

    return 0;
}
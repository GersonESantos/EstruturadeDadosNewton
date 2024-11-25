/*Fila é uma estrutura do tipo FIFO (First In First Out), ou seja, o primeiro
elemento inserido será o primeiro a ser removido. Cada elemento da estrutura
pode armazenar um ou vários dados e um ponteiro para o próximo elemento, o que
permite o encadeamento e mantêm uma estrutura linear.

A estrutura do tipo fila possui um ponteiro denominado INICIO, onde todas
operações de remoção acontecem e outro denominado FIM, onde acontecem as
inserções.

Serão abordadas as seguintes operações:

• Inserir na fila;
• Consultar toda fila;
• Remover elemento;
• Esvaziar fila.*/

#include <stdio.h>
#include <stdlib.h>

/*registro que reprensentará cada elemento da fila*/
struct Elemento {
  int num;
  struct Elemento *prox;
};
typedef struct Elemento Elemento;

/*registro do tipo Fila contento dois ponteiros do tipo nó para controlar a
 * fila*/
struct Fila {
  struct Elemento *inicio; /*aponta para o elemento do início da fila*/
  struct Elemento *fim;    /*aponta para o elemento do fim da fila*/
};
typedef struct Fila Fila;

/*ponteiro auxiliar*/
Elemento *aux;

Fila *cria_fila() {
  /*alocação do ponteiro fi para controlar a lista*/
  Fila *fi = (Fila *)malloc(sizeof(Fila));
  if (fi != NULL) {
    /*a fila inicia-se vazia, portanto inicio e fim são iguais a NULL*/
    fi->fim = NULL;
    fi->inicio = NULL;
  }
  return fi;
}

void insere_elemento(Fila *fi) {
  /*a cada inserção alocamos dinamicamente um espaço para um novo elemento*/
  Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
  printf("\nDigite o numero a ser inserido na fila: ");
  scanf("%d", &novo->num);
  novo->prox = NULL;
  /*caso a fila esteja vazia, o elemento inserido será o primeiro e o último */
  if (fi->inicio == NULL) {
    fi->inicio = novo;
    fi->fim = novo;
    /*caso a fila ja contenha algum elemento, o novo elemento será sempre
     * inserido no fim da fila*/
  } else {
    fi->fim->prox = novo;
    fi->fim = novo;
  }
  printf("\nNumero inserido na fila!\n");
}

/*os elementos da fila serão mostrados do primeiro inserido(inicio) ao último
 * (fim)*/
void consulta_fila(Fila *fi) {
  if (fi->inicio == NULL) {
    printf("\nFila Vazia!!");
  } else {
    aux = fi->inicio;
    do {
      printf("%d ", aux->num);
      aux = aux->prox;
    } while (aux != NULL);
  }
}

/*o elemento a ser removido será sempre o primeiro elemento inserido(inicio)*/
void remove_elemento_fila(Fila *fi) {
  if (fi->inicio == NULL) {
    printf("\nFila Vazia!!");
  } else {
    aux = fi->inicio;
    printf("%d elemento removido! da fila\n", fi->inicio->num);
    fi->inicio = fi->inicio->prox;
    free(aux);
  }
}

/*a fila será esvaziada e o espaço ocupado por ela será desalocado*/
void esvazia_fila(Fila *fi) {
  if (fi->inicio == NULL) {
    printf("\nFila Vazia!!");
  } else {
    aux = fi->inicio;
    do {
      fi->inicio = fi->inicio->prox;
      free(aux);
      aux = fi->inicio;
    } while (aux != NULL);
    printf("\nFila Esvaziada!!");
  }
}

int main(void) {

  Fila *fi = cria_fila();
  int op = 0;

  while (op != 99) {

    printf("\n##Exemplo de Fila em C - NewtonPaiva##\n");
    printf("\n##Informe a opção desejada##\n");
    printf("\n1 - Inserir na fila \n2 - Consultar toda Fila \n3 - Remover "
           "elemento \n4 - Esvaziar Fila\n99 - Sair \n ");
    scanf("%d", &op);
    printf("\n\n");

    switch (op) {
    case 1: {
      printf("\n#Inserindo elemento na Fila#\n");
      insere_elemento(fi);
      break;
    }
    case 2: {
      printf("\n#Consulta toda Fila#\n");
      consulta_fila(fi);
      break;
    }
    case 3: {
      printf("\n#Remove elemento da Fila#\n");
      remove_elemento_fila(fi);
      break;
    }
    case 4: {
      printf("\n#Esvaziar Fila#\n");
      esvazia_fila(fi);
      break;
    }
    default: {
      printf("Opção invalida\nPrograma finalizado com sucesso\n");
      op = 99;
      break;
    }
    }
  }
  return 0;
}
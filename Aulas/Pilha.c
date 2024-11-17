/*Pilha é uma estrutura do tipo FILO (First In Last Out), ou seja, o primeiro
elemento inserido será o último a ser removido. Cada elemento da estrutura, pode
armazenar um ou vários dados e um ponteiro para o próximo elemento, o que
permite o encadeamento e mantêm uma estrutura linear.

Qualquer estrutura do tipo possui um ponteiro denominado TOPO, onde todas
operações de inserção e remoção acontecem.

Serão abordadas as seguintes operações:

• Inserir na pilha;
• Consultar toda pilha;
• Remover elemento;
• Esvaziar pilha.*/

#include <stdio.h>
#include <stdlib.h>

/*registro que reprensentará cada elemento da pilha*/
struct Elemento {
  int num;
  struct Elemento *prox;
};
typedef struct Elemento Elemento;

/*registro do tipo Pilha contento um ponteiro "topo" do tipo Elemento para controlar a pilha*/
struct Pilha {
  struct Elemento *topo; /*aponta para o elemento que esta topo da pilha*/
};
typedef struct Pilha Pilha;

/*ponteiro auxiliar*/
Elemento *aux;

Pilha *cria_pilha() {
  /*alocação do ponteiro pi para controlar a pilha*/
  Pilha *pi = (Pilha *)malloc(sizeof(Pilha));
  if (pi != NULL) {
    pi->topo = NULL; /*a pilha inicia-se vazia, portanto seu topo é igual a NULL*/
  }
  return pi;
}

/*todo elemento será inserido no topo da pilha*/
void insere_elemento(Pilha *pi) {
  /*a cada inserção alocamos dinamicamente um espaço para um novo elemento*/
  Elemento *novo = (Elemento *)malloc(sizeof(Elemento));
  printf("\nDigite o numero a ser inserido na pilha: ");
  scanf("%d", &novo->num);
  /*como o número inserido será o novo topo, ele apontará para o topo atual que será o segundo elemento da pilha*/
  novo->prox = pi->topo;
  /*topo aponta para o endereço de novo*/
  pi->topo = novo;
  printf("\nNumero inserido na pilha!\n");
}

/*os elementos da pilha serão mostrados do último inserido(topo) ao primeiro*/
void consulta_pilha(Pilha *pi) {
  /*caso a pilha esteja vazia*/
  if (pi->topo == NULL) {
    printf("\nPilha Vazia!!\n");
    /*caso a pilha não esteja vazia*/
  } else {
    aux = pi->topo;
    do {
      printf("%d\n", aux->num);
      aux = aux->prox;
    } while (aux != NULL);
  }
}

/*o elemento a ser removido será sempre o topo(último elemento inserido)*/
void remove_elemento_pilha(Pilha *pi) {
  if (pi->topo == NULL) {
    printf("\nPilha Vazia!!");
  } else {
    aux = pi->topo;
    printf("%d removido!", pi->topo->num);
    pi->topo = pi->topo->prox;
    free(aux);
  }
}

/*a pilha será esvaziada e o espaço ocupado por ela será desalocado*/
void esvazia_pilha(Pilha *pi) {
  if (pi->topo == NULL) {
    printf("\nPilha Vazia!!");
  } else {
    aux = pi->topo;
    do {
      pi->topo = pi->topo->prox;
      free(aux);
      aux = pi->topo;
    } while (aux != NULL);
    printf("\nPilha Esvaziada!!");
  }
}

int main(void) {
  Pilha *pi = cria_pilha();
  int op = 0;

  while (op != 99) {

    printf("\n\n");
    printf("\n##Exemplo de Pilha em C - NewtonPaiva##\n");
    printf("\n##Informe a opção desejada##\n");
    printf("\n1 - Inserir na pilha \n2 - Consultar toda pilha \n3 - Remover "
           "elemento \n4 - Esvaziar pilha\n99 - Sair \n ");
    scanf("%d", &op);
    printf("\n\n");

    switch (op) {
    case 1: {
      printf("\n#Inserindo elemento na pillha#\n");
      insere_elemento(pi);
      break;
    }
    case 2: {
      printf("\n#Consulta toda pillha#\n");
      consulta_pilha(pi);
      break;
    }
    case 3: {
      printf("\n#Remove elemento da pillha#\n");
      remove_elemento_pilha(pi);
      break;
    }
    case 4: {
      printf("\n#Esvaziar pillha#\n");
      esvazia_pilha(pi);
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
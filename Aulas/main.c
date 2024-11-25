#include <stdio.h>
#include <stdlib.h>


int main() {
  int i,j,mat[3][3],soma;
  float media;
    soma=0;
    printf("Digite os valores da matriz 3x3:\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            mat[i][j]=i;

            soma+=mat[i][j];
        }
    }
    media=soma/9;
    printf("A media dos elementos da matriz é: %f\n",media);
    return 0;
}
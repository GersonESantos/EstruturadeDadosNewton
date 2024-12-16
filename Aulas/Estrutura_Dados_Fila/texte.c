struct nodo
{
    int num ;
    nodo *proximo;/* data */
};
nodo *inicio = NULL;
nodo *fim = NULL;

void funcao(
    nodo *elemento= new nodo();
    elemento->num = valor;
    if(inicio == NULL){
        inicio = elemento;
        fim = elemento;
        elemento->proximo = NULL;
        }else{
            fim->proximo = elemento;
            fim = elemento;
        }
    
)
//situação: codigo visando uma mercearia, onde pode cadastrar um produto(P=1),aumentar quantidade do produto(2), comprar um produto(3) e remover um produto(4);
//primeiro, entre com a quantidade de movimentações a ser realizadas, após isso, considere:
//1-ADD PRODUTO(1, ID PARA O PRODUTO,QUANTIDADE E PREÇO);
//2- AUMENTAR QUANTIDADE(2, ID DO PRODUTO, QUANTIDADE);
//3- COMPRAR PRODUTO(3, ID DO PRODUTO);                            CONSIDERAR OPERAÇÕES SEM VIRGULA, EX: (   1 1 3 50    )
//4-REMOVER PRODUTO(4, ID DO PRODUTO);
//AO FINAL, ELE MOSTRA O FATURAMENTO DE CADA PRODUTO COMPRADO, SEGUINDO UMA ORDEM DE PREÇO DE 1 UNIDADE DE PRODUTO, DO MAIS CARO PARA O MAIS BARATO.



#include <stdio.h>
#include <stdlib.h>

typedef struct loja {
  int ID;
  int quantidadeID;
  float precoID;
  int qntVendasID;
  float lucroID;
  struct loja *proximo;
} loja;

typedef struct {
  int tam;
  loja *inicio;
} Lista;

/////////////////////////////////////
void lista_vazia(Lista *lista) {
  lista->inicio = NULL;
  }
////////////////////////////////////

void InsereItem(Lista *lista, int id, int quantidade, float preco) {
  loja *aux, *novo = malloc(sizeof(loja));

  aux=lista->inicio;
  while(aux && aux->ID != id && aux->ID!=0)
    aux=aux->proximo;
  if(aux && aux->ID==id){
    printf("ja existe\n");
  }
  else{
    novo->ID = id;
    novo->quantidadeID = quantidade;
    novo->precoID = preco;
    if(novo){
        if (lista->inicio == NULL) {
          novo->proximo = NULL;
          lista->inicio = novo;
        } else if (novo->precoID > lista->inicio->precoID) {
            novo->proximo = lista->inicio;
            lista->inicio = novo;
          } else {
              aux = lista->inicio;
              while (aux->proximo != NULL && novo->precoID < aux->proximo->precoID)
                aux = aux->proximo;
              novo->proximo = aux->proximo;
              aux->proximo = novo;
          }
        }
      }
  }

/////////////////////////////////////

void AumentaQuantidade(Lista *lista, int id, int quantidade) {
  loja *aux = malloc(sizeof(loja));
  aux = lista->inicio;
  while (aux && aux->ID != id)
    aux = aux->proximo;
  if (aux) {
    for (int i = aux->quantidadeID; i <= quantidade; i++) {
      aux->quantidadeID++;
    }
  } else {
    printf("nao existe\n");
  }
}

/////////////////////////////////////
void CompraProduto(Lista *lista, int id) {
  loja *aux = malloc(sizeof(loja));

  aux = lista->inicio;
  while (aux && aux->ID != id)
    aux = aux->proximo;
  if (aux) {
    if (aux->quantidadeID <= 0)
      printf("nao existe\n");
    else {
      aux->qntVendasID++;
      aux->lucroID = aux->qntVendasID * aux->precoID;
      aux->quantidadeID--;
    }
  } else {
    printf("nao existe\n");
  }
}

/////////////////////////////////////

void RemoveProduto(Lista *lista, int id) {
  loja *aux, *remover=NULL;


   aux=lista->inicio;
  while(aux && aux->ID != id)
    aux=aux->proximo;
  if(aux){
    free(aux);
    aux=aux->proximo;
  }
  else
    printf("nao existe\n");
}


////////////////////////////////////////

void ImprimirLucro(Lista lista) {
  loja *loja = lista.inicio;

  while (loja && loja->lucroID != 0) {
    printf("%d:%.2f\n", loja->ID, loja->lucroID);
    loja = loja->proximo;
  }
}

///////////////////////////////////////

int main() {
  Lista lista;
  lista_vazia(&lista);
  int movimentacao = 0, P, id, quantidade;
  float preco;

  scanf("%d", &movimentacao);
  for (int i = 1; i <= movimentacao; i++) {

    scanf("%d", &P);

    switch (P) {
    case 1:
      scanf("%d %d %f", &id, &quantidade, &preco);
      InsereItem(&lista, id, quantidade, preco);
      break;

    case 2:
      scanf("%d %d", &id, &quantidade);
      AumentaQuantidade(&lista, id, quantidade);
      break;

    case 3:
      scanf("%d", &id);
      CompraProduto(&lista, id);
      break;

    case 4:
      scanf("%d", &id);
      RemoveProduto(&lista, id);
      break;
    }
  }
  ImprimirLucro(lista);
  return 0;
}

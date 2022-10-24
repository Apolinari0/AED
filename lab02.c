#include <stdio.h>
#include <stdlib.h>
//1 DEFINIÇÃO DO PROBLEMA
//A biblioteca do ICT deseja realizar um estudo para coletar o perfil dos estudantes que
//realizam a reserva de um determinado livro. O objetivo é identificar quantos alunos de
//cada ano utilizam aquele livro. Considere que a lista de reserva de um determinado
//livro pode conter no máximo 10 reservas.

//TAREFA A
//Desenvolva um algoritmo em linguagem C - utilizando lista estática encadeada -
//que forneça uma lista com os números de RA’s ordenados dos alunos que realizaram
//a reserva de um determinado livro. Além disso, seu algoritmo também deve fornecer
//quantos usuários de cada ano realizaram a reserva daquele livro.
//Para obter essa informação, considere que o RA dos alunos do ICT muda de acordo
//com o ano de entrada na universidade. Por exemplo, todos os alunos que entraram
//em 2013 possuem um RA de 5 dígitos que inicia com 86. Os alunos que entraram em
//2014, possuem um RA de 5 dígitos que inicia com 96. Os alunos que entraram em
//2015 possuem RA de 6 dígitos que inicia com 106, assim por diante.


typedef struct No {
  int RA;
  struct No *proximo;
} No;

typedef struct {
  int tam;
  No *inicio;
} Lista;

typedef struct lista_anos{
    int quantidade[8];
}lista_anos;
lista_anos lista;
//-------------------------------
void biblioteca_vazia(Lista *lista) {
  lista->inicio = NULL;
  lista->tam = 0;
}

//-------------------------------
int confereListaCheia(Lista *lista){
  if(lista->tam < 10){
    return 1;
  }
  else
    return 0;
}
//-------------------------------
void Inserir(Lista *lista, int x) { // insere de forma ordenada
  No *aux, *elem = malloc(sizeof(No));

  if (elem!=NULL) {
    elem->RA = x;
    if (lista->inicio == NULL) {
      elem->proximo = NULL;
      lista->inicio = elem;
    } else if (elem->RA < lista->inicio->RA) {
      elem->proximo = lista->inicio;
      lista->inicio = elem;
    } else {
      aux = lista->inicio;
      while (aux->proximo != NULL && elem->RA > aux->proximo->RA)
        aux = aux->proximo;
      elem->proximo = aux->proximo;
      aux->proximo = elem;
    }
  }
  lista->tam++;
}
//-------------------------------
int Remove(Lista *lista, int x) {
  No *aux, *remover = NULL;


  if (lista->inicio) {
    if (lista->inicio->RA == x) {
      remover = lista->inicio;
      lista->inicio = remover->proximo;
      lista->tam--;
      return 1;
    } else {
      aux = lista->inicio;
      while (aux->proximo != NULL && aux->proximo->RA != x)
        aux = aux->proximo;
      if (aux->proximo!=NULL) {
        remover = aux->proximo;
        aux->proximo = remover->proximo;
        lista->tam--;
        return 1;
      }
      else{
        if (aux->proximo != NULL && aux->proximo->RA != x){
          return 0;
        }
      }
    }
  }

}

//-------------------------------
void Imprimir(Lista lista) {
  No *no = lista.inicio;

  while (no!=NULL) {
    printf("%d ", no->RA);
    no = no->proximo;
  }
}

//-------------------------------

void adiciona_ano(int x){ //contador envia valor para o struct vetor lista.quantidade.
    int cont=0,cont1=0,cont2=0,cont3=0,cont4=0,cont5=0,cont6=0,cont7=0;
        if(x >= 66000 && x <= 75999){ //2011
            cont++;
            lista.quantidade[0]=lista.quantidade[0]+cont;
        }
        else{
            if(x >=76000 && x <=85999){ //2012
                cont1++;
                lista.quantidade[1]=lista.quantidade[1]+cont1;
            }
            else{
                if(x>=86000 && x <= 95999){ //2013
                    cont2++;
                    lista.quantidade[2]=lista.quantidade[2]+cont2;
                }
                else{
                    if(x>=96000 && x <= 105999){ //2014
                        cont3++;
                        lista.quantidade[3]=lista.quantidade[3]+cont3;
                    }
                    else{
                        if(x>=106000 && x <= 115999){ //2015
                            cont4++;
                            lista.quantidade[4]=lista.quantidade[4]+cont4;
                        }
                        else{
                            if(x>=116000 && x <= 125999){ //2016
                                cont5++;
                                lista.quantidade[5]=lista.quantidade[5]+cont5;
                            }
                            else{
                                if(x>=126000 && x <= 135999){ //2017
                                    cont6++;
                                    lista.quantidade[6]=lista.quantidade[6]+cont6;
                                }
                                else {
                                    if(x>=136000 && x <= 140000){ //2018
                                        cont7++;
                                        lista.quantidade[7]=lista.quantidade[7]+cont7;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
//-------------------------------
void Imprime_Ano(){
    int anos=2011;
    int i=0;
    printf("\n");
    while(anos!=2019){
        printf("%d:%d\n",anos,lista.quantidade[i]);
        anos++;
        i++;
    }
}
//-------------------------------

int main() {
  Lista lista;
  biblioteca_vazia(&lista);

  int movimentacao = 0, variavel1, variavel2;
  scanf("%d", &movimentacao);

  for (int i = 0; i < movimentacao; i++) {
    scanf("%d %d", &variavel1, &variavel2);
    if (variavel1 == 1) {
      if(confereListaCheia(&lista)==0)
        printf("lista cheia ");
      else{
        Inserir(&lista, variavel2);
        adiciona_ano(variavel2);
        Imprimir(lista);
      }
    }else {
      if(Remove(&lista, variavel2)==1)
        Imprimir(lista);
      else
        printf("nao existe\n");
    }
  }
  Imprime_Ano();
  return 0;
}

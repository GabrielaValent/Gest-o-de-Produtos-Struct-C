#include <stdio.h>
#include <stdbool.h> 
#include <string.h>
#include <stdlib.h>

int cont = -1;

typedef struct Produto{
  int codigo;
  char descricao[100];
  float valor;
}Produto;

void cadastro(Produto *p){
  cont++;
  printf("\nCódigo: ");
  scanf("%d", &p[cont].codigo);
  printf("\nDescrição: ");
  scanf(" %[^\n]s", p[cont].descricao);
  fflush(stdin);
  printf("\nValor: ");
  scanf("%f", &p[cont].valor);
}

void listar(Produto *p){
  for(int i = 0; i < cont + 1; i++){
    printf("\nCódigo: %d", p[i].codigo);
    printf("\nDescrição: %s", p[i].descricao);
    printf("\nValor: %.2f", p[i].valor);
    printf("\n");
  }
}

void editar(Produto *p){
  int cod2, codigo2;
  char descricao2[100];
  float valor2;
  bool achou = false;
  printf("Digite o código do produto que você deseja excluir: ");
  scanf("%d", &cod2);
  for(int i = 0; i < cont + 1; i++){
    if(p[i].codigo == cod2){
      printf("\nCódigo: ");
      scanf("%d", &codigo2);
      p[i].codigo = codigo2;

      printf("\nDescrição: ");
      scanf(" %[^\n]s", descricao2);
      fflush(stdin);
      strcpy(p[i].descricao, descricao2);
      
      printf("\nValor: ");
      scanf("%f", &valor2);
      p[i].valor = valor2;
      
      achou = true;
      printf("\nProduto editado com sucesso!");
    }
  }
  if(!achou){
    printf("\nProduto não encontrado!");
  }
}

void excluir(Produto *p){
  int cod2;
  bool achou = false;
  printf("Digite o código do produto que você deseja excluir: ");
  scanf("%d", &cod2);
  for(int i = 0; i < cont + 1; i++){
    if(p[i].codigo == cod2){
      p[i].codigo = 0;
      strcpy(p[i].descricao, "0");
      p[i].valor = 0;
      
      achou = true;
      printf("\nProduto excluido com sucesso!");
    }
  }
  if(!achou){
    printf("\nProduto não encontrado!");
  }
}

int menu(){
  int opcao;
  printf("\nMENU\n");
  printf("1 - Cadastrar Produto\n");
  printf("2 - Editar Produto\n");
  printf("3 - Excluir Produto\n");
  printf("4 - Exibir Todos os Produtos\n");
  printf("5 - Exibir a Quantidade Total de Produtos\n");
  printf("6 - Sair\n");
  printf("Escolha uma opção: ");
  scanf("%d", &opcao);
  fflush(stdin);

  return opcao;
}

int main(void) {
  int op;
  Produto p[10];
  do{
    op = menu();
    switch(op){
      case 1:
        cadastro(p);
        break;
      case 2:
        editar(p);
        break;
      case 3:
        excluir(p);
        break;
      case 4:
        listar(p);
        break;
      case 5:
        printf("Quantidade total de produtos: %d\n", cont+1);
        break;
      case 6:
        printf("Saindo...");
        break;
      deafult: printf("Opção Inválida");
    }
  }while(op != 6);
  return 0;
}

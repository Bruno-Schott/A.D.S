#include <stdio.h>

int main(){

// Variáveis para os produtos
char produtoA[30]; 
char produtoB[30];

unsigned int estoqueA = 1000;
unsigned int estoqueB = 2000;

float valorA = 10.50;
float valorB = 20.40;

unsigned int estoqueMinimoA = 500;
unsigned int estoqueMinimoB = 2500;

int resultadoA, resultadoB;

double valorTotalA;
double valorTotalB;

// Informações para o produto
printf("Produto %s tem estoque %u e o valor unitario é R$ %.2f\n", produtoA, estoqueA, valorA);
printf("Produto %s tem estoque %u e o valor unitario é R$ %.2f\n", produtoB, estoqueB, valorB);

// comparações com o valor minimo de estoque
resultadoA = estoqueA < estoqueMinimoA;
resultadoB = estoqueB < estoqueMinimoB;

printf("O produto %s tem estoque minimo %d\n", produtoA, resultadoA);
printf("O produto %s tem estoque minimo %d\n", produtoB, resultadoB);

// comparações entre os valores totais dos produtos

printf("O valor total de A (R$ %.2f) é maior que o valor total de B (R$%.2f)\n", estoqueA * estoqueA * valorA > estoqueB * estoqueB * valorB);


return 0;

}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
// Constantes para usar na lógica dos números aleatórios
#define max_Num 1000
#define aletor_number 100
// Estrutura do nó da árvore binária de busca
struct Node {
int data;
struct Node *left, *right;
};
// Função para criar um novo nó na árvore
struct Node* newNode(int data) {
struct Node* node = (struct Node*)malloc(sizeof(struct Node));
node->data = data;
node->left = node->right = NULL;
return node;
}
// Função para inserir um novo valor na árvore binária de busca
struct Node* insert(struct Node* node, int data) {
if (node == NULL) return newNode(data);
if (data < node->data)
node->left = insert(node->left, data);
else if (data > node->data)
node->right = insert(node->right, data);
return node;
}
// Função para varredura pré-ordem
void preOrder(struct Node* root) {
if (root != NULL) {
printf("%d ", root->data);
preOrder(root->left);
preOrder(root->right);
}
}
// Função para varredura em-ordem
void inOrder(struct Node* root) {
if (root != NULL) {
inOrder(root->left);
printf("%d ", root->data);
inOrder(root->right);
}
}
// Função para varredura pós-ordem
void postOrder(struct Node* root) {
if (root != NULL) {
postOrder(root->left);
postOrder(root->right);
printf("%d ", root->data);
}
}
// Execução da tarefa
int main() {
struct Node* root = NULL;
clock_t start, end;
int comparacoes = 0;
int numeros[aletor_number];
int count = 0;
srand(time(NULL));
// Dados dos alunos
char nome[4][50] = {
"Igor Matias De Arruda Figueiredo",
"Joao Guilherme",
"Guilherme Antonio Felix Da Silva",
"Thiago Mesquita Pinheiro"
};
char matricula[4][50] = {
"202304207437",
"202304613168",
"202304634106",
"202108460872"
};
int soma = 0;
int resultado = 0;
// Print dos dados
printf("Dados dos alunos:\n");
printf("_\n");
for (int i = 0; i < 4; i++) {
printf("Nome: %s\n", nome[i]);
printf("Matricula: %s\n", matricula[i]);
printf("_\n");
int n = strlen(matricula[i]);
int ultimoDigito = atoi(&matricula[i][n - 1]);
soma += ultimoDigito;
resultado = soma % 3;
}
printf("Soma dos ultimos digitos: %d \n", soma);
printf("Modulo: %d\n", resultado);
// Gera números aleatórios apenas uma vez
while (count < aletor_number) {
int num = rand() % max_Num + 1;
int Gerado = 0;
for (int i = 0; i < count; i++) {
if (numeros[i] == num) {
Gerado = 1;
break;
}
}
if (!Gerado) {
numeros[count] = num;
count++;
}
}
for (int i = 0; i < aletor_number; i++) {
root = insert(root, numeros[i]);
}
printf("\nNumeros aleatórios desordenados: ");
for (int i = 0; i < aletor_number; i++) {
if (i < aletor_number - 1) {
printf("%d, ", numeros[i]);
} else {
printf("%d\n", numeros[i]);
}
}
// Ordena os números aleatórios usando bubble sort
if (resultado == 0) {
start = clock();
for (int i = 0; i < aletor_number - 1; i++) {
for (int j = 0; j < aletor_number - i - 1; j++) {
if (numeros[j] > numeros[j + 1]) {
int temp = numeros[j];
numeros[j] = numeros[j + 1];
numeros[j + 1] = temp;
comparacoes++;
}
}
}
end = clock();
double tempoGasto = ((double) (end - start)) / CLOCKS_PER_SEC * 100000;
// ordenação Bubble sort
printf("\nNumeros aleatorios ordenados Bubble Sort: ");
printf("[");
for (int i = 0; i < aletor_number; i++) {
if (i < aletor_number - 1) {
printf("%d, ", numeros[i]);
} else {
printf("%d", numeros[i]);
}
}
printf("]\n");
printf("\nNumero de comparaçãoes feitas no Bubble Sort: %d", comparacoes);
printf("\nTempo gasto na execução do Bubble Sort: %.2f ms", tempoGasto);
printf("\n\nVarredura em pré-ordem:\n");
preOrder(root);
} else if (resultado == 1) { // Ordena os números aleatórios usando Selection Sort
start = clock();
for (int i = 0; i < aletor_number - 1; i++) {
int menorNumero = i;
for (int j = i + 1; j < aletor_number; j++) {
if (numeros[j] < numeros[menorNumero]) {
menorNumero = j;
comparacoes++;
}
}
int elemento = numeros[menorNumero];
numeros[menorNumero] = numeros[i];
numeros[i] = elemento;
}
end = clock();
double tempoGasto = ((double) (end - start)) / CLOCKS_PER_SEC * 100000;
// Selection sort
printf("\nNumeros aleatorios ordenados Selection sort: ");
printf("[");
for (int i = 0; i < aletor_number; i++) {
if (i < aletor_number - 1) {
printf("%d, ", numeros[i]);
} else {
printf("%d", numeros[i]);
}
}
printf("]\n");
printf("\nNumero de comparaçãoes feitas no Selection Sort: %d", comparacoes);
printf("\nTempo gasto na execução do Selection Sort: %.2f ms", tempoGasto);
printf("\n\nVarredura em ordem:\n");
inOrder(root);
} else if (resultado == 2) { // Ordena os números aleatórios usando Insertion Sort
start = clock();
for (int i = 1; i < aletor_number; i++) {
int key = numeros[i];
int j = i - 1;
while (j >= 0 && numeros[j] > key) {
numeros[j + 1] = numeros[j];
j--;
comparacoes++;
}
numeros[j + 1] = key;
}
end = clock();
double tempoGasto = ((double) (end - start)) / CLOCKS_PER_SEC * 100000;
// Insertion sort
printf("\nNumeros aleatorios ordenados Insertion Sort: ");
printf("[");
for (int i = 0; i < aletor_number; i++) {
if (i < aletor_number - 1) {
printf("%d, ", numeros[i]);
} else {
printf("%d", numeros[i]);
}
}
printf("]\n");
printf("\nNumero de comparacoes feitas no Insertion Sort: %d", comparacoes);
printf("\nTempo gasto na execução do Insertion Sort: %.2f ms", tempoGasto);
printf("\n\nVarredura em pós-ordem:\n");
postOrder(root);
 }
return 0;

}

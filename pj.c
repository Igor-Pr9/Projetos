#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define max_Num 10
#define aletor_number 10

int main() {
   int numeros[max_Num];
   int count = 0;
   srand(time(NULL));

    char nome[3][50] = {
      "Igor Matias",
      "Joao Guilherme",
      "Guilherme Magalhaes"
    };

     char matricula[3][50] = {
      "22210",
      "22211",
      "22214"
    };
     int n = strlen(matricula);
     int soma = 0;
     int resultado = 0;

    printf("\nDados dos alunos:\n");
    for (int i = 0; i < 3; i++) {
        printf("Nome: %s\n", nome[i]);
        printf("Matricula: %s\n", matricula[i]);
        printf("\n");

        int ultimoDigito = matricula[i][n-1] -'0';
        soma += ultimoDigito;
        resultado = soma % 3;
    }
    printf("%d \n",soma);
    printf("%d",resultado);

    while(count < aletor_number){
        int num = rand() % max_Num;
    

   int Gerado = 0;
   for(int i = 0; i< count; i++){
    if(numeros[i] == num){
        Gerado = 1;
        break;
    }
   }

   if(!Gerado){
    numeros[count] = num;
    count++;
   }
    }
   printf("\n numeros aleatorios:");
   for(int i = 0; i < aletor_number; i++){
    printf("%d", numeros[i]);
   }
    
   printf("\n");

    
      
   return 0;
}
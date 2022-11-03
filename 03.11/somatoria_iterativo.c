#include <stdio.h>

unsigned long int somatoria(unsigned long int vetor[], unsigned long int n);

int main(){
    unsigned long int *vetor;
    unsigned long int n,i;

    scanf("%ld", &n);

    for(i=0;i<n;i++){
        scanf("%ld", &vetor[i]);
    }

    printf("%ld\n", somatoria(vetor,n));
    
    return 0;
}

unsigned long int somatoria(unsigned long int vetor[], unsigned long int n){
    int i;
    unsigned long int soma = 0;

    for(i=0;i<n;i++){
        soma = soma + vetor[i];
    }
   return soma;
}
#include <stdio.h>

typedef unsigned long int uli;
uli somatoria(uli vetor[],uli n);

int main(){
    uli n,i;
    uli *vetor;

    scanf("%ld", &n);

    for(i=0;i<n;i++){
        scanf("%ld", &vetor[i]);
    }

    printf("%ld\n", somatoria(vetor,n));

    return 0;
}

uli somatoria(uli vetor[], uli n){
    if(n == 1){
        return vetor[n-1];

    } else {
        return vetor[n-1]+somatoria(vetor,n-1);

    }

}


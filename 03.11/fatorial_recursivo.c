#include <stdio.h>

typedef unsigned long int uli;
uli fatorial(uli n);

int main(){
    unsigned long int i,n,total=0;

    scanf("%ld", &n);

    printf("%ld\n", fatorial(n));
    
    return 0;
}

uli fatorial(uli n){
    if(n == 0){
        return 1;
    } else {
        return n*fatorial(n-1);
    }
}

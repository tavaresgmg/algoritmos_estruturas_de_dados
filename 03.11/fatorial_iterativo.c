#include <stdio.h>

int main(){
    unsigned long int i,n,total=1;

    scanf("%ld", &n);

    for(i=n;i>0;i--){
        total = total * i;
    }

    printf("%ld\n", total);
    
    return 0;
}
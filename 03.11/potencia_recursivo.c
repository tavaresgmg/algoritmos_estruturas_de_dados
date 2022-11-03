#include <stdio.h>

float potencia(float x, int n);

int main(){
    float x;
    int n,i;

    scanf("%f%d", &x, &n);

    printf("%f\n", potencia(x,n));
    
    return 0;
}

float potencia(float x, int n){
    if(n == 0){
        return 1;
    } else if (n == 1){
        return x;
    } else {
        return x*potencia(x,n-1);
    }
}

#include <stdio.h>

int main(void){
    int num, n; // casos e numero a ser convertido
    int i, k;
    char str[21];


    scanf("%d", &num); //leitura quantidade de casos 
    while(num > 0){  //loop quantidade de casos
        i = 0;
        scanf("%d", &n); //leitura do número
        
        if (n == 0) printf("A"); //se o número for igual ou menor que 3 ele já possui uma letra definida facilmente 
        if (n == 1) printf("C");
        if (n == 2) printf("G");
        if (n == 3) printf("T");
        
        while(n > 3){
            if(n % 4 == 0) str[i] = 'A';
            if(n % 4 == 1) str[i] = 'C';
            if(n % 4 == 2) str[i] = 'G';
            if(n % 4 == 3) str[i] = 'T';

            n /= 4;
            i++;
            if(n <= 3){
                if(n == 0) str[i] = 'A';
                if(n == 1) str[i] = 'C';
                if(n == 2) str[i] = 'G';
                if(n == 3) str[i] = 'T';
            }
        }
        for(k = i; k >= 0; k--) printf("%c", str[k]); //imprime string de tras para frente

        if(num != 1) printf(" "); //printa espaço se nao for o ultimo caso

        str[0] = '\0'; //zerar string

        num--;
    }

    printf("\n");



    return 0;
}
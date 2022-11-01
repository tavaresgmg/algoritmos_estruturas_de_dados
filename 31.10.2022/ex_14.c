#include <stdio.h>

int main(void){
    int casos, num;
    int i, confere;
    unsigned long long int n1, n2, n3, fib;
    unsigned long long int numero, p;
    double aux1;
    double aux2;
    p = 2;
    aux1 = 1;
    aux2 = 1;

    scanf("%d", &casos); //escaneia o numero de casos
    while(casos > 0){
        scanf("%d", &num); //escaneia o número para teste
        n1 = 1;
        n2 = 1;
        confere = 0;

        if(num == 1 || num == 2){
            fib = 1;
            printf("%llu", fib);
        }
        else{
            for(i = 2; i < num; i++){
                n3 = n1 + n2;
                n1 = n2;
                n2 = n3;
            }
            fib = n3;
        }
        //printf("%llu\n", fib);
            
        if(fib >= 2){
     
            numero = fib;
     
            printf("%llu", numero); //printa o numero de teste
     
            while(numero > 1){
     
                if(p < 8){
     
                    if((numero % p == 0) && (p==2 || p==3 || p==5 || p==7)){
     
                        if(fib == p)goto END; // para evitar "iguais" indesejados 
                        if(fib != p && confere == 0){
                            printf(" = ");
                            confere++;
                        }
                        printf("%lld", p);
     
                        numero /= p;
     
                        if(numero > 1){
     
                            printf(" x ");
                        }
                    }
                    else{
                        p++;
                    }
                }else if(p >= 8){
     
                    if((numero % p == 0)){
     
                        if((p % 3 != 0) && (p % 2 != 0) && (p % 5 != 0) && (p % 7 != 0)){
     
                            if(fib == p)goto END;
                            if(fib != p && confere == 0){
                                printf(" = ");
                                confere++;
                            }
                            printf("%lld", p);
     
                            numero /= p;
     
                            aux1++;
     
                            if(numero > 1){
     
                                printf(" x "); // para os primos da fatoraçao
                            }
                        }
     
                    }else{
                        aux2++;
                        
                        p++;
                    }
                }
            }
        }
        END:
        printf("\n"); 
        casos--;
        p = 2;
        aux1 = 1;
        aux2 = 1;
    }

    return 0;
}
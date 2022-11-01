#include <stdio.h>
#include <stdlib.h>

void fill_matrix(int ** M, int nl, int nc);
void somar_matrizes(int ** M, int ** A, int ** R, int nl, int nc);

int main() {

   int ** M = NULL; //primeira matriz
   int ** A = NULL; //segunda matriz
   int ** RM = NULL; //matriz resultante de multiplicação
   int nl, nc, l, c, k, t, aux = 0, lM, cM, lA, cA, lT, cT;
   char op; //caracter usado na operação, +,-, *

   // dimensão das matrizes
   scanf("%d %d", &nl, &nc);
   int RS[nl][nc];
   int T[nc][nl];

   // alocação dinâmica da memória das matrizes
   M = (int**) calloc(nl, sizeof(int*));
   for (l=0; l<nl; l++) {
      M[l] = (int *) calloc(nc, sizeof(int));
   }
   A = (int**) calloc(nl, sizeof(int*));
   for (l=0; l<nl; l++) {
      A[l] = (int *) calloc(nc, sizeof(int));
   }

   fill_matrix(M, nl, nc);
   scanf("%c", &op);
   fill_matrix(A, nl, nc);

   lM = nl;
   cM = nc;
   lA = nl;
   cA = nc;
   switch (op) {
      case '+':
         for (l=0; l<nl; l++) {
            for (c=0; c<nc; c++) {
               RS[l][c] = M[l][c] + A[l][c];
            }
         }
         for (l=0; l<nl; l++) {
            for (c=0; c<nc; c++) {
               printf("%d ", RS[l][c]);
            } printf("\n");
         }
         break;

      case 'x':
         // fazer a trasnposta
         if (nl!=nc) {
            for (l=0; l<nl; l++) {
               for (c=0; c<nc; c++) {
                  T[c][l] = A[l][c];
               }
            }
            lT = nc;
            cT = nl;
            
            RM = (int **) calloc(lM, sizeof(int*));
            for (l=0; l<lM; l++) {
               RM[l] = (int*) calloc(cT, sizeof(int*));
            }


            //multiplicar matrizes
            for(l=0; l<lM; l++) {
               for(c=0; c<cT; c++) {
                  RM[l][c] = 0;
                  for(k=0; k<lT; k++) {
                     aux +=  M[l][k] * T[k][c];
                  }

                  RM[l][c] = aux;
                  aux = 0;
               }
            }

            for (l=0; l<lM; l++) {
               for (c=0; c<cT; c++) {
                  printf("%d ", RM[l][c]);
               } printf("\n");
            }
            
            printf("TRANSPOSICAO");

         } else {
            RM = (int **) calloc(lM, sizeof(int*));
            for (l=0; l<lM; l++) {
               RM[l] = (int*) calloc(cA, sizeof(int*));
            }
            //multiplicar matrizes
            for(l=0; l<lM; l++) {
               for(c=0; c<cA; c++) {
                  RM[l][c] = 0;
                  for(k=0; k<lA; k++) {
                     aux +=  M[l][k] * A[k][c];
                  }

                  RM[l][c] = aux;
                  aux = 0;
               }
            }

            for (l=0; l<lM; l++) {
               for (c=0; c<cA; c++) {
                  printf("%d ", RM[l][c]);
               } printf("\n");
            }
         }

         break;
   }

   // liberar a memória alocada
   for (l=0; l<nl; l++) {
      free(M[l]);
      free(A[l]);
   }
   free(M);
   free(A);

   return 0;
}

void fill_matrix(int ** M, int nl, int nc) { //preenchimento
   int l, c;

   for (l=0; l<nl; l++) {
      for (c=0; c<nc; c++) {
         scanf("%d%*c", &M[l][c]);
      }
   }
}

void somar_matrizes(int ** M, int ** A, int ** R, int nl, int nc) { // adicao
   printf("Entrou na funcao somar\n");
   int l, c;

   for (l=0; l<nl; l++) {
      for (c=0; c<nc; c++) {
         R[l][c] = M[l][c] + A[l][c];
         printf("%d\n", R[l][c]);
      }
   }
}
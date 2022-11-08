#include <stdio.h>
#include <stdlib.h>

void fill_matrix(char ** M, int nl, int nc);
void print_matrix(char ** M, int nl, int nc);
int setas_inseguras(char ** M, int nl, int nc);
int somar_setas_in(char pos, char ** M, int pos_l, int pos_c, int dim);

int main(void) { //funcao principal
   int nl, nc, dim, i;
   char ** A = NULL;

   scanf("%d%*c", &dim);
   if (dim > 500 || dim < 1) return 0;
   A = (char**) malloc(dim*sizeof(char*));
   for (i=0; i<dim; i++) {
      A[i] = (char*) malloc(dim*sizeof(char));
   }
   nc = nl = dim;

   fill_matrix(A, nl, nc);
   printf("%d\n", dim*dim - setas_inseguras(A, nl, nc));

   for (i=0; i<nl; i++) {
      free(A[i]);
   }
   free(A);

   return 0;
}

void fill_matrix(char ** M, int nl, int nc) {
   int l, c;

   for (l=0; l<nl; l++) {
      for (c=0; c<nc; c++) {
         scanf("%c%*c", &M[l][c]);
      }
   }
}

void print_matrix(char ** M, int nl, int nc) {
   int l, c;

   for (l=0; l<nl; l++) {
      for (c=0; c<nc; c++) {
         printf("%c ", M[l][c]);
      } printf("\n");
   }
}

int setas_inseguras(char ** M, int nl, int nc) {
   int l, c, k;
   int in = 0;

   for (c=0; c<nc; c++) {
      if (M[0][c] == 'a') {
         in += somar_setas_in('a', M, 0, c, nl);
         //printf("%d\n", somar_setas_in('a', M, 0, c, nl));
      }

      if (M[nl-1][c] == 'v') {
         in += somar_setas_in('v', M, nl-1, c, nl);
         //printf("%d\n", somar_setas_in('v', M, nl-1, c, nl));
      }
   }

   for (l=0; l<nl; l++) {
      if (M[l][0] == '<') {
         in += somar_setas_in('<', M, l, 0, nl);
         //printf("%d\n", somar_setas_in('<', M, l, 0, nl));
      }
      if (M[l][nc-1] == '>') {
         in += somar_setas_in('>', M, l, nc-1, nl);
         //printf("%d\n", somar_setas_in('>', M, l, nc-1, nl));
      }
   }

   
   return in;
}

int somar_setas_in(char pos, char ** M, int pos_l, int pos_c, int dim) {
   int in = 0;

   switch (pos) {
      case 'a':
      

         if (pos_l < (dim-1) && pos_c < (dim-1) && pos_c > 0 && M[pos_l][pos_c+1] == '<' && M[pos_l][pos_c-1] == '>' && M[pos_l+1][pos_c] == 'a') {
            return 1 + somar_setas_in('<', M, pos_l, pos_c+1, dim) + somar_setas_in('>', M, pos_l, pos_c-1, dim) + somar_setas_in('a', M, pos_l+1, pos_c, dim);
               
         } else if (pos_c < (dim-1) && pos_c > 0 && M[pos_l][pos_c+1] == '<' && M[pos_l][pos_c-1] == '>') {
            return 1 + somar_setas_in('<', M, pos_l, pos_c+1, dim) + somar_setas_in('>', M, pos_l, pos_c-1, dim); 
         
         } else if (pos_l < (dim-1) && pos_c > 0 && M[pos_l][pos_c-1] == '>' && M[pos_l+1][pos_c] == 'a') {
            return 1 +  somar_setas_in('>', M, pos_l, pos_c-1, dim) + somar_setas_in('a', M, pos_l+1, pos_c, dim);
         
         } else if (pos_l < (dim-1) && pos_c < (dim-1) && M[pos_l][pos_c+1] == '<' && M[pos_l+1][pos_c] == 'a') {
            return 1 + somar_setas_in('<', M, pos_l, pos_c+1, dim) + somar_setas_in('a', M, pos_l+1, pos_c, dim);

         } else if (pos_c < (dim-1) && M[pos_l][pos_c+1] == '<') {
            return 1 + somar_setas_in('<', M, pos_l, pos_c+1, dim);

         } else if (pos_c > 0 && M[pos_l][pos_c-1] == '>') {
            return 1 + somar_setas_in('>', M, pos_l, pos_c-1, dim);

         } else if (pos_l < (dim-1) && M[pos_l+1][pos_c] == 'a') {
            return 1 + somar_setas_in('a', M, pos_l+1, pos_c, dim);

         } else {
            return 1;
         }

      case 'v':

         //printf("Entrou no case v\n");

         if (pos_l > 0 && pos_c < (dim-1) && pos_c > 0 && M[pos_l][pos_c+1] == '<' && M[pos_l][pos_c-1] == '>' && M[pos_l-1][pos_c] == 'v') {
            return 1 + somar_setas_in('<', M, pos_l, pos_c+1, dim) + somar_setas_in('>', M, pos_l, pos_c-1, dim) + somar_setas_in('v', M, pos_l-1, pos_c, dim);
               
         } else if (pos_c < (dim-1) && pos_c > 0 && M[pos_l][pos_c+1] == '<' && M[pos_l][pos_c-1] == '>') {
            return 1 + somar_setas_in('<', M, pos_l, pos_c+1, dim) + somar_setas_in('>', M, pos_l, pos_c-1, dim); 
         
         } else if (pos_l > 0 && pos_c > 0 && M[pos_l][pos_c-1] == '>' && M[pos_l-1][pos_c] == 'v') {
            return 1 +  somar_setas_in('>', M, pos_l, pos_c-1, dim) + somar_setas_in('v', M, pos_l-1, pos_c, dim);
         
         } else if (pos_c < (dim-1) && pos_l > 0 && M[pos_l][pos_c+1] == '<' && M[pos_l-1][pos_c] == 'v') {
            return 1 + somar_setas_in('<', M, pos_l, pos_c+1, dim) + somar_setas_in('v', M, pos_l-1, pos_c, dim);

         } else if (pos_c < (dim-1) && M[pos_l][pos_c+1] == '<') {
            return 1 + somar_setas_in('<', M, pos_l, pos_c+1, dim);

         } else if (pos_c > 0 && M[pos_l][pos_c-1] == '>') {
            return 1 + somar_setas_in('>', M, pos_l, pos_c-1, dim);

         } else if (pos_l > 0 && M[pos_l-1][pos_c] == 'v') {
            return 1 + somar_setas_in('v', M, pos_l-1, pos_c, dim);

         } else {
            return 1;
         }

      case '>':


         if (pos_l < (dim-1) && pos_l > 0 && pos_c > 0 && M[pos_l-1][pos_c] == 'v' && M[pos_l][pos_c-1] == '>' && M[pos_l+1][pos_c] == 'a') {
            return 1 + somar_setas_in('v', M, pos_l-1, pos_c, dim) + somar_setas_in('>', M, pos_l, pos_c-1, dim) + somar_setas_in('a', M, pos_l+1, pos_c, dim);
               
         } else if (pos_l > 0 && pos_c > 0 && M[pos_l-1][pos_c] == 'v' && M[pos_l][pos_c-1] == '>') {
            return 1 + somar_setas_in('v', M, pos_l-1, pos_c, dim) + somar_setas_in('>', M, pos_l, pos_c-1, dim); 
         
         } else if (pos_l < (dim-1) && pos_c > 0 && M[pos_l][pos_c-1] == '>' && M[pos_l+1][pos_c] == 'a') {
            return 1 +  somar_setas_in('>', M, pos_l, pos_c-1, dim) + somar_setas_in('a', M, pos_l+1, pos_c, dim);
         
         } else if (pos_l < (dim-1) && pos_l > 0 && M[pos_l-1][pos_c] == 'v' && M[pos_l+1][pos_c] == 'a') {
            return 1 + somar_setas_in('v', M, pos_l-1, pos_c, dim) + somar_setas_in('a', M, pos_l+1, pos_c, dim);

         } else if (pos_l > 0 && M[pos_l-1][pos_c] == 'v') {
            return 1 + somar_setas_in('v', M, pos_l-1, pos_c, dim);

         } else if (pos_c > 0 && M[pos_l][pos_c-1] == '>') {
            return 1 + somar_setas_in('>', M, pos_l, pos_c-1, dim);

         } else if (pos_l < (dim-1) && M[pos_l+1][pos_c] == 'a') {
            return 1 + somar_setas_in('a', M, pos_l+1, pos_c, dim);

         } else {
            return 1;
         }

      case '<':

         if (pos_l < (dim-1) && pos_c < (dim-1) && pos_l > 0 && M[pos_l-1][pos_c] == 'v' && M[pos_l][pos_c+1] == '<' && M[pos_l+1][pos_c] == 'a') {
            return 1 + somar_setas_in('v', M, pos_l-1, pos_c, dim) + somar_setas_in('<', M, pos_l, pos_c+1, dim) + somar_setas_in('a', M, pos_l+1, pos_c, dim);
               
         } else if (pos_c < (dim-1) && pos_l > 0 && M[pos_l-1][pos_c] == 'v' && M[pos_l][pos_c+1] == '<') {
            return 1 + somar_setas_in('v', M, pos_l-1, pos_c, dim) + somar_setas_in('<', M, pos_l, pos_c+1, dim); 
         
         } else if (pos_l < (dim-1) && pos_c < (dim-1) && M[pos_l][pos_c+1] == '<' && M[pos_l+1][pos_c] == 'a') {
            return 1 +  somar_setas_in('<', M, pos_l, pos_c+1, dim) + somar_setas_in('a', M, pos_l+1, pos_c, dim);
         
         } else if (pos_l < (dim-1) && pos_l > 0 && M[pos_l-1][pos_c] == 'v' && M[pos_l+1][pos_c] == 'a') {
            return 1 + somar_setas_in('v', M, pos_l-1, pos_c, dim) + somar_setas_in('a', M, pos_l+1, pos_c, dim);

         } else if (pos_l > 0 && M[pos_l-1][pos_c] == 'v') {
            return 1 + somar_setas_in('v', M, pos_l-1, pos_c, dim);

         } else if (pos_c < (dim-1) && M[pos_l][pos_c+1] == '<') {
            return 1 + somar_setas_in('<', M, pos_l, pos_c+1, dim);

         } else if (pos_l < (dim-1) && M[pos_l+1][pos_c] == 'a') {
            return 1 + somar_setas_in('a', M, pos_l+1, pos_c, dim);

         } else {
            return 1;
         }
   }
}
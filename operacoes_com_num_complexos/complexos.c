
// Definicao da TAD
struct complexo {
    float re; // Componente real
    float im; // Componente imaginária
};

// Incluindo meu header
#include "complexos.h"

Complexo *COMPLEXOcria(float real, float imag) {
    /*
      Retorna um número complexo dadas suas componentes

      real: Componente real
      imag: Componente imaginária
    */

   // criando um Complexo Nulo
   Complexo * num = NULL;

   // Alocando memória do complexo
   num = (Complexo *) malloc(sizeof(Complexo));

   if(num!=NULL) { // analisando se alocou memoria corretamente

      // atribuindo valores reais e imaginarios no meu numero complexo
      num->re = real;
      num->im = imag;
   }

   return num;
}

void COMPLEXOlibera(Complexo *z) {
  /*
      Elimina o número complexo criado
    */
   free(z);
}

void COMPLEXOatribui(Complexo *z, float real, float imag) {
  /*
    Atribui um valor a um número complexos
    z = real + imag i
  */
  z->re = real;
  z->im = imag;
}

void COMPLEXOmostra(Complexo *z) {
   /*
    Mostra o número
  */

  float aux_re = mod(z->re);
  float aux_im = mod(z->im);
  int e_re = 0;
  int e_im = 0;


  // transformando a parte real de z para notação cientifica usando 2 variaveis auxiliares
  if (aux_re>=10) {
    while(aux_re >= 10) {
      aux_re /= 10;
      e_re++;
    }

  } else if (aux_re>0 && aux_re<1) {
    while(aux_re < 1) {
      aux_re *= 10;
      e_re--;
    }
  }

  // transformando a parte imaginaria de z para notação cientifica usando 2 variaveis auxiliares
  if (aux_im>=10) {
    while(aux_im >= 10) {
      aux_im /= 10;
      e_im++;
    }

  } else if (aux_im>0 && aux_im<1) {
    while(aux_im < 1) {
      aux_im *= 10;
      e_im--;
    }
  }

  if (z->re < 0) aux_re = -aux_re;
  if (z->im < 0) aux_im = -aux_im;
  
  if(aux_im >= 0)printf("z = %.2fe%+.2d + %.2fe%+.2di\n", aux_re, e_re, aux_im, e_im);
  else printf("z = %.2fe%+.2d - %.2fe%+.2di\n", aux_re, e_re, (aux_im * -1), e_im);
}

Complexo *COMPLEXOconjuga(Complexo *z) {
   //criando um complexo auxiliar zerado
    Complexo *C = COMPLEXOcria(0, 0);
    C->re = z->re;
    //obtendo a conjugação pela simetria da parte imaginaria
    C->im = (z->im * -1);

    return C;

}

Complexo *COMPLEXOadiciona(Complexo *z1, Complexo *z2) {
   
  // Criando um complexo zerado para receber a soma de z1 e z2
  Complexo * s = COMPLEXOcria(0, 0);

  // atribuindo as somas as partes reais e imaginarias da soma
  s->re = z1->re + z2->re;
  s->im = z1->im + z2->im;

  return s;
}

Complexo *COMPLEXOmultiplica(Complexo *z1, Complexo *z2) {

  // Criando um complexo zerado para receber a multiplicação de z1 e z2
  Complexo * mult = COMPLEXOcria(0, 0);

  // Atribuindo a multiplicação de z1 e z2 às partes reais e imaginárias da operação
  mult->re = z1->re*z2->re - z1->im*z2->im;
  mult->im = z1->re*z2->im + z1->im*z2->re;

  return mult;
}

Complexo *COMPLEXOpotencia1(Complexo *base, int expoente) {
   float denom;

   if(expoente == 0){ // Caso específico onde o resultado é 1
      base->re = 1;
      base->im = 0;
      return base;

   } else if (expoente == 1) {
      // Caso trivial 2
      return base;

   } else if (expoente < 0) {
      // Caso trivial 3
      denom = pow(base->re, 2) + pow(base->im, 2);
      base->re = (base->re)/(denom);
      base->im = -(base->im)/(denom);
      return COMPLEXOpotencia1(base, mod(expoente));

   } else {
      return COMPLEXOmultiplica(base, COMPLEXOpotencia1(base, expoente-1));

   }
}

Complexo *COMPLEXOpotencia2(Complexo *base, Complexo *expoente) {
    //i^i = e^(-pi/2)

    // Criando um complexo zerado para receber a potencia i^i
    Complexo * pot2 = COMPLEXOcria(0, 0);

    pot2->im = 0; //i^i resulta em um numero real
    pot2->re = exp((-3.1415926/2));// função da biblioteca math.h; exp(x) == e^x

    return (pot2);
}

float COMPLEXOmagnitude(Complexo *z) {
  float mag;
  
  // calculando a magnitude do numero complexo z
  mag = sqrt(pow(z->re, 2) + pow(z->im, 2));

  return mag;
}

//função que calcula o angulo do numero complexo
float COMPLEXOangulo(Complexo *z) {
     float ang;

    ang = atan2(z->im,z->re);

    return ang;
}

// função que calcula o módulo de um número a
float mod(float a) {
  if (a < 0) a = -a;

  return a;
}

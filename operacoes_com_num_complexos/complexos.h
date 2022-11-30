#ifndef COMPLEXOS_H
#define COMPLEXOS_H

// Incluindo as bibliotecas
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Definicao da TAD
typedef struct complexo Complexo;

// Prototipos das funcoes
Complexo *COMPLEXOcria(float real, float imag); //funcao que cria um numero complexo
void COMPLEXOlibera(Complexo *z); //funcao que elimina um numero complexo criado
void COMPLEXOatribui(Complexo *z, float real, float imag); //funcao que atribui valores a um numero complexo
void COMPLEXOmostra(Complexo *z); //funcao que imprime o numero complexo
Complexo *COMPLEXOconjuga(Complexo *z); //funcao que retorna o conjugado do comlexo
Complexo *COMPLEXOadiciona(Complexo *z1, Complexo *z2); // funcao que adiciona complexos
Complexo *COMPLEXOmultiplica(Complexo *z1, Complexo *z2); // funcao que multiplica comlexos
Complexo *COMPLEXOpotencia1(Complexo *base, int expoente); // funcao que realiza as potencias
Complexo *COMPLEXOpotencia2(Complexo *base, Complexo *expoente); // funcao que realiza a potencia especial i ^ i
float COMPLEXOmagnitude(Complexo *z); // calcula a magnitude do numero complexo z
float COMPLEXOangulo(Complexo *z); //funcao que calcula o angulo do numero complexo
float mod(float a); // função que calcula o módulo de um número a

#endif

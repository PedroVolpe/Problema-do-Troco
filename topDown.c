#include <stdio.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define INFINITO 999999
#define MAX 100

int L[MAX];

int conta_moedas(int t,int M[], int n){
  if (t == 0)
    return 0;
  
  if (t < 0)
    return INFINITO;

  if (L[t] != -1)
    return L[t];

  int menor = INFINITO;
  for (int i = 0; i < n-1; i++){
    menor = MIN(menor, conta_moedas(t - M[i], M, n) + 1);
  }
  return L[t] = menor;
  
}


int main(void) {
  for (int i = 0; i < MAX; i++){
    L[i] = -1;
  }
  
  int M[] = {1,4,6};
  int n = 3;
  int t = 8;

  int res = conta_moedas(t, M, n);
  printf("A menor quantidade de moedas possivel para o troce é de: %d",res);
  return 0;
}
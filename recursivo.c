#include <stdio.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define INFINITO 999999


int conta_moedas(int t,int M[], int n){
  if (t == 0)
    return 0;

  if (t < 0)
    return INFINITO;

  int menor = INFINITO;
  for (int i = 0; i < n;i++){
    menor = MIN(menor,conta_moedas(t - M[i], M, n) + 1);
  }

  return menor;
}


int main(void) {

  int M[] = {1,4,6};
  int n = 3;
  int t = 8;
  
  int res = conta_moedas(t, M, n);
  printf("A menor quantidade de moedas possivel para o troce é de: %d",res);
  return 0;
}
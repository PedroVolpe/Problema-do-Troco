#include <stdio.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define INFINITO 999999
#define MAX 100

int troco[MAX];

int conta_moedas(int t,int M[], int n){
  for (int h = 1; h < t; h++)
    troco[h] = INFINITO;
  
  troco[0] = 0;

  for (int i = 0; i < t; i++){
    for(int j = 0;j < n; j++){
      if(i >= M[j])
        troco[i] = MIN(troco[i],troco[i - M[j]] + 1);
    }
  }
  return troco[t-1];
}

int main(void) {

  int M[] = {1,4,6};
  int n = 3;
  int t = 8;

  int res = conta_moedas(t, M, n);
  printf("A menor quantidade de moedas possivel para o troce é de: %d", res);
  return 0;
}
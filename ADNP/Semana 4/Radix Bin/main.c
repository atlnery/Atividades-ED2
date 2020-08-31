#include <stdio.h>

#define DEBUG 0

#include "vectorBin.h"
#include "radixsortBin.h"

void main() {
   
   int max = 10;
   int n = 10;

   char** rand = random_vectorBin(n, 100 * max, 0);
   imprimeBin(rand, n);

   radixsortBin(rand, n);
   
   #if DEBUG
   int x [n];
   for (int i = 0; i < n; i++) {
      x[i] = convertebin(rand[i], strlen(rand[i]));
      printf("%d ", x[i]);
   }
   printf("\n");
   #endif

   freeString(rand, n);
}

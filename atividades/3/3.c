#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

void fifo() {
  int n, i, q = 0;
  long long p[MAX];

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%lld", &p[i]);
  }

  while (scanf("%d", &q) != EOF) {
    printf("%d\n", q);
  }

  return;  
}

int main(int argc, char const *argv[]) {
  fifo();
  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int i, j, k;
  int n;
  int half;
  unsigned int **matrix_a, **matrix_b, **matrix_r;
  scanf("%d", &n);
  half = n / 2;

  matrix_a = (unsigned int **) malloc(n * sizeof(unsigned int *));
  matrix_b = (unsigned int **) malloc(n * sizeof(unsigned int *));
  matrix_r = (unsigned int **) malloc(n * sizeof(unsigned int *));
  
  for (i = 0; i < n; i++) {
    matrix_a[i] = (unsigned int *) malloc(n * sizeof(unsigned int));
    matrix_b[i] = (unsigned int *) malloc(n * sizeof(unsigned int));
    matrix_r[i] = (unsigned int *) malloc(n * sizeof(unsigned int));
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%u", &matrix_a[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%u", &matrix_b[i][j]);
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      matrix_r[i][j] = 0;
      for (k = 0; k < n; k++)
        matrix_r[i][j] += matrix_a[i][k] * matrix_b[k][j]; 
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (j < n - 1)
        printf("%d ", matrix_r[i][j]);
      else if (j == n - 1)
        printf("%d", matrix_r[i][j]);
    }
    printf("\n");
  }
  return 0;
}

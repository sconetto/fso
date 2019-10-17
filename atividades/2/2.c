#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#define MAX 2000

int status_a = 0;
int status_b = 0;
unsigned int matrix_a[MAX][MAX], matrix_b[MAX][MAX], matrix_r[MAX][MAX];

void continue_exec(int signal) {
  return;
}

void inc_a(int signal) {
  status_a++;
}

void inc_b(int signal) {
  status_b++;
}

int main(int argc, char const *argv[]) {
  int n, i, j, k, half, status;
  pid_t father, son_a, son_b;
  father = getpid();
  
  scanf("%d", &n);
  
  half = n / 2;
  
  signal(SIGUSR1, inc_a);
  signal(SIGUSR2, inc_b);
  
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

  son_a = fork();
  if (son_a == 0) {
    // I'm on A child
    signal(SIGUSR1, continue_exec);
    for (i = 0; i < half; i++) {
      for (j = 0; j < n; j++) {
        matrix_r[i][j] = 0;
        for (k = 0; k < n; k++)
          matrix_r[i][j] += matrix_a[i][k] * matrix_b[k][j]; 
      }
    }
    usleep(100);
    kill(getppid(), SIGUSR1);
    pause();
    for (i = 0; i < half; i++) {
      for (j = 0; j < n; j++) {
        if (j < n - 1)
          printf("%d ", matrix_r[i][j]);
        else if (j == n - 1)
          printf("%d", matrix_r[i][j]);
      }
      printf("\n");
    }
    exit(0);
  } else {
    son_b = fork();
    if (son_b == 0) {
      // I'm on B child
      signal(SIGUSR2, continue_exec);
      for (i = half; i < n; i++) {
        for (j = 0; j < n; j++) {
          matrix_r[i][j] = 0;
          for (k = 0; k < n; k++)
            matrix_r[i][j] += matrix_a[i][k] * matrix_b[k][j]; 
        }
      }
      usleep(150);
      kill(getppid(), SIGUSR2);
      pause();
      for (i = half; i < n; i++) {
        for (j = 0; j < n; j++) {
          if (j < n - 1)
            printf("%d ", matrix_r[i][j]);
          else if (j == n - 1)
            printf("%d", matrix_r[i][j]);
        }
        printf("\n");
      }
      exit(0);
    }
  }
  
  // I'm on the father
  while (!status_a || !status_b) {
    pause();
  }
  kill(son_a, SIGUSR1);
  wait(&status);
  kill(son_b, SIGUSR2);
  wait(&status);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

char string[100];

void sig_vogal(int sig) {
  int i;
  printf("Sem Vogais: ");
  for (i = 0; i < strlen(string); i++) {
    if (string[i] == 65 || string[i] == 69 || string[i] == 73 || string[i] == 79 || string[i] == 85) {
      continue;
    } else if (string[i] == 97 || string[i] == 101 || string[i] == 105 || string[i] == 111 || string[i] == 117) {
      continue;
    } else {
      printf("%c", string[i]);
    }
  }
  printf("\n");
  exit(0);
}

void sig_maiusc(int sig) {
  int i;
  printf("Letras Maiúsculas: ");
  for (i = 0; i < strlen(string); i++) {
    if (string[i] >= 97 && string[i] <= 122) {
      continue;
    } else {
      printf("%c", string[i]);
    }
  }
  printf("\n");
  exit(0);
}

void sig_minusc(int sig) {
  int i;
  printf("Letras Minúsculas: ");
  for (i = 0; i < strlen(string); i++) {
    if (string[i] >= 65 && string[i] <= 90) {
      continue;
    } else {
      printf("%c", string[i]);
    }
  }
  printf("\n");
  exit(0);
}

void read_string(char *s) {
	char c;
	int i = 0;
	do {
		c = getchar();
		if ( c != '\n') {
			s[i] = c;
		}
		i++;
	} while ( c != '\n' && c != '\0' && i <= 100);
	s[--i] = '\0';
	return;
}

int main(int argc, char const *argv[]) {
  signal(SIGTERM, sig_maiusc);
  signal(SIGUSR1, sig_minusc);
  signal(SIGUSR2, sig_vogal);
  int i, status;
  pid_t pid1 = 0, pid2 = 0, pid3 = 0, pid4 = 0, pid5 = 0;
  read_string(string);
  pid1 = fork();
  if (pid1 == 0) {
    // child - 1002
    pid3 = fork(); // create - 1004
    if (pid3 == 0) {
      kill(getpid(), SIGTERM);
    }
    wait(&status);
    pid5 = fork(); // create - 1007
    if (pid5 == 0) {
      kill(getpid(), SIGUSR2);
    }
    wait(&status);
    pid4 = fork(); // create - 1006
    if (pid4 == 0) {
      kill(getpid(), SIGUSR1);
    }
  } else {
    // parent - 1001
    pid2 = fork(); // create - 1003
    if (pid2 == 0) {
      // child - 1005
      printf("Tamanho da String: %ld\n", strlen(string));
      exit(0);
    }
  }
  return 0;
}

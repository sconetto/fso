#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

char string[101];

void print_maiusculas(int signal) {
  int i;
  printf("Letras Maiúsculas: ");
  for (i = 0; i < strlen(string); i++) {
    if (string[i] >= 97 && string[i] <= 122 || string[i] >= 129 && string[i] <= 141 || string[i] >= 147 && string[i] <= 152 || string[i] == 155 || string[i] >= 160 && string[i] <= 164 || string[i] >= 224 && string[i] <= 255) {
      continue;
    } else {
      printf("%c", string[i]);
    }
  }
  printf("\n");
}

void print_minusculas(int signal) {
  int i;
  printf("Letras Minúsculas: ");
  for (i = 0; i < strlen(string); i++) {
    if (string[i] >= 65 && string[i] <= 90 || string[i] == 128 || string[i] >= 142 && string[i] <= 144 || string[i] == 146 || string[i] >= 153 && string[i] <= 154 || string[i] == 165 || string[i] >= 192 && string[i] <= 221) {
      continue;
    } else {
      printf("%c", string[i]);
    }
  }
  printf("\n");
}

void print_sem_vogal(int signal) {
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
}

void continue_exec(int signal) {
  return;
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
	} while ( c != '\n' && c != '\0');
	s[--i] = '\0';
	return;
}

int main(int argc, char const *argv[]) {
  pid_t pid1001, pid1002, pid1003, pid1004, pid1005, pid1006, pid1007;
  int status = 0;
  read_string(string);
	
  pid1001 = getpid();
  pid1002 = fork();
  // sleep(1);
  if (pid1002 == 0) {
    // child - 1002
    // SIGUSR2 = 12
    signal(SIGUSR2, continue_exec);
    pid1004 = fork(); // create - 1004
    if (pid1004 == 0) {
      // child - 1004
      // SIGUSR1 = 10
      signal(SIGUSR1, print_maiusculas);
      pause();
      exit(0);
    } else {
      pid1006 = fork(); // create - 1006
      if (pid1006 == 0) {
        // child - 1006
        // SIGUSR1 = 30
        signal(SIGUSR1, print_minusculas);
        pause();
        exit(0);
      } else {
        pid1007 = fork(); // create - 1007
        if (pid1007 == 0) {
          // child -1007
          // SIGUSR2 = 31
          signal(SIGUSR2, print_sem_vogal);
          pause();
          exit(0);
        }
      }
    }
    pause();
    kill(pid1006, SIGUSR1);
    wait(&status);
    kill(pid1007, SIGUSR2);
    wait(&status);
    kill(pid1004, SIGUSR1);
    wait(&status);
    exit(0);
  } else {
    // parent - 1001
    pid1003 = fork(); // create - 1003
    // sleep(1);
    if (pid1003 == 0) {
      // child - 1003
      pid1005 = fork(); // create - 1005
      // sleep(1);
      if (pid1005 == 0) {
        // child - 1005
        exit(strlen(string));
      }
    } else {
      // parent - 1003
      wait(&status);
      exit(WEXITSTATUS(status));
    }
    wait(&status);
    printf("Tamanho da String: %d\n", WEXITSTATUS(status));
    usleep(500);
    kill(pid1002, SIGUSR2);
  }
  return 0;
}

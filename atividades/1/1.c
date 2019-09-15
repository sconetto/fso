#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

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
  char s[101];
  int i;
  pid_t pid1 = 0, pid2 = 0, pid3 = 0, pid4 = 0, pid5 = 0;
  pid_t pwait;
  read_string(s);
  pid1 = fork();

  if (pid1 == 0) {
    // child - 1002
    pid3 = fork(); // create - 1004
    if (pid3 == 0) {
      printf("Letras Maiúsculas: ");
      for (i = 0; i < strlen(s); i++) {
        if (s[i] >= 97 && s[i] <= 122) {
          continue;
        } else {
          printf("%c", s[i]);
        }
      }
      printf("\n");
      _exit(0);
    }
    pid5 = fork(); // create - 1007
    if (pid5 == 0) {
      pwait = getpid();
      printf("Sem Vogais: ");
      for (i = 0; i < strlen(s); i++) {
        if (s[i] == 65 || s[i] == 69 || s[i] == 73 || s[i] == 79 || s[i] == 85) {
          continue;
        } else if (s[i] == 97 || s[i] == 101 || s[i] == 105 || s[i] == 111 || s[i] == 117) {
          continue;
        } else {
          printf("%c", s[i]);
        }
      }
      printf("\n");
      _exit(0);
    }
    pid4 = fork(); // create - 1006
    if (pid4 == 0) {
      printf("Letras Minúsculas: ");
      for (i = 0; i < strlen(s); i++) {
        if (s[i] >= 65 && s[i] <= 90) {
          continue;
        } else {
          printf("%c", s[i]);
        }
      }
      printf("\n");
      _exit(0);
    }
  } else {
    // parent - 1001
    pid2 = fork(); // create - 1003
    if (pid2 == 0) {
      // child - 1005
      printf("Tamanho da String: %ld\n", strlen(s));
      _exit(0);
    }
  }
  return 0;
}

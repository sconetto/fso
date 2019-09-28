#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

void beep(int signal) {
  printf("beep\n");
}

int main(int argc, char const *argv[])
{
  printf("%d\n", getpid());
  signal(SIGUSR1, beep);
  pause();
}

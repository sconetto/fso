# Prova 1

## O que é sistema operacional?

Software que executa em modo núcleo. Podendo ser uma máquina estendida ou gerenciador de recursos. É um programa ou um conjunto de programas cuja função é gerenciar os recursos do sistema (definir qual programa recebe atenção do processador, gerenciar memória, criar um sistema de arquivos, etc.), fornecendo uma interface entre o computador e o usuário.

## O que é região crítica?

Região Crítica é a área de um código onde é feito o acesso à memória ou recurso compartilhado.

## Thread e processo são conceitos diferentes. Explique sucintamente, a diferença entre o conceito de processo e o conceito de thread. O que as threads acrescentam ao modelo de processo ?

Um processo é basicamente um programa em execução, sendo constituído de seu código executável (instruções), dos seus dados (valores de variáveis), do estado da sua pilha, do estado atual dos seus registradores (PC), dentre outros.
A Thread é a forma de um processo dividir-se a si mesmo em duas ou mais tarefas, que podem ser executadas em simultâneo.

As threads acrescentam a possibilidade de concorrência de execução, ou seja, execução de mais de uma tarefa quando em tempo de CPU.

## Dado o seguinte trecho de programa paralelo abaixo: Use funções de semáforo para garantir que a função funcao3() execute antes da função funcao1().

```
Semaphore S = 0;
Parbegin
  Begin
    P(S);
    funcao1();
    funcao2();
  End;
  Begin
    funcao3();
    V(S);
    funcao4();
  End;
Parend;
```

## Escreva um trecho de código que utiliza a função fork() e gera a seguinte hierarquia de processos:

```c
#include <stdlib.h>
#include <sys/types.h>

int main() {
  pid_t a, b, c, d, e, f, g;
  a = getpid();

  b = fork();
  if (b > 0) {
    // estou no pai
    c = fork();
    if (c == 0) {
      // estou no filho
      e = fork();
    }
    d = fork();
    if (d == 0) {
      // estou no filho
      f = fork();
      g = fork();
    }
  }
}

/*
  A
 /|\
B C D
  | |\
  E F G
*/
```

## Dado o diagrama abaixo, que mapeia os estados em que um processo pode se encontrar, descreva as condições em que as trocas de estado ocorrem.

1. O escalonador seleciona este processo e este está na CPU em execução
2. O escalonador seleciona outro processo e este volta para a fila de processos
3. O processo bloqueia aguardando alguma condição (entrada ou leitura de arquivo)
4. O processo se torna disponível e volta para a fila de processos

### Funções interessantes:

`getpid();` - pega o seu PID
`getppid();` - pega o PID do seu pai
`signal(SIG, func)` - Adiciona a funcão `func` como handler quando receber o sinal `SIG`
`pause()` - pausa a execução de um processo
`kill(pid, SIG)` - Manda um sinal `SIG` para um processo com o identificador `pid`
`exit(val)` - Termina a execução do processo enviando `val` para o pai.
`wait(&status)` - pega o `val` da execução no endereço de `status`
`WEXITSTATUS(status)` - pega os 4 bits menos significantes (0-255) da saída de `status`

### Informações importantes

- Monoprogramação: 1 processo na memória
- Multiprogramação: vários processos na memória (escalonador - seletor de processos)
- Algoritmos de escalonamento: Round-Robin; FIFO; Menor ciclo de processador (Shortest Job First); Prioridades (filas múltiplas)
- Condição de disputa (concorrência, corrida): dois ou mais processos estão acessando dados compartilhados e o resultado final depende de quem roda quando.
- Deadlock: dois ou mais processos ficam impedidos de continuar sua execução, esperando um pelo outro.
- Starvation: Processo nunca ganha tempo de CPU
- Região crítica: a parte do código de um processo cuja a execução pode levar a uma condição de disputa.
- POSIX: é um padrão que diz quantas chamadas de sistemas, seus nomes e como são utilizadas.
- Zombie: Processo que já executou mas ainda está na tabela de processos pois seu pai não recuperou seu sinal/status de saída
- Permissões de Arquivos:

  - 0: nenhuma
  - 1: apenas executar
  - 2: apenas escrever
  - 3: escrever e executar
  - 4: apenas ler
  - 5: ler e executar
  - 6: ler e escrever
  - 7: ler, escrever e executar

  - XYZ: X - Dono, Y - Grupo, Z - Outros
  - rwx: 4, 2, 1

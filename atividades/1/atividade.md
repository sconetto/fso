# Atividade 1 - FSO

Aluno: João Pedro Sconetto
Matrícula: 14/0145940
Professor: Bruno Ribas

1. O Processo pai de todos, dado por 1001 no exemplo acima, precisa ler, da entrada padrão, uma String S de tamanho máximo de 100 caracteres.

   - Os processos filhos e netos de 1001 devem ser lançados antes ou depois de 1001 ler a string S?

   R. Devem ser lançados depois, para que durante o processo de fork() a string S esteja na memória dos processos filhos.

2. O processo 1005 deve ser capaz de retornar o tamanho da string S, lida pelo processo 1001.

   - Como o processo 1001 faz para imprimir o tamanho da string S?

   R. O processo 1001 deve esperar do filho 1003 morrer e passar o status da sua execução (tamanho da string), enquanto o 1003 espera o 1005 no mesmo processo. Ou seja, o 1005 executa a operação `strlen()`, morre e passa como status o resultado, 1003 recebe esse status, morre e passa o seu status como resutaldo. Dessa forma 1001 recebe o tamanho da string executada por 1005.

3. O processo 1006 deve alterar a string S, removendo todos os caracteres maiúsculos, e deve imprimir essa nova string a pedido do processo 1001
   R. 1006 faz essa operação e espera um sinal para poder executar, o sinal é mandado de 1002 para 1006, onde 1002 também espera o sinal de 1001 para comandar seus filhos.

4. O processo 1004 deve remover os caracteres minúsculos de S
   R. Processo análogo ao do processo 1006 na questão 3.

5. O processo 1007 deve remover as vogais de S
   R. Processo análogo ao do processo 1006 na questão 3.

## Execução da atividade

Para executar a atividade basta executar o roteiro abaixo:

- Compilar

```shell
gcc atividade-1.c -o bin
```

- Executar

```shell
./bin
```

Após a execução o sistema ficará aguardando o input, que é a string S. Logo que digitada a string os resultados serão printados no terminal.

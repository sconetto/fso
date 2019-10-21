DEADLOCKS
---------

1) Liste três exemplos de deadlocks não relacionados a um ambiente de
computação.

R. Um cruzamento onde ônibus das quatro faixas (recurso) avancem ao mesmo tem, a pista ficará bloqueada causando um engarrafamento (deadlock).

2) É possí­vel haver um deadlock envolvendo apenas um processo? Explique sua
resposta.

R. O deadlock pode acontecer mesmo que haja só um processo no SO, considerando que este processo utilize várias threads e que tais threads requisitem os mesmos recursos alocados a outras threads no mesmo processo.

MEMÓRIA
-------

1) Considere um sistema cuja gerência de memória é feita através de partições
variáveis. Nesse momento, existem as seguintes lacunas (áreas livres):
10K, 4K, 20K, 18K, 7K, 9K, 12K e 13K, nessa ordem. Quais espaços serão ocupados
pelas solicitações: 5K, 10K e 6K, nessa ordem, se:
    - first-fit for utilizado?
    - best-fit for utilizado?
    - worst-fit for utilizado?

R.
first-fit:
  1⁰ - 5K vai ser alocado em 10K
  2⁰ - 10K vai ser alocado em 20K
  3⁰ - 6K vai ser alocado em 18K

best-fit:
  1⁰ - 5K vai ser alocado em 7K
  2⁰ - 10K vai ser alocado em 10K
  3⁰ - 6K vai ser alocado em 9K

worst-fit:
  1⁰ - 5K vai ser alocado em 20K
  2⁰ - 10K vai ser alocado em 18K
  3⁰ - 6K vai ser alocado em 13K

2) Calcule o número de bits para página, quadro e deslocamento.

- Memória lógica = 512K, Memória fí­sica = 512K, Tamanho de página = 8K

R. Página: 8K = 2¹³ = 8192 -> 13 bits
   Número de Páginas: 64 = 2⁷ -> 7 bits
   Número de Quadros: 64 = 2⁷ -> 7 bits
   Memória Lógica: 512K = 2¹⁹ = 524288 -> 19 bits
   Memória Física: 512K = 2¹⁹ = 524288 -> 19 bits
   Deslocamento: 13 bits  

- Tamanho de página = 4K, Número de páginas = 8, Número de quadros = 16

R. Página: 4K = 2¹² = 4096 -> 12 bits
   Número de Páginas: 8 = 2⁴ -> 4 bits
   Número de Quadros: 16 = 2⁵ -> 5 bits
   Memória Física: 64K = 2¹⁶ = 65536 -> 16 bits
   Memória Lógica: 32K = 2¹⁵ = 32768 -> 15 bits
   Deslocamento: 12 bits

3) O que é paginação?

R. É um esquema de gerênciamento de memória no qual o computador divide a memória física em bloco de tamanho fixos chamados quadros (frames) e divide a memória lógica em blocos em blocos de mesmo tamanho chamados páginas. É preciso manter um registro de todos os quadros livres, para rodar um programa de n páginas é preciso n quadros livres (e então se carrega o programa), é necessário traduzir o endereço lógico para o endereço físico e pode ocorrer fragmentação interna.

4) Qual é a diferença entre paginação e segmentação?

R. Segmentação é um esquema de gerenciamento de memória que suporta a visão do usuários, sendo que a memória será gerenciada a partir de blocos de segmentos, ou seja, para um programa N posso alocar um bloco de tamanho M necessário, enquanto na paginação temos o gerenciamento da memória por meio da divisão da memória em páginas de tamanho fixo a serem mapeadas para quadros, ou seja, para um programa N que necessita M de memória eu alocarei X páginas sendo que X >= M.

5) Considere que os processos da tabela abaixo devem ser executados em um SO
com paginação. A memória total é de 64K, o tamanho das páginas é de 4K e o
SO ocupa 8K. Mostre como seria a alocação de quadros para cada processo.
Processo | Mem. (K) | T. Cheg | T. Exec
P1         8          0          10
P2         6          1          15
P3         15         2          10
P4         5          3          14
P5         10         15         5

R.
64K -> 2¹⁶ = 65536 bytes -> 16 bits para a memória lógica/física
4K -> 2¹² = 4096 bytes -> 12 bits para o tamanho da página
4 bits para o número de páginas.
12 bits para o deslocamento.

    TB              T0            T1              T2            T3             T10            T12            T15            T16
| SO - 8K | -> | SO - 8K | -> | SO - 8K | -> | SO - 8K | -> | SO - 8K | -> | SO - 8K | -> | SO - 8K | -> | SO - 8K | -> | SO - 8K |
               | P1 - 8K |    | P1 - 8K |    | P1 - 8K |    | P1 - 8K |    | P2 - 6K |    | P2 - 6K |    | P2 - 6K |    | P4 - 5K |
                              | P2 - 6K |    | P2 - 6K |    | P2 - 6K |    | P3 - 15K|    | P4 - 5K |    | P4 - 5K |    | P5 - 10K|
                                             | P3 - 15K|    | P3 - 15K|    | P4 - 5K |                   | P5 - 10K|
                                                            | P4 - 5K |

   T17             T20
| SO - 8K | -> | SO - 8K |
| P5 - 10K|

5) Qual a diferença entre fragmentação interna e externa da memória
principal?

R. Fragmentação interna é a memória perdida dentro de uma partição (página), onde alocamos X Bytes fixos para Y bytes, sendo que Y < X. Fragmentação externa é a incapacidade de alocar memória, pois, apesar de haver memória livre  X >= Y de memória que queremos alocar, essa memória não está contígua.

6) Qual a principal diferença entre os sistemas que implementam paginação e
segmentação?

R. Sistemas que implementam paginação tem tamanho fixo para os blocos de memórias alocados enquanto que sistemas que implementam segmentação tem blocos de memória de tamanho variável, dependendo da lógica do programa para a alocação.

7) Para que serve o bit de validade nas tabelas de páginas e segmentos?

R. Para informar que o endereço descrito é válido, ou seja, que está na memória o que se deseja pegar lá.

8) Nos sistemas com paginação, a rotina para tratamento de page faults está
residente na memória principal. Esta rotina pode ser removida da memória em
algum momento? O que aconteceria se esta rotina não estivesse na memória
principal durante a ocorrência de um page fault?

R. A rotina pode sim ser removida, caso seja necessário. O SO interrompe a execução do processo.

9) Descreva como ocorre a fragmentação interna em um sistema que implementa
paginação.

R. A fragmenta ocorre quando um processo X pede uma quantidade N de memória, sendo que N ou seus múltiplos são menores que o tamanho T das páginas ou seus múltiplos, dessa forma uma parte da memória é perdida por não estar sendo utilizada. Exemplo, um processo que precisa de 10K de memória num sistema com paginação, onde as páginas tem 4K, logo a quantidade mínima de páginas seriam 3, dando 12K e desses 12K, 2K ficam alocados mas não são usados, ocorrendo a fragmentação interna.

VIRTUAL
-------

1) O que é memória virtual?

Memória virtual é uma técnica que usa a memória secundária como uma cache para armazenamento secundário. Houve duas motivações principais: permitir o compartilhamento seguro e eficiente da memória entre vários programas e remover os transtornos de programação de uma quantidade pequena e limitada na memória principal.

2) Quais das seguintes técnicas e estruturas de programação são "boas" para
um ambiente de paginação por demanda? Quais delas são "más"? Explique suas
respostas.
    a. Pilha
    b. Tabela de sí­mbolos submetida à função hash
    c. Busca sequêncial
    d. Busca Binária
    e. Código Puro
    f. Operações em vetor
    g. Simulação

3) Considere os seguintes algoritmos de substituição de páginas. Classifique
estes algoritmos em uma escala de cinco pontos do "ruim" ao "perfeito" de
acordo com a sua taxa de erros de página. Separe os algoritmos afetados pela
anomalia de Belady daqueles que não o são.
    a. Substituição LRU
    b. Substituição FIFO
    c. Substituição Ótima
    d. Substituição da segunda chance

4) Considere a seguinte sequência de referências de páginas:
    1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6

Quantos erros de páginas iriam ocorrer para os seguintes algoritmos de
substituição, considerando um, dois, três, quatro, cinco, seis ou sete
quadros? Lembre-se de que todos os quadros estão inicialmente vazios, de
modo que a primeira página de cada um implicará em um erro de página.
    - Substituição LRU
    - Substituição Ótima
    - Substituição do Relógio
    - Substituição WSClock

5) Você consegue imaginar alguma situação em que dar suporte à memória
virtual seria uma má ideia e o que se ganha quando não é necessário o
suporte a memória virtual? Explique.

6) Exercícios do capítulo 3 do Tanembaum

---

Exercícios Aula:

1.

Páginas de 2048 bytes: 2¹¹ -> 2048 -> 11 bits
Endereços lógicos: 16 bits

a. A quantidade de páginas seria 32 páginas, ou 2⁵, ou seja, 5 bits.

b. 0 -> 5, 1 -> 2, 2 -> 10, 3 -> Indisponível, 4 -> 8, 5 -> 3.

02C5 (hex) = 0000 0010 1100 0101

- 5 bits da página 00000 -> 0. 0 -> 5 (dec) : 00101 (bin)
0010 1010 1100 0101 (bin) -> memória física: 2AC5 (hex)

2162 (hex) = 0010 0001 0110 0010

- 5 bits da página 00100 -> 4. 4 -> 8 (dec) : 01000 (bin)
0100 0001 0110 0010 (bin) -> memória física: 4162 (hex)

3B34 (hex) = 0011 1011 0011 0100

- 5 bits da página 00111 -> 7. 7 -> Indisponível : error

2.

a. 3000 -> 2x 2048 = 4096 (2 páginas)
Um aproveitamento efetivo de 73% da memória, ou seja, 27% ficariam livres (fragmentação interna)

b. 10000 -> 5x 2048 = 10240 (5 páginas)
Um aproveitamento efetivo de 97% da memória, ou seja, 3% ficariam livres (fragmentação interna)

---

Exercícios Prova Exemplo:

2)

2¹⁸ - memória física
2³² - memória lógica
4096 = 2¹² - tamanho página
2⁶ = 64 - número de páginas
11123456
0001 0001 0001 0010 0011 0100 0101 0110

O endereço gerado é divídio em número da página (p) e deslocamento/offset (d). Dessa forma o endereço virtual gerado retira-se os 6 primeiros bits para se descobrir em qual página se está  e depois pega os próximos 12 bits para descobrir o deslocamento dentro da página, os demais bits são apenas virtuais já que temos apenas 18 bits para a memória física.

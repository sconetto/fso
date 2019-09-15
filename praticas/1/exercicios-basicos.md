# Exercícios

## Questões Básicas

1. Enumere e explique resumidamente as principais responsabilidades de um sistema operacional.

R: Sistema Operacional é o software que executa em modo núcleo.
Sistemas operacionais executam, basicamente, duas funções não relacionadas:
Fornecer aos programadores de aplicativos (e aos programas aplicativos) um conjunto de
recursos confusos de hardware e gerenciar esses recursos de hardware.

2. Qual é a diferença entre modo usuário e modo kernel? Por que esta distinção é feita?

R: Modo Kernel (ou modo núcleo): Nesse modo o sistema operacional tem acesso completo a todo
o hardware e pode executar quaquer instrução que a máquina seja capaz de executar.
Modo Usuário: Nesse modo o sistema operacional tem acesso apenas a um subconjunto de
instruções da máquina.
Instruções que afetam o controle da máquina ou realizam I/O (entrada e saída) são proibidas
para programas em modo usuários.
A distinção é feita para que o sistema operacional proteja o hardware de alguns tipos de
alterações que o usuário possa fazer.

3. Descreva como são implementados os seguintes eventos: (i) chamada de sistema, (ii) tratamento de interrupção e (iii) tratamento de sinais. Quais são as semelhanças e diferenças entre estes eventos?

4. Qual é a diferença entre um sistema monolítico e um baseado em camadas?

## Processos

1. Descreva o funcionamento da função fork(). Após o fork, como os processos pai e filho podem se comunicar/sincronizar?

2. O que é um processo Zumbi? Escreva um programa que crie processos zumbis.

3. Familiarize-se com as chamadas: fork(2), wait(2),

4. Abra um terminal e execute o comando: pstree -c -p Descreva o que está vendo.

5. Resolva http://wiki.inf.ufpr.br/maziero/doku.php?id=so:criacao_de_processos

6. Resolva http://www.dei.isep.ipp.pt/~orlando/so2/processos.htm

7. Familiarize-se com as chamdas: execve(2), clone(2)

##

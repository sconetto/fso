# Prova 2

## Gerenciamento de Memória

Atribuição de endereços de memória (para instruções e dados) podem ser feitos em três estágios:

- Em tempo de compilação;
- Em tempo de carregamento;
- Em tempo de execução;

Endereço Lógico: endereço gerado pelo CPU; também conhecido como endereço virtual.
Endereço Físico: endereço visto por uma unidade de memória (hardware).

MMU - Memory-Management Unit (Unidade de Gerenciamento de Memória): dispositivo de hardware que mapeia (registrador de relocação - adiciona valor aos endereços gerados pelo processo) endereços virtuais em físicos. O programas de usuário só vê endereços lógicos, nunca físicos.

Carregamento Dinâmico: rotina não é até que ela seja invocada (pode nunca ser carregada). Utilização mais otimizada de memória.
Ligação Dinâmica: ligação é adiada até o tempo de execução. Pequeno pedaço de código, o stub, é usado para localizar a apropriada rotina, residente na memória. A stub se substitui com o endereço da rotina e a executa (útil para bibliotecas).

Overlays (sobreposições): manter na memória somente instruções e dados que são necessários num instante t. Necessárias quando um processo é maior que a quantidade de memória alocada para ele. Estrutura complexa.

Páginação: O espaço de endereçamento lógico de um processo pode não ser contíguo. Dividir a memória física em blocos de tamanho fixo chamado quadros (frames) entre 512 e 8192 bytes. Dividir a memória lógica em blocos de mesmo tamanho chamados páginas. Manter um registro de todos os quadros livres. Para rodar um programa em N páginas, o SO precisa encontrar e carregar N quadros livres. Usar uma tabela de páginas para traduzir o endereço lógico para físico. Pode ocorrer fragmentação interna.

Fragmentação Interna: é a perda de espaço dentro de uma área de tamanho fixo. Ocorre quando um programa/arquivo não ocupa completamente o espaço da unidade de alocação destinado a ele, causando desperdício de espaço.
  Ex.: Processo ocupa 10K de memória e a memória está paginada em páginas e quadros de 4K, o processo receberá 12K de memória e haverá um desperdício de 2K de memória.

Fragmentação Externa: é a perda de espaço de um tamanho dinâmico. Ocorre quando um programa não consegue encontrar memória livre contígua, mas na soma dos blocos de memória livre há a quantidade necessária de memória.
  Ex.: Uma memória de 16K tem um bloco de 2K livre, um bloco de 2K com o processo A, um bloco 4K livre, um bloco de 5K com o processo B e por fim um bloco de 3K livre. Agora há um processo pedindo 6K de memória, no formato que a memória está dividida -> 2K livre, 2K ocupado, 4K livre, 5K ocupado e 3K livre, temos 9K livres mas não conseguimos inserir um processo de 6K pelo fato da memória estar fragmentada.

Esquema de tradução de endereço: O endereço gerado pela CPU é divido em número de página (p) e deslocamento/offset na página (d). O número da página é usado como um índice na tabela de páginas que contém o endereço-base de cada página na memória física. O deslocamento combinado com o endereço base define o endereço físico que será enviado a unidade de memória.

TLB (translation look-aside buffers): uma cache especial de busca rápida.
PTBR (page-table base register): registrador que aponta para o início da tabela de páginas.
PRLR (page-table length register): registrador que indica o tamanho da tabela de páginas.
STBR (segment-table base register): registrador que aponta para o início da tabela de segmentos.
STLR (segment-table lenght register): registrador que indica o tamanho da tabela de segmentos.

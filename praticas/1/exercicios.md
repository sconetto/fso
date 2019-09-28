# Prática 1

## Exercícios

1. Utilize o manual online para conhecer os comandos:

- date(1): _date - print or set the system date and time_
- echo(1): _echo - display a line of text_
- chmod(1): _chmod - change file mode bits_
- touch(1): _touch - change file timestamps_
- rm(1): _rm - remove files or directories_
- ls(1): _rm - remove files or directories_
- cp(1): _cp - copy files and directories_
- mv(1): _mv - move (rename) files_
- mkdir(1): _mkdir - make directories_
- rmdir(1): _rmdir - remove empty directories_
- less(1): _less - opposite of more_
- who(1): _who - show who is logged on_
- id(1): _id - print real and effective user and group IDs_
- whoami(1): _whoami - print effective userid_
- finger(1): _finger — user information lookup program_
- cat(1): _cat - concatenate files and print on the standard output_

2. Resolva os exercícios da Apostila Linux Básica, Capítulo 3, Secção 3.8

3. Crie o diretório ~/exerc_01/arquivos usando mkdir(1) APENAS uma vez.

```bash
mkdir -p ~/exerc_01/arquivos
```

4. Copie para o diretório criado no exercício anterior os arquivos passwd, group, issue, que estão no diretório etc na raiz do sistema. Resolva este exercício com APENAS UMA ÚNICA linha de comando.

```bash
cp /etc/passwd /etc/group /etc/issue ~/exerc_01/arquivos
```

5. Suponha que você tem em um diretório /home/Empresa os subdiretórios memorandos, contratos, vendas e clientes. Cada um destes subdiretórios possui centenas e centenas de arquivos e subdiretórios que foram criados por você. Agora, você quer proteger o diretório /home/Empresa e seu subdiretórios e arquivos, de forma que os arquivos possam ser lidos por você e por usuários de seu grupo UNIX, mas apenas você possa alterá-los. Além disso, outros usuários não devem ter qualquer permissão de acesso a estes arquivos. Como não bastasse, somente você deve ter permissão para listar os conteúdos do diretórios. Indique qual a seqüência de comandos que deve ser executada para garantir os objetivos acima.

```bash
chmod -R 750 /home/Empresa
```

6. Crie o arquivo mocorongo dentro do diretório ~/exercicios_01. Em seguida, indique como usar chmod(1) para definir as permissões abaixo:

- Leitura e escrita para você e outros. Nenhuma permissão para usuários de seu grupo UNIX;
- Somente você pode listar os arquivos do diretório;
- Todos podem ler os arquivos do diretório, mas somente você e usuários de seu grupo UNIX podem listar os arquivos do diretório

```bash
mkdir ~/exercicios_01
chmod -R 753 ~/exercicios_01
```

7. O que você fez errado? Como corrigir o problema, mantendo o seu objetivo inicial?

Com o comando feito a permissão foi dada para o usuário apenas de leitura e escrita, faltando permissão de execução

```bash
chmod -R 700 Trab_Prog_01
```

8. Considerando ainda o exercício anterior, qual seria o efeito dos comandos abaixo?

Conforme explicado, o arquivo daria ao dono apenas a permissão de leitura e escrita.

9. Você deseja retirar todos os arquivos com sufixo _.bak, _%, \*~ e os arquivos de nome core existentes em sua área. No entanto, o que você quer de fato é movê-los para um diretório ~/.trash para posteriormente apagá-los com algum outro comando.

```bash
mv *.bak *% *~ ~/.trash
```

10. Com o problema definido no exercício anterior, você agora deve comprimir (através de bzip2(1)) todos os arquivos do diretório ~/.trash cujo tamanho seja maior que 2M bytes.

```bash
find ~/.trash -type f -size +2M | bzip2
```

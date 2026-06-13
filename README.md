Montador para o Neander

Descrição

Este projeto implementa um montador (assembler) para o computador educacional Neander, desenvolvido em linguagem C. O programa traduz arquivos escritos em Assembly (.asm) para linguagem de máquina, gerando um arquivo binário compatível com o simulador do Neander.

Funcionamento

O montador lê um arquivo Assembly, converte cada instrução para seu respectivo opcode hexadecimal e grava o resultado em um arquivo binário chamado saida.mem.

Leitura do arquivo .asm fornecido pelo usuário.

Conversão dos mnemônicos para opcodes.

Gravação do arquivo binário no formato esperado pelo Neander.

O arquivo gerado sempre inicia com o cabeçalho obrigatório:

03 4E 44 52

Tabela de instruções

Assembly     Opcode

NOP            00

STA            10

LDA            20

ADD            30

OR             40

AND            50

NOT            60

JMP            80

JN             90

JZ             A0

HLT            F0


Formato de saída

Para instruções com operando, o montador grava:

[opcode] 00 [operando] 00

Exemplo:

LDA 80 → 20 00 80 00

Para instruções sem operando (NOP, NOT e HLT), o montador grava apenas:

[opcode] 00

Compilação

Compile o programa com o GCC:

Uso

Execute o montador passando o arquivo Assembly como argumento:

O arquivo de saída será gerado como:

saida.mem

Exemplo

Arquivo programa.asm:

Execução:

Arquivo gerado saida.mem (em hexadecimal):

Observações

O montador ignora instruções inválidas.

Os operandos devem ser informados em hexadecimal.

O programa gera sempre um arquivo chamado saida.mem.

Projeto desenvolvido para a disciplina de Arquitetura e Organização de Computadores, com foco em linguagem Assembly, tradução de instruções e geração de código de máquina.

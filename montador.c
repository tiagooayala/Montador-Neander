#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toUpperStr(char *s)
{
    for(int i = 0; s[i] != '\0'; i++)
    {
        s[i] = toupper(s[i]);
    }
}

int buscarOpcode(char instrucao[])
{
    if(strcmp(instrucao, "NOP") == 0) return 0x00;
    if(strcmp(instrucao, "STA") == 0) return 0x10;
    if(strcmp(instrucao, "LDA") == 0) return 0x20;
    if(strcmp(instrucao, "ADD") == 0) return 0x30;
    if(strcmp(instrucao, "OR")  == 0) return 0x40;
    if(strcmp(instrucao, "AND") == 0) return 0x50;
    if(strcmp(instrucao, "NOT") == 0) return 0x60;
    if(strcmp(instrucao, "JMP") == 0) return 0x80;
    if(strcmp(instrucao, "JN")  == 0) return 0x90;
    if(strcmp(instrucao, "JZ")  == 0) return 0xA0;
    if(strcmp(instrucao, "HLT") == 0) return 0xF0;

    return -1;
}

int usaOperando(char instrucao[])
{
    if(strcmp(instrucao, "NOP") == 0) return 0;
    if(strcmp(instrucao, "NOT") == 0) return 0;
    if(strcmp(instrucao, "HLT") == 0) return 0;

    return 1;
}

int main(int argc, char *argv[])
{
    FILE *arquivo;

    char instrucao[20];
    int operando;

    if(argc != 2)
    {
        printf("Uso: ./montador arquivo.asm\n");
        return 1;
    }

    arquivo = fopen(argv[1], "r");

    if(arquivo == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    while(fscanf(arquivo, "%s", instrucao) == 1)
    {
        toUpperStr(instrucao);

        int opcode = buscarOpcode(instrucao);

        if(opcode == -1)
        {
            printf("Instrucao invalida\n");
            continue;
        }

        if(usaOperando(instrucao))
        {
            fscanf(arquivo, "%x", &operando);

            printf("%02X %02X\n", opcode, operando);
        }
        else
        {
            printf("%02X\n", opcode);
        }
    }

    fclose(arquivo);

    return 0;
}
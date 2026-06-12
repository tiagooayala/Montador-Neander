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
    FILE *entrada;
    FILE *saida;

    char instrucao[20];
    int operando;

    unsigned char byte;

    if(argc != 2)
    {
        printf("Uso: ./montador arquivo.asm\n");
        return 1;
    }

    entrada = fopen(argv[1], "r");

    if(entrada == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    saida = fopen("saida.mem", "wb");

    if(saida == NULL)
    {
        printf("Erro ao criar arquivo\n");
        fclose(entrada);
        return 1;
    }

    unsigned char cabecalho[4] =
    {
        0x03,
        0x4E,
        0x44,
        0x52
    };

    fwrite(cabecalho, 1, 4, saida);

    while(fscanf(entrada, "%s", instrucao) == 1)
    {
        toUpperStr(instrucao);

        int opcode = buscarOpcode(instrucao);

        if(opcode == -1)
        {
            continue;
        }

        if(usaOperando(instrucao))
        {
            fscanf(entrada, "%x", &operando);

            byte = opcode;
            fwrite(&byte, 1, 1, saida);

            byte = 0x00;
            fwrite(&byte, 1, 1, saida);

            byte = operando;
            fwrite(&byte, 1, 1, saida);

            byte = 0x00;
            fwrite(&byte, 1, 1, saida);
        }
        else
        {
            byte = opcode;
            fwrite(&byte, 1, 1, saida);

            byte = 0x00;
            fwrite(&byte, 1, 1, saida);
        }
    }

    fclose(entrada);
    fclose(saida);

    printf("Arquivo saida.mem gerado com sucesso!\n");

    return 0;
}
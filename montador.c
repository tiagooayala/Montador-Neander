#include <stdio.h>
#include <string.h>
#include <ctype.h>

void toUpperStr(char *s) {
    for (int i = 0; s[i]; i++) {
        s[i] = toupper((unsigned char)s[i]);
    }
}

int buscarOpcode(const char *instrucao) {

    if (strcmp(instrucao, "NOP") == 0) return 0x00;
    if (strcmp(instrucao, "STA") == 0) return 0x10;
    if (strcmp(instrucao, "LDA") == 0) return 0x20;
    if (strcmp(instrucao, "ADD") == 0) return 0x30;
    if (strcmp(instrucao, "OR")  == 0) return 0x40;
    if (strcmp(instrucao, "AND") == 0) return 0x50;
    if (strcmp(instrucao, "NOT") == 0) return 0x60;
    if (strcmp(instrucao, "JMP") == 0) return 0x80;
    if (strcmp(instrucao, "JN")  == 0) return 0x90;
    if (strcmp(instrucao, "JZ")  == 0) return 0xA0;
    if (strcmp(instrucao, "HLT") == 0) return 0xF0;

    return -1;
}

int usaOperando(const char *instrucao) {

    if (strcmp(instrucao, "NOP") == 0) return 0;
    if (strcmp(instrucao, "NOT") == 0) return 0;
    if (strcmp(instrucao, "HLT") == 0) return 0;

    return 1;
}

int main() {

    char instrucao[20];
    int operando;

    while (1) {

        printf("Digite uma instrucao: ");

        if (scanf("%19s", instrucao) != 1) {
            break;
        }

        toUpperStr(instrucao);

        int opcode = buscarOpcode(instrucao);

        if (opcode == -1) {
            printf("Instrucao invalida!\n");
            continue;
        }

        if (usaOperando(instrucao)) {

            scanf("%x", &operando);

            printf("Bytes gerados: %02X %02X\n",
                   opcode,
                   operando);
        }
        else {

            printf("Byte gerado: %02X\n",
                   opcode);
        }

        if (strcmp(instrucao, "HLT") == 0) {
            break;
        }
    }

    return 0;
}
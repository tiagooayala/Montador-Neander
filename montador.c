#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char instrucao[20];
    int operando;

    while (1) {

        printf("Digite uma instrucao: ");
        if (scanf("%19s", instrucao) != 1) break;

        for (int i = 0; instrucao[i]; i++) {
            instrucao[i] = toupper(instrucao[i]);
        }

        if (strcmp(instrucao, "NOP") == 0) {
            printf("Byte gerado: 00\n");
        }

        else if (strcmp(instrucao, "STA") == 0) {
            scanf("%x", &operando);
            printf("Bytes gerados: 10 %02X\n", operando);
        }

        else if (strcmp(instrucao, "LDA") == 0) {
            scanf("%x", &operando);
            printf("Bytes gerados: 20 %02X\n", operando);
        }

        else if (strcmp(instrucao, "ADD") == 0) {
            scanf("%x", &operando);
            printf("Bytes gerados: 30 %02X\n", operando);
        }

        else if (strcmp(instrucao, "OR") == 0) {
            scanf("%x", &operando);
            printf("Bytes gerados: 40 %02X\n", operando);
        }

        else if (strcmp(instrucao, "AND") == 0) {
            scanf("%x", &operando);
            printf("Bytes gerados: 50 %02X\n", operando);
        }

        else if (strcmp(instrucao, "NOT") == 0) {
            printf("Byte gerado: 60\n");
        }

        else if (strcmp(instrucao, "JMP") == 0) {
            scanf("%x", &operando);
            printf("Bytes gerados: 80 %02X\n", operando);
        }

        else if (strcmp(instrucao, "JN") == 0) {
            scanf("%x", &operando);
            printf("Bytes gerados: 90 %02X\n", operando);
        }

        else if (strcmp(instrucao, "JZ") == 0) {
            scanf("%x", &operando);
            printf("Bytes gerados: A0 %02X\n", operando);
        }

        else if (strcmp(instrucao, "HLT") == 0) {
            printf("Byte gerado: F0\n");
            break;
        }

        else {
            printf("Instrucao invalida!\n");
        }
    }

    return 0;
}

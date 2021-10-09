#ifndef __ARQUIVOS__
#define __ARQUIVOS__

#include <stdio.h>
#include <stdlib.h>

int lerArquivo(int * vetor, int tamanho, const char * caminho);
int gravarArquivo(int * vetor, int tamanho, const char * caminho, int espacos);

// Retorna 0 se deu ruim
// Retorna 1 se deu certo
int lerArquivo(int * vetor, int tamanho, const char * caminho) {
    FILE * fp;
    fp = fopen(caminho, "r");
    if(fp == NULL) return 0;

    // Vai até o fim do arquivo, descobre quantos bytes tem
    // da posição atual (fim) até o início, guarda numa var
    // de tamanho e volta para o início do arquivo
    fseek(fp, 0, SEEK_END);
    unsigned int tamanhoArquivo = ftell(fp);
    fseek(fp, 0, SEEK_SET); // rewind(fp);

    // Se isso não estiver aqui, o último caractere não é lido.
    tamanhoArquivo++;

    // Aloca memória para ler os caracteres do arquivo
    char * arquivo = (char *)calloc(tamanhoArquivo + 1, sizeof(char));

    // Lê o arquivo no buffer criado acima
    fgets(arquivo, tamanhoArquivo, fp);

    // Distância, em caracteres, entre cada número:
    int distancia = 2;

    // Se for separado por espaços, a distância é 3.
    if(arquivo[2] == ' ') {
        distancia = 3;
    }

    int posArquivo = 0;
    while(posArquivo < tamanho) {
        int pos = posArquivo * distancia;

        char cA = arquivo[pos];
        char cB = arquivo[pos + 1];

        // Vamos transformar os caracteres
        // lidos (os dígitos) em ints:
        // Suponha que um dos dígitos é 5.
        // O valor do caractere 5 na tabela
        // ASCII é 53. O valor do primeiro
        // número (0) na tabela ASCII é 48.
        // Observe que 53 - 48 = 5.
        // Então para qualquer dígito lido,
        // seu valor correspondente em int
        // é o ASCII do caractere - ASCII de 0.
        // Em C, podemos transformar um char
        // em uma int correspondente a seu valor
        // ASCII implicitamente, sem fazer
        // conversão. Observe:
        int A = cA - '0';
        int B = cB - '0';

        int valor = A * 10 + B;

        vetor[posArquivo] = valor;

        posArquivo++;
    }

    fclose(fp);
    return 1;
}

// Retorna 0 se deu ruim
// Retorna 1 se deu certo
// Espaços: se for 0, não há espaços. Caso contrário, tem 1 espaço entre dígitos.
int gravarArquivo(int * vetor, int tamanho, const char * caminho, int espacos) {
    FILE * fp;
    fp = fopen(caminho, "w");
    if(fp == NULL) return 0;

    for(int i = 0; i < tamanho; i++) {
        fprintf(fp, "%02d", vetor[i]);
        if(espacos != 0 && i != tamanho - 1) {
            fprintf(fp, " ");
        }
    }

    // Se quiser, tire isso.
    fprintf(fp, "\n");

    fclose(fp);
    return 1;
}

#endif

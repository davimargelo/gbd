#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void gerarNumeroAleatorioEntre(const int minimo, const int maximo, const int quantidade) {
    int numeroGerado = 0;
    for (int i = 0; i < quantidade; i++) {
        numeroGerado = rand() % (maximo - minimo) + minimo;
        printf("%d ", numeroGerado);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int minimo = 0, maximo = 0, quantidade = 0;

    printf("Número mínimo: ");
    scanf("%d", &minimo);

    printf("Número máximo: ");
    scanf("%d", &maximo);

    printf("Números a serem sorteados: ");
    scanf("%d", &quantidade);

    gerarNumeroAleatorioEntre(minimo, maximo, quantidade);
    return 0;
}

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void sortear(int v[], int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % (10 * n) + 1;
    }
}

void mostrar(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void trocar(int v[], int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

bool crescente(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (v[i] > v[i + 1]) {
            return false;
        }
    }
    return true;
}

int bubble_sentinela_otimizado(int v[], int n) {
    int contador = 0;
    bool sentinela = false;

    for (int c = 0; c < n - 1; c++) {
        sentinela = false;
        for (int i = 0; i < n - 1 - c; i++) {
            contador++;
            if (v[i] > v[i + 1]) {
                sentinela = true;
                trocar(v, i, i + 1);
            }
        }
        if (!sentinela) {
            return contador;
        }
    }
    return contador;
}

int main(void) {
    srand(time(NULL));
    printf("Teste do algoritmo de ordenação!\n");
    int n = 100; // Altere o valor de n aqui
    int v[n];
    int execucoes = 10000;
    long soma = 0;
    long menor = -1;
    long maior = 0;
    for (int exec = 0; exec < execucoes; exec++) {
        sortear(v, n);
        int contador = bubble_sentinela_otimizado(v, n); // Chame a função bubble_sentinela_otimizado
        if (!crescente(v, n)) {
            printf("O vetor não está ordenado! Verifique sua função de ordenação!\n");
            return 1;
        }
        if (contador > maior) {
            maior = contador;
        }
        if (menor < 0 || contador < menor) {
            menor = contador;
        }
        soma += contador;
    }
    printf("Número total de execuções: %d\n", execucoes);
    double media = (double)soma / execucoes; // Correção para calcular a média como um número decimal
    printf("Menor valor do contador: %ld\n", menor);
    printf("Valor médio do contador: %.2f\n", media); // Mostra a média com duas casas decimais
    printf("Maior valor do contador: %ld\n", maior);
    return 0;
}

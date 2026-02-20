#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FACES 6

int main(void)
{
    int frequency[FACES] = {0}; // array para contar as faces
    int rolls;
    int face;

    // pede quantidade de lançamentos
    printf("Quantos lancamentos deseja simular? ");
    scanf("%d", &rolls);

    // inicializa o gerador de numeros aleatorios
    srand(time(NULL));

    // simulação
    for (int i = 0; i < rolls; i++)
    {
        face = rand() % FACES; // gera numero de 0 a 5
        frequency[face]++;     // incrementa a face correspondente
    }

    // saída
    printf("\nFace\tFrequencia\tPorcentagem\tHistograma\n");

    for (int i = 0; i < FACES; i++)
    {
        float percentage = (frequency[i] / (float)rolls) * 100;

        printf("%d\t%d\t\t%.2f%%\t\t", i + 1, frequency[i], percentage);

        // histograma
        for (int j = 0; j < frequency[i] / (rolls / 50 + 1); j++)
        {
            printf("*");
        }

        printf("\n");
    }

    return 0;
}

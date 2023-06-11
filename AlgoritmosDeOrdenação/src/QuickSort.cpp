#include <iostream>
#include "../include/SortAlgorithms_h.hpp"

using namespace std;

// Função para trocar dois elementos
void trocar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Função para encontrar a mediana entre três elementos
int encontrarMediana(int arr[], int esquerda, int direita) {
    int meio = esquerda + (direita - esquerda) / 2;

    if (arr[esquerda] > arr[meio])
        trocar(arr[esquerda], arr[meio]);
    if (arr[esquerda] > arr[direita])
        trocar(arr[esquerda], arr[direita]);
    if (arr[meio] > arr[direita])
        trocar(arr[meio], arr[direita]);

    return meio;
}

// Função para particionar a lista e encontrar a posição correta do pivô
int particionar(int arr[], int esquerda, int direita,int tam) {
    int pivoIndex = encontrarMediana(arr, esquerda, direita);
    int pivo = arr[pivoIndex];

    int i = esquerda - 1;

    for (int j = esquerda; j <= direita - 1; j++) {
        if (arr[j] < pivo) {
            i++;
            trocar(arr[i], arr[j]);
            print_arr(arr,tam);
        }
    }

    trocar(arr[i + 1], arr[direita]);
    print_arr(arr,tam);
    return (i + 1);
}

// Função recursiva do Quicksort
void quicksort(int arr[], int esquerda, int direita, int tam) {
    if (esquerda < direita) {
        int pi = particionar(arr, esquerda, direita, tam);

        // Ordena as sub-listas recursivamente
        quicksort(arr, esquerda, pi - 1, tam);
        quicksort(arr, pi + 1, direita, tam);
    }
}

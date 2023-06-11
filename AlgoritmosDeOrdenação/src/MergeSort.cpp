#include "../include/SortAlgorithms_h.hpp"

void merge(int arr[], int esquerda, int meio, int direita)
{
    // Declarando o tamanho dos arrays auxiliares
    int tamanho_esquerda = meio - esquerda + 1;
    int tamanho_direita = direita - meio;

    // Declarando os arrays auxiliares
    int arr_esquerda[tamanho_esquerda];
    int arr_direita[tamanho_direita];

    // Copiando os elementos para os arrays auxiliares
    for (int i = 0; i < tamanho_esquerda; i++)
    {
        arr_esquerda[i] = arr[esquerda + i];
    }
    for (int j = 0; j < tamanho_direita; j++)
    {
        arr_direita[j] = arr[meio + 1 + j];
    }

    // Declara as variáveis para a intercalação
    int indice_esquerda = 0;
    int indice_direita = 0;
    int indice_merge = esquerda;

    // Realiza o merge das listas
    while (indice_esquerda < tamanho_esquerda && indice_direita < tamanho_direita)
    {
        if (arr_esquerda[indice_esquerda] <= arr_direita[indice_direita])
        {
            arr[indice_merge] = arr_esquerda[indice_esquerda];
            indice_esquerda++;
            print_arr(arr,direita+1);
        }
        else
        {
            arr[indice_merge] = arr_direita[indice_direita];
            indice_direita++;
            print_arr(arr,direita+1);
        }
        indice_merge++;
    }

    // Coloca os elementos restantes na lista
    while (indice_esquerda < tamanho_esquerda)
    {
        arr[indice_merge] = arr_esquerda[indice_esquerda];
        indice_esquerda++;
        indice_merge++;
        print_arr(arr,direita+1);
    }
    while (indice_direita < tamanho_direita)
    {
        arr[indice_merge] = arr_direita[indice_direita];
        indice_direita++;
        indice_merge++;
        print_arr(arr,direita+1);
    }
}

void merge_sort(int arr[], int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;

        merge_sort(arr, esquerda, meio);
        merge_sort(arr, meio + 1, direita);

        merge(arr, esquerda, meio, direita);
        //print_arr(arr,direita+1);
    }
}
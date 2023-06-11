#include <iostream>
#include <string>
#include <cstdlib> // para usar a função rand()
#include <ctime>   // para usar a função time()

#include "../include/SortAlgorithms_h.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    int sortType = stoi(argv[1]);
    int tam = stoi(argv[2]); // tamanho do array
    int arr[tam]; // declaração do array
    // semente para a função rand() com base no tempo atual
    srand(time(NULL));

    std::cout << tam << std::endl;

    // preenche o array com valores aleatórios
    for (int i = 0; i < tam; i++) {
        arr[i] = rand() % 100; // valores entre 0 e 99
    }

    switch (sortType) 
    {
    case 1:
        bubble_sort(arr, tam);
        break;
    case 2:
        merge_sort(arr, 0, tam-1);
        break;
    case 3:
        quicksort(arr, 0, tam-1, tam);
        break;
    }
    print_arr(arr, tam);

    return 0;
}


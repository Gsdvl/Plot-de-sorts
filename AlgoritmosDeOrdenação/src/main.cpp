#include <iostream>
#include <cstdlib> // para usar a função rand()
#include <ctime>   // para usar a função time()

#include "../include/SortAlgorithms_h.hpp"

using namespace std;

int main()
{
    int tam = 10; // tamanho do array
    int arr[tam]; // declaração do array
    // semente para a função rand() com base no tempo atual
    srand(time(NULL));

    std::cout << tam << std::endl;

    // preenche o array com valores aleatórios
    for (int i = 0; i < tam; i++) {
        arr[i] = rand() % 100; // valores entre 0 e 99
    }
    int* sortedArray = bubble_sort(arr, tam);

    print_arr(sortedArray, tam);

    return 0;
}
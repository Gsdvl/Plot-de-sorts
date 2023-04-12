#include <iostream>
#include "../include/SortAlgorithms_h.hpp"


void print_arr(int arr[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    //std::cout << "\n" << std::endl;
}

int* bubble_sort(int arr[], int tam)
{
    int aux = 0;
    for(int i = 0; i < tam; i++)
    {
        for(int j = 1; j < tam; j++)
        {
            if(arr[j-1] > arr[j])
            {
                aux = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = aux;
            }
            print_arr(arr,tam);
        }
    }
    return arr;
}
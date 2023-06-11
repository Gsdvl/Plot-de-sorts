//Este algoritmo não será compilado com o resto, portanto possuirá um main próprio
//já que o mesmo serve apenas como objeto de estudo

#include <iostream>

using namespace std;

int bbin(int arr[], int chave, int esquerda, int direita)
{
    if(esquerda > direita){
        return -1;
    }
    int meio = (esquerda + direita) / 2;

    if(arr[meio] == chave)
    {
        return meio;
    }
    else if(arr[meio] < chave)
    {
        return bbin(arr, chave, meio+1, direita);
    }
    else
    {
        return bbin(arr, chave, esquerda, meio-1);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int chave = 0;
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    cin >> chave;
    cout << bbin(arr, chave, 0, tamanho);
}


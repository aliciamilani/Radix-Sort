#include <bits/stdc++.h>

using namespace std;

int digito(int num, int casa_decimal, int base)
{ //Extracao de digitos
    int d;
    if (base == 10)
    {
        d = num / (pow(10, casa_decimal));
        d %= 10;
        return d;
    }
    return 0;
}

// v = Vetor a ser ordenado, n = tamanho do vetor, base = base dos caracteres no vetor
//num_digitos = Numero maximo de digitos em um elemento
void radix_sort(int *v, int n, int base, int num_digitos)
{
    //iniciando variaveis auxiliares
    int i, j, w, count[base + 1], d, posicao;
    int *aux = (int *)malloc(n * sizeof(int));

    //percorrendo os digitos para realizar a ordenacao
    for (w = 0; w < num_digitos; w++)
    {
        //zerando o vetor que contara a quantidade de numeros por digito
        for (j = 0; j < base; j++)
            count[j] = 0;
        //percorrendo o vetor e contando a quantidade de numeros por digito
        for (i = 0; i < n; i++)
        {
            d = digito(v[i], w, base);
            count[d + 1]++;
        }
        //definindo a posicao inicial no vetor de cada digito
        for (j = 1; j < base; j++)
            count[j] += count[j - 1];
        //percorrendo o vetor para realizar a ordenacao
        for (i = 0; i < n; i++)
        {
            d = digito(v[i], w, base);
            //Extraindo a nova posicao do numero de acordo com seu digito que esta sendo analisado
            posicao = count[d];
            //ao adicionar um numero o digito em questao passara a ter uma nova posicao vaga
            count[d] += 1;
            aux[posicao] = v[i];
        }
        //vetor recebe a sua nova organizacao
        for (i = 0; i < n; i++)
            v[i] = aux[i];
    }
}

int main()
{

    int TAM = 100000;
    int vetor[TAM];

    for (int i = 0; i < TAM; i++)
    {
        cin >> vetor[i];
    }

    auto start = chrono::high_resolution_clock::now();
    radix_sort(vetor, TAM, 10, 5);
    auto end = chrono::high_resolution_clock::now();
    auto int_s = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "O tempo para ordenacao foi de: " << int_s.count() << " milisegundos" << endl;

    return 0;
}
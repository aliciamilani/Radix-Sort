#include <bits/stdc++.h>

using namespace std;

int digito(int num, int casa_decimal, int base){ //Extracao de digitos
    int d;
    if(base == 10){
        d = num/(pow(10, casa_decimal));
        d %= 10;
        return d;
    }
    return 0;
}

void radix(int *v, int n, int base, int num_digitos) { //vetor, quantidade de numeros, base decimal, digitos dos numeros
    int i, j, w, count[base+1], d, posicao;
    int *aux = (int *) malloc(n * sizeof(int));
    for(w = 0; w < num_digitos; w++) { //percorrendo os digitos para ordenar
        for(j = 0; j < base; j++) count[j] = 0; //contador de numeros baseado em seus digitos
        for(i = 0; i < n; i++) { //percorrendo vetor e extraindo o digito dos elementos
            d = digito(v[i], w, base); //extraindo o digito que esta sendo analisado
            count[d+1]++; //contando quantos numeros vao estar em casa posicao
        }
        for(j = 1; j < base; j++) count[j] += count[j-1]; //Pegando a posicao de inicio de cada digito
        for(i = 0; i < n; i++) { //Percorrendo vetor para ordenar
            d = digito(v[i], w, base); //Digito para definir a posicao no vetor
            posicao = count[d]; //pegando a posicao de insercao no vetor
            count[d] += 1; //nova posicao de insercao de determinado digito
            aux[posicao] = v[i]; //adicionando o elemento na nova posicao
            }
            for(i = 0; i < n; i++) v[i] = aux[i]; //vetor recebe a nova organizacao
    }
}

int main(){

    int TAM = 100000;
    int vetor[TAM];

    for(int i = 0; i < TAM; i++){
        cin >> vetor[i];

    }
    radix(vetor, TAM, 10, 5);

   for(int i = 0; i < TAM; i++){
       cout << vetor[i] << "\n";
   }

    return 0;
}
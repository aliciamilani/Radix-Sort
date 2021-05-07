#include <bits/stdc++.h>

using namespace std;

int digito(int num, int casa_decimal, int base){
    int d;
    if(base == 10){
        d = num/(pow(10, casa_decimal));
        d %= 10;
        return d;
    }
    return 0;
}

void radix(int *v, int n, int base, int num_digitos) {
    int i, j, w, count[base+1], d, posicao;
    int *aux = (int *) malloc(n * sizeof(int));
    for(w = 0; w < num_digitos; w++) {
        for(j = 0; j < base; j++) count[j] = 0; 
        for(i = 1; i <= n; i++) { 
            d = digito(v[i], w, base);
            count[d+1]++; 
        }
        for(j = 1; j < base; j++) count[j] += count[j-1];
        for(i = 0; i < n; i++) {
            d = digito(v[i], w, base);
            posicao = count[d];
            count[d] += 1;
            aux[posicao] = v[i];
            }
            for(i = 0; i < n; i++) v[i] = aux[i];
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
        cout << vetor[i] << " ";
    }

    return 0;
}
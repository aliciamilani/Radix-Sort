from random import randint

lista_numeros = [0]*100000

for pos in range(len(lista_numeros)):
    lista_numeros[pos] = str(randint(1, 99999)) + "\n"

print(len(lista_numeros))

arquivo_escrita = open("lista_100mil_aed2.txt", "x")

arquivo_escrita.writelines(lista_numeros)

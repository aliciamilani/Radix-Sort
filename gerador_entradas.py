from random import randint

lista_aleatorios = [0]*100000
lista_crescente = [str(i) + "\n" for i in range(100000)]
lista_decrescente = [str(i) + "\n" for i in range(100000, 0, -1)]

lista_crescente_decrescente = lista_crescente[:50000] + \
    lista_decrescente[50000:]

lista_decrescente_crescente = lista_decrescente[50000:] + \
    lista_crescente[:50000]

# Geração de 100.000 números aleatórios
for pos in range(len(lista_aleatorios)):
    lista_aleatorios[pos] = str(randint(1, 99999)) + "\n"


arquivo_escrita = open("entrada_aleatoria.txt", "x")
arquivo_escrita.writelines(lista_aleatorios)

arquivo_escrita = open("entrada_crescente.txt", "x")
arquivo_escrita.writelines(lista_crescente)

arquivo_escrita = open("entrada_decrescente.txt", "x")
arquivo_escrita.writelines(lista_decrescente)

arquivo_escrita = open("entrada_crescente_decrescente.txt", "x")
arquivo_escrita.writelines(lista_crescente_decrescente)

arquivo_escrita = open("entrada_decrescente_crescente.txt", "x")
arquivo_escrita.writelines(lista_decrescente_crescente)

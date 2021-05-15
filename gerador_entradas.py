from random import randint


def salvar_txt(nome_do_arquivo, lista):
    arquivo_escrita = open(nome_do_arquivo, "x")
    arquivo_escrita.writelines(lista)


lista_aleatorios = [0] * 100000
lista_crescente = [str(i) + "\n" for i in range(100000)]
lista_decrescente = [str(i) + "\n" for i in range(100000, 0, -1)]

lista_crescente_decrescente = lista_crescente[:50000] + \
    lista_decrescente[50000:]

lista_decrescente_crescente = lista_decrescente[50000:] + \
    lista_crescente[:50000]

# Geração de 100.000 números aleatórios
for pos in range(len(lista_aleatorios)):
    lista_aleatorios[pos] = str(randint(1, 99999)) + "\n"


salvar_txt("entrada_aleatoria.txt", lista_aleatorios)
salvar_txt("entrada_crescente.txt", lista_crescente)
salvar_txt("entrada_decrescente.txt", lista_decrescente)
salvar_txt("entrada_crescente_decrescente.txt", lista_crescente_decrescente)
salvar_txt("entrada_decrescente_crescente.txt", lista_decrescente_crescente)

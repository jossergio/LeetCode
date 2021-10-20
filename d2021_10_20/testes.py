#coding: utf-8

import modelo

obj = modelo.Solution ()

def mostrar (texto):
    print (texto, " <=> ", obj.reverseWords (texto))

mostrar ("O ceu e azul")
mostrar ("   o   ceu   e  azul  ")
mostrar ("o   ceu  e     azul")
mostrar ("")
mostrar ("o")
mostrar (" ceu    ")


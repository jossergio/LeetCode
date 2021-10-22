#coding: utf-8

import modelo

obj = modelo.Solution ()

def mostrar (s):
    print (s, " => ", obj.frequencySort (s))

mostrar ("abacadae")
mostrar ("abacdcefhejekehi")


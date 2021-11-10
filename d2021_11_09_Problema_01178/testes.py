# coding: utf-8

# from modelo import Solution
# from modelo2 import Solution
from modelo3 import Solution

teste = Solution ()

palavras = ["aaaa","asas","able","ability","actt","actor","access"]
puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]

print (teste.findNumOfValidWords (palavras, puzzles))

# Teste da lista do LeetCode
palavras = ["apple","pleas","please"]
puzzles = ["aelwxyz","aelpxyz","aelpsxy","saelpxy","xaelpsy"]

print (teste.findNumOfValidWords (palavras, puzzles))

